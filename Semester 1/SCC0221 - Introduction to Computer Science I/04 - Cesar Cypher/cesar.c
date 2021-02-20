#include<stdio.h>
#include<stdlib.h>

// Defining macros to use in the program
#define BUFFER 4096
#define and &&
#define or ||

// Defning a pointer to function
typedef int (*__math_op__)(int, int);

// Function definition
char *readline(FILE*);
void cesar_cypher(char*, int, __math_op__);
int encrypt(int, int);
int decrypt(int, int);

// Main function
int main(void){
    int operation, key;
    scanf("%d %d", &operation, &key);
    while(getchar() != 10);
    char *input = readline(stdin);
    // operation 1 realizes encrypts, operation 2 decrypts
    switch(operation){
        case 1:
            cesar_cypher(input, key, encrypt);
            break;
        case 2:
            cesar_cypher(input, key, decrypt);
            break;
    }
    printf("%s\n", input);
    // Deallocates memory allocated in the program
    free(input);
    free(operation_input);
    free(key_input);
    return 0;
}

// Reads a text line from a FILE*, stores every character in a char* and returns it as a string
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

// Receives the message to be as a char* input, the key to be used and the pointer to function to either encrypts or decrypts the input char*
void cesar_cypher(char *input, int key, __math_op__ function){
    for(int i = 0; input[i] != 0; i++){
        input[i] = function(input[i], key);
    }
}

// Encrypts each character using key
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

// Decrypts each character using the key
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