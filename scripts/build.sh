#!/bin/bash
cd "$(dirname "$0")/.." || exit 1
rm -rf ./build
mkdir ./build
g++ ./main.cpp -o ./build/calculator-repl