#!/bin/bash

printf "Enter a dir path: "
read dname

if [ -d "$dname" ]; then    
    printf "Number of files/dirs in '$dname': "
    ls -1 "$dname/" | wc -l
    num=$(ls -1 "$dname/" | wc -l)
    ls -1 "$dname/"

    d=$(date)
    echo $dname > "report_$d.txt"
    echo $d >> "report_$d.txt"
    echo $num >> "report_$d.txt"
    printf "Report Generated! Contents: "
    printf "\n"
    cat "report_$d.txt"
else
    printf "Directory '$dname' does not exist.\n"
fi