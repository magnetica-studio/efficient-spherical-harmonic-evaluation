#include "ConstexprSHEval.hpp"

// Simple test program which inspects constexpr is properly computed at compile-time.
// inspect with assembly
// clang++ -c -S minimaltest.cpp --std=gnu++17 -O3 -fconstexpr-depth=-1 -fconstexpr-steps=-1
// inspect with llvm-ir
// clang++ -c -S -emit-llvm minimaltest.cpp --std=gnu++17 -O3 -fconstexpr-depth=-1 -fconstexpr-steps=-1
int test(int index,double x,double y,double z){
    auto test = novonotes::constexprsheval::SHEvalExec<9>(x,y,z);
    return test.at(index);
}