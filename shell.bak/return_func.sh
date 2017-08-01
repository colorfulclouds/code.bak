#!/bin/bash


func_return()
{
    echo plus shell
    echo -n first number:
    read number1
    echo -n second number:
    read number2

    echo two number is $number1 and $number2
    return $(($number1+$number2))
}

func_return

echo sum=$?
