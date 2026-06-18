#!/bin/bash

dname=$1

if [[ -d "$dname" ]]; then
    printf "Dir exists!\n"
    ls .*
else
    printf "File doesn't exist!\n"
fi