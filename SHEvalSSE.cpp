#include <xmmintrin.h>
#include <mmintrin.h>

// output of SH Code generator below
// order 3
void SHEval3(const float *pX, const float *pY, const float *pZ, float *pSH)
{
   __m128 fX,fY,fZ;
   __m128 fC0,fC1,fS0,fS1,fTmpA,fTmpB,fTmpC;
   fX = _mm_load_ps(pX);
   fY = _mm_load_ps(pY);
   fZ = _mm_load_ps(pZ);

   __m128 fZ2 = _mm_mul_ps(fZ,fZ);

   _mm_store_ps(pSH + 0*4,_mm_set_ps1(0.2820947917738781f));
   _mm_store_ps(pSH + 2*4,_mm_mul_ps(_mm_set_ps1(0.4886025119029199f),fZ));
   _mm_store_ps(pSH + 6*4,_mm_add_ps(_mm_mul_ps(_mm_set_ps1(0.9461746957575601f),fZ2),_mm_set_ps1(-0.3153915652525201f)));
   fC0 = fX;
   fS0 = fY;

   fTmpA = _mm_set_ps1(-0.48860251190292f);
   _mm_store_ps(pSH + 3*4,_mm_mul_ps(fTmpA,fC0));
   _mm_store_ps(pSH + 1*4,_mm_mul_ps(fTmpA,fS0));
   fTmpB = _mm_mul_ps(_mm_set_ps1(-1.092548430592079f),fZ);
   _mm_store_ps(pSH + 7*4,_mm_mul_ps(fTmpB,fC0));
   _mm_store_ps(pSH + 5*4,_mm_mul_ps(fTmpB,fS0));
   fC1 = _mm_sub_ps(_mm_mul_ps(fX,fC0),_mm_mul_ps(fY,fS0));
   fS1 = _mm_add_ps(_mm_mul_ps(fX,fS0),_mm_mul_ps(fY,fC0));

   fTmpC = _mm_set_ps1(0.5462742152960395f);
   _mm_store_ps(pSH + 8*4,_mm_mul_ps(fTmpC,fC1));
   _mm_store_ps(pSH + 4*4,_mm_mul_ps(fTmpC,fS1));
}

// order 4
void SHEval4(const float *pX, const float *pY, const float *pZ, float *pSH)
{
   __m128 fX,fY,fZ;
   __m128 fC0,fC1,fS0,fS1,fTmpA,fTmpB,fTmpC;
   fX = _mm_load_ps(pX);
   fY = _mm_load_ps(pY);
   fZ = _mm_load_ps(pZ);

   __m128 fZ2 = _mm_mul_ps(fZ,fZ);

   _mm_store_ps(pSH + 0*4,_mm_set_ps1(0.2820947917738781f));
   _mm_store_ps(pSH + 2*4,_mm_mul_ps(_mm_set_ps1(0.4886025119029199f),fZ));
   _mm_store_ps(pSH + 6*4,_mm_add_ps(_mm_mul_ps(_mm_set_ps1(0.9461746957575601f),fZ2),_mm_set_ps1(-0.3153915652525201f)));
   _mm_store_ps(pSH + 12*4,_mm_mul_ps(fZ,(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(1.865881662950577f),fZ2),_mm_set_ps1(-1.119528997770346f)))));
   fC0 = fX;
   fS0 = fY;

   fTmpA = _mm_set_ps1(-0.48860251190292f);
   _mm_store_ps(pSH + 3*4,_mm_mul_ps(fTmpA,fC0));
   _mm_store_ps(pSH + 1*4,_mm_mul_ps(fTmpA,fS0));
   fTmpB = _mm_mul_ps(_mm_set_ps1(-1.092548430592079f),fZ);
   _mm_store_ps(pSH + 7*4,_mm_mul_ps(fTmpB,fC0));
   _mm_store_ps(pSH + 5*4,_mm_mul_ps(fTmpB,fS0));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(-2.285228997322329f),fZ2),_mm_set_ps1(0.4570457994644658f));
   _mm_store_ps(pSH + 13*4,_mm_mul_ps(fTmpC,fC0));
   _mm_store_ps(pSH + 11*4,_mm_mul_ps(fTmpC,fS0));
   fC1 = _mm_sub_ps(_mm_mul_ps(fX,fC0),_mm_mul_ps(fY,fS0));
   fS1 = _mm_add_ps(_mm_mul_ps(fX,fS0),_mm_mul_ps(fY,fC0));

   fTmpA = _mm_set_ps1(0.5462742152960395f);
   _mm_store_ps(pSH + 8*4,_mm_mul_ps(fTmpA,fC1));
   _mm_store_ps(pSH + 4*4,_mm_mul_ps(fTmpA,fS1));
   fTmpB = _mm_mul_ps(_mm_set_ps1(1.445305721320277f),fZ);
   _mm_store_ps(pSH + 14*4,_mm_mul_ps(fTmpB,fC1));
   _mm_store_ps(pSH + 10*4,_mm_mul_ps(fTmpB,fS1));
   fC0 = _mm_sub_ps(_mm_mul_ps(fX,fC1),_mm_mul_ps(fY,fS1));
   fS0 = _mm_add_ps(_mm_mul_ps(fX,fS1),_mm_mul_ps(fY,fC1));

   fTmpC = _mm_set_ps1(-0.5900435899266435f);
   _mm_store_ps(pSH + 15*4,_mm_mul_ps(fTmpC,fC0));
   _mm_store_ps(pSH + 9*4,_mm_mul_ps(fTmpC,fS0));
}

// order 5
void SHEval5(const float *pX, const float *pY, const float *pZ, float *pSH)
{
   __m128 fX,fY,fZ;
   __m128 fC0,fC1,fS0,fS1,fTmpA,fTmpB,fTmpC;
   fX = _mm_load_ps(pX);
   fY = _mm_load_ps(pY);
   fZ = _mm_load_ps(pZ);

   __m128 fZ2 = _mm_mul_ps(fZ,fZ);

   _mm_store_ps(pSH + 0*4,_mm_set_ps1(0.2820947917738781f));
   _mm_store_ps(pSH + 2*4,_mm_mul_ps(_mm_set_ps1(0.4886025119029199f),fZ));
   _mm_store_ps(pSH + 6*4,_mm_add_ps(_mm_mul_ps(_mm_set_ps1(0.9461746957575601f),fZ2),_mm_set_ps1(-0.3153915652525201f)));
   _mm_store_ps(pSH + 12*4,_mm_mul_ps(fZ,(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(1.865881662950577f),fZ2),_mm_set_ps1(-1.119528997770346f)))));
   _mm_store_ps(pSH + 20*4,_mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(1.984313483298443f),fZ),_mm_load_ps(pSH + 12*4)),_mm_mul_ps(_mm_set_ps1(-1.006230589874905f),_mm_load_ps(pSH + 6*4))));
   fC0 = fX;
   fS0 = fY;

   fTmpA = _mm_set_ps1(-0.48860251190292f);
   _mm_store_ps(pSH + 3*4,_mm_mul_ps(fTmpA,fC0));
   _mm_store_ps(pSH + 1*4,_mm_mul_ps(fTmpA,fS0));
   fTmpB = _mm_mul_ps(_mm_set_ps1(-1.092548430592079f),fZ);
   _mm_store_ps(pSH + 7*4,_mm_mul_ps(fTmpB,fC0));
   _mm_store_ps(pSH + 5*4,_mm_mul_ps(fTmpB,fS0));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(-2.285228997322329f),fZ2),_mm_set_ps1(0.4570457994644658f));
   _mm_store_ps(pSH + 13*4,_mm_mul_ps(fTmpC,fC0));
   _mm_store_ps(pSH + 11*4,_mm_mul_ps(fTmpC,fS0));
   fTmpA = _mm_mul_ps(fZ,(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(-4.683325804901025f),fZ2),_mm_set_ps1(2.007139630671868f))));
   _mm_store_ps(pSH + 21*4,_mm_mul_ps(fTmpA,fC0));
   _mm_store_ps(pSH + 19*4,_mm_mul_ps(fTmpA,fS0));
   fC1 = _mm_sub_ps(_mm_mul_ps(fX,fC0),_mm_mul_ps(fY,fS0));
   fS1 = _mm_add_ps(_mm_mul_ps(fX,fS0),_mm_mul_ps(fY,fC0));

   fTmpA = _mm_set_ps1(0.5462742152960395f);
   _mm_store_ps(pSH + 8*4,_mm_mul_ps(fTmpA,fC1));
   _mm_store_ps(pSH + 4*4,_mm_mul_ps(fTmpA,fS1));
   fTmpB = _mm_mul_ps(_mm_set_ps1(1.445305721320277f),fZ);
   _mm_store_ps(pSH + 14*4,_mm_mul_ps(fTmpB,fC1));
   _mm_store_ps(pSH + 10*4,_mm_mul_ps(fTmpB,fS1));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(3.31161143515146f),fZ2),_mm_set_ps1(-0.47308734787878f));
   _mm_store_ps(pSH + 22*4,_mm_mul_ps(fTmpC,fC1));
   _mm_store_ps(pSH + 18*4,_mm_mul_ps(fTmpC,fS1));
   fC0 = _mm_sub_ps(_mm_mul_ps(fX,fC1),_mm_mul_ps(fY,fS1));
   fS0 = _mm_add_ps(_mm_mul_ps(fX,fS1),_mm_mul_ps(fY,fC1));

   fTmpA = _mm_set_ps1(-0.5900435899266435f);
   _mm_store_ps(pSH + 15*4,_mm_mul_ps(fTmpA,fC0));
   _mm_store_ps(pSH + 9*4,_mm_mul_ps(fTmpA,fS0));
   fTmpB = _mm_mul_ps(_mm_set_ps1(-1.770130769779931f),fZ);
   _mm_store_ps(pSH + 23*4,_mm_mul_ps(fTmpB,fC0));
   _mm_store_ps(pSH + 17*4,_mm_mul_ps(fTmpB,fS0));
   fC1 = _mm_sub_ps(_mm_mul_ps(fX,fC0),_mm_mul_ps(fY,fS0));
   fS1 = _mm_add_ps(_mm_mul_ps(fX,fS0),_mm_mul_ps(fY,fC0));

   fTmpC = _mm_set_ps1(0.6258357354491763f);
   _mm_store_ps(pSH + 24*4,_mm_mul_ps(fTmpC,fC1));
   _mm_store_ps(pSH + 16*4,_mm_mul_ps(fTmpC,fS1));
}

