#!/bin/bash

#~ clear

echo 'Compiling...'
echo
make -f Makefile dbg=0 verbose=0

echo

echo 'Executing...'
echo
#~ ../../bin/linux/release/matrixMul 0
#~ ../../bin/linux/release/matrixMul 1
../../bin/linux/release/matrixMul 2
echo
