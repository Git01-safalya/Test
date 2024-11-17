#!/bin/bash

echo PRINT INTEGERS FROM 1-N USING UNTIL LOOP

a=1
echo Enter number
read N
echo 
until [ $a -eq $N ]
    do 
        echo $a 
        ((a=$a+1))
    done