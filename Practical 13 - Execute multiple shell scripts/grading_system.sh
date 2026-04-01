#!/bin/bash

echo "Enter your marks:"
read marks

if [ $marks -gt 75 ]
then
    echo "Distinction"
elif [ $marks -gt 65 ] && [ $marks -le 75 ]
then
    echo "First Division"
elif [ $marks -gt 55 ] && [ $marks -le 65 ]
then
    echo "Second Division"
else
    echo "Third Division"
fi
