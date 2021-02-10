#include<stdio.h>
#include<stdlib.h>

// Function definition
int *change(int);
int subtraction_lopp(int*, int);
void print_result(int*);

// Main function
int main(void){
    int input_value;
    scanf("%d", &input_value);
    int *coins = change(input_value);
    print_result(coins);
    free(coins);    
    return 0;
}

// Calculates how many coins is possible to return from value cents
int *change(int value){
    int *coins = (int*)calloc(6, sizeof(int));
    coins[0] = subtraction_lopp(&value, 100);
    coins[1] = subtraction_lopp(&value, 50);
    coins[2] = subtraction_lopp(&value, 25);
    coins[3] = subtraction_lopp(&value, 10);
    coins[4] = subtraction_lopp(&value, 5);
    coins[5] = value;
    return coins;
}

// Subtracts subtractor from number until it number is less than or equal to subtractor. Number is passed by reference, so its value change where it came from. It returns the amount of times the loop executed
int subtraction_lopp(int *number, int subtractor){
    int quantity = 0;
    while(*number >= subtractor){
        quantity++;
        *number = *number - subtractor;
    }
    return quantity;
}

// Prints the result as asked in teh statement
void print_result(int *coins){
    for(int i = 0; i < 6; i++){
        printf("O valor consiste em %d moedas de ", coins[i]);
        if(i == 0)
            printf("1 real\n");
        else if(i == 1)
            printf("50 centavos\n");
        else if(i == 2)
            printf("25 centavos\n");
        else if(i == 3)
            printf("10 centavos\n");
        else if(i == 4)
            printf("5 centavos\n");
        else
            printf("1 centavo\n");
    }
}