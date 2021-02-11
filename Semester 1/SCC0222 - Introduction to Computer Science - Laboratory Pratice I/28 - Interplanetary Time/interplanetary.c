#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Defining macros to be used in the program
#define BUFFER 4096
#define and &&
// The macros below refer to the seconds of a day on each planet
#define SECONDS_ON_MERCURY 5068800
#define SECONDS_ON_VENUS 20995200 // In this planet, there's a little mistake, in all test cases where used this value, but this represents the amount of seconds in 2.1 days
#define SECONDS_ON_EARTH 86400
#define SECONDS_ON_JUPITER 35760

// Creating a new type planets_t to store information about the requested planet and its time to be calculated
typedef struct planets{
    char *planet;
    long time;
}planets_t;

// Function deifinition
char *readline(FILE*);
planets_t *create_planet();
int string_compare(char*, char*);
void call_planet(planets_t*);
void erase_planet(planets_t*);
void calculate_time(planets_t*, int);

// Main function
int main(void){
    planets_t *info_planet = create_planet();
    char *input_time = readline(stdin);
    info_planet->time = atof(input_time);
    free(input_time);
    info_planet->planet = readline(stdin);
    call_planet(info_planet);
    erase_planet(info_planet);
    return 0;
}

// Reads a text line from a FILE* and stores every character in a char*. Returns this char*. It stops when it finds the break line character of it reaches the end of the file
char *readline(FILE *in){
    char *string = NULL;
    int pos = 0, character;
    do{
        if(pos % BUFFER == 0)
            string = (char*)realloc(string, (pos / BUFFER + 1) * BUFFER * sizeof(char));
        character = fgetc(in);
        if(character != 13)
            string[pos++] = character;
    }while(character != 32 and character != 10 and !feof(in));
    string[pos-1] = 0;
    string = (char*)realloc(string, pos * sizeof(char));
    return string;
}

// Allocates memory for a planet_t type and sets its members to 0 and NULL
planets_t *create_planet(){
    planets_t *p = (planets_t*)malloc(sizeof(planets_t));
    p->planet = NULL;
    p->time = 0;
    return p;
}

// Deallocates memory allocated for a planet_t type and its member char*
void erase_planet(planets_t *planet){
    free(planet->planet);
    free(planet);
}

// Calculates how many days, hours, minutes and seconds are in some planet based on the seconds_on_planet and information from planet_t type
void calculate_time(planets_t *planet, int seconds_on_planet){
    long days, hours, minutes, seconds, remainder;
    days = planet->time / seconds_on_planet;
    remainder = planet->time % seconds_on_planet;
    seconds = remainder % 60;
    remainder /= 60;
    minutes = remainder % 60;
    hours = remainder / 60;
    printf("%ld segundos no planeta %s equivalem a:\n%ld dias, %ld horas, %ld minutos e %ld segundos", planet->time, planet->planet, days, hours, minutes, seconds);
}

// Comapres two char* str1 and str2. Returns 1 if str1 comes first in the alphabet, -1 if str2 comes first and 0 if they're equal. I noticed that strcmp from string.h makes some mmistakes with some char*, so this is a way of overwriting them
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

// Calls calculate_time function based on which planet is requested to be calculated, and this is made by comparing strings from the requested planet
void call_planet(planets_t *planet){
    if(string_compare(planet->planet, "Jupiter") == 0)
        calculate_time(planet, SECONDS_ON_JUPITER);
    else if(string_compare(planet->planet, "Venus") == 0)
        calculate_time(planet, SECONDS_ON_VENUS);
    else if(string_compare(planet->planet, "Mercurio") == 0)
        calculate_time(planet, SECONDS_ON_MERCURY);
    else
        calculate_time(planet, SECONDS_ON_EARTH);
}