/*  
* Copyright (c) 2011-2013, NVIDIA Corporation
* All rights reserved.
*  
* Redistribution and use in source and binary forms, with or without  
* modification, are permitted provided that the following conditions are met:  
*   * Redistributions of source code must retain the above copyright  
*     notice, this list of conditions and the following disclaimer.
*   * Redistributions in binary form must reproduce the above copyright  
*     notice, this list of conditions and the following disclaimer in the  
*     documentation and/or other materials provided with the distribution.  
*   * Neither the name of NVIDIA Corporation nor the  
*     names of its contributors may be used to endorse or promote products  
*     derived from this software without specific prior written permission.  
*  
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND  
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  
* DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY  
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  
*/ 

// #include "stdafx.h"
#include <math.h>
#include <string>
#include <sstream>
#include "SHEvalCodeGen.hpp"

// set to generate SSE code instead of vanilla C
// does 4 evaluations in parallel...
// #define GENSSE 0

// simple utility functions
extern bool flipsign;

extern int g_sign ;

std::string sConst(double d){
    std::ostringstream  sstream;
    sstream.precision(16);
#ifdef GENSSE
    sstream << "_mm_set_ps1("<<d<<"f)";
#else
    sstream << d << "f";

#endif
    return sstream.str();	
}

std::string sMul(std::string s1, std::string s2)
{
    std::ostringstream  sstream;

#ifdef GENSSE
    sstream << "_mm_mul_ps("<<s1<<","<<s2<<")";
#else
    sstream << s1 << "*" << s2;
#endif
    return sstream.str();	
}

std::string sAdd(std::string s1, std::string s2)
{
    std::ostringstream  sstream;

#ifdef GENSSE
    sstream << "_mm_add_ps("<<s1<<","<<s2<<")";
#else
    sstream << s1 << " + " << s2;
#endif
    return sstream.str();	
}

std::string sSub(std::string s1, std::string s2)
{
    std::ostringstream  sstream;

#ifdef GENSSE
    sstream << "_mm_sub_ps("<<s1<<","<<s2<<")";
#else
    sstream << s1 << " - " << s2;
#endif
    return sstream.str();	
}


std::string sSHIndex(int idx)
{
    std::ostringstream  sstream;
#ifdef GENSSE
    sstream << "pSH + " << idx << "*4";
#else
    sstream << "pSH[" << idx << "]";
#endif
    return sstream.str();
}

std::string sAssign(std::string sVar, std::string sRHS)
{
    std::ostringstream  sstream;
#ifdef GENSSE
    sstream << "_mm_store_ps(" << sVar << "," << sRHS << ")";
#else
    sstream << sVar << " = " << sRHS;
#endif

    return sstream.str();
}

std::string sSSELoad(std::string sAddr)
{
    std::ostringstream  sstream;
    sstream << "_mm_load_ps("<< sAddr << ")";
    return sstream.str();
}

const double PI=3.1415926535897932384626433832795;

// SH Normalization function:
// K(l,m) = sqrt( (2*l + 1) (l - |m|)! / (4 Pi (l + |m|)! )
// factorials mostly cancel out, so you don't want overflow
// to really be numerically robust, you need to include this with the
// evaluation of Plm - particularly for large m

double K(const unsigned int l, const int m)
{
    const unsigned int cABSM = abs(m);

    double uVal = 1;// has to be double or code is incorrect for large m starting around order 8...

    for(unsigned int k = l + cABSM; k > (l - cABSM); k--) {
        uVal *= k;
    }

    return sqrt( (2.0*l + 1.0)/ ( 4*PI*uVal ) );
}


double Pmm(int m)
{
    double val = 1.0;
    int sign =(flipsign)? pow(-1,m) :1;
 
    for(int k=0;k<=m;k++) {
        val = sign * val*(1-2*k);
    }

    return val;
}
// some common strings for functions below
// these are variables that are often precomputed in some way...

std::string g_sX = "fX";
std::string g_sY = "fY";
std::string g_sZ = "fZ";
std::string g_sZ2 = "fZ2";

// Pmm = (1-2m) Pm-1m-1 => prod_k(1-2k)
// this normaly has the sin(theta) term (sqrt(1-x^2) in the associated legendre polynomials)
// but that gets mixed with the phi terms to treat things as polynomials...

std::string sRuleA(const int m, double fVal)
{
    return sConst(g_sign* double(Pmm(m)*K(m,m)*fVal));
}

// Pmm+1 = (2m+1) z Pmm => constant times z

std::string sRuleB(const int m, double fVal)
{
    return sMul(sConst(g_sign*double((2*m+1.0)*Pmm(m)*K(m+1,m)*fVal)),g_sZ);
}

