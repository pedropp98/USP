#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFFER 4096

#define and &&

typedef enum boolean{
    false, true
}boolean_t;

char *readline(FILE*);
int string_compare(char*, char*);

int main(void){
    char *file_out = readline(stdin);
    char *file_check = readline(stdin);
    FILE *out = fopen(file_out, "r");
    FILE *check = fopen(file_check, "r");
    boolean_t different = false;
    while(!feof(out) and !feof(check)){
        char *line_out = readline(out);
        char *line_check = readline(check);
        int size1 = strlen(line_out), size2 = strlen(line_check);
        for(int i = 0; line_out[i] != 0 and line_check[i] != 0; i++){
            if(line_out[i] != line_check[i]){
                printf("%s\n%s\n", line_check, line_out);
                i += size1;
                different = true;
            }
        }
        free(line_out);
        free(line_check);
    }
    if(!different){
        printf("Tudo certo");
    }

    fclose(out);
    fclose(check);
    free(file_out);
    free(file_check);
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