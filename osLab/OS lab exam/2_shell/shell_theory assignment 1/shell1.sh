#!/bin/bash

echo -e "\nProgram to find whether argument is +ve or -ve"
echo "Enter number : "
read num
if [ $num -gt 0 ]
    then
        echo -e "$num is positive\n"
elif [ $num -lt 0 ]
    then
        echo -e "$num is negative\n"
elif [ $num -eq 0 ]
    then 
        echo -e "$num is neither negative nor positive\n"
else
    echo -e "Incorrect input\n"
fi 