#!/bin/bash


while :
do
    echo -n number:
    read number

    case $number in
        1)
            echo one
            ;;
        2)
            echo two
            ;;
        *)
            echo other
            continue
            ;;
    esac
done
