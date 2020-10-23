#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include"pepelib.h"
#include"list.h"

struct node{
    int item;
    node_t *next;
};

struct list{
    node_t *begin, *end;
    int size;
};

list_t *create(){
    list_t *l = (list_t*)malloc(sizeof(list_t));
    assert(l != NULL);
    l->begin = NULL;
    l->end = NULL;
    l->size = 0;
    return l;
}

void insert(list_t *l, int i){
    assert(l != NULL);
    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    new_node->item = i;
    new_node->next = NULL;
    if(l->begin == NULL){
        l->begin = new_node;
        l->end = new_node;
    }
    else{
        l->end->next = new_node;
        l->end = new_node;
        l->end->next = l->begin;
    }
    l->size++;
}

int size(list_t *l){
    assert(l != NULL);
    return l->size;
}

void print(list_t *l){
    assert(l != NULL);
    node_t *n = l->begin;
    for(int i = 0; i < l->size; i++){
        printf("%d ", n->item);
        n = n->next;
    }
}

boolean_t is_in_list(list_t *l, int item){
    assert(l != NULL);
    node_t *n = l->begin;
    while(n != NULL){
        if(n->item == item){
            return true;
        }
        n = n->next;
    }
    return false;
}

boolean_t remove_list(list_t *l, int item){
    assert(l != NULL);
    node_t *node = l->begin;
    node_t *previous_node = NULL;
    
    for(int i = 0; i < l->size; i++){
        if(item == node->item){
            if(node == l->begin){
                l->begin = l->begin->next;
                l->end->next = l->begin;
            }
            else if(node == l->end){
                l->end = previous_node;
                l->end->next = l->begin;
            }
            else{
                previous_node->next = node->next;
            }
            l->size--;
            free(node);
            return true;
        }
        else{
            previous_node = node;
            node = node->next;
        }
    }
    
    return false;
}

int josephus(int n, int k){
    if(n == 1)
        return 1;
    return (josephus(n-1, k) + k-1) % n+1;
}

int item_in_position(list_t *l, int position){
    node_t *node = l->begin;
    for(int i = 1; i < position; i++){
        node = node->next;
    }
    return node->item;
}

void erase(list_t *l){
    if(l != NULL){
        node_t *n = l->begin;
        for(int i = 0; i < l->size; i++){
            l->begin = n->next;
            free(n);
            n = l->begin;
        }
        free(l);
    }
}
