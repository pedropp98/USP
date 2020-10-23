#include<stdlib.h>
#include<stdio.h>
#include"pepelib.h"
#include"list.h"

int input_integer();
list_t *create_list(int);
void print_result(int, int);

int main(int argc, char** argv){
    int test_cases = input_integer();
    for(int i = 0; i < test_cases; i++){
        int integer_n = input_integer();
        int integer_k = input_integer();
        list_t *list = create_list(integer_n);
        node_t *node = NULL;
        int item = item_in_position(list, josephus(integer_n, integer_k));   
        print_result(i+1, item);
        erase(list);
    }
    return 0;
}

//Reads an integer from stdin an returns it
int input_integer(){
    int integer;
    scanf("%d", &integer);
    return integer;
}

//Creates the list and inserts the values into it
list_t *create_list(int n){
    list_t *list = create();
    for(int i = 0; i < n; i++){
        insert(list, i+1);
    }
    return list;
}

//Prints the result from a test_case
void print_result(int test_case, int item){
    printf("Caso %d: %d\n", test_case, item);
}