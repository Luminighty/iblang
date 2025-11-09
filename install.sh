#!/bin/bash

cargo build --release
cp ./target/release/iblang /bin/ib
