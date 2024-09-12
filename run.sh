#!/bin/bash
if [ "$#" -ne 2 ]
then
    echo "Not enough arguments. Please enter the program version and the number of numbers to sort. Example:"
    echo "bash run.sh qsort 500"
    exit 1
fi

case "$1" in
    "merge" ) PS="push_swap_merge" ;;
    "insert" ) PS="push_swap_insert" ;;
    "qsort" ) PS="push_swap_qsort" ;;
    "smart" ) PS="push_swap_smart" ;;
    *) echo "$1 is not an version of push_swap"
    echo "List of version:"
    echo "merge"
    echo "insert"
    echo "qsort"
    echo "smart"
    echo "Example:"
    echo "bash run.sh qsort 500"
    exit 1;;
esac
if [ ! -x $PS ]
then
    echo "The $PS file does not exist, perhaps the 'make' command was not run."
    exit 1
fi
REGEX="^[0-9]+$"

if [[ -n "$2" && "$2" =~ $REGEX && "$2" -gt 0 ]]
then
    export ARG=`ruby -e "puts (1..$2).to_a.shuffle.join(' ')"`
    ./$PS $ARG | ./checker $ARG -g
else
    echo "Please enter a positive integer greater than 0 as the second argument. Example:"
    echo "bash run.sh qsort 500"
    exit 1
fi
