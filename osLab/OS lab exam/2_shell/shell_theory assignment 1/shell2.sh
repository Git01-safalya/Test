#!/bin/bash

echo "Program for arithmetic calculation program while using case structure"
echo -e "Choose operation :\n 1.Add\n 2.Subtract\n 3.Multiply\n 4.Divide\n"
read oper
echo "Enter the 2 nums"
read num1 num2
case $oper in
    1)  ((res=$num1 + $num2))
        echo "Addition       : $num1 + $num2 = $res"
    ;;

    2)  ((res=$num1 - $num2))
        echo "Subtraction    : $num1 - $num2 = $res"
    ;;

    3)  ((res=$num1 * $num2))
        echo "Multiplication : $num1 * $num2 = $res"
    ;;

    4)  ((res=$num1 / $num2))
        echo "Division       : $num1 / $num2 = $res"
    ;;

    *)
        echo "Wrong input"
    ;;
esac