add_executable(shevalconstexprtest ConstexprSHEvalTest.cpp)
target_compile_options(shevalconstexprtest PRIVATE -fconstexpr-depth=-1 -fconstexpr-steps=-1)
target_include_directories(shevalconstexprtest PRIVATE ${CMAKE_SOURCE_DIR})

target_compile_features(shevalconstexprtest PUBLIC cxx_std_17)

if(${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")

add_custom_target(minimaltest_llvmir
COMMAND ${CXX} -c -S minimaltest.cpp --std=gnu++17 -O3 -fconstexpr-depth=-1 -fconstexpr-steps=-1
)

add_custom_target(minimaltest_asm
COMMAND ${CXX} -c -S -emit-llvm minimaltest.cpp --std=gnu++17 -O3 -fconstexpr-depth=-1 -fconstexpr-steps=-1
)

endif()