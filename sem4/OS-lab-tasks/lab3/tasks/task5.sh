#!/bin/bash

dname=$1
backup_dir="project_backup_$(date +%Y%m%d%H%M%S)"

if [ -d "$dname" ]; then
    cp -r "$dname" "../$backup_dir/"
    printf "Directory '$dname' has been backed to '../$backup_dir'.\n"
    printf "Number of files backed: "
    find "../$backup_dir/$dname" -mindepth 1 -maxdepth 1 | wc -l
else
    printf "Directory '$dname' does not exist.\n"
fi
