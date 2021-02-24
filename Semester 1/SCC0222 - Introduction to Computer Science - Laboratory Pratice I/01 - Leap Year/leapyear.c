#include<stdio.h>
#include<stdlib.h>

// Main function
int main(void){
    int year;
    scanf("%d", &year);
    (year % 4 == 0) ? printf("SIM\n") : printf("NAO\n"); // Ternary operator
    return 0;
}