#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 0; // каст нужен чтобы небыло ошибки

    
    printf("Enter positive or negative number: \n");
    char buff[256];
    if (fgets(buff, sizeof(buff), stdin)) {
        if (1 == sscanf(buff, "%d", &a)) { // каст нужен чтобы небыло ошибки
            printf("%d\n", a);
        }
    }
    printf("Your number: %d\n", a);
    printf("Binary representation:");

    int one_count = 0;
    for(int i = 0; i<8 ; i++)
    {
        int bit = !!((a<<i)  & 0x80);
        printf("%d", bit);
        /* двойное отрицание нужно, чтобы после применения маски 
        на вывод приходил просто 0 или 1*/
        
        ((i+1) % 4 == 0) ? printf(" ") : 0;
        (bit > 0) ? one_count++ : 0;
    }
    printf("\n");
    printf("One count in binary: %d\n", one_count);

}