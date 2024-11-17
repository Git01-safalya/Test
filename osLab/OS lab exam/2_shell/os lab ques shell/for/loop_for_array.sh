#!/bin/bash

echo ARRAY USING FOR LOOP

arr1=("a" "b" "c" "d" "e")

for n in ${arr1[@]};
    do
        echo $n
    done