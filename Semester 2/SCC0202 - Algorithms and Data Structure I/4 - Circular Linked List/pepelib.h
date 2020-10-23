#ifndef PEPELIB_H
#define PEPELIB_H

#define BUFFER 4096

typedef enum boolean{
    false, true
}boolean_t;

//Reads a single line from a FILE*
char *readline(FILE* in);
//Reads 'til the end of a FILE*
char **readlines(FILE* in, int *n_lines);
//Reads a word in the line, stops at the space character (32 in ASCII) or at the end of FILE* if there's only one word
char *readword(FILE *in);
//replace str2 in str1 for str3
char *replacestring(char *str1, char *str2, char *str3);


#endif