#include "ConstexprSHEval.hpp"
#include "generated/SHEval_normal.cpp"
#include <iomanip>
#include <iostream>
namespace cshe = novonotes::constexprsheval;

// テスト用に order 0 の SHEval 関数を定義する。（generated 内のソースにはこの関数が生成されないので）
void SHEval1(const float fX, const float fY, const float fZ, float *pSH)
{
    pSH[0] = 0.2820947917738781f;
}

void SHEval(int order, float x, float y, float z, float *dest)
{
    switch(order) {
        case 1: return SHEval1(x, y, z, dest);
        case 2: return SHEval2(x, y, z, dest);
        case 3: return SHEval3(x, y, z, dest);
        case 4: return SHEval4(x, y, z, dest);
        case 5: return SHEval5(x, y, z, dest);
        case 6: return SHEval6(x, y, z, dest);
        case 7: return SHEval7(x, y, z, dest);
        case 8: return SHEval8(x, y, z, dest);
        default: return;
    }
}

template<int AMBI_ORDER>
void test()
{
    constexpr auto rt2 = novonotes::constexprsheval::constsqrt(2);

    std::array<float, (AMBI_ORDER + 1) * (AMBI_ORDER + 1)> expected;
    SHEval(AMBI_ORDER + 1, 0.12, rt2, rt2, expected.data());

    constexpr std::array<double, (AMBI_ORDER + 1) * (AMBI_ORDER + 1)> actual
        = cshe::SHEvalExec<AMBI_ORDER>(0.12,rt2,rt2);

    for(int i = 0; i < (AMBI_ORDER + 1) * (AMBI_ORDER + 1); ++i) {
        std::cout
            << std::setw(11) << std::setprecision(8) << expected[i] << ", "
            << std::setw(11) << std::setprecision(8) << actual[i] << " => "
            << ((std::fabs(expected[i] - actual[i]) <= 0.001) ? "same" : "differ")
            << std::endl;
    }
}

// test<0> から test<AMBI_ORDER> までのテストを順に呼び出す。
template<int AMBI_ORDER>
void invoke_tests()
{
    if constexpr(AMBI_ORDER > 0) {
        invoke_tests<AMBI_ORDER-1>();
    }

    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Test(" << AMBI_ORDER << ")" << std::endl;
    test<AMBI_ORDER>();
}

int main(){
    invoke_tests<7>();

    return 0;
}