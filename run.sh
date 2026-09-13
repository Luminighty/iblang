#!/bin/bash


# ib --entry=./src/main.ib --out=./bin/ib && echo "Running" && ./bin/ib --debug-ast


ib -cc_flags="-fsanitize=address,undefined,alignment,object-size -fno-omit-frame-pointer -g -O0 -Wall -Wextra" --entry=./src/main.ib --out=./bin/ib

printf "===== \x1b[1m\x1b[33mRUNNING COMPILER\x1b[0m ./bin/main help =====\n"

./bin/ib --entry="./src/main_other.ib"

gcc ./bin/main_generated.c -fsanitize=address,undefined,alignment,object-size -fno-omit-frame-pointer -g -O0 -Wall -Wextra -g -o ./bin/main

# printf "===== \x1b[1m\x1b[33mRUNNING\x1b[0m ./bin/main help ====="
# echo
# echo
# ./bin/main -v --out="./bin/main2"

# ib -cc_flags="-g -Wall -O0 -Wextra" --entry=./src/main.ib --out=./bin/ib && \
# echo "===== Running =====" && \
# ./bin/ib

# ib -cc_flags="-g -O0 -Wall -Wextra" --entry=./src/main.ib --out=./bin/ib && \
# echo "===== Running =====" && \
# ./bin/ib

# ib --entry=./src/main.ib --out=./bin/ib && \
# echo "===== Running =====" && \
# ./bin/ib
