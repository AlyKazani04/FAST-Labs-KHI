#!/bin/bash

fname=$1

if [[ -e "$fname" ]]; then
    printf "File exists!\n"
    printf "Lines: "
    wc -l < "$fname"
    printf "Characters: "
    wc -m < "$fname"
else
    printf "The file is missing or cannot be read!\n"
fi