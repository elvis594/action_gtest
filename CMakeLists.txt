cmake_minimum_required(VERSION 3.11)
project(ppx VERSION 1.2)

set(CMAKE_CXX_STANDARD 14)

# option(ENABLE_AVX "Enable AVX intrinsic" OFF)
option(ENABLE_UNIT_TESTS "Enable unit tests" ON)
# option(ENABLE_BENCHMARK "Enable benchmark" OFF)
option(ENABLE_LCOV "Enable code coverage tests" ON)

INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_LIST_DIR}/include
)

add_subdirectory(demo)

if(ENABLE_UNIT_TESTS)
  enable_testing()
  add_subdirectory(test)
endif()
