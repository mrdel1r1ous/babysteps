cmake_minimum_required(VERSION 3.31)
project(Lab1)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
include(CompilerSettings)
include(Dependencies)

add_executable(${PROJECT_NAME} src/${PROJECT_NAME}.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE include)