#!/bin/bash

# strong pswd detection
echo "Enter pswd"
read pswd
count=0

# length >= 8
if [ (${#pswd} -le 8) ]
    then echo -e "length of pswd should be atleast 8\n"
    break


for n in ${pswd[@]};
do
    # one capital
    for i in {A..Z};
    do  
        if [ $n == $i ]
            then break
        else
            ((count=$count+1))
            break
        fi
    done

    if [ $count -eq ${#pswd} ]
        then 
            echo -e "pswd should contain atleast 1 uppercase letter\n"
            break
    fi

    # one lowercase
    for i in {a..z};
    do  
        if [ $n == $i ]
            then break
        else
            ((count=$count+1))
            break
        fi
    done

    if [ $count -eq ${#pswd} ]
        then 
            echo -e "pswd should contain atleast 1 lowercase letter\n"
            break
    fi

    # one digit
    for i in {0..9};
    do  
        if [ $n == $i ]
            then break
        else
            ((count=$count+1))
            break
        fi
    done

    if [ $count -eq ${#pswd} ]
        then 
            echo -e "pswd should contain atleast 1 digit\n"
            break
    fi

done
