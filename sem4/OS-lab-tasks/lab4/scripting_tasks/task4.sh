#!/bin/bash

printf "Enter a number: "
read num

if [[ $num -gt 0 ]]; then
    printf "The number $num is positive.\n"
elif [[ $num -lt 0 ]]; then
        printf "The number $num is negative.\n"
elif [[ $num -eq 0 ]]; then
    printf "The number $num is zero.\n"
else
    printf "Invalid value entered!"
fi