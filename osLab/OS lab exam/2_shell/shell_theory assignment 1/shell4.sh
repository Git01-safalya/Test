#!/bin/bash

echo -e "\nProgram to check whether string is palindrome or not"
echo "Enter string"
read str
rev=""

len=${#str}
for (( i=$len-1; i>=0; i-- ))
do
    rev="$rev${str:$i:1}"
done
echo "$rev"
if [ $rev == $str ]
    then
        echo -e "String $str is a palindrome\n"
else
    echo -e "String $str is not a palindrome\n"
fi 