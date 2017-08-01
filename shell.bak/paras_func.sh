#!/bin/bash

paras_func()
{
    echo paras number:$#
    
    echo first para:$1
    echo second para:$2
# $10 is wrong cannot point tenth para must use the format ${!0}
#>=10 paras all 
    echo all para:$*
}

paras_func 1 2
