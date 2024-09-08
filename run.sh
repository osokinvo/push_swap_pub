#!/bin/bash

if [ -nz "$1" ]
then
    case "$1" in
    merge) PS="push_swap_merge" ;;
    insert) PS="push_swap_insert" ;;
    qsort) PS="push_swap_qsort" ;;
    smart) PS="push_swap_smart" ;;
    *) echo "$1 is not an version of push_swap" ;;
    esac
    if [ -e "$PS" ]
    then
        echo "The $PS file does not exist, perhaps the 'make' command was not run."
    fi
fi

if [ -n "$2" ]
then

export ARG=`ruby -e "puts (1..$2).to_a.shuffle.join(' ')"`
./$PS $ARG | ./checker $ARG -g
