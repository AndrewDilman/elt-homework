#include <stdio.h>
#include <stdlib.h>

int read_number(int* number){
    char buff[256];
    if (fgets(buff, sizeof(buff), stdin)) {
        if (sscanf(buff, "%d", number) == 0) {
            printf("can't read number!\n");
            return 0;
        }
    }
    return 1;  
}

void replace_third_byte(char* number, int* replace){
    // number+=1; //смещаем указатель на третий байт
    // *number = *replace;
    number[2] = *replace;
}

void print_num(int* number){
    for(int i = 0; i<32 ; i++)
    {
        int bit = !!((*number<<i) & 0x80000000);
        printf("%d", bit);
        /* двойное отрицание нужно, чтобы после применения маски 
        на вывод приходил просто 0 или 1*/
        
        ((i+1) % 4 == 0) ? printf(" ") : 0;
    }
    printf("\n");
}

int main()
{
    int32_t number = 0;    
    printf("Enter positive or negative number: \n");
    if( !read_number(&number) )
        return 0;
    
    printf("Binary representation:\n");
    print_num(&number);
    
    // замена третьего байта
    int32_t replace = 0;
    printf("Enter number to replace third byte: \n");
    if( !read_number(&replace) )
        return 0;
    if(replace > 255){
        printf("Maximum is 255\n");
        replace = 255;
    }
    
    replace_third_byte((char*)&number, &replace);
    print_num(&number);
    
    
}