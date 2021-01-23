#include<stdio.h>
#include<stdlib.h>

typedef struct attack{
    int *power_of_attack;
    int type;
}attack_t;

attack_t *create_attack();
double **create_matrix(int);
void get_better_attack(attack_t*, double**, int);
void store_attacks(attack_t*);
void erase_attack(attack_t*);
void erase_matrix(double**, int);

int main(void){
    attack_t *attack = create_attack();
    double **matrix = create_matrix(attack->type);
    store_attacks(attack);
    int enemy_type;
    scanf("%d", &enemy_type);
    get_better_attack(attack, matrix, enemy_type);
    erase_matrix(matrix, attack->type);
    erase_attack(attack);
    return 0;
}

attack_t *create_attack(int q_type){
    attack_t *a = (attack_t*)malloc(sizeof(attack_t));
    scanf("%d", &a->type);
    a->power_of_attack = (int*)malloc(a->type * sizeof(int));
    return a;
}

double **create_matrix(int size_matrix){
    double **matrix = (double**)malloc(size_matrix * sizeof(double*));
    for(int i = 0; i < size_matrix; i++){
        matrix[i] = (double*)malloc(size_matrix * sizeof(double));
        for(int j = 0; j < size_matrix; j++){
            scanf("%lf", &matrix[i][j]);
        }
    }
    return matrix;
}

void get_better_attack(attack_t *attack, double **matrix, int enemy_type){
    double maior = attack->power_of_attack[0] * matrix[0][enemy_type];
    int index = 0;
    for(int i = 0; i < attack->type; i++){
        double compare_attack = attack->power_of_attack[i] * matrix[i][enemy_type];
        if(compare_attack > maior){
            maior = compare_attack;
            index = i;
        }
    }
    printf("O melhor ataque possui indice %d e dano %.2lf\n", index, maior);
}

void store_attacks(attack_t *attack){
    int read_integer, count = 0;
    do{
        scanf("%d", &read_integer);
        if(read_integer != -1){
            attack->power_of_attack[count++] = read_integer;
            scanf("%d", &read_integer);
        }
    }while(read_integer != -1);
}

void erase_matrix(double **matrix, int size_matrix){
    for(int i = 0; i < size_matrix; i++)
        free(matrix[i]);
    free(matrix);
}

void erase_attack(attack_t *attack){
    free(attack->power_of_attack);
    free(attack);
}