cmake_minimum_required(VERSION 3.15)
project(lab6)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
include(CompilerSettings)
include(Dependencies)

add_executable(app src/Lab6.cpp src/note.cpp src/note.h)

target_include_directories(${PROJECT_NAME} PRIVATE include)
