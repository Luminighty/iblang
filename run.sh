#!/bin/bash


# ib --entry=./src/main.ib --out=./bin/ib && echo "Running" && ./bin/ib --debug-ast


ib -cc_flags="-fsanitize=address,undefined -g -O0 -Wall -Wextra" --entry=./src/main.ib --out=./bin/ib && \
echo "===== Running =====" && \
./bin/ib

# ib --entry=./src/main.ib --out=./bin/ib && \
# echo "===== Running =====" && \
# ./bin/ib -dt
#
