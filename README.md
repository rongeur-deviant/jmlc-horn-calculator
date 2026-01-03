# jmlc-horn-calculator

## author

louis mingot

## description

C++ tool to generate JMLC horn profiles
based on the work of Jean Fourcade
detailed in his paper "calcul du pavillon Le Cléac'h"

## features

- Jean-michel Le Cléac'h (JMLC) horn profile calculation
- DXF export (profile) --> which you can then import in a CAD software
- CMake build system

## build and run!

```bash
mkdir build
cd build
cmake ..
cmake --build .
cd Debug/
./jmlc_horn.exe