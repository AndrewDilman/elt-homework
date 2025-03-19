#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR_LEN 256

int read_string(char *string){
    char buff[STR_LEN];
    if (fgets(buff, sizeof(buff), stdin)) {
        if (sscanf(buff, "%s", string) == 0) {
            printf("can't read string!\n");
            return 0;
        }
    }
    return 1;
}

char* Find_pattern(char str[STR_LEN], char pat[STR_LEN]){
    int n = strlen(str);
    int m = strlen(pat);

    printf("%d\n", n);
    // пытаемся найти искомую строку от каждого символа 
    for(int i = 0; i < n; i++){
        int j = 0;
        while( j < m && str[i+j] == pat[j]){
            j = j + 1;
        }
        if (j == m){ // строка найдена
            return (str + i);
        }
    }
    return NULL;

}

int main()
{
    char str[STR_LEN];
    char pat[STR_LEN];
    printf("Type initial line:\n");
    read_string(str);
    printf("Type line for search:\n");
    read_string(pat);
    
    char* pat_ptr = Find_pattern(str, pat);

    if(pat_ptr)
        printf("String found: %s\n", pat_ptr);
    else
        printf("String not found\n");
}