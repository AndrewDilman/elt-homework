#include <stdio.h>
#include <stdlib.h>

void print_arr(int32_t *arr){
    for(int i=0; i<10; i++){
        // смещаем указательна i для получения числа
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int main(){
    int32_t arr[10]={1,2,3,4,5,6,7,8,9,10};
    print_arr(arr);

    return 0;
}