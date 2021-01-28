#include<stdio.h>
#include<stdlib.h>

// Function definition
int readInt();
double readDouble();
double printDouble(double val);
double calculateAverage(double*, int);

// Main function
int main(void){
    int N_works = readInt();
    double *grades = (double*)malloc(N_works * sizeof(double)); // Allocates N_works * 8 bytes in heap memory
    for(int i = 0; i < N_works; i++){
        grades[i] = readDouble();
    }
    printDouble(calculateAverage(grades, N_works));
    free(grades); // Deallocates memory allocated for grades
    return 0;
}

// Reads an integer from stdin and returns it
int readInt(){
    int number;
    scanf("%d", &number);
    return number;
}

// Reads a double from stdin and returns it
double readDouble(){
    double number;
    scanf("%lf", &number);
    return number;
}

// Calculates the harmonic average using the especific equation in the exercise
double calculateAverage(double *grades, int n_grades){
    double sum_harmonic_grades = 0;
    for(int i = 0; i < n_grades; i++){
        sum_harmonic_grades += 1 / (grades[i] + 1);
    }
    double average = (n_grades / sum_harmonic_grades) - 1;
    return average;
}

// Prints the result
double printDouble(double val){
    printf("%.2lf", val);
}