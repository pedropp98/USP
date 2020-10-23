#ifndef CARTAS_H
#define CARTAS_H

typedef struct Stack stack_t;

void *create(int num);
int push(stack_t *variable, int card);
int pop(stack_t *variable);
int top(stack_t *varible);
int size(stack_t *variable);
void *empty(stack_t *var);
int isFull(stack_t *variable);
int isEmpty(stack_t *variable);


#endif