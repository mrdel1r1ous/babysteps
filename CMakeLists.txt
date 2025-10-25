cmake_minimum_required(VERSION 3.15)
project(lab5)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
include(CompilerSettings)
include(Dependencies)

add_executable(app src/app.cpp src/time_lib.cpp src/time_lib.h)