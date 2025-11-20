cmake_minimum_required(VERSION 3.31)
project(SIAOD_7_1 CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(SIAOD_7_1 7_1.cpp)

if (WIN32)
    target_link_options(SIAOD_7_1 PRIVATE -static-libgcc -static-libstdc++)
endif()