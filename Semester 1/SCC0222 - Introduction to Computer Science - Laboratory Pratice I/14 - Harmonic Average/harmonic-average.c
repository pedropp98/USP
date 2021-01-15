#include<stdio.h>
#include<stdlib.h>

int readInt();
double readDouble();
double printDouble(double val);
double calculateAverage(double*, int);


int main(void){
    int N_works = readInt();
    double *grades = (double*)malloc(N_works * sizeof(double));
    for(int i = 0; i < N_works; i++){
        grades[i] = readDouble();
    }
    printDouble(calculateAverage(grades, N_works));
    free(grades);
    return 0;
}

int readInt(){
    int number;
    scanf("%d", &number);
    return number;
}

double readDouble(){
    double number;
    scanf("%lf", &number);
    return number;
}

double calculateAverage(double *grades, int n_grades){
    double sum_harmonic_grades = 0;
    for(int i = 0; i < n_grades; i++){
        sum_harmonic_grades += 1 / (grades[i] + 1);
    }
    double average = (n_grades / sum_harmonic_grades) - 1;
    return average;
}

double printDouble(double val){
    printf("%.2lf", val);
}