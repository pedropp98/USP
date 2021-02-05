#include<stdio.h>
#include<stdlib.h>

// Defining macro or and setting it to the or boolean condition
#define or ||

// Main function
int main(void){
    int n_prints, num1, num2;
    scanf("%d %d %d", &n_prints, &num1, &num2); // Reads 3 integers from stdin
    for(int i = 0, check_multiple = 0; i < n_prints; check_multiple++){ // Prints n_prints multiples from either num1 or num2
        if(check_multiple % num1 == 0 or check_multiple % num2 == 0){
            printf("%d\n", check_multiple);
            i++;
        }
    }
    return 0;
}