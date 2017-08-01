#!/bin/bash

u(){
for i in 1 2 3 4 5
do
    echo $i
done
}

uu(){
for i
do
    echo $1
done
}

for i in "hjhj"
do
    echo $i
done

for i in 'hjhj'
do
    echo $i
done

for i in hjhj
do
    echo $i
done
