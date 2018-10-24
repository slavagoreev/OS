#!/bin/bash
num=$(tail -1 ex2.txt)
num=$((num + 1))
echo "$num" >> "ex2.txt"