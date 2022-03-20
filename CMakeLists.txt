cmake_minimum_required(VERSION 3.18)
project(HiStd)
include(CTest)

add_library(histd INTERFACE)
target_include_directories(histd INTERFACE include)

if (BUILD_TESTING AND (PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME))
    link_libraries(histd)

    add_executable(std20_test std20_test.cpp)
    add_executable(std17_test std17_test.cpp)
    add_executable(std14_test std14_test.cpp)
    add_executable(std11_test std11_test.cpp)
    # target_compile_features(std20_test PRIVATE cxx_std_17)
    # target_compile_features(std17_test PRIVATE cxx_std_14)
    # target_compile_features(std14_test PRIVATE cxx_std_11)
endif ()
