#!/bin/bash

echo -e "\nProgram to check whether number is prime or not"
echo "Enter num"
read num
count=0
((temp=$num/2))
for (( i=2 ; i<=$temp ; i++ ));
do
    ((test=$num % $i))
    if [ $test == 0 ]
    then
        ((count=$count+1))
        break
    fi
done

if [ $num -lt 2 ]
then 
    echo "$num is not prime"
elif [ $count == 0 ]
then
    echo "$num is prime"
else
    echo "$num is not prime"
fi