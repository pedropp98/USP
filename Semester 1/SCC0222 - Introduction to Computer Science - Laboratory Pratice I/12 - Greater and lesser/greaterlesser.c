#include<stdio.h>
#include<stdlib.h>

typedef enum boolean{
    false, true
}boolean_t;

void bubblesort(int *array, int size);

int main(void){
    int q_numbers;
    scanf("%d", &q_numbers);
    int *numbers = (int*)malloc(q_numbers * sizeof(int));
    for(int i = 0; i < q_numbers; i++){
        scanf("%d", &numbers[i]);
    }
    bubblesort(numbers, q_numbers);
    printf("max: %d\nmin: %d\n", numbers[q_numbers-1], numbers[0]);
    free(numbers);
    return 0;
}

void bubblesort(int *array, int size){
    boolean_t sort = true;
    while(sort){
        sort = false;
        for(int i = 0; i < size-1; i++){
            if(array[i] > array[i+1]){
                int copy = array[i];
                array[i] = array[i+1];
                array[i+1] = copy;
                sort = true;
            }
        }
    }
}