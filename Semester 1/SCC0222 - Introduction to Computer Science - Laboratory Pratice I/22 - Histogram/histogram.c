#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Defining macros to use in the program
#define SIZE_IMAGE 5*5
#define and &&

// Creating a pointer to function type __compare_function__ to help in the sorting algorithm
typedef int (*__compare_function__)(void*, void*);

// Creating a new type boolean_t to work with boolean values true and false
typedef enum{
    false, true
}boolean_t;

// Function definition
int *create_image();
int *create_copy(int*);
void read_image(int*);
void bubblesort(void*, int, int, __compare_function__);
void erase_image(int*);
void print_result(int*, int*);
int compare_int(void*, void*);

// Main function
int main(void){
    int *img = create_image();
    read_image(img); // Inputs every integer for the original image
    int *img_copy = create_copy(img); // Copies the original image to the copy image
    bubblesort(img_copy, SIZE_IMAGE, sizeof(int), compare_int); // Sorts img_copy in ascending order
    print_result(img_copy, img); // Calls print_result
    erase_image(img);
    erase_image(img_copy);
    return 0;
}

// Allocates memory for an int*, SIZE_IMAGE * 4 bytes in heap memory
int *create_image(){
    int *img = (int*)malloc(SIZE_IMAGE * sizeof(int));
    return img;
}

// Creates a copy for img_original, copying each value from img_original to each value of img_copy
int *create_copy(int *img_original){
    int *img_copy = create_image();
    for(int i = 0; i < SIZE_IMAGE; i++)
        img_copy[i] = img_original[i];
    return img_copy;
}

// Reads SIZE_IMAGE integers from stdin and stores them in the int*
void read_image(int *img){
    for(int i = 0; i < SIZE_IMAGE; i++)
        scanf("%d", &img[i]);
}

// Deallocates memmory allocated for an int*
void erase_image(int *img){
    free(img);
}

// Sorts the q_items of size size_items from the array using bubblesort logic
void bubblesort(void *array, int q_items, int size_items, __compare_function__ function){
    char *last = ((char*)array) + (q_items * size_items);
    char *side_array1;
    char *copy = (char*)malloc(size_items);
    boolean_t swap = true;
    for(side_array1 = array; side_array1 < (last - size_items); side_array1 += size_items){
        swap = false;
        char *side_array2;
        for(side_array2 = side_array1 + size_items; side_array2 < last; side_array2 += size_items){
            if(function(side_array1, side_array2) > 0){
                memcpy(copy, side_array1, size_items);
                memcpy(side_array1, side_array2, size_items);
                memcpy(side_array2, copy, size_items);
                swap = true;
            }
        }
    }
    free(copy);
}

// Compares i1 with i2, returns 1 if i1 is greater than i2, -1 if i2 is greater and 0 if they're equal
int compare_int(void *i1, void *i2){
    int *int1 = i1, *int2 = i2;
    if(*int1 > *int2)
        return 1;
    if(*int1 < *int2)
        return -1;
    return 0;
}

// Receives the copied image and the original image and prints '#' the amount of times each inputted value appears in the array (from the sorted copied image) and prints the position from the most repetitive (from the original image)
void print_result(int *img_copy, int *img_original){
    int bigger_num = 0, bigger_repetitive = 0;
    for(int i = 0; i < SIZE_IMAGE - 1; i++){
        int repetitive = 1;
        printf("%d |#", img_copy[i]);
        while(i < (SIZE_IMAGE - 1) and img_copy[i] == img_copy[i+1]){
            printf("#");
            i++;
            repetitive++;
            if(repetitive > bigger_repetitive){
                bigger_num = img_copy[i];
                bigger_repetitive = repetitive;
            }
        }
        printf("\n");
    }
    for(int i = 0; i < SIZE_IMAGE; i++){
        if(img_original[i] == bigger_num)
            printf("%d\n", i);
    }
}