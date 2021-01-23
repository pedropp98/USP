#include<stdio.h>
#include<stdlib.h>

// Function declaration
double operation(double, double, int);

// Main function
int main(void){
    double number1, number2;
    char op;
    scanf("%lf %c %lf", &number1, &op, &number2);
    printf("%lf\n", operation(number1, number2, op)); // Prints the result of the returned value from function operation
    return 0;
}

// Function definition
double operation(double n1, double n2, int op){
    double result;
    switch(op){
    case 37: // Module (%)
        result = ((n1 * 1.0) / (n2 * 1.0)) * 100;
        break;
    case 42: // Multiplication (*)
        result = n1 * n2;
        break;
    case 43: // Sum (+)
        result = n1 + n2;
        break;
    case 45: // Subtraction (-)
        result = n1 - n2;
        break;
    case 47: // Division(/)
        result = n1 / n2;
        break;
    }
    return result;
}