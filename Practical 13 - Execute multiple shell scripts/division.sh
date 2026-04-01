#!/bin/bash
echo "Enter two numbers:"
read a b

if [ $b -ne 0 ]
then
    div=$((a / b))
    echo "Division = $div"
else
    echo "Division by zero not allowed"
fi
