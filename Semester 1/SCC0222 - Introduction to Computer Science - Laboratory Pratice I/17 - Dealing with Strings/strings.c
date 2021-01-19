#include<stdio.h>
#include<stdlib.h>

#define and &&
#define BUFFER 4096

typedef enum boolean{
    false, true
}boolean_t;

char *readline(FILE*);
char *concatenate_strings(char*, char*);
int stringlen(const char*);
boolean_t is_equal(const char*, const char*);

int main(void){
    char *string_1 = readline(stdin);
    char *string_2 = readline(stdin);
    if(is_equal(string_1, string_2))
        printf("iguais\n");
    else{
        string_1 = concatenate_strings(string_1, string_2);
        printf("%s\n", string_1);
    }
    free(string_1);
    free(string_2);
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

char *concatenate_strings(char *str1, char *str2){
    int size1 = stringlen(str1), size2 = stringlen(str2);
    str1 = (char*)realloc(str1, (size1 + size2 + 1) * sizeof(char));
    for(int i = size1, j = 0; j < size2; i++, j++){
        str1[i] = str2[j];
    }
    str1[size1+size2] = 0;
    return str1;
}

int stringlen(const char *STRING){
    int size = 0;
    for(size = 0; STRING[size] != 0; size++);
    return size;
}

boolean_t is_equal(const char *STR1, const char *STR2){
    int size_1 = stringlen(STR1), size_2 = stringlen(STR2), compare = 0;
    for(int i = 0; i < size_1 and i < size_2; i++){
        if(STR1[i] == STR2[i])
            compare++;
        else
            return false;
    }
    if(compare == size_1 and compare == size_2)
        return true;
    else
        return false;
}