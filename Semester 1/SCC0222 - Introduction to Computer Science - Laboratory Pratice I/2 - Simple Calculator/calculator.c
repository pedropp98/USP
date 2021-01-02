#include<stdio.h>
#include<stdlib.h>

double operation(double, int);

int main(void){
    double a, b;
    int op;
    scanf("%lf %d %lf", &a, &op, &b);
    printf("%lf", operation(a, b, op));
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