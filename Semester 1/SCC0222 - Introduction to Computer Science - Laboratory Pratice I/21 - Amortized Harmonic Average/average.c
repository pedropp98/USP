#include<stdio.h>
#include<stdlib.h>

// Function definition
double average(int);

// Main function
int main(void){
    int n_grades;
    scanf("%d", &n_grades);
    printf("%lf\n", average(n_grades));
    return 0;
}

// Calculates harmonic average of n_grades
double average(int n_grades){
    double sum_divisor = 0, grade;
    for(int i = 0; i < n_grades; i++){
        scanf("%lf", &grade);
        sum_divisor += 1 / (grades[i] + 1);
    }
    return (n_grades / sum_divisor) - 1;
}