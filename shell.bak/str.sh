#!/bin/bash
	> File Name: str.sh
	> Author: 
	> Mail: 
	> Created Time: Tue Jul 11 21:36:27 2017
 ************************************************************************/

str1=yu
str2=li

if [ $str1 = $str2 ]
then
    echo hh
else
    echo ll
fi

if [ -z $str1 ] #-n is opposite to -z
then
    echo length=0
else
    echo length!=0
fi

if [ $str1 ]
then 
    echo not null
else
    echo null
fi
