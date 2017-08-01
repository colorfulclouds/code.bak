#!/bin/bash


number=10

until [ $number -gt 15 ]
do
    echo $number
    let number++
done
