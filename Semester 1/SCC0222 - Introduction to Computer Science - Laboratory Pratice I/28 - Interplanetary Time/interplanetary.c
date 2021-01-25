#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFFER 4096
#define and &&
#define SECONDS_ON_MERCURY 5068800
#define SECONDS_ON_VENUS 20995200
#define SECONDS_ON_EARTH 86400
#define SECONDS_ON_JUPITER 35760

typedef struct planets{
    char *planet;
    long time;
}planets_t;

char *readline(FILE*);
planets_t *create_planet();
int string_compare(char*, char*);
void call_planet(planets_t*);
void erase_planet(planets_t*);
void calculate_time(planets_t*, int);

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

planets_t *create_planet(){
    planets_t *p = (planets_t*)malloc(sizeof(planets_t));
    p->planet = NULL;
    p->time = 0;
    return p;
}

void erase_planet(planets_t *planet){
    free(planet->planet);
    free(planet);
}

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