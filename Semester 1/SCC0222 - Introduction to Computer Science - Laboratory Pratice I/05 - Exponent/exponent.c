#include<stdio.h>
#include<stdlib.h>

// Function definition
double exponent(double, double);

// Main function
int main(void){
    double n1, n2;
    scanf("%lf %lf", &n1, &n2);
    printf("%lf\n", exponent(n1, n2));
    return 0;
}

//Function declaration
// Exponent function makes a to the power of b and returns this value
double exponent(double a, double b){
    int e = 1;
    for(int i = 0; i < b; i++){
        e *= a;
    }
    return e;
}