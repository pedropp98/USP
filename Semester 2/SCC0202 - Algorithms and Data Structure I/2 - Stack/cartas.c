#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include"cartas.h"

struct Stack{
    int top, max_size;
    int *cards;
};

void *create(int num){
    stack_t *variable = (stack_t*)malloc(sizeof(stack_t));
    assert(variable != NULL);
    variable->top = -1;
    variable->cards = (int*)malloc(num * sizeof(int));
    variable->max_size = num;
    return variable;
}

int push(stack_t *variable, int card){
    assert(variable != NULL);
    if(isFull(variable)) return -1;
    memcpy(&variable->cards[++variable->top], &card, sizeof(int));
    return 1;
}

int pop(stack_t *variable){
    assert(variable != NULL);
    if(isEmpty(variable)) return -1;
    int top_item = variable->cards[variable->top--];
    return top_item;
}

int top(stack_t *variable){
    assert(variable != NULL && !isEmpty(variable));
    return variable->cards[variable->top];
}

int isFull(stack_t *variable){
    assert(variable != NULL);
    if(variable->top == variable->max_size-1) return 1;
    return 0;
}

int isEmpty(stack_t *variable){
    assert(variable != NULL);
    if(variable->top == -1) return 1;
    return 0;
}

int size(stack_t *variable){
    return variable->top + 1;
}

void *empty(stack_t *var){
    free(var->cards);
    free(var);
}
