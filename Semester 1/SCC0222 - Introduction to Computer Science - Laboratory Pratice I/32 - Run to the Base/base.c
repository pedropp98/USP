#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct board{
    int **board;
    int width, height, base_x, base_y;
}board_t;

typedef struct player{
    int x_position, y_position;
    double move;
}player_t;

board_t *create_board();
player_t *create_player();
void read_board(board_t*);
double calculate_distance(board_t*, player_t*);
void print_result(player_t*, double);
void erase_board(board_t*);
void erase_player(player_t*);

int main(void){
    board_t *board = create_board();
    player_t *player = create_player();
    read_board(board);
    print_result(player, calculate_distance(board, player));
    erase_board(board);
    erase_player(player);
    return 0;
}

board_t *create_board(){
    board_t *board = (board_t*)malloc(sizeof(board_t));
    scanf("%d %d", &board->height, &board->width);
    board->board = (int**)calloc(board->height, sizeof(int*));
    for(int i = 0; i < board->height; i++)
        board->board[i] = (int*)calloc(board->width, sizeof(int));
    board->base_x = 0;
    board->base_y = 0;
    return board;
}

player_t *create_player(){
    player_t *player = (player_t*)malloc(sizeof(player_t));
    scanf("%d %d %lf", &player->x_position, &player->y_position, &player->move);
    return player;
}

void read_board(board_t *board){
    for(int i = 0; i < board->height; i++){
        for(int j = 0; j < board->width; j++){
            scanf("%d", &board->board[i][j]);
            if(board->board[i][j] == 1){
                board->base_x = i;
                board->base_y = j;
            }
        }
    }
}

double calculate_distance(board_t *board, player_t *player){
    return sqrt(pow(board->base_x - player->x_position, 2) + pow(board->base_y - player->y_position, 2));
}

void print_result(player_t *player, double distance){
    if(distance > player->move)
        printf("Game Over!\n");
    else
        printf("Voce escapou!\n");
}

void erase_board(board_t *board){
    for(int i = 0; i < board->height; i++)
        free(board->board[i]);
    free(board->board);
    free(board);
}

void erase_player(player_t *player){
    free(player);
}