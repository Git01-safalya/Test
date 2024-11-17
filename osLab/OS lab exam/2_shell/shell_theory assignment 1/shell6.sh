#!/bin/bash

echo -e "\nProgram to reverse digits of number"
echo "Enter number"
read num
rev=""

len=${#num}
for (( i=$len-1; i>=0; i-- ))
do
    rev="$rev${num:$i:1}"
done
echo -e "Reverse of $num is $rev\n"