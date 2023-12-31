﻿# CMakeList.txt : CMake project for Gator AVL Project, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Gator AVL Project")

set(CMAKE_CXX_STANDARD 14)

#recommended by aman to match test environment
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

#pull in desired version of catch through cmake automatically, make it available
Include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.4.0 # or a later release
)
FetchContent_MakeAvailable(Catch2)

include_directories(test-unit)

add_executable(Main
        src/main.cpp
        src/gator_node.h
        src/gator_tree.cpp
        src/gator_node.cpp
)

add_executable(Tests
        test-unit/test.cpp
        src/gator_node.h
        src/gator_tree.cpp
        src/gator_node.cpp
)

add_custom_target(run_test_with_input
        COMMAND Tests < ${CMAKE_CURRENT_SOURCE_DIR}/test-io/input-files/2.txt
        DEPENDS Tests
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

target_link_libraries(Tests PRIVATE Catch2::Catch2WithMain) #link catch to test.cpp file
#if your testing executable is named Project1, change Tests in the line above to Project1