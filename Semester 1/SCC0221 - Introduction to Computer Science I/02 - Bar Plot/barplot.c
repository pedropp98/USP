#include<stdio.h>
#include<stdlib.h>

// Function definition
void bubblesort(int*, int);

// Main function
int main(void){
    int q_bars, q_data, *data;
    scanf("%d %d", &q_bars, &q_data); // reads from stdin the amount of bars and data
    data = (int*)malloc(q_data * sizeof(int)); // Allocates q_data * 4 bytes in heap memory
    for(int i = 0; i < q_data; i++){
        scanf("%d", &data[i]); // Reads q_data integers from stdin and stores them into each position of data
    }
    bubblesort(data, q_data); // Sorts data in ascending order
    int *count = (int*)calloc(q_bars, sizeof(int)); // Allocates q_bars * 4 bytes in heap memory and initializes every one to 0
    for(int i = 0, j = 0; i < q_data-1; i++){ // Counts every occurence of an integer in a certain position of data array
        if(data[i] == data[i+1])
            count[j]++;
        else
            j++;
    }
    for(int i = 0; i < q_bars; i++){ // Prints the result as asked for the exercise
        printf("%d - ", i);
        for(int j = 0; j <= count[i]; j++)
            printf("#");
        printf("\n");
    }
    free(data); // Deallocates memory allocated in data
    free(count); // Deallocates memory allocated in count
    return 0;
}

// Sorts an array of size elements using bubblesort logic
void bubblesort(int *array, int size){
    int sort = 1;
    while(sort){
        sort = 0;
        for(int i = 0; i < size-1; i++){
            if(array[i] > array[i+1]){
                int copy = array[i];
                array[i] = array[i+1];
                array[i+1] = copy;
                sort = 1;
            }
        }
    }
}