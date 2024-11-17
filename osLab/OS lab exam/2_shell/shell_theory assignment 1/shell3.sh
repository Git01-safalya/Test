#!/bin/bash

echo -e "\nProgram to calculate factorial"
echo "Enter number"
read num

fact=1
for (( i=$num ; i>0 ; i-- ));
do 
    ((fact=$fact*$i))
done

echo -e "Factorial of $num is $fact\n"