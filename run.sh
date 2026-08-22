#!/bin/bash

ib --entry=./src/main.ib --out=./bin/ib
./bin/ib --debug-ast
