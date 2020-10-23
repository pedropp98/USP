#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include "pepelib.h"

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
