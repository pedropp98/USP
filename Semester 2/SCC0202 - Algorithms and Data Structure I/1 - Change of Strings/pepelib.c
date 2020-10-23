#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include "pepelib.h"

char* readline(FILE* in){
    assert(in != NULL);
    char *string = NULL;
    int aux = 0, c = 0;
    do{
        if (aux % BUFFER == 0) 
            string = (char *)realloc(string, ((aux / BUFFER) + 1) * BUFFER);
        c = fgetc(in);
        if (c != 13)    string[aux++] = c;
    }while(string[aux - 1] != 10 && !feof(in));
    string[aux - 1] = '\0';
    string = (char *)realloc(string, aux);
    return string;
}

char *replacestring(char *str1, char *str2, char *str3){
    char *return_string = NULL;
    char *rest_string = str1;
    char *temporary = NULL;
    int len_str1 = strlen(str1), len_str2 = strlen(str2), len_str3 = strlen(str3), 
        counter = 0, distance = 0;
    assert(str1 != NULL && str2 != NULL && str3 != NULL && str2 > 0);
    //Saving the string after the part needing substitution, for future use
    for(counter = 0; temporary = strstr(rest_string, str2); counter++)  
        rest_string = temporary + len_str2;
    temporary = return_string = (char*)malloc((len_str1 + (len_str3 - len_str2) 
                                                * counter + 1) * sizeof(char));
    assert(return_string != NULL);
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