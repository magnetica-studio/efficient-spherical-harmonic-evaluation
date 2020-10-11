cmake_minimum_required(VERSION 3.13)
# set(CMAKE_C_COMPILER "/usr/local/opt/llvm/bin/clang")

# set(CMAKE_CXX_COMPILER "/usr/local/opt/llvm/bin/clang++")
project(SHEVAL )

add_executable(shevalcodegen SHEvalCodeGen.cpp SHJCGT.cpp)

# set if you want to use SIMD for x86 arch code
target_compile_definitions(shevalcodegen PRIVATE GENSSE)

target_compile_features(shevalcodegen PUBLIC cxx_std_17)