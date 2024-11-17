#!/bin/bash

echo "***  Program to compare 2 numbers  ***"
echo "Enter the 2 numbers"
read n1 n2
if [ $n1 -gt $n2 ]
    then
        echo "$n1 > $n2"
elif [ $n1 -lt $n2 ]
    then
        echo "$n1 < $n2"
else
        echo "$n1 = $n2"
fi