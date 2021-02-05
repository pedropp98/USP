#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Defining macros to use in the program
#define BUFFER 4096 // Used in readline function
#define and && // Used to substitute and boolean condition, to improve understanding in the code

// Defining a new type names_t to store all the names and the amount of them
typedef struct{
    char **names;
    int q_names;
}names_t;

// Defining a new type boolean_t to work with boolean values true or false
typedef enum{
    false, true
}boolean_t;

// Defining a new pointer to function __compare_function__ type, that returns an integer
typedef int(*__compare_function__)(void*, int, int);

// Function definition
names_t *read_names(FILE*);
char *readline(FILE*);
int string_compare(char*, char*);
int access_data_str(void*, int, int);
void erase_names(names_t*);
void bubblesort(void*, int, __compare_function__);
void print_names(names_t*);
void change_position(void*, int, int);

// Main function
int main(void){
    names_t *names = read_names(stdin);
    bubblesort(names, names->q_names, access_data_str);
    print_names(names);
    erase_names(names);
    return 0;
}

// // Reads an entire string line from a FILE*. It allocates space for a char* and stores every character read in it. It stops when it reaches a break line character or the end of the file
char *readline(FILE *in){
    char *string = NULL;
    int pos = 0, character;
    do{
        if(pos % BUFFER == 0)
            string = (char*)realloc(string, (pos / BUFFER + 1) * BUFFER * sizeof(char));
        character = fgetc(in);
        if(character != 13 and character != 0)
            string[pos++] = character;
    }while(character != 10 and !feof(in));
    string[pos-1] = 0;
    string = (char*)realloc(string, pos * sizeof(char));
    return string;
}

// Stores every singles name read in the FILE* into a names_t, gets rid of the last one, 'cause in the exercise the last name read in the FILE* was an character '0'
names_t *read_names(FILE *in){
    names_t *names = (names_t*)malloc(sizeof(names_t));
    names->names = NULL;
    names->q_names = 0;
    while(!feof(in)){
        names->q_names++;
        names->names = (char**)realloc(names->names, names->q_names * sizeof(char*));
        names->names[names->q_names-1] = readline(in);
    }
    free(names->names[names->q_names-1]);
    names->q_names--;
    return names;
}

// Deallocates memory allocated for a names_t type
void erase_names(names_t *names){
    for(int i = 0; i < names->q_names; i++){
        free(names->names[i]);
    }
    free(names->names);
    free(names);
}

// Compares str1 with str2. If str1 comes first in the alfabet, it returns 1, if str2 comes first it returns 2. It returns 0 if both char* are equal
int string_compare(char *str1, char *str2){
    int size1 = strlen(str1), size2 = strlen(str2);
    for(int i = 0; i < size1 and i < size2; i++){
        if(str1[i] > str2[i])
            return 1;
        else if(str1[i] < str2[i])
            return -1;
    }
    if(size1 > size2)
        return 1;
    else if(size1 < size2)
        return -1;
    return 0;
}

// Sorts an array with q_items items comparing them in the function using bubblesort logic
void bubblesort(void *array, int q_items, __compare_function__ function){
    boolean_t swap = true;
    int begin = 0;
    while(swap){
        swap = false;      
        for(int i = 0; i < q_items-1; i++){
            if(function(array, i, i+1) > 0){
                change_position(array, i, i+1);
                swap = true;
            }
        }
    }
}

// Prints all the names stored in the names_t
void print_names(names_t *names){
    for(int i = 0; i < names->q_names; i++){
        printf("%s\n", names->names[i]);
    }
}

// Used as a auxiliar function to work with bubblesort, it access char* data in the names_t and returns the comparison between the char* in pos1 with char* in pos2
int access_data_str(void *m1, int pos1, int pos2){
    names_t *n1 = m1;
    return string_compare(n1->names[pos1], n1->names[pos2]);
}

// Changes the position of char* if they need to change in order to be sorted
void change_position(void *array, int pos1, int pos2){
    names_t *n = array;
    int size1 = strlen(n->names[pos1]), size2 = strlen(n->names[pos2]);
    void *data = malloc(size1+1);
    memcpy(data, n->names[pos1], size1+1);
    n->names[pos1] = (char*)realloc(n->names[pos1], (size2+1));
    memcpy(n->names[pos1], n->names[pos2], size2+1);
    n->names[pos2] = (char*)realloc(n->names[pos2], size1+1);
    memcpy(n->names[pos2], data, size1+1);
    free(data);
}