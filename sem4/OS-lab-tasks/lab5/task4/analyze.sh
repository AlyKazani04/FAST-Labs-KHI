#!/bin/bash

printf "Script Name: %s\nTotal Args: %d\n" "$0" "$#"

i=0
for arg in "$@"; do
  i=$((i + 1))
  printf "Arg %d: %s\n" "$i" "$arg"
done


if [ -n "$1" ]; then
  printf "\n"
  printf "First Arg: %s\n" "$1"
fi

if [ -n "$2" ]; then
  printf "Second Arg: %s\n" "$2"
fi

if [ "$#" -eq 0 ]; then
  printf "No Arguments passed.\n"
fi

printf "\n"
printf "Current User: %s\n" "$(whoami)"
printf "Home Directory:\n%s\n\n" "$(ls ~/)"

printf "Current Directory: %s\n" "$(pwd)"

printf '%s\n' "${PATH//:/$'\n'}"
