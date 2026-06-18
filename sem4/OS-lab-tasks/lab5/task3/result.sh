#!/bin/bash

printf "Enter student's name: "
read name

printf "Enter student's marks in three subjects ( like m1 m2 m3 ): "
read mark1 mark2 mark3

sum=$((mark1 + mark2 + mark3))

average=$((sum / 3))

if [[ $average -ge 80 ]]; then
  result='A'
elif [[ $average -ge 70 ]]; then
  result='B'
elif [[ $average -ge 60 ]]; then
  result='C'
elif [[ $average -ge 50 ]]; then
  result='D'
else
  result='F'
fi

printf "Student %s's Grade: %c \nAverage: %d" $name $result $average

