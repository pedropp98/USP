#include<stdio.h>
#include<stdlib.h>

// Defining macros to be used iin the program
#define BUFFER 4096 // Used in readline function
#define and && // Defining and to be the boolean and operator

// Creating a new type calendar_t to store information about the acitivities
typedef struct{
    char *activity, *day, *month, *year, *hour, *minutes, *seconds;;
}calendar_t;

// Creating a type boolean_t to work with boolean values true and false
typedef enum{
    false, true
}boolean_t;

// Function declaration
char *readline(FILE*);
calendar_t *create_calendar();
void erase_calendar(calendar_t*);

// Main function
int main(void){
    int amount_of_activities;
    scanf("%d", &amount_of_activities);
    while(getchar() != 10); // Reading all the characters were not consumed by scanf, so it doesn't mess with the rest of the code
    for(int i = 0; i < amount_of_activities; i++){
        calendar_t *calendar = create_calendar();
        printf("%s/%s/%s - %s:%s:%s\n%s\n", calendar->day, calendar->month, calendar->year, calendar->hour, calendar->minutes, calendar->seconds, calendar->activity); // Prints the result as asked in the statement
        erase_calendar(calendar);
    }
    return 0;
}

// Reads a text line from a FILE* and stores every character in a char*, then returns it
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

// Allocatesspace for a calendar_t type and reads from readline every single of its members
calendar_t *create_calendar(){
    calendar_t *cal = (calendar_t*)malloc(sizeof(calendar_t));
    cal->day = readline(stdin);
    cal->month = readline(stdin);
    cal->year = readline(stdin);
    cal->hour = readline(stdin);
    cal->minutes = readline(stdin);
    cal->seconds = readline(stdin);
    cal->activity = readline(stdin);
    return cal;
}

// Deallocates memory allocated for the calendar_t type and its members
void erase_calendar(calendar_t *calendar){
    free(calendar->day);
    free(calendar->hour);
    free(calendar->minutes);
    free(calendar->month);
    free(calendar->seconds);
    free(calendar->year);
    free(calendar->activity);
    free(calendar);
}
