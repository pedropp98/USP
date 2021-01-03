#include<stdio.h>
#include<stdlib.h>

#define N_GRADES 3

double min(double*);

int main(void){
    double *grades = (double*)calloc((N_GRADES+1), sizeof(double));
    double minimum, average = 0;
    for(int i = 0; i < N_GRADES+1; i++){
        scanf("%lf ", &grades[i]);
        average += grades[i];
    }
    average -= min(grades);
    average /= N_GRADES;
    printf("%lf\n", average);
    free(grades);
    return 0;
}

double min(double *grades){
    double minimum = grades[0];
    for(int i = 0; i < (N_GRADES+1); i++){
        if(minimum > grades[i])
            minimum = grades[i];
    }
    return minimum;
}