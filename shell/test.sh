#!/bin/bash

a=1
b=0

if test $a = $b
then
    echo same
else
    echo different
fi


if test $a == $b
then 
    echo same
else
    echo different
fi

if [ $a = $b ]
then
    echo same
else
    echo different
fi

if [ $a == $b ]
then
    echo same
else
    echo different
fi
