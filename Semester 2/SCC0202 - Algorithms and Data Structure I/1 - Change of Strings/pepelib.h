#ifndef pepelib_H
#define pepelib_H

#define BUFFER 4096

//Reads a single line from a FILE*
char *readline(FILE* in);
//replace str2 in str1 for str3
char *replacestring(char *str1, char *str2, char *str3);

#endif