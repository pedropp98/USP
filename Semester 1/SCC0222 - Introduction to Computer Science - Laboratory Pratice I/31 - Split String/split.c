#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// Defining macros to use in the code
#define BUFFER 4096
#define and &&

// Defining a new type words_t to store the splitted words and its amount
typedef struct{
    char **splitted;
    int q_words;
}words_t;

// Defining a new type boolean_t to work with boolean
typedef enum{
    false, true
}boolean_t;

// Function definition
char *readline(FILE*);
words_t *split_word(char*, char);
void erase_words(words_t*);
void bubblesort(char**, int);
int string_compare(char*, char*);
void operate(words_t*, int);

// Main function
int main(void){
    char *input_line = readline(stdin);
    int operation;
    scanf("%d", &operation);
    words_t *splitted = split_word(input_line, 32);
    operate(splitted, operation);
    free(input_line);
    erase_words(splitted);
    return 0;
}

// Reads a character line from a FILE*, store it into a char* and returns it
char *readline(FILE *in){
    char *string = NULL;
    int pos = 0, character;
    do{
        if(pos % BUFFER == 0)
            string = (char*)realloc(string, (pos / BUFFER + 1) * BUFFER * sizeof(char));
        character = fgetc(in);
        if(character != 13)
            string[pos++] = tolower(character);
    }while(character != 10 and !feof(in));
    string[pos-1] = 0;
    string = (char*)realloc(string, pos * sizeof(char));
    return string;
}

// Creates a word_t space in heap memory and stores every words from the string separated by the split_character, it counts how many words are found and stores it too into the words_t
words_t *split_word(char *string, char split_character){
    words_t *split = (words_t*)malloc(sizeof(words_t));
    split->splitted = (char**)malloc(sizeof(char*));
    split->splitted[0] = NULL;
    split->q_words = 0;
    int len = 0;
    for(int i = 0; string[i] != 0; i++){
        if(string[i] == split_character){
            split->q_words++;
            len = 0;
            split->splitted = (char**)realloc(split->splitted, (split->q_words+1) * sizeof(char*));
            split->splitted[split->q_words] = NULL;
        }
        else{
            split->splitted[split->q_words] = (char*)realloc(split->splitted[split->q_words], (len+2) * sizeof(char));
            split->splitted[split->q_words][len++] = string[i];
            split->splitted[split->q_words][len] = 0;
        }
    }
    split->q_words++;
    return split;
}

// Deallocates memory allocated for a word_t type and its members
void erase_words(words_t *words){
    for(int i = 0; i < words->q_words; i++)
        free(words->splitted[i]);
    free(words->splitted);
    free(words);
}

// Sorts an array of char** containing q_items using the logic of bubblesort
void bubblesort(char **array, int q_items){
    boolean_t swap = true;
    int begin = 0;
    while(swap){
        swap = false;      
        for(int i = begin; i < q_items; i++){
            if(string_compare(array[begin], array[i]) > 0){
                int size1 = strlen(array[begin]), size2 = strlen(array[i]);
                void *data = (void*)malloc(size1+1); // Auxiliar variable to store the char* and not loose it
                memcpy(data, array[begin], size1+1);
                array[begin] = (char*)realloc(array[begin], (size2+1) * sizeof(char)); // Reallocating it to receive its new char*
                memcpy(array[begin], array[i], size2+1);
                array[i] = (char*)realloc(array[i], (size1+1) * sizeof(char)); // Reallocating it to receive its new char*
                memcpy(array[i], data, size1+1);
                free(data); // Deallocating memory from data, the auxiliar variable
                swap = true;
            }
        }
        begin++;
    }
}

// It compares two char* and returns 1 if str1 one comes before str2 in the alfabet, -1 if it comes after and 0 if they're the same char*
int string_compare(char *str1, char *str2){
    int size1 = strlen(str1), size2 = strlen(str2);
    for(int i = 0; i < size1 and i < size2; i++){
        if(str1[i] > str2[i])
            return 1;
        else if(str1[i] < str2[i])
            return -1;
    }
    if(size1 > size2)
        return 1;
    else if(size1 < size2)
        return -1;
    return 0;
}

// Function to realize what was asked in the statement
void operate(words_t *words, int operation){
    switch(operation){
        case 2:
            bubblesort(words->splitted, words->q_words);
            break;
    }
    for(int i = 0; i < words->q_words; i++)
        printf("%s\n", words->splitted[i]);
}