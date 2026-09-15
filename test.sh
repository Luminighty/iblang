#!/bin/bash

ib -cc_flags="-fsanitize=address,undefined -g -O0 -Wall -Wextra" -e --entry=./src/test.ib --out=./bin/tests


# ib --entry=./src/main.ib --out=./bin/ib
# ./bin/ib --cc-flags="-fsanitize=address,undefined -g -O0 -Wall -Wextra" --entry=./src/test.ib --out=./bin/tests2
# ./bin/tests2

# ib -e --entry=./src/test.ib --out=./bin/tests
