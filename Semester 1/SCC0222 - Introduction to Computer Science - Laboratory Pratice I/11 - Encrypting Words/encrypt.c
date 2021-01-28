#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Defining macros
#define BUFFER 4096
#define and &&

// Function definition
char *readline(FILE*);
int encrypt_and_find_char_in_string(char, char*);

// Main function
int main(void){
    char find_character = fgetc(stdin); // Reads the amount of sum to encrypt the string
    getchar(); // Reads the character 13, all the test case files contain it
    getchar(); // Reads the break line character
    char *string = readline(stdin); // Reads the line
    char *copy_string = (char*)malloc((strlen(string)+1)* sizeof(char)); 
    strcpy(copy_string, string); // Copies the line read, to keep the original string intact
    int num = encrypt_and_find_char_in_string(find_character, string); // Encrypts the string
    printf("Numero de trocas: %d\nNova palavra: %s\nPalavra original: %s\n", num, string, copy_string);
    free(string);
    free(copy_string);
    return 0;
}

// Reads a FILE* and returns a char* containing all the characters in a determined line. It stops reading when it find the break line character or it reaches the end of the file
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

// It applies the encrypting algotirthm asked in the exercise, changing all the characters in a determined string, all the character must remain in lower case
int encrypt_and_find_char_in_string(char character, char *string){
    int found_char = 0;
    for(int i = 0; string[i] != 0; i++){
        if(string[i] == character){
            int sum = string[i] + i;
            sum > 122 ? (string[i] = sum - 26) : (string[i] = sum);
            found_char++;
        }
    }
    return found_char;
}