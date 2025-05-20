#!/bin/bash

# Code for finding factorial

echo "Input a number to find its factorial: "
read a

b=1

if [ $a -lt 0 ]; then
    echo "Exception occured"
else
    for (( i=1; i<=a; i++ ))
    do
        b=$((b * i))
    done

    echo "Factorial of $a is= $b"
fi
