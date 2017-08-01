/*************************************************************************
	> File Name: libwho.h
	> Author: 
	> Mail: 
	> Created Time: 2017年07月03日 星期一 21时35分48秒
 ************************************************************************/

#ifndef _LIBWHO_H
#define _LIBWHO_H
#include "head.h"

void show_reg_time(time_t time , int show_begin , int show_end);
void print_user_info(struct utmp *user_info);
void get_user_from_utmp();

#endif
