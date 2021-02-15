#include<stdio.h>
#include<stdlib.h>

// Defining macro named BOARD_SIZE, that defines the size of the board used in the game
#define BOARD_SIZE 3

// Function definition
char *create_board(int);
int change_board(char*, int, int);
int is_finished(char*);
void player_turn(char*, int);
void print_board(char*);

// Main function
int main(void){
    char *board = create_board(BOARD_SIZE);
    print_board(board);
    printf("Jogo da velha!\n");
    int finish = 0, count = 0;
    while(!finish && count < 9){ 
        finish = is_finished(board);
        // Player 1
        if(!finish){
            if(count < 9){
                player_turn(board, 88);
                print_board(board);
                count++;
            }
        }
        else{
            printf("Fim de jogo! O jogador O venceu!\n");
            break;
        }
        finish = is_finished(board);
        // Player 2
        if(!finish){
            if(count < 9){
                player_turn(board, 79);
                print_board(board);
                count++;
            }
        }
        else{
            printf("Fim de jogo! O jogador X venceu!\n");
            break;
        }
    }
    if(count == 9){
        printf("Deu velha!\n");
    }
    free(board);
    return 0;
}

/*
Creates a square board like the one below:
1   |2   |3   |
----+----+-----
4   |5   |6   |
----+----+----+
7   |8   |9   |
----+----+-----
*/
char *create_board(int size){
    int square_size = size * size;
    char *board = (char*)calloc(square_size, sizeof(char));
    for(int i = 0; i < square_size; i++)
        change_board(board, i, i+49);
    return board;
}

// Checks if a certain position is already occupied by a player (X or O), if so, it prints a text telling it was not a valid movement and returns 0. If it's not occupied by a player, then it changes the value of that position to the one that correponds to the player ASCII value
// It also does not allow an invalid position, which would be anything smaler than 0 or greater than 8
int change_board(char *board, int position, int player){
    if(board[position] != 88 & board[position] != 79 && position >= 0 && position <= 8){
        board[position] = player;
        return 1;
    }
    else{
        printf("Jogada inválida! Escolha outra casa.\n");
        return 0;
    }
}

// Checks if the board is in a position which a player won, either be horizontally, vertically or diagonally. returns 1 if so, 0 otherwise
int is_finished(char *board){
    for(int i = 0; i < (BOARD_SIZE * BOARD_SIZE); i += 3){
        if(board[i] == board[i+1] && board[i] == board[i+2])
            return 1;
    }
    for(int i = 0; i < BOARD_SIZE; i++){
        if(board[i] == board[i+BOARD_SIZE] && board[i] == board[i + (2*BOARD_SIZE)])
            return 1;
    }
    if(board[0] == board[4] && board[0] == board[8])
        return 1;
    else if(board[2] == board[4] && board[2] == board[6])
        return 1;
    else
        return 0;
}


// Prints the board, so the players can see the current state of the game
void print_board(char *board){
    for(int i = 0; i < (BOARD_SIZE * BOARD_SIZE); i++){
        printf("%c   |", board[i]);
        if((i+1) % BOARD_SIZE == 0){
            printf("\n");
            for(int j = 0; j < BOARD_SIZE; j++){
                printf("----+");
            }
            printf("\n");
        }
    }
}

// Prints a message telling it's a player's turn and reads an integer from stdin until change_board function returns 1, which means it's a valid movement
void player_turn(char *board, int player){
    printf("Escolha um número para jogar, jogador %c!\n", player);
    int position;
    do{
        scanf("%d", &position);
    }while(change_board(board, position-1, player) != 1);
}