#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFFER 4096

#define and &&

char *readline(FILE*);
char *replacestring(char*, char*, char*);

int main(int argc, char** argv){
    int total_words = 0;
    while(!feof(stdin)){
        char *original_text = readline(stdin);
        char *error_text = readline(stdin);
        char *correct_text = readline(stdin);
        
        char *result = replacestring(original_text, error_text, correct_text);
        printf("%s\n", result);
        free(result);
        free(original_text);
        free(error_text);
        free(correct_text);
    }
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

char *replacestring(char *str1, char *str2, char *str3){
    char *return_string = NULL;
    char *rest_string = str1;
    char *temporary = NULL;
    int len_str1 = strlen(str1), len_str2 = strlen(str2), len_str3 = strlen(str3), 
        counter = 0, distance = 0;

    //Saving the string after the part needing substitution, for future use
    for(counter = 0; temporary = strstr(rest_string, str2); counter++)  
        rest_string = temporary + len_str2;
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