#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void){
    double num;
    scanf("%lf", &num); // Reads a number from stdin
    //Prints the result
    printf("%d\n", (int)num); // Prints its integer part
    printf("%.4lf\n", num - (int)num); // Prints its decimal part
    printf("%.0lf\n", round(num)); // Rounds the number, using round function from math.h
    return 0;
}