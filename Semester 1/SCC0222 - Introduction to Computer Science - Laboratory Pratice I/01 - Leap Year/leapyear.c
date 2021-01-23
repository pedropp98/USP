#include<stdio.h>
#include<stdlib.h>

// Main function
int main(void){
    int year;
    scanf("%d", &year);
    if(year % 4 == 0) // If the remainder of year by 4 is 0, then year is a leap year
        printf("SIM\n");
    else
        printf("NAO\n");
    return 0;
}