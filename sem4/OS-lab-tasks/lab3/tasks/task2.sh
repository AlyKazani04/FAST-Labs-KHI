#!/bin/bash

fname=$1

if [[ -e "$fname" ]]; then
    printf "File exists!\n"
    printf "Lines: "
    wc -l < "$fname"
    printf "Characters: "
    wc -m < "$fname"
else
    printf "File doesn't exist!\n"
fi