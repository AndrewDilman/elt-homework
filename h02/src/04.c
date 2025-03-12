#include <stdio.h>
#include <stdlib.h>

#define SIZE 7


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
            printf("%2d ", ar[i][j]);
        }
        printf("\n");
    }
}

void fill_spiral_arr(int ar[SIZE][SIZE], int diff, int counter){ // diff - отступ кольца
    if(diff < 0 || diff > SIZE/2){ // отлов слишком большого отступа
        printf("Error: to big difference value!");
        return;
    }
    
    if((SIZE % 2 == 1) && (diff == SIZE/2)){ // отлов конца нечёного массива
        ar[diff][diff] = counter;
        return;
    }
   
    int x = 0 + diff, y = 0 + diff; 
    
    // заполнение веерх
    for(; x < SIZE - diff-1; x++){
        ar[y][x] = counter;
        counter ++;
    }

    // заполнение право
    for(; y < SIZE - diff-1; y++){
        ar[y][x] = counter;
        counter ++;
    }

    // заполнение низ
    for(; x > diff; x--){
        ar[y][x] = counter;
        counter ++;
    }
    
    // заполнение лево
    for(; y > diff; y--){
        ar[y][x] = counter;
        counter ++;
    }

    if((diff == SIZE/2)) // отлов конца чёного массива
        return;
    
    diff++;
    fill_spiral_arr(ar, diff, counter);
}

int main()
{
    int arr[SIZE][SIZE];
    
    fill_arr(arr); // Заполняем нулями
    fill_spiral_arr(arr, 0, 0); // заполняем спираль
    print_arr(arr);


    return 0;
}