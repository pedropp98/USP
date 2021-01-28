#include<stdio.h>
#include<stdlib.h>

// Defining macros used in the program
#define and &&
#define or ||
#define BOARD_SIZE 3

// Function deifinition
char **read_board(FILE*);
int check_played_positions(char**);
int check_state(char**);
void free_board(char**);

// Main function
int main(void){
    char **board = read_board(stdin);
    int state = check_state(board);
    if(state == 1)
        printf("empate\n");
    else if(state == 0)
        printf("em jogo\n");
    else    
        printf("%c ganhou\n", state);
    free_board(board);
    return 0;
}

// Reads the entire board from stdin and returns it as a char**
char **read_board(FILE *in){
    char **string = (char**)malloc(BOARD_SIZE * sizeof(char*)); // Allocates BOARD_SIZE(3) * 8 bytes in heap memory
    for(int i = 0; i < BOARD_SIZE; i++){
        string[i] = (char*)malloc(BOARD_SIZE * sizeof(char)); // Allocates BOARD_SIZE(3) * 1 bytes in heap memory
        for(int j = 0; j < BOARD_SIZE; j++){
            scanf("%c", &string[i][j]); // Reads a char from stdin and stores it
            getchar(); // Reads the space character
        }
        getchar(); // Reads the break line character
    }
    return string;
}

// Counts how many moves was made until that point in the game
int check_played_positions(char **board){
    int played = 0;
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            if(board[i][j] != 45)
                played++;
        }
    }
    return played;
}

// It will check if there's a winner. If so, it returns the specific character from the player as an integer. If it was a tie, it returns 1, if the game is not yet finished it returns 0
int check_state(char **board){
    for(int i = 0, j = 0; i < (BOARD_SIZE); i++){
        if((board[i][j] == board[i][j+1] && board[i][j] == board[i][j+2]) and board[i][j] != 45)
            return board[i][j];
    }
    for(int i = 0, j = 0; i < BOARD_SIZE; i++){
        if((board[j][i] == board[j+1][i] && board[j][i] == board[j+2][i]) and board[j][i] != 45)
            return board[j][i];
    }
    if((board[0][0] == board[1][1] && board[0][0] == board[2][2]) and board[0][0] != 45)
        return board[0][0];
    else if((board[0][2] == board[1][1] && board[0][2] == board[2][0]) and board[0][2] != 45)
        return board[0][2];
    else{
        int played = check_played_positions(board);
        if(played == 9)
            return 1;
        else
            return 0;
    }
    return 0;
}

// Deallocates memory allocated for the board
void free_board(char **board){
    for(int i = 0; i < BOARD_SIZE; i++){
        free(board[i]);
    }
    free(board);
}