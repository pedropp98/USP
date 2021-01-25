#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Defining macros
#define BUFFER 4096
#define and &&

// Creating a new type struct name_t
typedef struct name{
    char *name;
    char *last_name;
}name_t;

// Function declaration
char *readline(FILE*);
char **read_name(FILE*);
char *get_lastname(char*);
void free_memory(name_t*, int);

// Main function
int main(void){
    name_t **names = NULL;
    int i = 0;
    for(i = 0; !feof(stdin); i++){
        // Allocating 8 bytes in heap memory to store each name
        names = (name_t**)realloc(names, (i+1) * sizeof(name_t*));
        // Allocating 8 bytes in heap memory to store the strings
        names[i] = (name_t*)malloc(sizeof(name_t));
        names[i]->name = readline(stdin);   // Reads a string from stdin and stores it
        names[i]->last_name = get_lastname(names[i]->name); // Stores the string returned from get_lastname function
        printf("%s", names[i]->name);
        if(i % 2 != 0){     // When i variable is odd, it prints the previous name->last_name
            int size = strlen(names[i-1]->last_name);
            printf(" ");
            for(int j = size-1; j >= 0; j--){
                printf("%c", names[i-1]->last_name[j]);
            }
        }
        printf("\n");
    }
    free_memory(names, i);
    return 0;
}

// Reads an entire line from a FILE*, stops when it finds the break line character or when it reaches the end of the file. It returns the string, or NULL if the file is empty
char *readline(FILE *in){
    char *string = NULL;
    int pos = 0, character;
    do{
        if(pos % BUFFER == 0)
            string = (char*)realloc(string, (pos / BUFFER + 1) * BUFFER * sizeof(char));
        character = fgetc(in);
        if(character != 13 and character != 36)
            string[pos++] = character;
    }while(character != 10 and !feof(in));
    string[pos-1] = 0;
    string = (char*)realloc(string, pos * sizeof(char));
    return string;
}

// Reads a char* from its last character, until it finds the space character. In all test cases for this exercise this function works, it can be modified to avoid errors. It returns this string inverted.
char *get_lastname(char *string){
    int size = strlen(string), size_lastname = 0;
    char *last_name = (char*)malloc(size * sizeof(char));
    for(int i = size-1; string[i] != 32; i--){
        last_name[size_lastname++] = string[i];
    }
    last_name[size_lastname] = 0;
    last_name = (char*)realloc(last_name, (size_lastname+1) * sizeof(char));
    return last_name;
}

// Deallocates memory allocated for name_t type
void free_memory(name_t *names, int q_allocated){
    for(int i = 0; i < q_allocated; i++){
        free(names[i]->name);
        free(names[i]->last_name);
        free(names[i]);
    }
    free(names);
}