#!/bin/bash

echo "Enter name: "
read name

age=20

echo "Student: $name"
echo "Age: $age" 


echo "Enter a number: "
read num

if [ $num -gt 10 ]; then
    echo "Number greater than 10"
elif [ $num -lt 10 ]; then
    echo "Number less than 10"
else
    echo "Number equal to 10"
fi

for i in {1..5}
do
    echo $i
done