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

void replace_third_byte(int* number, int* replace){
    int32_t n_buf = *number;
    int32_t r_buf = *replace;

    r_buf = r_buf << (8*2); // смещаем число на 3 байт
    n_buf = n_buf & 0xFFFFF0FF; // маска убирающая 3 байт
    n_buf = n_buf | r_buf; // Совмещаем два числа
    *number = n_buf;
}

int print_and_count_num(int* number){
    int one_count = 0;
    for(int i = 0; i<32 ; i++)
    {
        int bit = !!((*number<<i) & 0x80000000);
        printf("%d", bit);
        /* двойное отрицание нужно, чтобы после применения маски 
        на вывод приходил просто 0 или 1*/
        
        ((i+1) % 4 == 0) ? printf(" ") : 0;
        (bit > 0) ? one_count++ : 0;
    }
    printf("\n");
    return one_count;
}

int main()
{
    int32_t number = 0;    
    printf("Enter positive or negative number: \n");
    if( !read_number(&number) )
        return 0;
    
    // вывод числа и подсчёт единиц
    printf("Binary representation:\n");
    int one_count = print_and_count_num(&number);
    
    printf("One count in binary: %d\n", one_count);
    
    // замена третьего байта
    int32_t replace = 0;
    printf("Enter number to replace third byte: \n");
    if( !read_number(&replace) )
        return 0;
    if(replace > 255){
        printf("Maximum is 255\n");
        replace = 255;
    }
    
    replace_third_byte(&number, &replace);
    print_and_count_num(&number);
    
    
}