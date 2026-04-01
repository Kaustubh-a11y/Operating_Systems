#!/bin/bash
echo "Enter two numbers:"
read a b

if [ $a -gt $b ]
then
    result=$((a - b))
    echo "Result = $result"
else
    result=$((b - a))
    echo "Result = $result"
fi