// PmL = ((2L-1)z PmL-1 - (L+m-1) PmL-2)/(L-m)
// workhorse rule, other rules are modeled as special cases of this rule...
// PmL = ((2L-1)/ (L-m) PmL-1  z - (L+m-1)/ (L-m) PmL-2 
// assume Klm and fVal were folded into previous values...
// fVal not neded - since it is included in PmL-1 and PmL-2 already...
std::string sRuleC(const int l, const int m, std::string sPm1, std::string sPm2)
{

    double fA=g_sign*K(l,m)/K(l-1,m)*(2*l-1.0)/(l-m);
    double fB=g_sign*-K(l,m)/K(l-2,m)*(l+m-1.0)/(l-m);

    return sAdd(sMul(sMul(sConst(fA),g_sZ),sPm1),sMul(sConst(fB),sPm2));
}

// plug rule A and B into rule C
// Pmm+2 = ( (2(m+2)-1) z ((2m+1) z Pmm) - (m+2+m-1) Pmm  )/2
// now fold all of the constants together...
// Pmm+2 = ( (2m+3)(2m+1)Pmm/2 z^2  - (2m+1) Pmm / 2

std::string sRuleD(const int m, double fVal)
{
    const int l = m+2;

    return sAdd(sMul(sConst(g_sign*double( (2*m+3)*(2*m+1)*Pmm(m)/2*K(l,m)*fVal )),g_sZ2),sConst(g_sign*double(-1.0*(2*m+1)*Pmm(m)/2*K(l,m)*fVal)));
}

// plug rule D and B into rule C, factor out a z...
// Pmm+3 = ( (2(m+3)-1)z (( (2m+3)(2m+1)Pmm/2 z^2  - (2m+1) Pmm / 2) - (m+3+m-1) (2m+1) z Pmm )/3
// fold constants, pull out z...
// Pmm+3 = z ( (2m+5)(2m+3)(2m+1)Pmm/6 z^2 - ( (2m+5)(2m+1) Pmm/6 + (2m+2)(2m+1) Pmm/3 )

std::string sRuleE(const int m, double fVal)
{
    const int l = m+3;

    const double Pu = g_sign*Pmm(m);
    const double fA = g_sign*(2*m+5)*(2*m+3)*(2*m+1)*Pu/6*K(m+3,m)*fVal;
    const double fB = g_sign*-fVal*K(m+3,m)*((2*m+5)*(2*m+1)*Pu/6 + (2*m+2)*(2*m+1)*Pu/3);

    std::string fZ2 = "fZ2";

    std::ostringstream  sstream;
    sstream.precision(16);

    sstream << "(" << sAdd(sMul(sConst(fA),g_sZ2),sConst(fB)) << ")";
    return sMul(g_sZ,sstream.str());
}

// this is the reccurence relation for sin/cos

std::string sCreateSinReccur(std::string sCL, std::string sSL)
{
    return sAdd(sMul(g_sX,sSL),sMul(g_sY,sCL));
}

std::string sCreateCosReccur(std::string sCL, std::string sSL)
{
    return sSub(sMul(g_sX,sCL),sMul(g_sY,sSL));
}

// generates SH evaluation code (in sResult) using symbolic stuff..