// order 6
void SHEval6(const float *pX, const float *pY, const float *pZ, float *pSH)
{
   __m128 fX,fY,fZ;
   __m128 fC0,fC1,fS0,fS1,fTmpA,fTmpB,fTmpC;
   fX = _mm_load_ps(pX);
   fY = _mm_load_ps(pY);
   fZ = _mm_load_ps(pZ);

   __m128 fZ2 = _mm_mul_ps(fZ,fZ);

   _mm_store_ps(pSH + 0*4,_mm_set_ps1(0.2820947917738781f));
   _mm_store_ps(pSH + 2*4,_mm_mul_ps(_mm_set_ps1(0.4886025119029199f),fZ));
   _mm_store_ps(pSH + 6*4,_mm_add_ps(_mm_mul_ps(_mm_set_ps1(0.9461746957575601f),fZ2),_mm_set_ps1(-0.3153915652525201f)));
   _mm_store_ps(pSH + 12*4,_mm_mul_ps(fZ,(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(1.865881662950577f),fZ2),_mm_set_ps1(-1.119528997770346f)))));
   _mm_store_ps(pSH + 20*4,_mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(1.984313483298443f),fZ),_mm_load_ps(pSH + 12*4)),_mm_mul_ps(_mm_set_ps1(-1.006230589874905f),_mm_load_ps(pSH + 6*4))));
   _mm_store_ps(pSH + 30*4,_mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(1.98997487421324f),fZ),_mm_load_ps(pSH + 20*4)),_mm_mul_ps(_mm_set_ps1(-1.002853072844814f),_mm_load_ps(pSH + 12*4))));
   fC0 = fX;
   fS0 = fY;

   fTmpA = _mm_set_ps1(-0.48860251190292f);
   _mm_store_ps(pSH + 3*4,_mm_mul_ps(fTmpA,fC0));
   _mm_store_ps(pSH + 1*4,_mm_mul_ps(fTmpA,fS0));
   fTmpB = _mm_mul_ps(_mm_set_ps1(-1.092548430592079f),fZ);
   _mm_store_ps(pSH + 7*4,_mm_mul_ps(fTmpB,fC0));
   _mm_store_ps(pSH + 5*4,_mm_mul_ps(fTmpB,fS0));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(-2.285228997322329f),fZ2),_mm_set_ps1(0.4570457994644658f));
   _mm_store_ps(pSH + 13*4,_mm_mul_ps(fTmpC,fC0));
   _mm_store_ps(pSH + 11*4,_mm_mul_ps(fTmpC,fS0));
   fTmpA = _mm_mul_ps(fZ,(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(-4.683325804901025f),fZ2),_mm_set_ps1(2.007139630671868f))));
   _mm_store_ps(pSH + 21*4,_mm_mul_ps(fTmpA,fC0));
   _mm_store_ps(pSH + 19*4,_mm_mul_ps(fTmpA,fS0));
   fTmpB = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(2.03100960115899f),fZ),fTmpA),_mm_mul_ps(_mm_set_ps1(-0.991031208965115f),fTmpC));
   _mm_store_ps(pSH + 31*4,_mm_mul_ps(fTmpB,fC0));
   _mm_store_ps(pSH + 29*4,_mm_mul_ps(fTmpB,fS0));
   fC1 = _mm_sub_ps(_mm_mul_ps(fX,fC0),_mm_mul_ps(fY,fS0));
   fS1 = _mm_add_ps(_mm_mul_ps(fX,fS0),_mm_mul_ps(fY,fC0));

   fTmpA = _mm_set_ps1(0.5462742152960395f);
   _mm_store_ps(pSH + 8*4,_mm_mul_ps(fTmpA,fC1));
   _mm_store_ps(pSH + 4*4,_mm_mul_ps(fTmpA,fS1));
   fTmpB = _mm_mul_ps(_mm_set_ps1(1.445305721320277f),fZ);
   _mm_store_ps(pSH + 14*4,_mm_mul_ps(fTmpB,fC1));
   _mm_store_ps(pSH + 10*4,_mm_mul_ps(fTmpB,fS1));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(3.31161143515146f),fZ2),_mm_set_ps1(-0.47308734787878f));
   _mm_store_ps(pSH + 22*4,_mm_mul_ps(fTmpC,fC1));
   _mm_store_ps(pSH + 18*4,_mm_mul_ps(fTmpC,fS1));
   fTmpA = _mm_mul_ps(fZ,(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(7.190305177459987f),fZ2),_mm_set_ps1(-2.396768392486662f))));
   _mm_store_ps(pSH + 32*4,_mm_mul_ps(fTmpA,fC1));
   _mm_store_ps(pSH + 28*4,_mm_mul_ps(fTmpA,fS1));
   fC0 = _mm_sub_ps(_mm_mul_ps(fX,fC1),_mm_mul_ps(fY,fS1));
   fS0 = _mm_add_ps(_mm_mul_ps(fX,fS1),_mm_mul_ps(fY,fC1));

   fTmpA = _mm_set_ps1(-0.5900435899266435f);
   _mm_store_ps(pSH + 15*4,_mm_mul_ps(fTmpA,fC0));
   _mm_store_ps(pSH + 9*4,_mm_mul_ps(fTmpA,fS0));
   fTmpB = _mm_mul_ps(_mm_set_ps1(-1.770130769779931f),fZ);
   _mm_store_ps(pSH + 23*4,_mm_mul_ps(fTmpB,fC0));
   _mm_store_ps(pSH + 17*4,_mm_mul_ps(fTmpB,fS0));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(-4.403144694917254f),fZ2),_mm_set_ps1(0.4892382994352505f));
   _mm_store_ps(pSH + 33*4,_mm_mul_ps(fTmpC,fC0));
   _mm_store_ps(pSH + 27*4,_mm_mul_ps(fTmpC,fS0));
   fC1 = _mm_sub_ps(_mm_mul_ps(fX,fC0),_mm_mul_ps(fY,fS0));
   fS1 = _mm_add_ps(_mm_mul_ps(fX,fS0),_mm_mul_ps(fY,fC0));

   fTmpA = _mm_set_ps1(0.6258357354491763f);
   _mm_store_ps(pSH + 24*4,_mm_mul_ps(fTmpA,fC1));
   _mm_store_ps(pSH + 16*4,_mm_mul_ps(fTmpA,fS1));
   fTmpB = _mm_mul_ps(_mm_set_ps1(2.075662314881041f),fZ);
   _mm_store_ps(pSH + 34*4,_mm_mul_ps(fTmpB,fC1));
   _mm_store_ps(pSH + 26*4,_mm_mul_ps(fTmpB,fS1));
   fC0 = _mm_sub_ps(_mm_mul_ps(fX,fC1),_mm_mul_ps(fY,fS1));
   fS0 = _mm_add_ps(_mm_mul_ps(fX,fS1),_mm_mul_ps(fY,fC1));

   fTmpC = _mm_set_ps1(-0.6563820568401703f);
   _mm_store_ps(pSH + 35*4,_mm_mul_ps(fTmpC,fC0));
   _mm_store_ps(pSH + 25*4,_mm_mul_ps(fTmpC,fS0));
}

