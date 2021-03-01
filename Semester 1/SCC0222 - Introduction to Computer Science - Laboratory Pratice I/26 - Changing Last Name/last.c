#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFFER 4096
#define and &&

typedef struct{
    char **names;
    int qtd_names;
}names_t;

char *readline(FILE*);
char *my_strtok(char*, const char*);
names_t **input_names(int*);
void change_last_names(names_t**, int);
void print_result(names_t**, int);
void free_memory(names_t**, int);

int main(void){
    char *read_name;
    int i = 0;
    names_t **name = input_names(&i);
    change_last_names(name, i);
    print_result(name, i);
    free_memory(name, i);
}

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

names_t **input_names(int *i){
    int side_i = *i;
    names_t **name = NULL;
    for(side_i = 0; !feof(stdin); side_i++){
        name = (names_t**)realloc(name, (side_i+1) * sizeof(names_t*));
        name[side_i] = (names_t*)malloc(sizeof(names_t));
        name[side_i]->qtd_names = 0;
        name[side_i]->names = (char**)malloc((name[side_i]->qtd_names+1) * sizeof(char*));
        name[side_i]->names[name[side_i]->qtd_names++] = my_strtok(readline(stdin), " ");
        while(name[side_i]->names[name[side_i]->qtd_names-1] != NULL){
            name[side_i]->names = (char**)realloc(name[side_i]->names, (name[side_i]->qtd_names+1) * sizeof(char*));
            name[side_i]->names[name[side_i]->qtd_names++] = my_strtok(NULL, " ");
        }
        name[side_i]->qtd_names--;
    }
    *i = side_i;
    return name;
}

void change_last_names(names_t **name, int i){
    for(int j = 0, k = i-1; j <= i / 2 and k >= i / 2; j++, k--){
        char *copy = name[j]->names[name[j]->qtd_names-1];
        name[j]->names[name[j]->qtd_names-1] = name[k]->names[name[k]->qtd_names-1];
        name[k]->names[name[k]->qtd_names-1] = copy;
    }
}

void print_result(names_t **name, int i){
    for(int j = 0; j < i; j++){
        for(int k = 0; k < name[j]->qtd_names; k++){
            printf("%s ", name[j]->names[k]);
        }
        printf("\n");
    }
}

void free_memory(names_t **name, int i){
    for(int j = 0; j < i; j++){
        free(name[j]->names[0]);
        free(name[j]->names);
        free(name[j]);
    }
    free(name);
}