#include<stdio.h>
#include<stdlib.h>

void factorization(int);

int main(void){
    int number;
    scanf("%d", &number);
    factorization(number);
    return 0;
}

void factorization(int number){
    for(int i = 2; i <= number; i++){
        if(number % i == 0){
            int count = 0;
            while(number % i == 0){
                count++;
                number /= i;
            }
            printf("%d %d\n", i, count);
        }
    }
}