// order 7
void SHEval7(const float *pX, const float *pY, const float *pZ, float *pSH)
{
   __m128 fX,fY,fZ;
   __m128 fC0,fC1,fS0,fS1,fTmpA,fTmpB,fTmpC;
   fX = _mm_load_ps(pX);
   fY = _mm_load_ps(pY);
   fZ = _mm_load_ps(pZ);

   __m128 fZ2 = _mm_mul_ps(fZ,fZ);

   _mm_store_ps(pSH + 0*4,_mm_set_ps1(0.2820947917738781f));
   _mm_store_ps(pSH + 2*4,_mm_mul_ps(_mm_set_ps1(0.4886025119029199f),fZ));
   _mm_store_ps(pSH + 6*4,_mm_add_ps(_mm_mul_ps(_mm_set_ps1(0.9461746957575601f),fZ2),_mm_set_ps1(-0.3153915652525201f)));
   _mm_store_ps(pSH + 12*4,_mm_mul_ps(fZ,(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(1.865881662950577f),fZ2),_mm_set_ps1(-1.119528997770346f)))));
   _mm_store_ps(pSH + 20*4,_mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(1.984313483298443f),fZ),_mm_load_ps(pSH + 12*4)),_mm_mul_ps(_mm_set_ps1(-1.006230589874905f),_mm_load_ps(pSH + 6*4))));
   _mm_store_ps(pSH + 30*4,_mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(1.98997487421324f),fZ),_mm_load_ps(pSH + 20*4)),_mm_mul_ps(_mm_set_ps1(-1.002853072844814f),_mm_load_ps(pSH + 12*4))));
   _mm_store_ps(pSH + 42*4,_mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(1.993043457183567f),fZ),_mm_load_ps(pSH + 30*4)),_mm_mul_ps(_mm_set_ps1(-1.001542020962219f),_mm_load_ps(pSH + 20*4))));
   fC0 = fX;
   fS0 = fY;

   fTmpA = _mm_set_ps1(-0.48860251190292f);
   _mm_store_ps(pSH + 3*4,_mm_mul_ps(fTmpA,fC0));
   _mm_store_ps(pSH + 1*4,_mm_mul_ps(fTmpA,fS0));
   fTmpB = _mm_mul_ps(_mm_set_ps1(-1.092548430592079f),fZ);
   _mm_store_ps(pSH + 7*4,_mm_mul_ps(fTmpB,fC0));
   _mm_store_ps(pSH + 5*4,_mm_mul_ps(fTmpB,fS0));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(-2.285228997322329f),fZ2),_mm_set_ps1(0.4570457994644658f));
   _mm_store_ps(pSH + 13*4,_mm_mul_ps(fTmpC,fC0));
   _mm_store_ps(pSH + 11*4,_mm_mul_ps(fTmpC,fS0));
   fTmpA = _mm_mul_ps(fZ,(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(-4.683325804901025f),fZ2),_mm_set_ps1(2.007139630671868f))));
   _mm_store_ps(pSH + 21*4,_mm_mul_ps(fTmpA,fC0));
   _mm_store_ps(pSH + 19*4,_mm_mul_ps(fTmpA,fS0));
   fTmpB = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(2.03100960115899f),fZ),fTmpA),_mm_mul_ps(_mm_set_ps1(-0.991031208965115f),fTmpC));
   _mm_store_ps(pSH + 31*4,_mm_mul_ps(fTmpB,fC0));
   _mm_store_ps(pSH + 29*4,_mm_mul_ps(fTmpB,fS0));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(2.021314989237028f),fZ),fTmpB),_mm_mul_ps(_mm_set_ps1(-0.9952267030562385f),fTmpA));
   _mm_store_ps(pSH + 43*4,_mm_mul_ps(fTmpC,fC0));
   _mm_store_ps(pSH + 41*4,_mm_mul_ps(fTmpC,fS0));
   fC1 = _mm_sub_ps(_mm_mul_ps(fX,fC0),_mm_mul_ps(fY,fS0));
   fS1 = _mm_add_ps(_mm_mul_ps(fX,fS0),_mm_mul_ps(fY,fC0));

   fTmpA = _mm_set_ps1(0.5462742152960395f);
   _mm_store_ps(pSH + 8*4,_mm_mul_ps(fTmpA,fC1));
   _mm_store_ps(pSH + 4*4,_mm_mul_ps(fTmpA,fS1));
   fTmpB = _mm_mul_ps(_mm_set_ps1(1.445305721320277f),fZ);
   _mm_store_ps(pSH + 14*4,_mm_mul_ps(fTmpB,fC1));
   _mm_store_ps(pSH + 10*4,_mm_mul_ps(fTmpB,fS1));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(3.31161143515146f),fZ2),_mm_set_ps1(-0.47308734787878f));
   _mm_store_ps(pSH + 22*4,_mm_mul_ps(fTmpC,fC1));
   _mm_store_ps(pSH + 18*4,_mm_mul_ps(fTmpC,fS1));
   fTmpA = _mm_mul_ps(fZ,(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(7.190305177459987f),fZ2),_mm_set_ps1(-2.396768392486662f))));
   _mm_store_ps(pSH + 32*4,_mm_mul_ps(fTmpA,fC1));
   _mm_store_ps(pSH + 28*4,_mm_mul_ps(fTmpA,fS1));
   fTmpB = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(2.11394181566097f),fZ),fTmpA),_mm_mul_ps(_mm_set_ps1(-0.9736101204623268f),fTmpC));
   _mm_store_ps(pSH + 44*4,_mm_mul_ps(fTmpB,fC1));
   _mm_store_ps(pSH + 40*4,_mm_mul_ps(fTmpB,fS1));
   fC0 = _mm_sub_ps(_mm_mul_ps(fX,fC1),_mm_mul_ps(fY,fS1));
   fS0 = _mm_add_ps(_mm_mul_ps(fX,fS1),_mm_mul_ps(fY,fC1));

   fTmpA = _mm_set_ps1(-0.5900435899266435f);
   _mm_store_ps(pSH + 15*4,_mm_mul_ps(fTmpA,fC0));
   _mm_store_ps(pSH + 9*4,_mm_mul_ps(fTmpA,fS0));
   fTmpB = _mm_mul_ps(_mm_set_ps1(-1.770130769779931f),fZ);
   _mm_store_ps(pSH + 23*4,_mm_mul_ps(fTmpB,fC0));
   _mm_store_ps(pSH + 17*4,_mm_mul_ps(fTmpB,fS0));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(-4.403144694917254f),fZ2),_mm_set_ps1(0.4892382994352505f));
   _mm_store_ps(pSH + 33*4,_mm_mul_ps(fTmpC,fC0));
   _mm_store_ps(pSH + 27*4,_mm_mul_ps(fTmpC,fS0));
   fTmpA = _mm_mul_ps(fZ,(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(-10.13325785466416f),fZ2),_mm_set_ps1(2.763615778544771f))));
   _mm_store_ps(pSH + 45*4,_mm_mul_ps(fTmpA,fC0));
   _mm_store_ps(pSH + 39*4,_mm_mul_ps(fTmpA,fS0));
   fC1 = _mm_sub_ps(_mm_mul_ps(fX,fC0),_mm_mul_ps(fY,fS0));
   fS1 = _mm_add_ps(_mm_mul_ps(fX,fS0),_mm_mul_ps(fY,fC0));

   fTmpA = _mm_set_ps1(0.6258357354491763f);
   _mm_store_ps(pSH + 24*4,_mm_mul_ps(fTmpA,fC1));
   _mm_store_ps(pSH + 16*4,_mm_mul_ps(fTmpA,fS1));
   fTmpB = _mm_mul_ps(_mm_set_ps1(2.075662314881041f),fZ);
   _mm_store_ps(pSH + 34*4,_mm_mul_ps(fTmpB,fC1));
   _mm_store_ps(pSH + 26*4,_mm_mul_ps(fTmpB,fS1));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(5.550213908015966f),fZ2),_mm_set_ps1(-0.5045649007287241f));
   _mm_store_ps(pSH + 46*4,_mm_mul_ps(fTmpC,fC1));
   _mm_store_ps(pSH + 38*4,_mm_mul_ps(fTmpC,fS1));
   fC0 = _mm_sub_ps(_mm_mul_ps(fX,fC1),_mm_mul_ps(fY,fS1));
   fS0 = _mm_add_ps(_mm_mul_ps(fX,fS1),_mm_mul_ps(fY,fC1));

   fTmpA = _mm_set_ps1(-0.6563820568401703f);
   _mm_store_ps(pSH + 35*4,_mm_mul_ps(fTmpA,fC0));
   _mm_store_ps(pSH + 25*4,_mm_mul_ps(fTmpA,fS0));
   fTmpB = _mm_mul_ps(_mm_set_ps1(-2.366619162231753f),fZ);
   _mm_store_ps(pSH + 47*4,_mm_mul_ps(fTmpB,fC0));
   _mm_store_ps(pSH + 37*4,_mm_mul_ps(fTmpB,fS0));
   fC1 = _mm_sub_ps(_mm_mul_ps(fX,fC0),_mm_mul_ps(fY,fS0));
   fS1 = _mm_add_ps(_mm_mul_ps(fX,fS0),_mm_mul_ps(fY,fC0));

   fTmpC = _mm_set_ps1(0.6831841051919144f);
   _mm_store_ps(pSH + 48*4,_mm_mul_ps(fTmpC,fC1));
   _mm_store_ps(pSH + 36*4,_mm_mul_ps(fTmpC,fS1));
}

