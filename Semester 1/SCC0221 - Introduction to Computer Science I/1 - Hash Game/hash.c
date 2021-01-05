#include<stdio.h>
#include<stdlib.h>

#define BOARD_SIZE 3

char *create_board(int);
int change_board(char*, int, int);
int is_finished(char*);
void player_turn(char*, int);
void print_board(char*);

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
        }
    }
    if(count == 9){
        printf("Deu velha!\n");
    }
    free(board);
    return 0;
}

char *create_board(int size){
    int square_size = size * size;
    char *board = (char*)calloc(square_size, sizeof(char));
    for(int i = 0; i < square_size; i++)
        change_board(board, i, i+49);
    return board;
}

int change_board(char *board, int position, int player){
    if(board[position] != 88 & board[position] != 79){
        board[position] = player;
        return 1;
    }
    else{
        printf("Jogada inválida! Escolha outra casa.\n");
        return 0;
    }
}

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

void player_turn(char *board, int player){
    printf("Escolha um número para jogar, jogador %c!\n", player);
    int position;
    do{
        scanf("%d", &position);
    }while(change_board(board, position-1, player) != 1);
}