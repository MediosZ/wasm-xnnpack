project(xnntest CXX)
cmake_minimum_required(VERSION 3.5)
set(CXX_STANDARD 14)
set(CMAKE_MODULE_PATH
  "${PROJECT_SOURCE_DIR}/cmake"
  ${CMAKE_MODULE_PATH}
)
find_package(xnnpack REQUIRED)

add_executable(main main.cpp)
target_link_libraries(main XNNPACK)
