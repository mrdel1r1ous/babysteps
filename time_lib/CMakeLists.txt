list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
include(CompilerSettings)
include(Dependencies)

add_library(time_lib src/time_lib.cpp)

target_sources(time_lib PUBLIC src/time_lib.h)

target_include_directories(time_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})