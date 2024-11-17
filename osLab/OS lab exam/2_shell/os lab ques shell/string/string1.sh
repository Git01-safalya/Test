 #!/bin/bash

echo "STRING operations"

echo "Enter string"

read str

echo -e "\nMenu :\n1.length\n2.concat 2 strings\n3.compare 2 strings\n4.substring\n\nChoose operation : "
read choice

case $choice in 
    1)
        echo "length of $str is : ${#str}"
    ;;
    2)
        echo "Enter 2nd string"
        read str2
        echo "concating $str with $str2 : $str$str2"
    ;;
    3)
        echo "Enter 2nd string"
        read str2
        echo "Comparing strings :"
        if [ "$str" == "$str2" ]
        then
            echo "strings are same"
        else
            echo "strings are NOT same"
        fi
    ;;
    4)
        echo "Enter starting & ending index of substring : "
        read n1 n2
        echo -e "\nsubstring from $n1 to $n2 is    : ${str:$n1:$n2}"
    ;;
*)
;;
esac