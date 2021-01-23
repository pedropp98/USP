#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Function declaration
void bubblesort(int*);
int check_sides(int*);

// Main function
int main(void){
    int *sides = (int*)calloc(3, sizeof(int));
    for(int i = 0; i < 3; i++)
        scanf("%d", &sides[i]);
    bubblesort(sides); // Calls bubblesort function
    if(check_sides(sides) && pow(sides[0], 2) + pow(sides[1], 2) == pow(sides[2], 2))
        printf("SIM\n");
    else
        printf("NAO\n");
    free(sides);
    return 0;
}

//Function definition
// Bubblesort is a sorting function. It sorts an array in ascending order
void bubblesort(int *array){
    int copy;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(array[i] < array[j]){
                copy = array[j];
                array[j] = array[i];
                array[i] = copy;
            }
        }
    }
}

// It checks if all the sides are different than zero. It returns 1 if do, 0 otherwise
int check_sides(int *sides){
    for(int i = 0; i < 3; i++)
        if(sides[i] == 0)
            return 0;
    return 1;
}