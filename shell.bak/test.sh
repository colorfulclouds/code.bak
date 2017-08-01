#!/bin/bash
	> File Name: test.sh
	> Author: 
	> Mail: 
	> Created Time: Wed Jul 12 08:39:45 2017
 ************************************************************************/

a=10
b=100

if test $a -eq $b
then
    echo equal
else
    echo not equal
fi


echo **************

str1=yufei
str2=maomao

if test $str1 = $str2
then
    echo equal
else
    echo not equal
fi

echo **************

if test -z $str1
then
    echo zero
else
    echo non zero
fi
