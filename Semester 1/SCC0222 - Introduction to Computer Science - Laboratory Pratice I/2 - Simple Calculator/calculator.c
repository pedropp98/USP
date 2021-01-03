#include<stdio.h>
#include<stdlib.h>

double operation(double, double, int);

int main(void){
    double number1, number2;
    char op;
    scanf("%lf %c %lf", &number1, &op, &number2);
    printf("%lf\n", operation(number1, number2, op));
    return 0;
}

double operation(double n1, double n2, int op){
    double result;
    
    switch(op){
    
    case 37:
        result = ((n1 * 1.0) / (n2 * 1.0)) * 100;
        break;
    case 42:
        result = n1 * n2;
        break;
    case 43:
        result = n1 + n2;
        break;
    case 45:
        result = n1 - n2;
        break;
    case 47:
        result = n1 / n2;
        break;
    }
    return result;
}