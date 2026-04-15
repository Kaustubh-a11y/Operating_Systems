#!/bin/bash

echo "Choose an option:"
echo "a) Leap Year"
echo "b) Even or Odd"
echo "c) Largest of 3 Numbers"
read choice

case $choice in
    a)
        echo "Enter year:"
        read year

        if (( (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ))
        then
            echo "$year is a Leap Year"
        else
            echo "$year is NOT a Leap Year"
        fi
        ;;
    
    b)
        echo "Enter a number:"
        read num

        if (( num % 2 == 0 ))
        then
            echo "$num is Even"
        else
            echo "$num is Odd"
        fi
        ;;

    c)
        echo "Enter three numbers:"
        read a b c

        if (( a >= b && a >= c ))
        then
            echo "$a is largest"
        elif (( b >= a && b >= c ))
        then
            echo "$b is largest"
        else
            echo "$c is largest"
        fi
        ;;

    *)
        echo "Invalid choice"
        ;;
esac
