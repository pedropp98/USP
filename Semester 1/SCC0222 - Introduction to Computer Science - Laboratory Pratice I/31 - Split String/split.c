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
words_t *split_word(char*, const char*);
void erase_words(words_t*);
void bubblesort(char**, int);
int string_compare(char*, char*);
void operate(words_t*, int);
char *my_strtok(char*, const char*);

// Main function
int main(void){
    char *input_line = readline(stdin);
    int operation;
    scanf("%d", &operation);
    words_t *splitted = split_word(input_line, " ");
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
words_t *split_word(char *string, const char *split_character){
    words_t *split = (words_t*)malloc(sizeof(words_t));
    split->q_words = 0;
    split->splitted = (char**)malloc(sizeof(char*));
    split->splitted[split->q_words++] = my_strtok(string, split_character);
    
    while(split->splitted[split->q_words-1] != NULL){
        split->splitted = (char**)realloc(split->splitted, (split->q_words+1) * sizeof(char*));
        split->splitted[split->q_words++] = my_strtok(NULL, split_character);
    }
    split->q_words--;
    return split;
}

// Deallocates memory allocated for a word_t type and its members
void erase_words(words_t *words){
    free(words->splitted);
    free(words);
}

// Sorts an array of char** containing q_items using the logic of bubblesort
void bubblesort(char **array, int q_items){
    boolean_t swap = true;
    while(swap){
        swap = false;      
        for(int i = 0; i < q_items-1; i++){
            if(string_compare(array[i], array[i+1]) > 0){
                void *data = array[i];
                array[i] = array[i+1];
                array[i+1] = data;
                swap = true;
            }
        }
    }
}

// It compares two char* and returns 1 if str1 one comes before str2 in the alfabet, -1 if it comes after and 0 if they're the same char*
int string_compare(char *str1, char *str2){
    for(; *str1 != 0 and *str2 != 0; str1++, str2++){
        if(*str1 > *str2)
            return 1;
        else if(*str1 < *str2)
            return -1;
    }
    int size1 = strlen(str1), size2 = strlen(str2);
    if(size1 > size2)
        return 1;
    else if(size1 < size2)
        return -1;
    return 0;
}

// Function to realize what was asked in the statement
void operate(words_t *words, int operation){
    if(operation == 2)
        bubblesort(words->splitted, words->q_words);
    for(int i = 0; i < words->q_words; i++)
        printf("%s\n", words->splitted[i]);
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