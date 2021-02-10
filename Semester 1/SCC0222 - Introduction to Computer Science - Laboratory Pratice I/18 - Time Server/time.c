#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Deifning macro Q_MONTHS to be valued as 12
#define Q_MONTHS 12

// Creating a new type boolean_t to work with boolean values true and false
typedef enum{
    false, true
}boolean_t;

// Creating a pointer to function type __function_compare__, that receies two addresses of memory and returns an integer
typedef int(*__function_compare__)(void*, void*);

// Creatinf a new type time_average_t to store info about time and month
typedef struct{
    double time;
    int month;
}time_average_t;

// Function definition
int compare_double(void*, void*);
time_average_t *set_bigger(time_average_t*);

// Main function
int main(void){
    time_average_t *times = (time_average_t*)malloc(Q_MONTHS * sizeof(time_average_t)); // Allocates memory to store every time in the year
    for(int i = 0; i < Q_MONTHS; i++){
        scanf("%lf", &times[i].time);
        times[i].month = i + 1;
    }
    time_average_t *bigger = set_bigger(times);
    printf("%d %.2lf\n", bigger->month, bigger->time);
    // Deallocates memory allocated for bigger and times
    free(bigger);
    free(times);
    return 0;
}

// Sets the biggest time and stores it in the array as with its correspondent month
time_average_t *set_bigger(time_average_t *array){
    time_average_t *time = (time_average_t*)malloc(sizeof(time_average_t));
    time->month = array[0].month;
    time->time = array[0].time;
    for(int i = 0; i < Q_MONTHS; i++){
        if(array[i].time > time->time){
            time->time = array[i].time;
            time->month = array[i].month;
        }
    }
    return time;
}