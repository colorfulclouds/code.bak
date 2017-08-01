/*************************************************************************
	> File Name: libwho.c
	> Author: 
	> Mail: 
	> Created Time: 2017年07月03日 星期一 21时36分06秒
 ************************************************************************/

#include "libwho.h"

void show_reg_time(time_t time , int show_length , int show_begin)
{
    printf("%*s ", show_length ,ctime(&time)+ show_begin);
}

void print_user_info(struct utmp *user_info)
{
    if(user_info->ut_type != USER_PROCESS)
        return ;
    
    printf("%s ", user_info->ut_name); //user Name
    printf("%s ", user_info->ut_line); //user tty
    show_reg_time(user_info->ut_time , 4 , 12); //user login time
    printf("(%s)\n", user_info->ut_host); //user host
}

void get_user_from_utmp()
{
    struct utmp user_info;
    int utmp_s_length = sizeof(struct utmp);
    int utmp_fd = open(UTMP_FILE , O_RDONLY);
    
    if(utmp_fd == -1)
    {
        perror("open utmp file");
        exit(EXIT_FAILURE);
    }

    while( read(utmp_fd , &user_info , utmp_s_length ) == utmp_s_length) 
    {
        print_user_info(&user_info);
    }
    close(utmp_fd);

}
