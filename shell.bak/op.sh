#!/bin/bash

val=`expr 12 + 12`
echo "plus is $val"

a=10
b=20
echo "chengfa = `expr $a \* $b`"

if [ $a < $b ]
then
    echo "hh"
else
    echo "ll"
fi

#b=10
#echo "[ $a == $b ]"
