# CMakeList.txt : CMake project for Gator AVL Project, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Gator AVL Project")

# Add source to this project's executable.
add_executable (CMakeTarget "src/main.cpp" "src/tree.h")

# TODO: Add tests and install targets if needed.
