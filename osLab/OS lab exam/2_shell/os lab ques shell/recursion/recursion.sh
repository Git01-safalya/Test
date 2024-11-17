#!/bin/bash

#factorial using recursion

fact()
{
    num1=$1
    if [ $num1 -le 1 ]
        then
            echo "Factorial of $num = $res"
    else
        ((res=$num1*$res))
        ((num1=$num1-1))
        fact $num1
    fi
}

echo -e " *** Factorial of number *** \n"
echo "Enter num : "
read num
res=1
fact $num