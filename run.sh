#!/bin/bash


# ib --entry=./src/main.ib --out=./bin/ib && echo "Running" && ./bin/ib --debug-ast


ib --entry=./src/main.ib --out=./bin/ib && \
echo "===== Running =====" && \
./bin/ib -dt

