#include<stdio.h>
#include<stdlib.h>

int *change(int);
int subtraction_lopp(int*, int);
void print_result(int*);

int main(void){
    int input_value;
    scanf("%d", &input_value);
    int *coins = change(input_value);
    print_result(coins);
    free(coins);    
    return 0;
}

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

int subtraction_lopp(int *number, int subtrator){
    int quantity = 0;
    while(*number >= subtrator){
        quantity++;
        *number = *number - subtrator;
    }
    return quantity;
}

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