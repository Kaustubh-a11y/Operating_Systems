#!/bin/bash
echo "Enter your age:"
read age

if [ $age -ge 18 ]
then
    echo "You are an adult"
elif [ $age -gt 12 ]
then
    echo "You are a teenager"
else
    echo "You are a child"
fi
