#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Function definition
double an_term(double, double, double);
double sn_sum(double, double, double);

// Main function
int main(void){
    double a1, ratio, n;
    scanf("%lf %lf %lf", &a1, &ratio, &n);
    printf("%.2lf\n", an_term(a1, ratio, n));
    printf("%.2lf\n", sn_sum(a1, ratio, n));
    return 0;
}

// Function declaration
// Finds the a_n term in a geometric progression
double an_term(double a1, double ratio, double n){
    return a1 * pow(ratio, n-1);
}

// Calculate the sum of n terms in a geometric progression
double sn_sum(double a1, double ratio, double n){
    return (a1 * (pow(ratio, n) - 1)) / (ratio - 1);
}