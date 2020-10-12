#include "ConstexprSHEval.hpp"
#include "generated/SHEval_normal.cpp"
#include <iomanip>
#include <iostream>
namespace cshe = novonotes::constexprsheval;
int main(){
    auto rt2 = novonotes::constexprsheval::constsqrt(2);
    auto res =cshe::SHEvalExec<8>(0.12,rt2,rt2);
    int count =0;
    std::cout << std::setprecision(6);
    for(int order =0; order<8;order++){
        for(int m =0;m< 2*order+1;m++ ){
        std::cout << res.at(count++) << " ";
    }
    std::cout << "\n";
    }
    std::cout << std::endl;
    std::array<float,64> shdata;
    SHEval9(0.12,rt2,rt2,shdata.data());
    count =0;
    for(int order =0; order<8;order++){
        for(int m =0;m< 2*order+1;m++ ){
        std::cout << shdata.at(count++) << " ";
    }
    std::cout << "\n";
    }
        std::cout << std::endl;

    return 0;
}