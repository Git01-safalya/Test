#!/bin/bash

echo Enter number
read num
echo Table of $num
for n in 1 2 3 4 5 6 7 8 9 10;
    do
        echo num x $n = $[$n * $num]
    done