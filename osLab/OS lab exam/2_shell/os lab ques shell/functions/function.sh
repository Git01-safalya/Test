#!/bin/bash

echo FUNCTION to print table of input number

table(){
    echo Table of $num 
    
    for i in {1..10}
        do
            echo $num x $i = $[$num * $i]
        done
}

echo Enter number
read num

table