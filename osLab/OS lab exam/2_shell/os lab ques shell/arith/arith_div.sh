#!/bin/bash

echo "Enter 1st number"
read n1
echo "Enter 2nd number"
read n2
divint=$[$n1/$n2]
#divfloat=$(echo "scale=2; $n1/$n2" | bc)
echo "Division  : $n1 / $n2 = $divint"
#echo "Division (Float): $n1 / $n2 = $divfloat"