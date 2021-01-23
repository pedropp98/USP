#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void){
    double num, float_part;
    int integer;
    scanf("%lf", &num); // Reads a number from stdin
    integer = (int)num / 1; // Gets its integer part from the division by 1
    float_part = num - integer; // Gets its floating point part subtracting the integer part from the original number
    //Prints the result
    printf("%d\n", integer);
    printf("%.4lf\n", float_part);
    printf("%.0lf\n", round(num));
    return 0;
}