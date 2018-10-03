#!/bin/bash
echo "Writing info about $1 to ex1.txt"
# Printing to terminal
size $1
# Writing to file
size $1 > ex1.txt