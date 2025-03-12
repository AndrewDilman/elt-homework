#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

void print_arr(int ar[SIZE][SIZE]){
    for(int i = SIZE-1; i > -1 ; i--){
        for(int j = SIZE-1; j > -1 ; j--){
            printf("%d ", ar[i][j]);
        }
    }
    printf("\n");
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