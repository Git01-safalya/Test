#!/bin/bash

echo "Enter a character"
read char

case $char in
    *[A-Z]* )
            echo -e "It's an uppercase letter\n" 
        ;;

    *[a-z]* )
            echo -e "It's a lowercase letter\n" 
        ;;

    *[0-9]* )
            echo -e "It's a digit\n"
        ;;

    *)
            echo -e "It's a spcl char\n" 
        ;;
esac