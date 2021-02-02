#include<stdio.h>
#include<stdlib.h>

// Defining macros that sets the size of the pallet
#define WIDTH 3
#define HEIGHT 6

// Creating a new type set_t to store the pallet
typedef struct set{
    int **pallet;
}set_t;

// Function definition
int read_int();
set_t *create_set();
void *read_set(set_t*);
void erase_set(set_t*);
void change_set(set_t*, set_t*, int, int, int);
void print_set(set_t*);

// Main function
int main(void){
    int pos1_color = read_int(); // Contains the first line that will be used
    int pos2_color = read_int(); // Contains the second line that will be used
    int pos_result= read_int(); // Contains the line that must be changed

    set_t *colors_set = create_set();
    read_set(colors_set);
    set_t *new_set = create_set();
    change_set(colors_set, new_set, pos1_color, pos2_color, pos_result);

    printf("Start:\n");
    print_set(colors_set);
    printf("\nResult:\n");
    print_set(new_set);

    erase_set(colors_set);
    erase_set(new_set);
    return 0;
}

// Reads an integer from stdin and returns it
int read_int(){
    int number;
    scanf("%d", &number);
    return number;
}

// Allocates memory for a set_t and its members
set_t *create_set(){
    set_t *s = (set_t*)malloc(sizeof(set_t)); // Allocates 8 bytes in heap memory
    s->pallet = (int**)malloc(HEIGHT * sizeof(int*)); // Allocates 48 bytes in heap memory
    for(int i = 0; i < HEIGHT; i++)
        s->pallet[i] = (int*)malloc(WIDTH * sizeof(int)); // Allocates 12 bytes in heap memory (6x)
    return s;
}

// Reads from stdin 18 integers and stores them inthe set_t
void *read_set(set_t *set){
    for(int i = 0; i < HEIGHT; i++)
        for(int j = 0; j < WIDTH; j++)
            set->pallet[i][j] = read_int();
}

// Deallocates memory allocated for a set_t
void erase_set(set_t *set){
    for(int i = 0; i < HEIGHT; i++)
        free(set->pallet[i]);
    free(set->pallet);
    free(set);
}

// Copies values from orig_set to dest_set, unless the position is equal to pos_result
// If the position is equal to pos_result, it sums dest_set->pallet to the values of orig_set->pallet[pos1] / 2 and orig_set->pallet[pos2] / 2, in each position
void change_set(set_t *orig_set, set_t *dest_set, int pos1, int pos2, int pos_result){
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            dest_set->pallet[i][j] = orig_set->pallet[i][j];
            if(i == pos_result){
                dest_set->pallet[i][j] += (orig_set->pallet[pos1][j] / 2) + (orig_set->pallet[pos2][j] / 2);
                if(dest_set->pallet[i][j] > 255)
                    dest_set->pallet[i][j] = 255;
            }
        }
    }
}

// Prints the set_t
void print_set(set_t *set){
    for(int i = 0; i < HEIGHT; i++){
        printf("Color(%d): [ ", i);
        for(int j = 0; j < WIDTH; j++)
            printf("%d ", set->pallet[i][j]);
        printf("]\n");
    }
}