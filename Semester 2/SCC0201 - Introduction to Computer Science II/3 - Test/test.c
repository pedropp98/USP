#include<stdlib.h>
#include<stdio.h>

unsigned char* funcao(unsigned short*, unsigned short*, int);
int recursive_square_compare_function(unsigned short, unsigned short*, int*, int); 
int recursive_nlogn_compare_function(unsigned short, unsigned short*, int, int);
unsigned char *recursive_n_compare_function(unsigned short*, unsigned short*, unsigned char*, int, int, int, int);
unsigned short *define_list(int);

//En - main funtion
//Pt - Função main
int main(int argc, char** argv){
    int n;
    scanf("%d", &n);
    srand(1);
    unsigned short *v1 = define_list(n);
    unsigned short *v2 = define_list(n);
    unsigned char* found = funcao(v1, v2, n);
    for(int i = 0; i < n; i++){
        if(found[i] == 1) printf("%04hu ", v1[i]);
    }
    printf("\n");
    free(v1);
    free(v2);
    free(found);
    return 0;
}

//En - Function that defines a pseudorandom list of numbers
//Pt - Função que define uma lista com números pseudoaleatórios
unsigned short *define_list(int n_items){
    unsigned short *v = (unsigned short*)malloc(n_items * sizeof(unsigned short));
    v[0] = rand()%2;
    for (int i = 1; i < n_items; i++) 
        v[i] = v[i-1]+(rand()%3)+1;
    return v;
}

//En - The original function given by the assignment was changed a bit to fit in my needs.
//Pt - A função original disponibilizada pelo exercício foi alterada um pouco para se adequar às minhas necessidades.
unsigned char* funcao(unsigned short* v1, unsigned short* v2, int n){
    unsigned char* found = calloc(n+1, sizeof(unsigned char));
    found = recursive_n_compare_function(v1, v2, found, 0, n, 0, n);
    /*int begin = 0;
    for (int i = 0; i < n; i++){
        //found[i] = recursive_square_compare_function(v1[i], v2, &begin, n);
        found[i] = recursive_logn_compare_function(v1[i], v2, begin, n);
    }*/ 
    return found;
}

//En - The function stops if the v2 position reaches the end. If not, it compares the key with a v2 value. If it finds the value, increases in one the initial position on v2. Since the vector is ordered and has unique values, there's no reason to look for repeated values.
//Pt - A função para se a posição de v2 chegar ao fim. Se não, compara key com um valor de v2. Se encontrar o valor, incrementa em 1 a posição inicial de v2. Já que o vetor está ordenado e possui valores únicos, não há razão para procurar por valores repetidos.
int recursive_square_compare_function(unsigned short key, unsigned short *v2, int *v2_pos, int end){
    int auxiliar_v2pos = *v2_pos;
    if(auxiliar_v2pos >= end) 
        return 0;
    if(key < v2[auxiliar_v2pos]) 
        return 0;
    if(key == v2[auxiliar_v2pos]){
        auxiliar_v2pos++;
        *v2_pos = auxiliar_v2pos;
        return 1;
    }
    auxiliar_v2pos++;
    *v2_pos = auxiliar_v2pos;
    return recursive_square_compare_function(key, v2, v2_pos, end);
}

//En - The function defines where the middle value is and make sure it's in a available position. If yes, then it compares the key with v2 middle value. Redefining the boudaries in v2 if necessary.
//Pt - A função define onde está o valor do meio e certifica de que está em um posição válida. Se sim, então compara key com o valor de v2 no meio. Redefine os intervalos em v2 se necessário.
int recursive_nlogn_compare_function(unsigned short key, unsigned short* v2, int begin, int end){
    int half = (int)((begin+end)/2);
    if(half >= end) return 0;
    if(key == v2[half]) return 1;
    if(key < v2[half]) return recursive_nlogn_compare_function(key, v2, begin, half);
    return recursive_nlogn_compare_function(key, v2, half+1, end);    
}

//En - The function makes sure that neither v1 or v2 reached the end. If both of them are in available positions, it compares the values of v1 and v2 in certain position. If they're equal, we can move up both inital positions. If one of them is greater, we move up the other inital vector position. It happens because we have unique and orderes values, so we don't need to look for a repeated value, neither keep trying if we reach a value less than the other.
//Pt - A função certifica que nenhum dos vetores v1 ou v2 chegou ao fim. Se os dois estiverem em posições válidas, compara o valor de v1 e o valor de v2 em uma certa posição. Se são iguais, podemos mover ambas as posições iniciais para cima. Se um deles é maior, iremos mover a posição inicial do outro para cima. Isso acontece porque temos valores únicos e ordenados, então não precisamos procurar por valores repetidos, nem continuar insistindo se encontrarmos um valor que é menor do que o outro.
unsigned char *recursive_n_compare_function(unsigned short* v1, unsigned short* v2, unsigned char* found, int begin_v1, int end_v1, int begin_v2, int end_v2){
    if(begin_v1 >= end_v1)
        return found;
    if(begin_v2 >= end_v2) 
        return found;
    unsigned short value_v1 = v1[begin_v1], value_v2 = v2[begin_v2];
    if(value_v1 == value_v2){
        found[begin_v1] = 1;
        begin_v1++;
        begin_v2++;
    }
    if(value_v1 > value_v2)
        begin_v2++;
    if(value_v1 < value_v2){
        found[begin_v1] = 0;
        begin_v1++;
    }
    return recursive_n_compare_function(v1, v2, found, begin_v1, end_v1, begin_v2, end_v2);
}