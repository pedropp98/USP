#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define BUFFER 4096

char *readline(FILE*);
int binary_to_decimal(char*);
int string_len(char*);

int main(void){
    char *binary = readline(stdin);
    printf("%d\n", binary_to_decimal(binary));
    free(binary);
    return 0;
}

char *readline(FILE *in){
    char *string = NULL;
    int character, pos = 0;
    do{
        if(pos % BUFFER == 0)
            string = (char*)realloc(string, ((pos / BUFFER) + 1) * BUFFER * sizeof(char));
        character = fgetc(in);
        if(character != 13)
            string[pos++] = character;
    }while(character != 10 && !feof(in));
    string[pos-1] = 0;
    string = (char*)realloc(string, pos * sizeof(char));
    return string;
}

int string_len(char *string){
    int size = 0;
    for(size = 0; string[size] != 0; size++);
    return size; 
}

int binary_to_decimal(char *binary){
    int size = string_len(binary), integer = 0;
    for(int i = size-1, j = 0; i >= 0; i--, j++){
        integer += (binary[i] - 48) * pow(2, j);
    }
    return integer;
}