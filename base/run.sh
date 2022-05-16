#! /bin/bash

SRC=$1

g++ -o test ${SRC}
echo "---------------------"
./test < input.txt
rm test
