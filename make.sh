#! /bin/bash

excecutable=$1
mkdir -p bin

rm -rf *.o
gcc -c *.c linkedlist.c
gcc -o ./bin/$excecutable *.o && ./bin/$excecutable
rm -rf *.o