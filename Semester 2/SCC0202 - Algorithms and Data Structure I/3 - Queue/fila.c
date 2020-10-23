#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include"pepelib.h"
#include"fila.h"

queue_t *create(int size){
    queue_t *q = (queue_t*)malloc(sizeof(queue_t));
    assert(q != NULL);
    q->begin = 0;
    q->end = 0;
    q->total = size;
    q->elements = (people_t*)calloc(size, sizeof(people_t));
    return q;
}

int insert(queue_t *q, people_t x){
    assert(q != NULL);
    if(isfull(q)) return 0;
    int position = q->end-1;
    //printf("1 - nameQ: %s priorityQ: %d nameX: %s priorityX: %d\n", q->elements[q->begin].name, q->elements[q->begin].priority, x.name,x.priority);
    while(position >= q->begin && x.priority < q->elements[position].priority){
        q->elements[position+1] = q->elements[position];
        position--;
    }
    
    position++;
    q->elements[position].name = (char*)malloc((strlen(x.name)+1) * sizeof(char));
    strcpy(q->elements[position].name, x.name);
    //q->elements[q->end].name = x.name;
    q->elements[position].age = x.age;
    q->elements[position].priority = x.priority;
    q->elements[position].health_condition = x.health_condition;
    q->end++;
    //printf("2 - pos: %d begin: %d name: %s\n", position, q->begin, q->elements[q->begin].name);
    return 1;
}

int pop(queue_t *q, people_t *x){
    if(isempty(q)) return 0;
    //printf("begin: %d\n", q->begin);
    *x = q->elements[q->begin];
    q->begin = (q->begin+1) % q->total;
    return 0;
}

int front(queue_t *q, people_t *x){
    if(isempty(q)) return 0;
    *x = q->elements[q->begin];
    //printf("name: %s age: %d health: %d priority: %d\n", q->elements[q->begin].name, q->elements[q->begin].age, q->elements[q->begin].health_condition, q->elements[q->begin].priority);
    return 0;
}

int isempty(queue_t *q){
    assert(q != NULL);
    if(q->end == q->begin) return 1;
    return 0;
}

int isfull(queue_t *q){
    assert(q != NULL);
    if(q->begin == ((q->end+1) % q->total)) return 1;
    return 0;
}

void destroy(queue_t *q){
    for(int i = 0; i < q->total; i++){
        free(q->elements[i].name);
    }
    free(q->elements);
    free(q);
    return;
}

