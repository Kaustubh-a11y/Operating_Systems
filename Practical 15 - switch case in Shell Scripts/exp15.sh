#!/bin/bash

echo "Enter the option:"
echo "a = print the date"
echo "b = list all files in current dir"

read choice

case $choice in
    a)
        date
        ;;
    b)
        ls
        ;;
    *)
        echo "Not a valid option"
        ;;
esac
