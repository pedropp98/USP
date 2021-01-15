#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define and &&
#define BUFFER 4096

typedef int (*__compare_function__)(void*, void*);

typedef struct movies{
    char *title;
    int integer;
}movies_t;

typedef enum boolean{
    false, true
}boolean_t;

char *readline(FILE*);
int access_data_str(void*, void*);
int access_data_int(void*, void*);
int string_compare(void*, void*);
int integer_compare(void*, void*);
movies_t *find_number_in_string(char*);
boolean_t is_digit(char);
void erase_movies(movies_t**, int);
void bubble_sort(void*, int, int, __compare_function__);

int main(void){
    int operation = getchar();
    getchar();
    movies_t **movies = (movies_t**)malloc(sizeof(movies_t*));
    int n_movies = 0;
    while(!feof(stdin)){
        movies = (movies_t**)realloc(movies, (n_movies+1) * sizeof(movies_t*));
        movies[n_movies++] = find_number_in_string(readline(stdin));
    }

    switch(operation){
        case 49:
            bubble_sort(movies, n_movies, sizeof(movies_t), access_data_str);
            break;
        case 50:
            bubble_sort(movies, n_movies, sizeof(movies_t), access_data_int);
            break;
    }
    
    for(int i = 0; i < n_movies; i++){
        printf("%d %s\n", movies[i]->integer, movies[i]->title);
    }

    erase_movies(movies, n_movies);
    return 0;
}

movies_t *create_movies(){
    movies_t *movies = (movies_t*)malloc(sizeof(movies_t));
    movies->title = NULL;
    movies->integer = 0;
    return movies;
}

boolean_t is_digit(char character){
    if(character > 47 and character < 58)
        return true;
    return false;
}

movies_t *find_number_in_string(char *string){
    movies_t *movies = create_movies();
    char *number = NULL;
    for(int i = 0, size_title = 0, size_number = 0; string[i] != 0; i++){
        if(!is_digit(string[i])){
            movies->title = (char*)realloc(movies->title, (size_title+1) * sizeof(char));
            movies->title[size_title++] = string[i];
        }
        else{
            number = (char*)realloc(number, (size_number+2) * sizeof(char));
            if(string[i-1] == 45){
                number = (char*)realloc(number, (size_number+3) * sizeof(char));
                number[size_number++] = string[i-1];
                movies->title[size_title-2] = 0;
            }
            else{
                movies->title[size_title-1] = 0;
            }
            number[size_number++] = string[i];
            number[size_number] = 0;
        }
    }
    movies->integer = atoi(number);
    free(number);
    free(string);
    return movies;
}

void erase_movies(movies_t **movies, int n_movies){
    for(int i = 0; i < n_movies; i++){
        free(movies[i]->title);
        free(movies[i]);
    }
    free(movies);
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

int string_compare(void *str_1, void *str_2){
    char *str1 = str_1, *str2= str_2;
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

int integer_compare(void *int_1, void *int_2){
    int *int1 = int_1, *int2 = int_2;
    if(int1[0] > int2[0])
        return 1;
    else if(int1[0] < int2[0])
        return -1;
    else
        return 0;
}

void bubble_sort(void *array, int q_items, int size_items, __compare_function__ function){
    char **side_array = array;
    boolean_t swap = true;
    int begin = 0;
    while(swap){
        swap = false;      
        for(int i = begin; i < q_items; i++){
            if(function(side_array[begin], side_array[i]) > 0){
                void *data = (void*)malloc(size_items);
                memcpy(data, side_array[begin], size_items);
                memcpy(side_array[begin], side_array[i], size_items);
                memcpy(side_array[i], data, size_items);
                free(data);
                swap = true;
            }
        }
        begin++;
    }
    // free(side_array);
}

int access_data_str(void *m1, void *m2){
    movies_t *m_1 = m1, *m_2 = m2;
    return string_compare(m_1->title, m_2->title);
}

int access_data_int(void *m1, void *m2){
    movies_t *m_1 = m1, *m_2 = m2;
    return integer_compare(&m_1->integer, &m_2->integer);
}