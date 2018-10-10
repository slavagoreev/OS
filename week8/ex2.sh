#!/bin/bash
gcc -o ex2 -w ./ex2.c
./ex2 &
# Prints si so columns in Mac os
vm_stat 1 | awk '{print $21,$22}'