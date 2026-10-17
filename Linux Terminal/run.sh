#!/bin/bash
NAME="${1:-code}"
g++ -O2 -std=c++17 "${NAME}.cpp" -o "${NAME}" && ./"${NAME}"

# Run once the first time:
# chmod +x run.sh

# For other turns: 
# ./run.sh name
# Ex: ./run.sh code for running code.cpp