/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: 2017年07月03日 星期一 21时47分00秒
 ************************************************************************/

#include <stdio.h>
#include <fcntl.h>
#include <utmp.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <pwd.h>

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

void get_user_from_utmp(char *argv_one ,  char *argv_two)
{
    struct utmp user_info;
    struct passwd *one;
    int utmp_s_length = sizeof(struct utmp);
    int utmp_fd = open(UTMP_FILE , O_RDONLY);
    
    if(utmp_fd == -1)
    {
        perror("open utmp file");
        exit(EXIT_FAILURE);
    }

    if(argv_one == NULL)
    {
        while( read(utmp_fd , &user_info , utmp_s_length ) == utmp_s_length) 
        {
            print_user_info(&user_info);
        }
        close(utmp_fd);
    }
    else
    {
        one = getpwuid(getuid());
        char buff[20];
        bzero(buff , sizeof(buff));
        strcpy(buff , one->pw_name);

        while( read(utmp_fd , &user_info , utmp_s_length ) == utmp_s_length) 
        {
            if( strcmp(user_info.ut_name , buff) == 0 )
            {
                print_user_info(&user_info);
                return ;
            }
        }

    }
}

int main(int argc , char *argv[])
{

    if(argc <= 2)
        get_user_from_utmp(NULL , NULL);
    else
        get_user_from_utmp(argv[1] , argv[2]);

    return 0;
}
