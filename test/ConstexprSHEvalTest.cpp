#include "ConstexprSHEval.hpp"
#include "codegen/generated/SHEval_normal.cpp"
namespace Flipped
{
#include "codegen/generated/SHEval_Flipped.cpp"
}

#include <iomanip>
#include <iostream>
namespace cshe = novonotes::constexprsheval;


// Compare SHEval functions between an original and Constexpr Version.

void SHEval1(const float fX, const float fY, const float fZ, float *pSH)
{
    pSH[0] = 0.2820947917738781f;
}

void SHEval(int order, float x, float y, float z, float *dest, bool signflip = false)
{
    if(!signflip)
    {
        switch(order)
        {
            case 1:
                return SHEval1(x, y, z, dest);
            case 2:
                return SHEval2(x, y, z, dest);
            case 3:
                return SHEval3(x, y, z, dest);
            case 4:
                return SHEval4(x, y, z, dest);
            case 5:
                return SHEval5(x, y, z, dest);
            case 6:
                return SHEval6(x, y, z, dest);
            case 7:
                return SHEval7(x, y, z, dest);
            case 8:
                return SHEval8(x, y, z, dest);
            default:
                return;
        }
    }
    else
    {
        switch(order)
        {
            case 1:
                return SHEval1(x, y, z, dest);
            case 2:
                return Flipped::SHEval2(x, y, z, dest);
            case 3:
                return Flipped::SHEval3(x, y, z, dest);
            case 4:
                return Flipped::SHEval4(x, y, z, dest);
            case 5:
                return Flipped::SHEval5(x, y, z, dest);
            case 6:
                return Flipped::SHEval6(x, y, z, dest);
            case 7:
                return Flipped::SHEval7(x, y, z, dest);
            case 8:
                return Flipped::SHEval8(x, y, z, dest);
            default:
                return;
        }
    }
}

template <int AMBI_ORDER, bool SIGNFLIP>
bool test()
{
    bool res = true;
    constexpr auto rt3 = novonotes::constexprsheval::constsqrt(3);

    std::array<float, (AMBI_ORDER + 1) * (AMBI_ORDER + 1)> expected;
    SHEval(AMBI_ORDER + 1, 1.0 / rt3, 1.0 / rt3, 1.0 / rt3, expected.data(), SIGNFLIP);

    constexpr std::array<double, (AMBI_ORDER + 1) * (AMBI_ORDER + 1)> actual = cshe::SHEvalExec<AMBI_ORDER, SIGNFLIP>(1.0 / rt3, 1.0 / rt3, 1.0 / rt3);

    for(int i = 0; i < (AMBI_ORDER + 1) * (AMBI_ORDER + 1); ++i)
    {
        auto exec_result = ((std::fabs(expected[i] - actual[i]) <= 0.001));

        std::cout
            << std::setw(11) << std::setprecision(8) << expected[i] << ", "
            << std::setw(11) << std::setprecision(8) << actual[i] << " => "
            << (exec_result ? "same" : "differ")
            << std::endl;
        res &= exec_result;
    }
    return res;
}

// test<0> から test<AMBI_ORDER> までのテストを順に呼び出す。
template <int AMBI_ORDER>
bool invoke_tests()
{
    bool res = true;
    if constexpr(AMBI_ORDER > 0)
    {
        res &= invoke_tests<AMBI_ORDER - 1>();
    }

    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Test(" << AMBI_ORDER << ")" << std::endl;
    res &= test<AMBI_ORDER, false>();
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Test(FLIPPED SIGN: " << AMBI_ORDER << ")" << std::endl;
    res &= test<AMBI_ORDER, true>();
    return res;
}

int main()
{
    bool res = invoke_tests<7>();
    std::cout << "Test " << ((res) ? "SUCCEEDED" : "FAILED") << "." << std::endl;

    return (res) ? 0 : -1;
}