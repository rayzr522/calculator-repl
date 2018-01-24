#!/bin/bash
cd "$(dirname "$0")/.." || exit 1
if [ ! -d ./build ]; then mkdir ./build; fi
gcc ./main.c -o ./build/calculator
