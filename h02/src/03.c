#include <stdio.h>
#include <stdlib.h>

#define SIZE 6

void fill_arr(int ar[SIZE][SIZE]){
    for(int i = 0; i < SIZE ; i++){
        for(int j = 0; j < SIZE ; j++){
            ar[i][j] = 0;
        }
        
    }
}

void print_arr(int ar[SIZE][SIZE]){
    for(int i = 0; i < SIZE ; i++){
        for(int j = 0; j < SIZE ; j++){
            printf("%d ", ar[i][j]);
        }
        printf("\n");
    }
}

void fill_triangle_arr(int ar[SIZE][SIZE]){
    int count = 0;
    for(int i = 0; i < SIZE ; i++){
        count = SIZE - i - 1; // указывает колво нулей в строке
        for(int j = 0; j < SIZE ; j++){
            if(count > 0)
                ar[i][j] = 0;
            else
                ar[i][j] = 1;
            count -= 1; // отсчитываем колво поставленных нулей

        }
    }
}


int main()
{
    int arr[SIZE][SIZE];

    fill_arr(arr);
    fill_triangle_arr(arr);
    print_arr(arr);

    // первый и самый тупой алгоритм по заполнению массива сработал))))


    return 0;
}