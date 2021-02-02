#include<stdio.h>
#include<stdlib.h>

#define WIDTH 3
#define HEIGHT 6

typedef struct set{
    int **pallet;
}set_t;

int read_int();
set_t *create_set();
void *read_set(set_t*);
void erase_set(set_t*);
void change_set(set_t*, set_t*, int, int, int);
void print_set(set_t*);

int main(void){
    int pos1_color = read_int();
    int pos2_color = read_int();
    int pos_result= read_int();
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

int read_int(){
    int number;
    scanf("%d", &number);
    return number;
}

set_t *create_set(){
    set_t *s = (set_t*)malloc(sizeof(set_t));
    s->pallet = (int**)malloc(HEIGHT * sizeof(int*));
    for(int i = 0; i < HEIGHT; i++)
        s->pallet[i] = (int*)malloc(WIDTH* sizeof(int));
    return s;
}

void *read_set(set_t *set){
    for(int i = 0; i < HEIGHT; i++)
        for(int j = 0; j < WIDTH; j++)
            set->pallet[i][j] = read_int();
}

void erase_set(set_t *set){
    for(int i = 0; i < HEIGHT; i++)
        free(set->pallet[i]);
    free(set->pallet);
    free(set);
}

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

void print_set(set_t *set){
    for(int i = 0; i < HEIGHT; i++){
        printf("Color(%d): [ ", i);
        for(int j = 0; j < WIDTH; j++)
            printf("%d ", set->pallet[i][j]);
        printf("]\n");
    }
}