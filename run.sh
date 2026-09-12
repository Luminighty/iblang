#!/bin/bash


# ib --entry=./src/main.ib --out=./bin/ib && echo "Running" && ./bin/ib --debug-ast

ib -cc_flags="-fsanitize=address,undefined,alignment,object-size -fno-omit-frame-pointer -g -O0 -Wall -Wextra" --entry=./src/main.ib --out=./bin/ib && \
./bin/ib

gcc ./build/main.c -o ./bin/main > /dev/null 2>&1

printf "===== \x1b[1m\x1b[33mRUNNING\x1b[0m ./bin/main help ====="
echo
echo
./bin/main help

# ib -cc_flags="-g -Wall -O0 -Wextra" --entry=./src/main.ib --out=./bin/ib && \
# echo "===== Running =====" && \
# ./bin/ib

# ib -cc_flags="-g -O0 -Wall -Wextra" --entry=./src/main.ib --out=./bin/ib && \
# echo "===== Running =====" && \
# ./bin/ib

# ib --entry=./src/main.ib --out=./bin/ib && \
# echo "===== Running =====" && \
# ./bin/ib
