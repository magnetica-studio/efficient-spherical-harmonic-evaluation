add_executable(shevalcodegen SHEvalCodeGen.cpp SHJCGT.cpp)

# set if you want to use SIMD for x86 arch code
target_compile_definitions(shevalcodegen PRIVATE GENSSE)
target_compile_features(shevalcodegen PUBLIC cxx_std_17)