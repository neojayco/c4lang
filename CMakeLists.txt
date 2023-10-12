cmake_minimum_required(VERSION 3.25)

project(c4lang C CXX)

file(GLOB_RECURSE SOURCES "./src/**.cpp")

set(CMAKE_CXX_STANDARD 17)

add_executable(c4 ${SOURCES})