// order 8
void SHEval8(const float *pX, const float *pY, const float *pZ, float *pSH)
{
   __m128 fX,fY,fZ;
   __m128 fC0,fC1,fS0,fS1,fTmpA,fTmpB,fTmpC;
   fX = _mm_load_ps(pX);
   fY = _mm_load_ps(pY);
   fZ = _mm_load_ps(pZ);

   __m128 fZ2 = _mm_mul_ps(fZ,fZ);

   _mm_store_ps(pSH + 0*4,_mm_set_ps1(0.2820947917738781f));
   _mm_store_ps(pSH + 2*4,_mm_mul_ps(_mm_set_ps1(0.4886025119029199f),fZ));
   _mm_store_ps(pSH + 6*4,_mm_add_ps(_mm_mul_ps(_mm_set_ps1(0.9461746957575601f),fZ2),_mm_set_ps1(-0.3153915652525201f)));
   _mm_store_ps(pSH + 12*4,_mm_mul_ps(fZ,(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(1.865881662950577f),fZ2),_mm_set_ps1(-1.119528997770346f)))));
   _mm_store_ps(pSH + 20*4,_mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(1.984313483298443f),fZ),_mm_load_ps(pSH + 12*4)),_mm_mul_ps(_mm_set_ps1(-1.006230589874905f),_mm_load_ps(pSH + 6*4))));
   _mm_store_ps(pSH + 30*4,_mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(1.98997487421324f),fZ),_mm_load_ps(pSH + 20*4)),_mm_mul_ps(_mm_set_ps1(-1.002853072844814f),_mm_load_ps(pSH + 12*4))));
   _mm_store_ps(pSH + 42*4,_mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(1.993043457183567f),fZ),_mm_load_ps(pSH + 30*4)),_mm_mul_ps(_mm_set_ps1(-1.001542020962219f),_mm_load_ps(pSH + 20*4))));
   _mm_store_ps(pSH + 56*4,_mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(1.994891434824135f),fZ),_mm_load_ps(pSH + 42*4)),_mm_mul_ps(_mm_set_ps1(-1.000927213921958f),_mm_load_ps(pSH + 30*4))));
   fC0 = fX;
   fS0 = fY;

   fTmpA = _mm_set_ps1(-0.48860251190292f);
   _mm_store_ps(pSH + 3*4,_mm_mul_ps(fTmpA,fC0));
   _mm_store_ps(pSH + 1*4,_mm_mul_ps(fTmpA,fS0));
   fTmpB = _mm_mul_ps(_mm_set_ps1(-1.092548430592079f),fZ);
   _mm_store_ps(pSH + 7*4,_mm_mul_ps(fTmpB,fC0));
   _mm_store_ps(pSH + 5*4,_mm_mul_ps(fTmpB,fS0));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(-2.285228997322329f),fZ2),_mm_set_ps1(0.4570457994644658f));
   _mm_store_ps(pSH + 13*4,_mm_mul_ps(fTmpC,fC0));
   _mm_store_ps(pSH + 11*4,_mm_mul_ps(fTmpC,fS0));
   fTmpA = _mm_mul_ps(fZ,(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(-4.683325804901025f),fZ2),_mm_set_ps1(2.007139630671868f))));
   _mm_store_ps(pSH + 21*4,_mm_mul_ps(fTmpA,fC0));
   _mm_store_ps(pSH + 19*4,_mm_mul_ps(fTmpA,fS0));
   fTmpB = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(2.03100960115899f),fZ),fTmpA),_mm_mul_ps(_mm_set_ps1(-0.991031208965115f),fTmpC));
   _mm_store_ps(pSH + 31*4,_mm_mul_ps(fTmpB,fC0));
   _mm_store_ps(pSH + 29*4,_mm_mul_ps(fTmpB,fS0));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(2.021314989237028f),fZ),fTmpB),_mm_mul_ps(_mm_set_ps1(-0.9952267030562385f),fTmpA));
   _mm_store_ps(pSH + 43*4,_mm_mul_ps(fTmpC,fC0));
   _mm_store_ps(pSH + 41*4,_mm_mul_ps(fTmpC,fS0));
   fTmpA = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(2.015564437074638f),fZ),fTmpC),_mm_mul_ps(_mm_set_ps1(-0.9971550440218319f),fTmpB));
   _mm_store_ps(pSH + 57*4,_mm_mul_ps(fTmpA,fC0));
   _mm_store_ps(pSH + 55*4,_mm_mul_ps(fTmpA,fS0));
   fC1 = _mm_sub_ps(_mm_mul_ps(fX,fC0),_mm_mul_ps(fY,fS0));
   fS1 = _mm_add_ps(_mm_mul_ps(fX,fS0),_mm_mul_ps(fY,fC0));

   fTmpA = _mm_set_ps1(0.5462742152960395f);
   _mm_store_ps(pSH + 8*4,_mm_mul_ps(fTmpA,fC1));
   _mm_store_ps(pSH + 4*4,_mm_mul_ps(fTmpA,fS1));
   fTmpB = _mm_mul_ps(_mm_set_ps1(1.445305721320277f),fZ);
   _mm_store_ps(pSH + 14*4,_mm_mul_ps(fTmpB,fC1));
   _mm_store_ps(pSH + 10*4,_mm_mul_ps(fTmpB,fS1));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(3.31161143515146f),fZ2),_mm_set_ps1(-0.47308734787878f));
   _mm_store_ps(pSH + 22*4,_mm_mul_ps(fTmpC,fC1));
   _mm_store_ps(pSH + 18*4,_mm_mul_ps(fTmpC,fS1));
   fTmpA = _mm_mul_ps(fZ,(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(7.190305177459987f),fZ2),_mm_set_ps1(-2.396768392486662f))));
   _mm_store_ps(pSH + 32*4,_mm_mul_ps(fTmpA,fC1));
   _mm_store_ps(pSH + 28*4,_mm_mul_ps(fTmpA,fS1));
   fTmpB = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(2.11394181566097f),fZ),fTmpA),_mm_mul_ps(_mm_set_ps1(-0.9736101204623268f),fTmpC));
   _mm_store_ps(pSH + 44*4,_mm_mul_ps(fTmpB,fC1));
   _mm_store_ps(pSH + 40*4,_mm_mul_ps(fTmpB,fS1));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(2.081665999466133f),fZ),fTmpB),_mm_mul_ps(_mm_set_ps1(-0.9847319278346618f),fTmpA));
   _mm_store_ps(pSH + 58*4,_mm_mul_ps(fTmpC,fC1));
   _mm_store_ps(pSH + 54*4,_mm_mul_ps(fTmpC,fS1));
   fC0 = _mm_sub_ps(_mm_mul_ps(fX,fC1),_mm_mul_ps(fY,fS1));
   fS0 = _mm_add_ps(_mm_mul_ps(fX,fS1),_mm_mul_ps(fY,fC1));

   fTmpA = _mm_set_ps1(-0.5900435899266435f);
   _mm_store_ps(pSH + 15*4,_mm_mul_ps(fTmpA,fC0));
   _mm_store_ps(pSH + 9*4,_mm_mul_ps(fTmpA,fS0));
   fTmpB = _mm_mul_ps(_mm_set_ps1(-1.770130769779931f),fZ);
   _mm_store_ps(pSH + 23*4,_mm_mul_ps(fTmpB,fC0));
   _mm_store_ps(pSH + 17*4,_mm_mul_ps(fTmpB,fS0));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(-4.403144694917254f),fZ2),_mm_set_ps1(0.4892382994352505f));
   _mm_store_ps(pSH + 33*4,_mm_mul_ps(fTmpC,fC0));
   _mm_store_ps(pSH + 27*4,_mm_mul_ps(fTmpC,fS0));
   fTmpA = _mm_mul_ps(fZ,(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(-10.13325785466416f),fZ2),_mm_set_ps1(2.763615778544771f))));
   _mm_store_ps(pSH + 45*4,_mm_mul_ps(fTmpA,fC0));
   _mm_store_ps(pSH + 39*4,_mm_mul_ps(fTmpA,fS0));
   fTmpB = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(2.207940216581962f),fZ),fTmpA),_mm_mul_ps(_mm_set_ps1(-0.959403223600247f),fTmpC));
   _mm_store_ps(pSH + 59*4,_mm_mul_ps(fTmpB,fC0));
   _mm_store_ps(pSH + 53*4,_mm_mul_ps(fTmpB,fS0));
   fC1 = _mm_sub_ps(_mm_mul_ps(fX,fC0),_mm_mul_ps(fY,fS0));
   fS1 = _mm_add_ps(_mm_mul_ps(fX,fS0),_mm_mul_ps(fY,fC0));

   fTmpA = _mm_set_ps1(0.6258357354491763f);
   _mm_store_ps(pSH + 24*4,_mm_mul_ps(fTmpA,fC1));
   _mm_store_ps(pSH + 16*4,_mm_mul_ps(fTmpA,fS1));
   fTmpB = _mm_mul_ps(_mm_set_ps1(2.075662314881041f),fZ);
   _mm_store_ps(pSH + 34*4,_mm_mul_ps(fTmpB,fC1));
   _mm_store_ps(pSH + 26*4,_mm_mul_ps(fTmpB,fS1));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(5.550213908015966f),fZ2),_mm_set_ps1(-0.5045649007287241f));
   _mm_store_ps(pSH + 46*4,_mm_mul_ps(fTmpC,fC1));
   _mm_store_ps(pSH + 38*4,_mm_mul_ps(fTmpC,fS1));
   fTmpA = _mm_mul_ps(fZ,(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(13.49180504672677f),fZ2),_mm_set_ps1(-3.113493472321562f))));
   _mm_store_ps(pSH + 60*4,_mm_mul_ps(fTmpA,fC1));
   _mm_store_ps(pSH + 52*4,_mm_mul_ps(fTmpA,fS1));
   fC0 = _mm_sub_ps(_mm_mul_ps(fX,fC1),_mm_mul_ps(fY,fS1));
   fS0 = _mm_add_ps(_mm_mul_ps(fX,fS1),_mm_mul_ps(fY,fC1));

   fTmpA = _mm_set_ps1(-0.6563820568401703f);
   _mm_store_ps(pSH + 35*4,_mm_mul_ps(fTmpA,fC0));
   _mm_store_ps(pSH + 25*4,_mm_mul_ps(fTmpA,fS0));
   fTmpB = _mm_mul_ps(_mm_set_ps1(-2.366619162231753f),fZ);
   _mm_store_ps(pSH + 47*4,_mm_mul_ps(fTmpB,fC0));
   _mm_store_ps(pSH + 37*4,_mm_mul_ps(fTmpB,fS0));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(-6.745902523363385f),fZ2),_mm_set_ps1(0.5189155787202604f));
   _mm_store_ps(pSH + 61*4,_mm_mul_ps(fTmpC,fC0));
   _mm_store_ps(pSH + 51*4,_mm_mul_ps(fTmpC,fS0));
   fC1 = _mm_sub_ps(_mm_mul_ps(fX,fC0),_mm_mul_ps(fY,fS0));
   fS1 = _mm_add_ps(_mm_mul_ps(fX,fS0),_mm_mul_ps(fY,fC0));

   fTmpA = _mm_set_ps1(0.6831841051919144f);
   _mm_store_ps(pSH + 48*4,_mm_mul_ps(fTmpA,fC1));
   _mm_store_ps(pSH + 36*4,_mm_mul_ps(fTmpA,fS1));
   fTmpB = _mm_mul_ps(_mm_set_ps1(2.645960661801901f),fZ);
   _mm_store_ps(pSH + 62*4,_mm_mul_ps(fTmpB,fC1));
   _mm_store_ps(pSH + 50*4,_mm_mul_ps(fTmpB,fS1));
   fC0 = _mm_sub_ps(_mm_mul_ps(fX,fC1),_mm_mul_ps(fY,fS1));
   fS0 = _mm_add_ps(_mm_mul_ps(fX,fS1),_mm_mul_ps(fY,fC1));

   fTmpC = _mm_set_ps1(-0.7071627325245963f);
   _mm_store_ps(pSH + 63*4,_mm_mul_ps(fTmpC,fC0));
   _mm_store_ps(pSH + 49*4,_mm_mul_ps(fTmpC,fS0));
}