void BuildSHEvalCode(std::string& sResult, const unsigned int lmax,bool flipsign)
{
   std::ostringstream  ssResult(sResult);
   ssResult.precision(16);

   unsigned int l,m;

   const double dSqrt2 = sqrt(2.0);

#ifdef GENSSE
    ssResult << "void SHEval" << lmax + 1<< "(const float *pX, const float *pY, const float *pZ, float *pSH)\n{\n";
    ssResult << "__m128 fX,fY,fZ;\n";
    ssResult << "__m128 fC0,fC1,fS0,fS1,fTmpA,fTmpB,fTmpC;\n";
    ssResult << "fX = _mm_load_ps(pX);\nfY = _mm_load_ps(pY);\nfZ = _mm_load_ps(pZ);\n\n";
#else
    ssResult << "void SHEval" << lmax + 1 << "(const float fX, const float fY, const float fZ, float *pSH)\n{\n";
    ssResult << "float fC0,fC1,fS0,fS1,fTmpA,fTmpB,fTmpC;\n";
#endif

   if (lmax >= 2) {
#ifdef GENSSE
        ssResult << "__m128 fZ2 = " << sMul(g_sZ,g_sZ) << ";\n\n";
#else
        ssResult << "float fZ2 = fZ*fZ;\n\n";
#endif
   } else {
      ssResult << "\n"; // make sure we have the extra line...
   }

   // DC is trivial
   ssResult << sAssign(sSHIndex(0),sConst(K(0,0))) << ";\n";

   m = 0;
   l=1;

   int idx = l*l+l;

   ssResult << sAssign(sSHIndex(idx), sRuleB(m,1.0)) << ";\n";

   if (lmax >= 2) {
      l=2;
      idx = l*l+l;
      ssResult << sAssign(sSHIndex(idx), sRuleD(m,1.0)) << ";\n";
   }

   if (lmax >= 3) {
      l=3;
      idx = l*l+l;
      ssResult << sAssign(sSHIndex(idx), sRuleE(m,1.0)) << ";\n";
   }	

   // loop for the rest of them...
   for(l=4;l<=lmax;l++) {
      std::string sPm1 = sSHIndex((l-1)*(l-1)+(l-1));
      std::string sPm2 = sSHIndex((l-2)*(l-2)+(l-2));
      idx = l*l+l;

#ifdef GENSSE
      // have to issue SSE load instructions for above...
      sPm1 = sSSELoad(sPm1);
      sPm2 = sSSELoad(sPm2);
#endif

      ssResult << sAssign(sSHIndex(idx), sRuleC(l,m,sPm1,sPm2)) << ";\n";
   }

   // now loop through the rest of "m's" emiting code

   ssResult << "fC0 = fX;\nfS0 = fY;\n\n"; // recurence for sin/cos

   // these 4 variables are required - no way to get around it
   std::string sC[2] = {"fC0","fC1"};
   std::string sS[2] = {"fS0","fS1"};

   // temporary variables, used by production rules
   std::string sPrev[3] = {"fTmpA","fTmpB","fTmpC"};

   int idxSC=0; // sine/cosine active index

   int idxC,idxS,idxP; // cosine (+m) sine (-m) pairs are what you loop through...

   for(m=1;m<lmax;m++) {
      l=m;

      idxC = l*l+l+m;
      idxS = l*l+l-m;

      idxP = 0;

      ssResult << sPrev[idxP] << " = " << sRuleA(m,dSqrt2) << ";\n";

      ssResult << sAssign(sSHIndex(idxC),sMul(sPrev[idxP],sC[idxSC&1])) << ";\n";
      ssResult << sAssign(sSHIndex(idxS),sMul(sPrev[idxP],sS[idxSC&1])) << ";\n";

      if (m+1 <= lmax) {
         l++;

         idxC = l*l+l+m;
         idxS = l*l+l-m;

         idxP++;

         ssResult << sPrev[idxP] << " = " << sRuleB(m,dSqrt2) << ";\n";

         ssResult << sAssign(sSHIndex(idxC),sMul(sPrev[idxP],sC[idxSC&1])) << ";\n";
         ssResult << sAssign(sSHIndex(idxS),sMul(sPrev[idxP],sS[idxSC&1])) << ";\n";
      }

      if (m+2 <= lmax) {
         l++;

         idxC = l*l+l+m;
         idxS = l*l+l-m;

         idxP++;

         ssResult << sPrev[idxP] << " = " << sRuleD(m,dSqrt2) << ";\n";

         ssResult << sAssign(sSHIndex(idxC),sMul(sPrev[idxP],sC[idxSC&1])) << ";\n";
         ssResult << sAssign(sSHIndex(idxS),sMul(sPrev[idxP],sS[idxSC&1])) << ";\n";
      }

      if (m+3 <= lmax) {
         l++;

         idxC = l*l+l+m;
         idxS = l*l+l-m;

         idxP++;

         ssResult << sPrev[idxP%3] << " = " << sRuleE(m,dSqrt2) << ";\n";

         ssResult << sAssign(sSHIndex(idxC),sMul(sPrev[idxP%3],sC[idxSC&1])) << ";\n";
         ssResult << sAssign(sSHIndex(idxS),sMul(sPrev[idxP%3],sS[idxSC&1])) << ";\n";
      }


      for(l=m+4;l<=lmax;l++) {
         idxC = l*l+l+m;
         idxS = l*l+l-m;

         idxP++;

         ssResult << sPrev[idxP%3] << " = " << sRuleC(l,m,sPrev[(idxP+3-1)%3],sPrev[(idxP+3-2)%3]) << ";\n";

         ssResult << sAssign(sSHIndex(idxC),sMul(sPrev[idxP%3],sC[idxSC&1])) << ";\n";
         ssResult << sAssign(sSHIndex(idxS),sMul(sPrev[idxP%3],sS[idxSC&1])) << ";\n";
      }

      // update cosine and sine

      ssResult << sC[(idxSC+1)&1] << " = " << sCreateCosReccur(sC[idxSC&1],sS[idxSC&1]) << ";\n";
      ssResult << sS[(idxSC+1)&1] << " = " << sCreateSinReccur(sC[idxSC&1],sS[idxSC&1]) << ";\n\n";


      idxSC++; // bump active index 
   }

   // final pair

   l = lmax;

   idxC = l*l+l+m;
   idxS = l*l+l-m;

   idxP=(idxP+1)%3; // use any tmp variable here, just bump to the next to maximize scheduling issues...

   ssResult << sPrev[idxP] << " = " << sRuleA(m,dSqrt2) << ";\n";

   ssResult << sAssign(sSHIndex(idxC),sMul(sPrev[idxP],sC[idxSC&1])) << ";\n";
   ssResult << sAssign(sSHIndex(idxS),sMul(sPrev[idxP],sS[idxSC&1])) << ";\n";

   ssResult << "}\n";
   sResult = ssResult.str();
}
