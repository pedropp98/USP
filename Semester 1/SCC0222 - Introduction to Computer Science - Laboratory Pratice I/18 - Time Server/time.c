#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Q_MONTHS 12

typedef enum boolean{
    false, true
}boolean_t;

typedef int(*__function_compare__)(void*, void*);

typedef struct time_average{
    double time;
    int month;
}time_average_t;

int compare_double(void*, void*);
time_average_t *set_bigger(time_average_t*);

int main(void){
    time_average_t *times = (time_average_t*)malloc(Q_MONTHS * sizeof(time_average_t));
    for(int i = 0; i < Q_MONTHS; i++){
        scanf("%lf", &times[i].time);
        times[i].month = i + 1;
    }
    time_average_t *bigger = set_bigger(times);
    printf("%d %.2lf\n", bigger->month, bigger->time);
    free(bigger);
    free(times);
    return 0;
}

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