// order 9
void SHEval9(const float *pX, const float *pY, const float *pZ, float *pSH)
{
   __m128 fX,fY,fZ;
   __m128 fC0,fC1,fS0,fS1,fTmpA,fTmpB,fTmpC;
   fX = _mm_load_ps(pX);
   fY = _mm_load_ps(pY);
   fZ = _mm_load_ps(pZ);

   __m128 fZ2 = _mm_mul_ps(fZ,fZ);

   _mm_store_ps(pSH + 0*4,_mm_set_ps1(0.2820947917738781f));
   _mm_store_ps(pSH + 2*4,_mm_mul_ps(_mm_set_ps1(0.4886025119029199f),fZ));
   _mm_store_ps(pSH + 6*4,_mm_add_ps(_mm_mul_ps(_mm_set_ps1(0.9461746957575601f),fZ2),_mm_set_ps1(-0.3153915652525201f)));
   _mm_store_ps(pSH + 12*4,_mm_mul_ps(fZ,(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(1.865881662950577f),fZ2),_mm_set_ps1(-1.119528997770346f)))));
   _mm_store_ps(pSH + 20*4,_mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(1.984313483298443f),fZ),_mm_load_ps(pSH + 12*4)),_mm_mul_ps(_mm_set_ps1(-1.006230589874905f),_mm_load_ps(pSH + 6*4))));
   _mm_store_ps(pSH + 30*4,_mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(1.98997487421324f),fZ),_mm_load_ps(pSH + 20*4)),_mm_mul_ps(_mm_set_ps1(-1.002853072844814f),_mm_load_ps(pSH + 12*4))));
   _mm_store_ps(pSH + 42*4,_mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(1.993043457183567f),fZ),_mm_load_ps(pSH + 30*4)),_mm_mul_ps(_mm_set_ps1(-1.001542020962219f),_mm_load_ps(pSH + 20*4))));
   _mm_store_ps(pSH + 56*4,_mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(1.994891434824135f),fZ),_mm_load_ps(pSH + 42*4)),_mm_mul_ps(_mm_set_ps1(-1.000927213921958f),_mm_load_ps(pSH + 30*4))));
   _mm_store_ps(pSH + 72*4,_mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(1.996089927833914f),fZ),_mm_load_ps(pSH + 56*4)),_mm_mul_ps(_mm_set_ps1(-1.000600781069515f),_mm_load_ps(pSH + 42*4))));
   fC0 = fX;
   fS0 = fY;

   fTmpA = _mm_set_ps1(-0.48860251190292f);
   _mm_store_ps(pSH + 3*4,_mm_mul_ps(fTmpA,fC0));
   _mm_store_ps(pSH + 1*4,_mm_mul_ps(fTmpA,fS0));
   fTmpB = _mm_mul_ps(_mm_set_ps1(-1.092548430592079f),fZ);
   _mm_store_ps(pSH + 7*4,_mm_mul_ps(fTmpB,fC0));
   _mm_store_ps(pSH + 5*4,_mm_mul_ps(fTmpB,fS0));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(-2.285228997322329f),fZ2),_mm_set_ps1(0.4570457994644658f));
   _mm_store_ps(pSH + 13*4,_mm_mul_ps(fTmpC,fC0));
   _mm_store_ps(pSH + 11*4,_mm_mul_ps(fTmpC,fS0));
   fTmpA = _mm_mul_ps(fZ,(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(-4.683325804901025f),fZ2),_mm_set_ps1(2.007139630671868f))));
   _mm_store_ps(pSH + 21*4,_mm_mul_ps(fTmpA,fC0));
   _mm_store_ps(pSH + 19*4,_mm_mul_ps(fTmpA,fS0));
   fTmpB = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(2.03100960115899f),fZ),fTmpA),_mm_mul_ps(_mm_set_ps1(-0.991031208965115f),fTmpC));
   _mm_store_ps(pSH + 31*4,_mm_mul_ps(fTmpB,fC0));
   _mm_store_ps(pSH + 29*4,_mm_mul_ps(fTmpB,fS0));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(2.021314989237028f),fZ),fTmpB),_mm_mul_ps(_mm_set_ps1(-0.9952267030562385f),fTmpA));
   _mm_store_ps(pSH + 43*4,_mm_mul_ps(fTmpC,fC0));
   _mm_store_ps(pSH + 41*4,_mm_mul_ps(fTmpC,fS0));
   fTmpA = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(2.015564437074638f),fZ),fTmpC),_mm_mul_ps(_mm_set_ps1(-0.9971550440218319f),fTmpB));
   _mm_store_ps(pSH + 57*4,_mm_mul_ps(fTmpA,fC0));
   _mm_store_ps(pSH + 55*4,_mm_mul_ps(fTmpA,fS0));
   fTmpB = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(2.011869540407391f),fZ),fTmpA),_mm_mul_ps(_mm_set_ps1(-0.9981668178901745f),fTmpC));
   _mm_store_ps(pSH + 73*4,_mm_mul_ps(fTmpB,fC0));
   _mm_store_ps(pSH + 71*4,_mm_mul_ps(fTmpB,fS0));
   fC1 = _mm_sub_ps(_mm_mul_ps(fX,fC0),_mm_mul_ps(fY,fS0));
   fS1 = _mm_add_ps(_mm_mul_ps(fX,fS0),_mm_mul_ps(fY,fC0));

   fTmpA = _mm_set_ps1(0.5462742152960395f);
   _mm_store_ps(pSH + 8*4,_mm_mul_ps(fTmpA,fC1));
   _mm_store_ps(pSH + 4*4,_mm_mul_ps(fTmpA,fS1));
   fTmpB = _mm_mul_ps(_mm_set_ps1(1.445305721320277f),fZ);
   _mm_store_ps(pSH + 14*4,_mm_mul_ps(fTmpB,fC1));
   _mm_store_ps(pSH + 10*4,_mm_mul_ps(fTmpB,fS1));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(3.31161143515146f),fZ2),_mm_set_ps1(-0.47308734787878f));
   _mm_store_ps(pSH + 22*4,_mm_mul_ps(fTmpC,fC1));
   _mm_store_ps(pSH + 18*4,_mm_mul_ps(fTmpC,fS1));
   fTmpA = _mm_mul_ps(fZ,(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(7.190305177459987f),fZ2),_mm_set_ps1(-2.396768392486662f))));
   _mm_store_ps(pSH + 32*4,_mm_mul_ps(fTmpA,fC1));
   _mm_store_ps(pSH + 28*4,_mm_mul_ps(fTmpA,fS1));
   fTmpB = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(2.11394181566097f),fZ),fTmpA),_mm_mul_ps(_mm_set_ps1(-0.9736101204623268f),fTmpC));
   _mm_store_ps(pSH + 44*4,_mm_mul_ps(fTmpB,fC1));
   _mm_store_ps(pSH + 40*4,_mm_mul_ps(fTmpB,fS1));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(2.081665999466133f),fZ),fTmpB),_mm_mul_ps(_mm_set_ps1(-0.9847319278346618f),fTmpA));
   _mm_store_ps(pSH + 58*4,_mm_mul_ps(fTmpC,fC1));
   _mm_store_ps(pSH + 54*4,_mm_mul_ps(fTmpC,fS1));
   fTmpA = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(2.06155281280883f),fZ),fTmpC),_mm_mul_ps(_mm_set_ps1(-0.9903379376602873f),fTmpB));
   _mm_store_ps(pSH + 74*4,_mm_mul_ps(fTmpA,fC1));
   _mm_store_ps(pSH + 70*4,_mm_mul_ps(fTmpA,fS1));
   fC0 = _mm_sub_ps(_mm_mul_ps(fX,fC1),_mm_mul_ps(fY,fS1));
   fS0 = _mm_add_ps(_mm_mul_ps(fX,fS1),_mm_mul_ps(fY,fC1));

   fTmpA = _mm_set_ps1(-0.5900435899266435f);
   _mm_store_ps(pSH + 15*4,_mm_mul_ps(fTmpA,fC0));
   _mm_store_ps(pSH + 9*4,_mm_mul_ps(fTmpA,fS0));
   fTmpB = _mm_mul_ps(_mm_set_ps1(-1.770130769779931f),fZ);
   _mm_store_ps(pSH + 23*4,_mm_mul_ps(fTmpB,fC0));
   _mm_store_ps(pSH + 17*4,_mm_mul_ps(fTmpB,fS0));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(-4.403144694917254f),fZ2),_mm_set_ps1(0.4892382994352505f));
   _mm_store_ps(pSH + 33*4,_mm_mul_ps(fTmpC,fC0));
   _mm_store_ps(pSH + 27*4,_mm_mul_ps(fTmpC,fS0));
   fTmpA = _mm_mul_ps(fZ,(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(-10.13325785466416f),fZ2),_mm_set_ps1(2.763615778544771f))));
   _mm_store_ps(pSH + 45*4,_mm_mul_ps(fTmpA,fC0));
   _mm_store_ps(pSH + 39*4,_mm_mul_ps(fTmpA,fS0));
   fTmpB = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(2.207940216581962f),fZ),fTmpA),_mm_mul_ps(_mm_set_ps1(-0.959403223600247f),fTmpC));
   _mm_store_ps(pSH + 59*4,_mm_mul_ps(fTmpB,fC0));
   _mm_store_ps(pSH + 53*4,_mm_mul_ps(fTmpB,fS0));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(2.15322168769582f),fZ),fTmpB),_mm_mul_ps(_mm_set_ps1(-0.9752173865600178f),fTmpA));
   _mm_store_ps(pSH + 75*4,_mm_mul_ps(fTmpC,fC0));
   _mm_store_ps(pSH + 69*4,_mm_mul_ps(fTmpC,fS0));
   fC1 = _mm_sub_ps(_mm_mul_ps(fX,fC0),_mm_mul_ps(fY,fS0));
   fS1 = _mm_add_ps(_mm_mul_ps(fX,fS0),_mm_mul_ps(fY,fC0));

   fTmpA = _mm_set_ps1(0.6258357354491763f);
   _mm_store_ps(pSH + 24*4,_mm_mul_ps(fTmpA,fC1));
   _mm_store_ps(pSH + 16*4,_mm_mul_ps(fTmpA,fS1));
   fTmpB = _mm_mul_ps(_mm_set_ps1(2.075662314881041f),fZ);
   _mm_store_ps(pSH + 34*4,_mm_mul_ps(fTmpB,fC1));
   _mm_store_ps(pSH + 26*4,_mm_mul_ps(fTmpB,fS1));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(5.550213908015966f),fZ2),_mm_set_ps1(-0.5045649007287241f));
   _mm_store_ps(pSH + 46*4,_mm_mul_ps(fTmpC,fC1));
   _mm_store_ps(pSH + 38*4,_mm_mul_ps(fTmpC,fS1));
   fTmpA = _mm_mul_ps(fZ,(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(13.49180504672677f),fZ2),_mm_set_ps1(-3.113493472321562f))));
   _mm_store_ps(pSH + 60*4,_mm_mul_ps(fTmpA,fC1));
   _mm_store_ps(pSH + 52*4,_mm_mul_ps(fTmpA,fS1));
   fTmpB = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(2.304886114323221f),fZ),fTmpA),_mm_mul_ps(_mm_set_ps1(-0.9481763873554654f),fTmpC));
   _mm_store_ps(pSH + 76*4,_mm_mul_ps(fTmpB,fC1));
   _mm_store_ps(pSH + 68*4,_mm_mul_ps(fTmpB,fS1));
   fC0 = _mm_sub_ps(_mm_mul_ps(fX,fC1),_mm_mul_ps(fY,fS1));
   fS0 = _mm_add_ps(_mm_mul_ps(fX,fS1),_mm_mul_ps(fY,fC1));

   fTmpA = _mm_set_ps1(-0.6563820568401703f);
   _mm_store_ps(pSH + 35*4,_mm_mul_ps(fTmpA,fC0));
   _mm_store_ps(pSH + 25*4,_mm_mul_ps(fTmpA,fS0));
   fTmpB = _mm_mul_ps(_mm_set_ps1(-2.366619162231753f),fZ);
   _mm_store_ps(pSH + 47*4,_mm_mul_ps(fTmpB,fC0));
   _mm_store_ps(pSH + 37*4,_mm_mul_ps(fTmpB,fS0));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(-6.745902523363385f),fZ2),_mm_set_ps1(0.5189155787202604f));
   _mm_store_ps(pSH + 61*4,_mm_mul_ps(fTmpC,fC0));
   _mm_store_ps(pSH + 51*4,_mm_mul_ps(fTmpC,fS0));
   fTmpA = _mm_mul_ps(fZ,(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(-17.24955311049054f),fZ2),_mm_set_ps1(3.449910622098108f))));
   _mm_store_ps(pSH + 77*4,_mm_mul_ps(fTmpA,fC0));
   _mm_store_ps(pSH + 67*4,_mm_mul_ps(fTmpA,fS0));
   fC1 = _mm_sub_ps(_mm_mul_ps(fX,fC0),_mm_mul_ps(fY,fS0));
   fS1 = _mm_add_ps(_mm_mul_ps(fX,fS0),_mm_mul_ps(fY,fC0));

   fTmpA = _mm_set_ps1(0.6831841051919144f);
   _mm_store_ps(pSH + 48*4,_mm_mul_ps(fTmpA,fC1));
   _mm_store_ps(pSH + 36*4,_mm_mul_ps(fTmpA,fS1));
   fTmpB = _mm_mul_ps(_mm_set_ps1(2.645960661801901f),fZ);
   _mm_store_ps(pSH + 62*4,_mm_mul_ps(fTmpB,fC1));
   _mm_store_ps(pSH + 50*4,_mm_mul_ps(fTmpB,fS1));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(7.984991490893139f),fZ2),_mm_set_ps1(-0.5323327660595426f));
   _mm_store_ps(pSH + 78*4,_mm_mul_ps(fTmpC,fC1));
   _mm_store_ps(pSH + 66*4,_mm_mul_ps(fTmpC,fS1));
   fC0 = _mm_sub_ps(_mm_mul_ps(fX,fC1),_mm_mul_ps(fY,fS1));
   fS0 = _mm_add_ps(_mm_mul_ps(fX,fS1),_mm_mul_ps(fY,fC1));

   fTmpA = _mm_set_ps1(-0.7071627325245963f);
   _mm_store_ps(pSH + 63*4,_mm_mul_ps(fTmpA,fC0));
   _mm_store_ps(pSH + 49*4,_mm_mul_ps(fTmpA,fS0));
   fTmpB = _mm_mul_ps(_mm_set_ps1(-2.91570664069932f),fZ);
   _mm_store_ps(pSH + 79*4,_mm_mul_ps(fTmpB,fC0));
   _mm_store_ps(pSH + 65*4,_mm_mul_ps(fTmpB,fS0));
   fC1 = _mm_sub_ps(_mm_mul_ps(fX,fC0),_mm_mul_ps(fY,fS0));
   fS1 = _mm_add_ps(_mm_mul_ps(fX,fS0),_mm_mul_ps(fY,fC0));

   fTmpC = _mm_set_ps1(0.72892666017483f);
   _mm_store_ps(pSH + 80*4,_mm_mul_ps(fTmpC,fC1));
   _mm_store_ps(pSH + 64*4,_mm_mul_ps(fTmpC,fS1));
}

