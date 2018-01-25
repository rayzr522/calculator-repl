#!/bin/bash
cd "$(dirname "$0")/.." || exit 1
rm -rf ./build
mkdir ./build
clang++ -std=c++11 -stdlib=libc++ main.cpp -o build/calculator-repl
