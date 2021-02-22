#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define BUFFER 4096
#define and &&
#define or ||

char *readline(FILE*);
int stringcompare(const char*, const char*);
int stringlen(const char*);
int biggest(int, int);
int sum(const char*);
int repetitions(const char*, const char);
int appearance(const char*, const char);
void run(const char*, const char*, const int);

int main(void){
    int operation;
    scanf("%d", &operation);
    while(getchar() != 10);
    char *word1 = readline(stdin), *word2 = readline(stdin);
    run(word1, word2, operation);
    free(word1);
    free(word2);
    return 0;
}

void run(const char *WORD1, const char *WORD2, const int OPERATION){
    char character;
    switch(OPERATION){
        case 1:
            printf("%d\n", biggest(stringlen(WORD1), stringlen(WORD2)));
            break;
        case 2:
            printf("%d\n", stringcompare(WORD1, WORD2));
            break;
        case 3:
            printf("%d\n", biggest(sum(WORD1), sum(WORD2)));
            break;
        case 4:
            character = fgetc(stdin);
            printf("%d\n", biggest(repetitions(WORD1, character), repetitions(WORD2, character)));
            break;
        case 5:
            character = fgetc(stdin);
            if(appearance(WORD1, character) > appearance(WORD2, character))
                printf("2\n");
            else if(appearance(WORD1, character) < appearance(WORD2, character))
                printf("1\n");
            else
                printf("0\n");
            break;
    }
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

int stringcompare(const char *STR1, const char *STR2){
    for(; *STR1 != 0 and *STR2 != 0; STR1++, STR2++){
        if(tolower(*STR1) > tolower(*STR2))
            return 1;
        if(tolower(*STR1) < tolower(*STR2))
            return 2;
    }
    int size1 = stringlen(STR1), size2 = stringlen(STR2);
    if(size1 > size2)
        return 2;
    if(size1 < size2)
        return 1;
    return 0;
}

int stringlen(const char *STRING){
    int size = 0;
    for(; STRING[size] != 0; size++);
    return size;
}

int sum(const char *STR){
    int sum = 0;
    for(; *STR != 0; STR++)
        sum += (tolower(*STR) - 97);
    return sum;
}

int biggest(int integer1, int integer2){
    if(integer1 > integer2)
        return 1;
    if(integer1 < integer2)
        return 2;
    return 0;
}

int repetitions(const char *STR, const char character){
    int count = 0;
    for(; *STR != 0; STR++){
        if(tolower(*STR) == tolower(character))
            count++;
    }
    return count;
}

int appearance(const char *STR, const char character){
    int pos = 0;
    for(; STR[pos] != 0; pos++)
        if(tolower(STR[pos]) == tolower(character))
            return pos;
    return -1;
}