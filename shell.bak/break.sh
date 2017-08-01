#!/bin/bash


while :
do
    echo -n a number:
    read number
    case $number in
        1|2|3)
            echo $number
            ;;
        *)
            echo other number
            echo game exit
            break
            ;;
    esac
done
