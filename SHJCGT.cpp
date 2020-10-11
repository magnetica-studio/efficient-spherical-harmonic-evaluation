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
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

// SHJCGT.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>

#include <iostream>

#include "SHEvalCodeGen.hpp"

#include <filesystem>
namespace fs = std::filesystem;

// extern void BuildSHEvalCode(std::string &sResult, const unsigned int lmax);

bool flipsign = false;
int g_sign = 1;
int main(int argc, char *argv[]) {
  FILE *f = fopen(argv[1], "wb");
#ifndef GENSSE
  fs::path eval("generated/SHEval_normal.cpp");
  fs::path evalflipped("generated/SHEval_Flipped.cpp");
#else
  fs::path eval("generated/SHEval_normal_SSE.cpp");
  fs::path evalflipped("generated/SHEval_Flipped_SSE.cpp");
#endif
  std::ostringstream output;
  std::ofstream outfile1(fs::absolute(eval).string());
  std::ofstream outfile2(fs::absolute(evalflipped).string());
#ifdef GENSSE
  outfile1 << "#include <xmmintrin.h>\n#include <mmintrin.h>\n";
  outfile2 << "#include <xmmintrin.h>\n#include <mmintrin.h>\n";
  ;
#endif
  for (unsigned int order = 1; order <= 9; order++) {
    std::string sTmp;
    BuildSHEvalCode(sTmp, order);

    outfile1 << "//order " << order << "\n";
    outfile1 << sTmp;
  }
  flipsign = true;
  g_sign = -1;
  for (unsigned int order = 1; order <= 9; order++) {
    std::string sTmp2;

    BuildSHEvalCode(sTmp2, order);
    outfile2 << "//order " << order << "\n";
    outfile2 << sTmp2;
  }

  return 0;
}
