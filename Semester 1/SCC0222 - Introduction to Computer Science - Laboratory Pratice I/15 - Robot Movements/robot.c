#include<stdio.h>
#include<stdlib.h>

#define BUFFER 4096
#define and &&
#define or ||

char *readline(FILE*);
int calculate_movement(char*);
void print_result(int);

int main(void){
    char *input = readline(stdin);
    print_result(calculate_movement(input));
    free(input);
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
    string[pos-1]= 0;
    string = (char*)realloc(string, pos * sizeof(char));
    return string;
}

int calculate_movement(char *input){
    int pos = 0;
    for(int i = 0; input[i] != 0; i++){
        switch (input[i]){
            case 68:
                pos = (pos + 1) % 4;
                break;
            case 69:
                pos = (pos - 1) % 4;
                break;
        }
    }
    return pos;
}

void print_result(int result){
    if(result == 0)
        printf("Norte\n");
    if(result == 1 or result == -3)
        printf("Leste\n");
    if(result == 2 or result == -2)
        printf("Sul\n");
    if(result == 3 or result == -1)
        printf("Oeste\n");
}