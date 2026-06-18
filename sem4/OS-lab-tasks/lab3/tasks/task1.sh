#!/bin/bash

num1=$1
num2=$2
num3=$3
max=$num1

printmax() {
    printf "The largest number among $num1, $num2, and $num3 is $max.\n"
}

if [[ $num1 -gt $num2 ]]; then
    if [[ $num1 -gt $num3 ]]; then
        max=$num1
    else
        max=$num3
    fi
else
    if [[ $num2 -gt $num3 ]]; then
        max=$num2
    else
        max=$num3
    fi
fi

printmax