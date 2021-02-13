#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Defining macros to use in the program
#define BUFFER 4096
#define and &&

// Function definition
int stringcompare(const char*, const char*);
char *readline(FILE*);
char *replacestring(char*, char*, char*, int*);

// Main function
int main(void){
    char *word = readline(stdin); // Reads the word to be found from stdin
    char *phrase = readline(stdin); // Reads the phrase from stdin
    int count = 0; // Stores the amount of timesword occurs in phrase
    char *change = replacestring(phrase, word, "", &count); // Stores the replaced string in phrase
    printf("A palavra tabu foi encontrada %d vezes\n", count);
    printf("Frase: %s\n", change);
    // Deallocates memory allocated for the 3 char*
    free(word);
    free(phrase);
    free(change);
    return 0;
}

// Reads a text line from a FILE*, stores every character, but carriage return (13 in ASCII) and '$' (36 in ASCII) from this line into a char*
// Character 36 is not stored in this program because it represents the last readable character, so it should be disonsidered, but as my readline function goes all the way until the of the file, I found better just to adapt it to not store character 36
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

// Compares STR1 with STR2, returns 1 if STR1 comes first in the alphabet, -1 if STR2 comes first and 0 if they're equal
int stringcompare(const char *STR1, const char *STR2){
    for(; *STR1 != 0 and *STR2 != 0; STR1++, STR2++){
        if(*STR1 > *STR2)
            return 1;
        if(*STR1 < *STR2)
            return -1;
    }
    int size1 = strlen(STR1), size2 = strlen(STR2);
    if(size1 > size2)
        return -1;
    if(size1 < size2)
        return 1;
    return 0;
}

// Finds every time str2 occurs in str1 and replaces it with str3, count stores the times str2 is found in str1
char *replacestring(char *str1, char *str2, char *str3, int *count){
    char *return_string = NULL;
    char *rest_string = str1;
    char *temporary = NULL;
    int len_str1 = strlen(str1), len_str2 = strlen(str2), len_str3 = strlen(str3), 
        counter = 0, distance = 0;

    //Saving the string after the part needing substitution, for future use
    for(*counter = 0; temporary = strstr(rest_string, str2); counter++)
        rest_string = temporary + len_str2;
    *count = counter;
    temporary = return_string = (char*)malloc((len_str1 + (len_str3 - len_str2)
                                                * counter + 1) * sizeof(char));
        

    while(counter > 0){
        rest_string = strstr(str1, str2);
        distance = rest_string - str1;
        temporary = strncpy(temporary, str1, distance) + distance;      //copy of distance bytes from str1 to temporary, + distance sets the current temporary position to distance
        temporary = strcpy(temporary, str3) + len_str3;                 //copy the str3 to temporary from distance position, + len_str3 sets the current position to (distance + str_len3)
        str1 += distance + len_str2;                                    //sets the current position in str1 to be distance + len_str3
        counter--;
    }
    strcpy(temporary, str1);
    return return_string;
}