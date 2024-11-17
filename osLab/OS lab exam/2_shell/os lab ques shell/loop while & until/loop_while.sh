#!/bin/bash

echo "PRINT 1ST 10 INTEGERS & THEIR SQUARES USING WHILE LOOP"

n=1
while [ $n -le 10 ]
do  
    ((sq=$n*$n))
    echo "$n ^2 = $sq"
    ((n=$n+1))
done