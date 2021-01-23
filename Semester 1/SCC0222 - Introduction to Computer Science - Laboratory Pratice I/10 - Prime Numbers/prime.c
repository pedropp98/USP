#include<stdio.h>
#include<stdlib.h>

// Function definition
void factorization(int);

// Main function
int main(void){
    int number;
    scanf("%d", &number);
    factorization(number);
    return 0;
}

// Function declaration
//It factores a number and prints the result
void factorization(int number){
    for(int i = 2; i <= number; i++){
        if(number % i == 0){
            int count = 0;
            while(number % i == 0){
                count++; // Adding 1 to count every single time number is divided by i
                number /= i;
            }
            printf("%d %d\n", i, count);
        }
    }
}