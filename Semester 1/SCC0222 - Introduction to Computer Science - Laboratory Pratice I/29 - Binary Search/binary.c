#include<stdio.h>
#include<stdlib.h>

// Definnig a new type boolean_t to work with boolean values
typedef enum{
    false, true
}boolean_t;

// Function definition
int *input_array(int);
void bubblesort(int*, int);
int recursive_binary_search(int*, int, int, int);

// Main function
int main(void){
    int size_array, key;
    scanf("%d %d", &size_array, &key);
    int *array = input_array(size_array);

    // In order to binary search to work properly, the array needs to be sorted
    bubblesort(array, size_array);
    int result = recursive_binary_search(array, 0, size_array, key);

    // If the result is -1 it means that the key does not exist in the array
    if(result != -1)
        printf("%d\n", result);
    else
        printf("Chave inexistente\n");
    free(array); // Deallocates memory previously allocated for array
    return 0;
}

// Allocates memory for an int*, reads size integers from stdin and stores them in array. Returns array
int *input_array(int size){
    int *array = (int*)malloc(size * sizeof(int)); // Allocates size * 4 bytes in heap memory
    for(int i = 0; i < size; i++){
        scanf("%d", &array[i]);
    }
    return array;
}

// Sorts an array of size elements in crescent order
void bubblesort(int *array, int size){
    boolean_t sort = true;
    // It goes all the way in the array at least once, if the array is already sorted then it stops the loop. This works better than other versions of bubblesort
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

// Looks for key in an array using binary search logic. This function is recursive, so be aware that stack overflow may occur if array is big enough
int recursive_binary_search(int *array, int begin, int end, int key){
    if(end < begin)
        return -1; // This means that the element does not exist in the array
    int middle = (begin + end) / 2; // Sets the middle position in the current range
    if(array[middle] == key)
        return middle;
    else if(array[middle] < key)
        return recursive_binary_search(array, middle+1, end, key); // Sets the range to be [middle+1, end], and calls recursive_binary_search under the new range
    else
        return recursive_binary_search(array, begin, middle-1, key); // Sets the range to be [begin, middle-1], and calls recursive_binary_search under the new range
}