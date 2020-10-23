#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"pepelib.h"
#include"fila.h"

//Sets priority to be placed on the queue
int setpriority(int age, int health_condition);

//Chcks if the queues are empty, if not pop from the right queue
void check_emptiness_or_pop(queue_t*);

//Inserts into the right queue
void insert_main(queue_t*);

//Function main
int main(int argc, char **argv){
    char *char_action = readword(stdin);
    int actions = atoi(char_action);
    free(char_action);

    //Creating a queue
    queue_t *queue = create(actions);

    for(int i = 0; i < actions; i++){
        char *operation = readword(stdin);
        if(strstr(operation, "SAI") != NULL){
            check_emptiness_or_pop(queue);
        }
        else{
            if(isfull(queue)) printf("FILA CHEIA");
            else insert_main(queue);
        }
        free(operation);
    }
    destroy(queue);
    
    return 0;
}

int setpriority(int age, int health_condition){
    int priority = 0;
    if(age >= 60 && health_condition == 1) priority = 1;
    else if(health_condition == 1) priority = 2;
    else if(age >= 60) priority = 3;
    else priority = 4;
    return priority;
}

void check_emptiness_or_pop(queue_t *queue){
    people_t person;
    if(isempty(queue)) printf("FILA VAZIA\n");
    else{
        if(!isempty(queue)) pop(queue, &person);
        printf("%s %d %d\n", person.name, person.age, person.health_condition);
    }
    return;
}

void insert_main(queue_t *queue){
    people_t person;
    char *name = readword(stdin);            
    person.name = (char*)malloc((strlen(name)+1) * sizeof(char));
    strcpy(person.name, name);
    free(name);
    char *age = readword(stdin);
    person.age = atoi(age);
    free(age);
    char *health_condition = readword(stdin);
    person.health_condition = atoi(health_condition);
    free(health_condition);
    person.priority = setpriority(person.age, person.health_condition);
    insert(queue, person);
    free(person.name);
    return;
}