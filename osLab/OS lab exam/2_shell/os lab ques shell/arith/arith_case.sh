#!/bin/bash

echo "Enter 2 numbers"
read n1 n2
echo -e "\nMenu :\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n\nChoose operation : "
read choice

case $choice in 
    1)
        echo -e "\nAddition    : $n1 + $n2 = $[$n1+$n2]"
    ;;
    2)
        echo -e "\nSubtraction : $n1 - $n2 = $[$n1-$n2]"
    ;;
    3)
        echo -e "\nMultiply    : $n1 x $n2 = $[$n1*$n2]"
    ;;
    4)
        echo -e "\nDivision    : $n1 / $n2 = $[$n1/$n2]"
    ;;
*)
;;
esac