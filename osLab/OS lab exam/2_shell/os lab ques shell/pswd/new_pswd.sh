#!/bin/bash

# strong pswd detection

# length >= 8
length() {
    if [ $len -le 8 ]
        then echo -e "Length of pswd should be atleast 8"
        return
    fi
    ((count=$count+1))
}


uppercase() 
{
    case $pswd in
        *[A-Z]* ) ((count=$count+1))
            return 
            ;;
    esac
    
    echo -e "Atleast 1 uppercase needed"   
}

lowercase() 
{
    case $pswd in
        *[a-z]* ) ((count=$count+1))
            return 
            ;;
    esac
    
    echo -e "Atleast 1 lowercase needed"   
}

digit() 
{
    case $pswd in
        *[0-9]* ) ((count=$count+1))
            return 
            ;;
    esac
    
    echo -e "Atleast 1 digit needed"   
}

spcl() 
{
    case $pswd in
        *['!''@''#''$''%''^''*''_''+']* ) ((count=$count+1))
            return 
            ;;
    esac
    
    echo -e "Atleast 1 spcl char needed"   
}

echo "Enter pswd"
read pswd
count=0
len=${#pswd}
length
uppercase
lowercase
digit
spcl

if [ $count -eq 5 ]
then
    echo "pswd accepted"
fi