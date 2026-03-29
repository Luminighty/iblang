#!/bin/bash

# cargo build
# cp ./target/debug/iblang /bin/ib

cargo build --release
cp ./target/release/iblang /bin/ib
