#!/bin/bash

ib -cc_flags="-fsanitize=address,undefined -g -O0 -Wall -Wextra" -e --entry=./src/test.ib --out=./bin/tests


# ib -e --entry=./src/test.ib --out=./bin/tests