// order 10
void SHEval10(const float *pX, const float *pY, const float *pZ, float *pSH)
{
   __m128 fX,fY,fZ;
   __m128 fC0,fC1,fS0,fS1,fTmpA,fTmpB,fTmpC;
   fX = _mm_load_ps(pX);
   fY = _mm_load_ps(pY);
   fZ = _mm_load_ps(pZ);

   __m128 fZ2 = _mm_mul_ps(fZ,fZ);

   _mm_store_ps(pSH + 0*4,_mm_set_ps1(0.2820947917738781f));
   _mm_store_ps(pSH + 2*4,_mm_mul_ps(_mm_set_ps1(0.4886025119029199f),fZ));
   _mm_store_ps(pSH + 6*4,_mm_add_ps(_mm_mul_ps(_mm_set_ps1(0.9461746957575601f),fZ2),_mm_set_ps1(-0.3153915652525201f)));
   _mm_store_ps(pSH + 12*4,_mm_mul_ps(fZ,(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(1.865881662950577f),fZ2),_mm_set_ps1(-1.119528997770346f)))));
   _mm_store_ps(pSH + 20*4,_mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(1.984313483298443f),fZ),_mm_load_ps(pSH + 12*4)),_mm_mul_ps(_mm_set_ps1(-1.006230589874905f),_mm_load_ps(pSH + 6*4))));
   _mm_store_ps(pSH + 30*4,_mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(1.98997487421324f),fZ),_mm_load_ps(pSH + 20*4)),_mm_mul_ps(_mm_set_ps1(-1.002853072844814f),_mm_load_ps(pSH + 12*4))));
   _mm_store_ps(pSH + 42*4,_mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(1.993043457183567f),fZ),_mm_load_ps(pSH + 30*4)),_mm_mul_ps(_mm_set_ps1(-1.001542020962219f),_mm_load_ps(pSH + 20*4))));
   _mm_store_ps(pSH + 56*4,_mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(1.994891434824135f),fZ),_mm_load_ps(pSH + 42*4)),_mm_mul_ps(_mm_set_ps1(-1.000927213921958f),_mm_load_ps(pSH + 30*4))));
   _mm_store_ps(pSH + 72*4,_mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(1.996089927833914f),fZ),_mm_load_ps(pSH + 56*4)),_mm_mul_ps(_mm_set_ps1(-1.000600781069515f),_mm_load_ps(pSH + 42*4))));
   _mm_store_ps(pSH + 90*4,_mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(1.996911195067937f),fZ),_mm_load_ps(pSH + 72*4)),_mm_mul_ps(_mm_set_ps1(-1.000411437993134f),_mm_load_ps(pSH + 56*4))));
   fC0 = fX;
   fS0 = fY;

   fTmpA = _mm_set_ps1(-0.48860251190292f);
   _mm_store_ps(pSH + 3*4,_mm_mul_ps(fTmpA,fC0));
   _mm_store_ps(pSH + 1*4,_mm_mul_ps(fTmpA,fS0));
   fTmpB = _mm_mul_ps(_mm_set_ps1(-1.092548430592079f),fZ);
   _mm_store_ps(pSH + 7*4,_mm_mul_ps(fTmpB,fC0));
   _mm_store_ps(pSH + 5*4,_mm_mul_ps(fTmpB,fS0));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(-2.285228997322329f),fZ2),_mm_set_ps1(0.4570457994644658f));
   _mm_store_ps(pSH + 13*4,_mm_mul_ps(fTmpC,fC0));
   _mm_store_ps(pSH + 11*4,_mm_mul_ps(fTmpC,fS0));
   fTmpA = _mm_mul_ps(fZ,(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(-4.683325804901025f),fZ2),_mm_set_ps1(2.007139630671868f))));
   _mm_store_ps(pSH + 21*4,_mm_mul_ps(fTmpA,fC0));
   _mm_store_ps(pSH + 19*4,_mm_mul_ps(fTmpA,fS0));
   fTmpB = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(2.03100960115899f),fZ),fTmpA),_mm_mul_ps(_mm_set_ps1(-0.991031208965115f),fTmpC));
   _mm_store_ps(pSH + 31*4,_mm_mul_ps(fTmpB,fC0));
   _mm_store_ps(pSH + 29*4,_mm_mul_ps(fTmpB,fS0));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(2.021314989237028f),fZ),fTmpB),_mm_mul_ps(_mm_set_ps1(-0.9952267030562385f),fTmpA));
   _mm_store_ps(pSH + 43*4,_mm_mul_ps(fTmpC,fC0));
   _mm_store_ps(pSH + 41*4,_mm_mul_ps(fTmpC,fS0));
   fTmpA = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(2.015564437074638f),fZ),fTmpC),_mm_mul_ps(_mm_set_ps1(-0.9971550440218319f),fTmpB));
   _mm_store_ps(pSH + 57*4,_mm_mul_ps(fTmpA,fC0));
   _mm_store_ps(pSH + 55*4,_mm_mul_ps(fTmpA,fS0));
   fTmpB = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(2.011869540407391f),fZ),fTmpA),_mm_mul_ps(_mm_set_ps1(-0.9981668178901745f),fTmpC));
   _mm_store_ps(pSH + 73*4,_mm_mul_ps(fTmpB,fC0));
   _mm_store_ps(pSH + 71*4,_mm_mul_ps(fTmpB,fS0));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(2.009353129741012f),fZ),fTmpB),_mm_mul_ps(_mm_set_ps1(-0.9987492177719088f),fTmpA));
   _mm_store_ps(pSH + 91*4,_mm_mul_ps(fTmpC,fC0));
   _mm_store_ps(pSH + 89*4,_mm_mul_ps(fTmpC,fS0));
   fC1 = _mm_sub_ps(_mm_mul_ps(fX,fC0),_mm_mul_ps(fY,fS0));
   fS1 = _mm_add_ps(_mm_mul_ps(fX,fS0),_mm_mul_ps(fY,fC0));

   fTmpA = _mm_set_ps1(0.5462742152960395f);
   _mm_store_ps(pSH + 8*4,_mm_mul_ps(fTmpA,fC1));
   _mm_store_ps(pSH + 4*4,_mm_mul_ps(fTmpA,fS1));
   fTmpB = _mm_mul_ps(_mm_set_ps1(1.445305721320277f),fZ);
   _mm_store_ps(pSH + 14*4,_mm_mul_ps(fTmpB,fC1));
   _mm_store_ps(pSH + 10*4,_mm_mul_ps(fTmpB,fS1));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(3.31161143515146f),fZ2),_mm_set_ps1(-0.47308734787878f));
   _mm_store_ps(pSH + 22*4,_mm_mul_ps(fTmpC,fC1));
   _mm_store_ps(pSH + 18*4,_mm_mul_ps(fTmpC,fS1));
   fTmpA = _mm_mul_ps(fZ,(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(7.190305177459987f),fZ2),_mm_set_ps1(-2.396768392486662f))));
   _mm_store_ps(pSH + 32*4,_mm_mul_ps(fTmpA,fC1));
   _mm_store_ps(pSH + 28*4,_mm_mul_ps(fTmpA,fS1));
   fTmpB = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(2.11394181566097f),fZ),fTmpA),_mm_mul_ps(_mm_set_ps1(-0.9736101204623268f),fTmpC));
   _mm_store_ps(pSH + 44*4,_mm_mul_ps(fTmpB,fC1));
   _mm_store_ps(pSH + 40*4,_mm_mul_ps(fTmpB,fS1));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(2.081665999466133f),fZ),fTmpB),_mm_mul_ps(_mm_set_ps1(-0.9847319278346618f),fTmpA));
   _mm_store_ps(pSH + 58*4,_mm_mul_ps(fTmpC,fC1));
   _mm_store_ps(pSH + 54*4,_mm_mul_ps(fTmpC,fS1));
   fTmpA = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(2.06155281280883f),fZ),fTmpC),_mm_mul_ps(_mm_set_ps1(-0.9903379376602873f),fTmpB));
   _mm_store_ps(pSH + 74*4,_mm_mul_ps(fTmpA,fC1));
   _mm_store_ps(pSH + 70*4,_mm_mul_ps(fTmpA,fS1));
   fTmpB = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(2.048122358357819f),fZ),fTmpA),_mm_mul_ps(_mm_set_ps1(-0.9934852726704042f),fTmpC));
   _mm_store_ps(pSH + 92*4,_mm_mul_ps(fTmpB,fC1));
   _mm_store_ps(pSH + 88*4,_mm_mul_ps(fTmpB,fS1));
   fC0 = _mm_sub_ps(_mm_mul_ps(fX,fC1),_mm_mul_ps(fY,fS1));
   fS0 = _mm_add_ps(_mm_mul_ps(fX,fS1),_mm_mul_ps(fY,fC1));

   fTmpA = _mm_set_ps1(-0.5900435899266435f);
   _mm_store_ps(pSH + 15*4,_mm_mul_ps(fTmpA,fC0));
   _mm_store_ps(pSH + 9*4,_mm_mul_ps(fTmpA,fS0));
   fTmpB = _mm_mul_ps(_mm_set_ps1(-1.770130769779931f),fZ);
   _mm_store_ps(pSH + 23*4,_mm_mul_ps(fTmpB,fC0));
   _mm_store_ps(pSH + 17*4,_mm_mul_ps(fTmpB,fS0));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(-4.403144694917254f),fZ2),_mm_set_ps1(0.4892382994352505f));
   _mm_store_ps(pSH + 33*4,_mm_mul_ps(fTmpC,fC0));
   _mm_store_ps(pSH + 27*4,_mm_mul_ps(fTmpC,fS0));
   fTmpA = _mm_mul_ps(fZ,(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(-10.13325785466416f),fZ2),_mm_set_ps1(2.763615778544771f))));
   _mm_store_ps(pSH + 45*4,_mm_mul_ps(fTmpA,fC0));
   _mm_store_ps(pSH + 39*4,_mm_mul_ps(fTmpA,fS0));
   fTmpB = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(2.207940216581962f),fZ),fTmpA),_mm_mul_ps(_mm_set_ps1(-0.959403223600247f),fTmpC));
   _mm_store_ps(pSH + 59*4,_mm_mul_ps(fTmpB,fC0));
   _mm_store_ps(pSH + 53*4,_mm_mul_ps(fTmpB,fS0));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(2.15322168769582f),fZ),fTmpB),_mm_mul_ps(_mm_set_ps1(-0.9752173865600178f),fTmpA));
   _mm_store_ps(pSH + 75*4,_mm_mul_ps(fTmpC,fC0));
   _mm_store_ps(pSH + 69*4,_mm_mul_ps(fTmpC,fS0));
   fTmpA = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(2.118044171189805f),fZ),fTmpC),_mm_mul_ps(_mm_set_ps1(-0.9836628449792094f),fTmpB));
   _mm_store_ps(pSH + 93*4,_mm_mul_ps(fTmpA,fC0));
   _mm_store_ps(pSH + 87*4,_mm_mul_ps(fTmpA,fS0));
   fC1 = _mm_sub_ps(_mm_mul_ps(fX,fC0),_mm_mul_ps(fY,fS0));
   fS1 = _mm_add_ps(_mm_mul_ps(fX,fS0),_mm_mul_ps(fY,fC0));

   fTmpA = _mm_set_ps1(0.6258357354491763f);
   _mm_store_ps(pSH + 24*4,_mm_mul_ps(fTmpA,fC1));
   _mm_store_ps(pSH + 16*4,_mm_mul_ps(fTmpA,fS1));
   fTmpB = _mm_mul_ps(_mm_set_ps1(2.075662314881041f),fZ);
   _mm_store_ps(pSH + 34*4,_mm_mul_ps(fTmpB,fC1));
   _mm_store_ps(pSH + 26*4,_mm_mul_ps(fTmpB,fS1));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(5.550213908015966f),fZ2),_mm_set_ps1(-0.5045649007287241f));
   _mm_store_ps(pSH + 46*4,_mm_mul_ps(fTmpC,fC1));
   _mm_store_ps(pSH + 38*4,_mm_mul_ps(fTmpC,fS1));
   fTmpA = _mm_mul_ps(fZ,(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(13.49180504672677f),fZ2),_mm_set_ps1(-3.113493472321562f))));
   _mm_store_ps(pSH + 60*4,_mm_mul_ps(fTmpA,fC1));
   _mm_store_ps(pSH + 52*4,_mm_mul_ps(fTmpA,fS1));
   fTmpB = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(2.304886114323221f),fZ),fTmpA),_mm_mul_ps(_mm_set_ps1(-0.9481763873554654f),fTmpC));
   _mm_store_ps(pSH + 76*4,_mm_mul_ps(fTmpB,fC1));
   _mm_store_ps(pSH + 68*4,_mm_mul_ps(fTmpB,fS1));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(2.229177150706235f),fZ),fTmpB),_mm_mul_ps(_mm_set_ps1(-0.9671528397231821f),fTmpA));
   _mm_store_ps(pSH + 94*4,_mm_mul_ps(fTmpC,fC1));
   _mm_store_ps(pSH + 86*4,_mm_mul_ps(fTmpC,fS1));
   fC0 = _mm_sub_ps(_mm_mul_ps(fX,fC1),_mm_mul_ps(fY,fS1));
   fS0 = _mm_add_ps(_mm_mul_ps(fX,fS1),_mm_mul_ps(fY,fC1));

   fTmpA = _mm_set_ps1(-0.6563820568401703f);
   _mm_store_ps(pSH + 35*4,_mm_mul_ps(fTmpA,fC0));
   _mm_store_ps(pSH + 25*4,_mm_mul_ps(fTmpA,fS0));
   fTmpB = _mm_mul_ps(_mm_set_ps1(-2.366619162231753f),fZ);
   _mm_store_ps(pSH + 47*4,_mm_mul_ps(fTmpB,fC0));
   _mm_store_ps(pSH + 37*4,_mm_mul_ps(fTmpB,fS0));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(-6.745902523363385f),fZ2),_mm_set_ps1(0.5189155787202604f));
   _mm_store_ps(pSH + 61*4,_mm_mul_ps(fTmpC,fC0));
   _mm_store_ps(pSH + 51*4,_mm_mul_ps(fTmpC,fS0));
   fTmpA = _mm_mul_ps(fZ,(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(-17.24955311049054f),fZ2),_mm_set_ps1(3.449910622098108f))));
   _mm_store_ps(pSH + 77*4,_mm_mul_ps(fTmpA,fC0));
   _mm_store_ps(pSH + 67*4,_mm_mul_ps(fTmpA,fS0));
   fTmpB = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_set_ps1(2.401636346922062f),fZ),fTmpA),_mm_mul_ps(_mm_set_ps1(-0.9392246042043708f),fTmpC));
   _mm_store_ps(pSH + 95*4,_mm_mul_ps(fTmpB,fC0));
   _mm_store_ps(pSH + 85*4,_mm_mul_ps(fTmpB,fS0));
   fC1 = _mm_sub_ps(_mm_mul_ps(fX,fC0),_mm_mul_ps(fY,fS0));
   fS1 = _mm_add_ps(_mm_mul_ps(fX,fS0),_mm_mul_ps(fY,fC0));

   fTmpA = _mm_set_ps1(0.6831841051919144f);
   _mm_store_ps(pSH + 48*4,_mm_mul_ps(fTmpA,fC1));
   _mm_store_ps(pSH + 36*4,_mm_mul_ps(fTmpA,fS1));
   fTmpB = _mm_mul_ps(_mm_set_ps1(2.645960661801901f),fZ);
   _mm_store_ps(pSH + 62*4,_mm_mul_ps(fTmpB,fC1));
   _mm_store_ps(pSH + 50*4,_mm_mul_ps(fTmpB,fS1));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(7.984991490893139f),fZ2),_mm_set_ps1(-0.5323327660595426f));
   _mm_store_ps(pSH + 78*4,_mm_mul_ps(fTmpC,fC1));
   _mm_store_ps(pSH + 66*4,_mm_mul_ps(fTmpC,fS1));
   fTmpA = _mm_mul_ps(fZ,(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(21.39289019090864f),fZ2),_mm_set_ps1(-3.775215916042701f))));
   _mm_store_ps(pSH + 96*4,_mm_mul_ps(fTmpA,fC1));
   _mm_store_ps(pSH + 84*4,_mm_mul_ps(fTmpA,fS1));
   fC0 = _mm_sub_ps(_mm_mul_ps(fX,fC1),_mm_mul_ps(fY,fS1));
   fS0 = _mm_add_ps(_mm_mul_ps(fX,fS1),_mm_mul_ps(fY,fC1));

   fTmpA = _mm_set_ps1(-0.7071627325245963f);
   _mm_store_ps(pSH + 63*4,_mm_mul_ps(fTmpA,fC0));
   _mm_store_ps(pSH + 49*4,_mm_mul_ps(fTmpA,fS0));
   fTmpB = _mm_mul_ps(_mm_set_ps1(-2.91570664069932f),fZ);
   _mm_store_ps(pSH + 79*4,_mm_mul_ps(fTmpB,fC0));
   _mm_store_ps(pSH + 65*4,_mm_mul_ps(fTmpB,fS0));
   fTmpC = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(-9.263393182848905f),fZ2),_mm_set_ps1(0.5449054813440533f));
   _mm_store_ps(pSH + 97*4,_mm_mul_ps(fTmpC,fC0));
   _mm_store_ps(pSH + 83*4,_mm_mul_ps(fTmpC,fS0));
   fC1 = _mm_sub_ps(_mm_mul_ps(fX,fC0),_mm_mul_ps(fY,fS0));
   fS1 = _mm_add_ps(_mm_mul_ps(fX,fS0),_mm_mul_ps(fY,fC0));

   fTmpA = _mm_set_ps1(0.72892666017483f);
   _mm_store_ps(pSH + 80*4,_mm_mul_ps(fTmpA,fC1));
   _mm_store_ps(pSH + 64*4,_mm_mul_ps(fTmpA,fS1));
   fTmpB = _mm_mul_ps(_mm_set_ps1(3.177317648954698f),fZ);
   _mm_store_ps(pSH + 98*4,_mm_mul_ps(fTmpB,fC1));
   _mm_store_ps(pSH + 82*4,_mm_mul_ps(fTmpB,fS1));
   fC0 = _mm_sub_ps(_mm_mul_ps(fX,fC1),_mm_mul_ps(fY,fS1));
   fS0 = _mm_add_ps(_mm_mul_ps(fX,fS1),_mm_mul_ps(fY,fC1));

   fTmpC = _mm_set_ps1(-0.7489009518531884f);
   _mm_store_ps(pSH + 99*4,_mm_mul_ps(fTmpC,fC0));
   _mm_store_ps(pSH + 81*4,_mm_mul_ps(fTmpC,fS0));
}

