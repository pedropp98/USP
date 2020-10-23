#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"cartas.h"

int *inputnumbers();
int calculaterounds(stack_t*, stack_t*, int);

int main(int argc, char **argv){
    int n_cards = 0;
    scanf("%d", &n_cards);
    int *input_numbers = inputnumbers(n_cards);
    stack_t *next= (stack_t*)create(n_cards);
    stack_t *buy = (stack_t*)create(n_cards);
    for(int i = n_cards; i > 0; i--){
        push(buy, input_numbers[i-1]);
        push(next, i);
    }
    free(input_numbers);
    printf("%d\n", calculaterounds(buy, next, n_cards));
    empty(next);
    empty(buy);
    return 0;
}

//this function is supposed to help, since I understood the program diferently than it really is
//it stores the numbers into a vector, so i can push it backwards to the buy deck
int *inputnumbers(int n){
    int *input = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d ", &input[i]);
    }
    return input;
}

//calculate the numebr of rounds needed to move all the cards to the discard deck
int calculaterounds(stack_t *buy, stack_t *next, int n_cards){
    stack_t *discard = (stack_t*)create(n_cards);
    stack_t *death = (stack_t*)create(n_cards);
    int rounds = 0;
    while(!isFull(discard)){
        for(int i = 0; i < n_cards && !isFull(discard) && !isEmpty(buy); i++){
            int top_buy = top(buy);
            if(top_buy == top(next)){ //it'll place the top card from the buy deck into the discard deck. The new card will be the next one in the next deck
                pop(next);
                push(discard, top_buy);
            }
            else{ //it'll place the top card from the buy deck into the death deck
                push(death, top_buy);
            }
            pop(buy); //it'll pop the top card from the buy deck
        }
        for(int i = 0; i < n_cards && !isEmpty(death); i++){ //it'll push the items in the death deck, popping them form there after
            push(buy, top(death));
            pop(death);
        }
        rounds++;
    }
    empty(death);
    empty(discard);
    return rounds;
}    