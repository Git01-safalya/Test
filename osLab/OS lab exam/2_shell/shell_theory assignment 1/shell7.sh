 #!/bin/bash

echo -e "\n Program to check & count occurrences of 
            sub-string in given string by using CLA"

string="$1"
substr="$2"

sub_len=${#substr}

count=0

while [ "${string#*$substr}" != "$string" ];
do
    string="${string#*$substr}"
    ((count++))
done

echo "Occurrences of '$2' in '$1': $count"

