#!/bin/bash

i=1
until [ $i -gt 5 ]
do
  echo $i
  ((i++))
done
