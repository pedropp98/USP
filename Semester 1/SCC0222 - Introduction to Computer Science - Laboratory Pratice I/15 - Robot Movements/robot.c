#include<stdio.h>
#include<stdlib.h>

// Defining macros to use in the program
#define BUFFER 4096
#define and &&
#define or ||

// Function definition
char *readline(FILE*);
int calculate_movement(char*);
void print_result(int);

// Main function
int main(void){
    char *input = readline(stdin);
    print_result(calculate_movement(input));
    free(input);
    return 0;
}

// Reads an entire string line from a FILE*. It allocates space for a char* and stores every character read in it. It stops when it reaches a break line character or the end of the file
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

// Calculates the movements of the robot based on the input string. Since there are 4 positions (North, South, East and West), the program will calculate which side the robot will be facing in the end
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

// Prints the final position based on what's returned from calculate_movement function
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