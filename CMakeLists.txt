cmake_minimum_required(VERSION 3.10)
project(jmlc_horn)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    jmlc_horn
    src/main.cpp
    src/ExpansionLaw.cpp
    src/JMLCHorn.cpp
    src/DXFExporter.cpp
)