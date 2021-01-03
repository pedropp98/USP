#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void bubblesort(int*);
int check_sides(int*);

int main(void){
    int *sides = (int*)calloc(3, sizeof(int));
    for(int i = 0; i < 3; i++)
        scanf("%d", &sides[i]);
    bubblesort(sides);
    if(check_sides(sides) && pow(sides[0], 2) + pow(sides[1], 2) == pow(sides[2], 2))
        printf("SIM\n");
    else
        printf("NAO\n");
    free(sides);
    return 0;
}

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

int check_sides(int *sides){
    if(sides[0] == 0)
        return 0;
    else if(sides[1] == 0)
        return 0;
    else if(sides[2] == 0)
        return 0;
    else
        return 1;
}