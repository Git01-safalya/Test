#!/bin/bash

echo PRINT EVEN NUMBERS FROM 10-20 USING INFINITE LOOP

n=10
for(( ; ; ));
    do 
        if [ $n -gt 20 ]
            then 
                break
        fi
        echo $n 
        ((n=$n+2))
    done