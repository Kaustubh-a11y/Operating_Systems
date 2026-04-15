#!/bin/bash

echo "Enter first number:"
read num1

echo "Enter second number:"
read num2

echo "Choose operation:"
echo "+ for Addition"
echo "- for Subtraction"
echo "* for Multiplication"
echo "/ for Division"

read op

case $op in
    +)
        result=$((num1 + num2))
        echo "Result: $result"
        ;;
    -)
        result=$((num1 - num2))
        echo "Result: $result"
        ;;
    \*)
        result=$((num1 * num2))
        echo "Result: $result"
        ;;
    /)
        if [ $num2 -ne 0 ]; then
            result=$((num1 / num2))
            echo "Result: $result"
        else
            echo "Error: Division by zero!"
        fi
        ;;
    *)
        echo "Invalid operator"
        ;;
esac
