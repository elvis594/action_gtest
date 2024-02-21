include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
)

FetchContent_MakeAvailable(googletest)

# 寻找gtest包
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# 包含项目的头文件目录
include_directories(${CMAKE_SOURCE_DIR}/include)

# 添加测试可执行文件
add_executable(test_add test_add.cpp)
# 链接gtest和你的库
target_link_libraries(test_add ${GTEST_LIBRARIES} pthread add)

gtest_discover_tests(test_add)

add_executable(test_hello test_hello.cpp)
# 链接gtest和你的库
target_link_libraries(test_hello ${GTEST_LIBRARIES} pthread add)
gtest_discover_tests(test_hello)

set(SUBPRJ "test")
message(STATUS "---------------------------")
message(STATUS "Current : ${SUBPRJ}")

if (ENABLE_LCOV)
message(STATUS "Enable Lcov in ${SUBPRJ}")
message(STATUS "-- lcov Configure")
find_program(LCOV_BIN lcov)
if (NOT LCOV_BIN MATCHES "lcov$")
    message(FATAL_ERROR "lcov required, but not found!")
endif ()
if (CMAKE_BUILD_TYPE MATCHES Debug)
    include(CodeCoverage.cmake)
    APPEND_COVERAGE_COMPILER_FLAGS()
    setup_target_for_coverage_lcov(
            NAME coverage
            EXECUTABLE ctest test
            BASE_DIRECTORY "${PROJECT_SOURCE_DIR}/build"
            EXCLUDE "${PROJECT_SOURCE_DIR}/build/_deps/*" "/usr/*"
            DEPENDENCIES test_hello test_add )
endif ()
endif ()