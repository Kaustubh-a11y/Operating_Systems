#!/bin/bash
echo "Enter two numbers:"
read a b

if [ $a -gt $b ]
then
    echo "$a is largest"
else
    echo "$b is largest"
fi
