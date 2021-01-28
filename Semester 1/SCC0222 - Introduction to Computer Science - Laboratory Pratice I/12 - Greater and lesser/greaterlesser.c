#include<stdio.h>
#include<stdlib.h>

// Defining a new type boolean_t
typedef enum boolean{
    false, true
}boolean_t;

// Function definition
void bubblesort(int *array, int size);

// Main function
int main(void){
    int q_numbers;
    scanf("%d", &q_numbers);
    int *numbers = (int*)malloc(q_numbers * sizeof(int)); // Allocates q_numbers * 4 bytes in heap memory
    for(int i = 0; i < q_numbers; i++){
        scanf("%d", &numbers[i]);
    }
    bubblesort(numbers, q_numbers); // Bubblesort sorts the array numbers
    printf("max: %d\nmin: %d\n", numbers[q_numbers-1], numbers[0]);  // As numbers is sorted, the lowest number is the first index and the highest is in the last index
    free(numbers); // Deallocates memory from numbers
    return 0;
}

// sorts an array containing size items, using the logic of bubblesort algorithm
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