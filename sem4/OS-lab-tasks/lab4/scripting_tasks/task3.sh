#!/bin/bash

dname=$1

if [[ -d "$dname" ]]; then
    printf "Dir exists!\n"
    ls -1d $dname/*/
    printf "Number of sub-dirs: "
    ls -1d $dname/*/ | wc -l
else
    printf "Directory doesn't exist!\n"
fi