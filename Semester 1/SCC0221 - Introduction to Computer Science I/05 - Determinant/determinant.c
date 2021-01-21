#include<stdio.h>
#include<stdlib.h>

void determinant(int**, int);

int main(void){
    int lines, columns;
    scanf("%d %d", &lines, &columns);
    if(lines < 1 || lines > 3 || columns < 1 || columns > 3){
        printf("Entradas invalidas!\n");
    }
    else if(lines != columns){
        printf("A matriz de entrada nao possui determinante!\n");
    }
    else{
        int **matrix = (int**)malloc(lines * sizeof(int*));
        for(int i = 0; i < lines; i++){
            matrix[i] = (int*)malloc(columns * sizeof(int));
            for(int j = 0; j < columns; j++){
                scanf("%d ", &matrix[i][j]);
            }
        }
        determinant(matrix, lines);
        for(int i = 0; i < lines; i++){
            free(matrix[i]);
        }
        free(matrix);
    }
    
    return 0;
}

void determinant(int **matrix, int size){
    int det;
    switch(size){
        case 1:
            det = matrix[0][0];
            break;
        case 2:
            det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
            break;
        case 3:
            det = matrix[0][0] * matrix[1][1] * matrix[2][2] + 
                  matrix[0][1] * matrix[1][2] * matrix[2][0] +
                  matrix[0][2] * matrix[1][0] * matrix[2][1] -
                  matrix[0][2] * matrix[1][1] * matrix[2][0] -
                  matrix[0][0] * matrix[1][2] * matrix[2][1] -
                  matrix[0][1] * matrix[1][0] * matrix[2][2];
            break;
    }
    printf("O determinante da matriz de entrada equivale a %d e tem ordem %d\n", det, size);
}