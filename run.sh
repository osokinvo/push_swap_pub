#!/bin/bash

for i in {1..5000}
do
    export ARG=`ruby -e "puts (1..5000).to_a.shuffle.join(' ')"`
    ./push_swap_qsort $ARG | ./checker $ARG
done