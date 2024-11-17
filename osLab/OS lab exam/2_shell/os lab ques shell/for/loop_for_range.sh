#!/bin/bash

echo "Enter number"
read num

for n in {1..10};
    do
        echo num x $n = $[$n * $num]
    done