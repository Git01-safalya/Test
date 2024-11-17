#!/bin/bash

arr2=("Mumbai" "Pune" "Nagpur" "Delhi")

echo -e "\nEnter city :"
read city
count=0
for n in ${arr2[@]};
do
    if [ $city == $n ]
        then
            echo -e "\nCity found\n"
            break
    else
        ((count=$count+1))
    fi
done
if [ $count -eq 4 ]
then    
    echo -e "\nCity NOT found\n"
fi