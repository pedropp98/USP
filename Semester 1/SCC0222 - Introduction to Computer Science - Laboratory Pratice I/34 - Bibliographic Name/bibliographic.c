#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// Defining macros to use in the program
#define BUFFER 4096
#define and &&

// Creating a new type name_t to store the names and its amount
typedef struct{
    char **names;
    int q_names;
}name_t;

// Function definition
char *readline(FILE*);
name_t *create_name(char*);
void erase_name(name_t*);
void print_bibliographic(name_t*);
char *my_strtok(char*, const char*);

// Main function
int main(void){
    char *input_name = readline(stdin);  
    name_t *name = create_name(input_name);
    print_bibliographic(name);
    erase_name(name);
    free(input_name);
    return 0;
}

// Reads a text line from FILE*, stores the characters into a char* and returns it. It stops when it finds a break line character or it reaches the end of the file
char *readline(FILE *in){
    char *string = NULL;
    int pos = 0, character;
    do{
        if(pos % BUFFER == 0)
            string = (char*)realloc(string, (pos / BUFFER + 1) * BUFFER * sizeof(char));
        character = fgetc(in);
        if(character != 13)
            string[pos++] = character;
    }while(character != 10 and !feof(in));
    string[pos-1] = 0;
    string = (char*)realloc(string, pos * sizeof(char));
    return string;
}

// Allocates space for a name_t and split input_name in the space character, splitting the names and storing them into the name_type
name_t *create_name(char *input_name){
    name_t *name = (name_t*)malloc(sizeof(name_t));
    name->q_names = 0;
    name->names = (char**)malloc(sizeof(char*));
    name->names[name->q_names++] = my_strtok(input_name, " ");
    while(name->names[name->q_names-1] != NULL){
        name->names = (char**)realloc(name->names, (name->q_names+1) * sizeof(char*));
        name->names[name->q_names++] = my_strtok(NULL, " ");
    }
    name->q_names--; // The last stored name is NULL
    return name;
}

// Deallocates memory allocated for the name_t type
void erase_name(name_t *name){
    free(name->names);
    free(name);
}

// Works similarly as strtok from string.h library
char *my_strtok(char *string, const char *delimiter){
    static char *buffer;
    if(string != NULL)
        buffer = string;
    if(buffer[0] == 0)
        return NULL;
    char *return_string = buffer, *copy_buffer;
    const char *COPY_DELIM;
    for(copy_buffer = buffer; *copy_buffer != 0; copy_buffer++){
        for(COPY_DELIM = delimiter; *COPY_DELIM != 0; COPY_DELIM++){
            if(*copy_buffer == *COPY_DELIM){
                *copy_buffer = 0;
                buffer = copy_buffer+1;
                if(copy_buffer == return_string){
                    return_string++;
                    continue;
                }
                return return_string;
            }
        }
    }
    buffer = copy_buffer;
    return return_string;
}

// Sets every character from the last name to upper case letters, prints it, then prints the rest of the name, as it is in a bibliographic reference
void print_bibliographic(name_t *name){
    for(int i = 0; name->names[name->q_names-1][i] != 0; i++){
        name->names[name->q_names-1][i] = toupper(name->names[name->q_names-1][i]);
    }
    printf("%s, ", name->names[name->q_names-1]);
    for(int i = 0; i < name->q_names-1; i++){
        printf("%s ", name->names[i]);
    }
    printf("\n");
}