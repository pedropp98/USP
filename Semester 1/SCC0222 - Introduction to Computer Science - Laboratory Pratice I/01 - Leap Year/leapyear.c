#include<stdio.h>
#include<stdlib.h>

int main(void){
    int year;
    scanf("%d", &year);
    if(year % 4 == 0)
        printf("SIM\n");
    else
        printf("NAO\n");
}