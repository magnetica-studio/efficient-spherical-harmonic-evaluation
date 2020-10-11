# efficient-spherical-harmonic-evaluation

http://jcgt.org/published/0002/02/06/


## Modification

- removed unused windows dependency
- added cmake configuration
- generated code originally located in root is moved to `generated_original/`

## build & generate code 

```sh
mkdir build && cd build
cmake ..
cmake --build . -j
cd ../
build/shevalcodegen
```

This will create `SHEval_normal.cpp` and  `SHEval_Flipped.cpp`.

`SHEval_Flipped.cpp` is alternative version that is used in IEM allradecoder that some signs for constants are flipped.

## SIMD code generation

uncomment the line below in CMakeLists.txt

```
# set if you want to use SIMD for x86 arch code
# target_compile_definitions(shevalcodegen PRIVATE GENSSE)
```

# constexpr version

```cpp
#include "ConstexprSHEval.hpp"

namespace cshe =  novonotes::constexprsheval

cshe::SHEvalExec<7>(0.2, 0.3, 0.3)
```