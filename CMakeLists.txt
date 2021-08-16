project(xnntest CXX)
cmake_minimum_required(VERSION 3.5)
set(CXX_STANDARD 14)
set(CMAKE_MODULE_PATH
  "${PROJECT_SOURCE_DIR}/cmake"
  ${CMAKE_MODULE_PATH}
)
# find_package(xnnpack REQUIRED)
include(xnnpack)
add_executable(main main.cpp)
target_link_libraries(main XNNPACK)

set(FLAGS
    -s MODULARIZE=1
    --bind
    -s EXPORT_NAME='GeneratorWasmModule'
    -s EXPORTED_RUNTIME_METHODS=['cwrap']
)
string(REPLACE ";" " " FLAG_STR "${FLAGS}")

set_target_properties(main
PROPERTIES
LINK_FLAGS ${FLAG_STR}
)
