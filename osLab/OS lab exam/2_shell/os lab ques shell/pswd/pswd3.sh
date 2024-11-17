#!/bin/bash

# strong pswd detection

countcap=0
countlow=0
countnum=0
countspcl=0

# length >= 8
length() {
    if [ $len -le 8 ]
        then echo -e "length of pswd should be atleast 8\n"
        break
    fi
}


uppercase() {
    for n in ${pswd[@]};
    do  
        case $n in
            [A-Z]) break
            ;;
            *) ((countcap=$countcap+1))
            ;;
        esac
    done
    if (($countcap -lt $len ))
        then    
            echo -e "Atleast 1 uppercase needed\n"
            break
    fi
}

lowercase() {
    for n in ${pswd[@]};
    do  
        case $n in
            [a-z]) break
            ;;
            *) ((countlow=$countlow+1))
            ;;
        esac
    done
    if (($countlow -lt $len ))
        then    
            echo -e "Atleast 1 uppercase needed\n"
            break
    fi
}

digit() {
    for n in ${pswd[@]};
    do  
        case $n in
            [0-9]) break
            ;;
            *) ((countnum=$countnum+1))
            ;;
        esac
    done
    if (($countnum -lt $len ))
        then    
            echo -e "Atleast 1 digit needed\n"
            break
    fi
}

spcl() {
    for n in ${pswd[@]};
    do  
        case $n in
            !|@|#|$|%|^|&|-|_) 
                break
            ;;
            *) ((countspcl=$countspcl+1))
            ;;
        esac
    done
    if (($countspcl -lt $len ))
        then    
            echo -e "Atleast 1 spcl char needed\n"
            break
    fi

}

echo "Enter pswd"
read pswd
len=${#pswd}
length
uppercase
lowercase
digit
spcl