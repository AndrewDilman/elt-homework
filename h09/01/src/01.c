#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define LENGTH 16

int main()
{
    // https://stackoverflow.com/questions/28466715/using-open-to-create-a-file-in-c
    // не понимаю, почему не видит S_IWRITE | S_IREAD
    int f_dis = open("filename", O_RDWR | O_CREAT, 0644);

    if(f_dis == -1){
        printf("Error while file creating! %s\n", strerror(errno));
        return 1;
    }
    
    // записываем строку
    char buf[LENGTH] = "String from file";
    int writen_bytes = write(f_dis, buf, LENGTH);

    if(writen_bytes == -1){
        printf("Error while file writing! %s\n", strerror(errno));
        return 1;
    }

    // читаем файл
    char out[LENGTH];
    for( int i =0; i <= LENGTH; i++){
        lseek(f_dis, -i, SEEK_END);
        if(read(f_dis, out, 1) == -1){
            printf("Error while file reading! %s\n", strerror(errno));
            return 1;
        }
        printf("%c", out[0]);

    }
    printf("\n");
    return 0;
}