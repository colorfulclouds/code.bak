#!/bin/bash


echo -n input a number:
read number

case $number in
    1)
        echo one
        ;;
    2)
        echo two
        ;;
    3)
        echo three
        ;;
    *)
        echo other number
        ;;
esac
