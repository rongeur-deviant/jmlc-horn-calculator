cmake_minimum_required(VERSION 3.10)
project(JMLC_Horn)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    jmlc_horn
    src/main.cpp
    src/JMLCHorn.cpp
    src/Geometry.cpp
    src/Exporter.cpp
)