#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Defining a new type board_t to store board info
typedef struct board{
    int **board;
    int width, height, base_x, base_y;
}board_t;

// Defining a new type player_t to store plater info
typedef struct player{
    int x_position, y_position;
    double move;
}player_t;

// Function definition
board_t *create_board();
player_t *create_player();
void read_board(board_t*);
double calculate_distance(board_t*, player_t*);
void print_result(player_t*, double);
void erase_board(board_t*);
void erase_player(player_t*);

// Main function
int main(void){
    board_t *board = create_board();
    player_t *player = create_player();
    read_board(board);
    print_result(player, calculate_distance(board, player));
    erase_board(board);
    erase_player(player);
    return 0;
}

// Allocates memory for a board_t and returns it
board_t *create_board(){
    board_t *board = (board_t*)malloc(sizeof(board_t)); // Allocates 24 bytes in heap memory
    scanf("%d %d", &board->height, &board->width); // Reads two integers from stdin
    board->board = (int**)malloc(board->height * sizeof(int*)); // Allocates height * 8 bytes in heap memory
    for(int i = 0; i < board->height; i++)
        board->board[i] = (int*)calloc(board->width, sizeof(int)); // Allocates width * 4 bytes in heap memory and initializes it with 0
    // These two variables are used to control the amount of loops in the code
    board->base_x = 0;
    board->base_y = 0;
    return board;
}

// Allocates memory for player_t and returns it
player_t *create_player(){
    player_t *player = (player_t*)malloc(sizeof(player_t)); // Allocates 16 bytes in heap memory
    scanf("%d %d %lf", &player->x_position, &player->y_position, &player->move); // Reads two integers an one double value from stdin
    return player;
}

// Reads height * width integers from stdin and stores them in the array. As we know, there's only one position for the base, represeted by 1, so when it's found this position, x_base and y_base are set to i and j respectively
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

// Calculate de Euclidian distance from the player position and the base position and returns it
double calculate_distance(board_t *board, player_t *player){
    return sqrt(pow(board->base_x - player->x_position, 2) + pow(board->base_y - player->y_position, 2));
}

// Prints the result. If the distance is bigger then the allowed player movement, then it's game over, else, the player can escape
void print_result(player_t *player, double distance){
    if(distance > player->move)
        printf("Game Over!\n");
    else
        printf("Voce escapou!\n");
}

// Deallocates memory allocated for a board_t and its members
void erase_board(board_t *board){
    for(int i = 0; i < board->height; i++)
        free(board->board[i]);
    free(board->board);
    free(board);
}

// Deallocates memory allocated for a player_t
void erase_player(player_t *player){
    free(player);
}