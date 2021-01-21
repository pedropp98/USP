#include<stdio.h>
#include<stdlib.h>

#define BUFFER 4096

#define and &&
#define or ||

typedef int (__math_op__)(int, int);

char *readline(FILE*);
void cesar_cypher(char*, int, __math_op__);
int encrypt(int, int);
int decrypt(int, int);

int main(void){
    char *operation_input, *key_input;
    operation_input = readline(stdin);
    key_input = readline(stdin);
    int operation, key;
    operation = atoi(operation_input);
    key = atoi(key_input);
    char *input = readline(stdin);
    // printf("%s\n", input);
    switch(operation){
        case 1:
            cesar_cypher(input, key, encrypt);
            break;
        case 2:
            cesar_cypher(input, key, decrypt);
            break;
    }
    printf("%s\n", input);
    free(input);
    free(operation_input);
    free(key_input);
    return 0;
}

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

void cesar_cypher(char *input, int key, __math_op__ function){
    for(int i = 0; input[i] != 0; i++){
        input[i] = function(input[i], key);
    }
}

int encrypt(int character, int key){
    int e = character + key;
    if(character >= 32 and character <= 64)
        return character;
    if(character >= 65 and character <= 90)
        while(e > 90)
            e -= 26;
    if(character >= 97 and character <= 122)
        while(e > 122)
            e -= 26;
    return e;
}

int decrypt(int character, int key){
    int e = character - key;
    if(character >= 32 and character <= 64)
        return character;
    if(character >= 65 and character <= 90) 
        while(e < 65)
            e += 26;    
    if(character >= 97 and character <= 122)
        while(e < 97)
            e += 26;
    return e;
}