#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

void print_arr(int ar[SIZE][SIZE]){
    for(int i = 0; i < SIZE ; i++){
        for(int j = 0; j < SIZE ; j++){
            printf("%d ", ar[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    int arr[SIZE][SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    print_arr(arr);

    


    return 0;
}