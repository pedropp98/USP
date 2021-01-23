#include<stdio.h>
#include<stdlib.h>

// Defining a macro N_GRADES
#define N_GRADES 3

// Function declaration
double min(double*);

// Main function
int main(void){
    double *grades = (double*)calloc((N_GRADES+1), sizeof(double)); // Allocating 32 bytes in heap memory
    double minimum, average = 0;
    for(int i = 0; i < N_GRADES+1; i++){
        scanf("%lf ", &grades[i]);
        average += grades[i]; // Adding new values to average variable
    }
    average -= min(grades); // Subtracting the lowest grade
    average /= N_GRADES; // Making the average of grades
    printf("%lf\n", average); // Printing the result
    free(grades); // Deallocating heap memory
    return 0;
}

// Function definition. It returns the lowest value stored in an array
double min(double *grades){
    double minimum = grades[0];
    for(int i = 0; i < (N_GRADES+1); i++){
        if(minimum > grades[i])
            minimum = grades[i];
    }
    return minimum;
}