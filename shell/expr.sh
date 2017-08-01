#!/bin/bash

number=12

number=`expr $number + 1`
echo $number

number=$(( number + 1 ))
echo $number
