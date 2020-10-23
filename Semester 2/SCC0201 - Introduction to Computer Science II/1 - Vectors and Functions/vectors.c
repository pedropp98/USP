#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//BUFFER utilizado na funcao readLine
#define BUFFER 4096

//enum BOOL, para realizar operações booleanas de TRUE ou FALSE
typedef enum{
    FALSE, TRUE
}BOOL;

//struct Repetidos, contém as informações dos números repetidos
typedef struct{
    int* numerosRepetidos;
    int* contadorRepetidos;
    int qtdRepetidos;
}Repetidos;

//Declaracao das funcoes utilizadas no programa
void freeMemoria(Repetidos*, int*);
void printResultado(Repetidos*);
char *readLine(FILE*);
int *retornaEntradaNumeros(int*);
int readInt(char*);
int buscaSequencial(int, int*, int);
Repetidos *retornaNumerosRepetidos(int, int*);
Repetidos *alocaRepetidos();

//Funcao main
int main(int argc, char** argv){
    int *numeros = NULL;
    int qtdNumeros = 0;
    numeros = retornaEntradaNumeros(&qtdNumeros);
    Repetidos *repetidos = retornaNumerosRepetidos(qtdNumeros, numeros);

    printResultado(repetidos);
    freeMemoria(repetidos, numeros);
    
    return 0;
}

//Recebe um FILE* contendo a entrada padrão stdin. Retorna os caracteres lidos até encontrar um espaço, uma quebra de linha ou o fim do arquivo
char* readLine(FILE* in){
    char* string = 0;
    char c;
    int aux = 0;
	do{
		if (aux % BUFFER == 0){
            string = (char*)realloc(string, ((aux / BUFFER) + 1) * BUFFER);
        }
        c = (char)fgetc(in);
        if(c != 13) string[aux++] = c;
	}while(string[aux-1] != 10 && string[aux-1] != 32 && !feof(in));
    string = (char*)realloc(string, aux);
	string[aux-1] = '\0';
    return string;
}

//Recebe o número a ser procurado, o vetor onde esse número deve ser procurado e quantidade de ítens no vetor. Retorna a quantidade de vezes que esse número se repete no vetor, contando, inclusive, o próprio número
int buscaSequencial(int valor, int* vetor, int numeroItens){
    int qtd = 0;
    for(int i = 0; i < numeroItens; i++){
        if(valor == vetor[i]){
            qtd++;
        }
    }
    return qtd;
}

//Recebe uma string. Retorna essa string transformada em um número inteiro
int readInt(char* texto){
    int len = 0, retornaNumero = 0, caracterInicio = 0;
    len = strlen(texto);
    if(texto[0] == 45){
        len--;    
        caracterInicio = 1;
    }
    for(int i = caracterInicio; texto[i] != '\0'; i++){
        if(texto[0] == 45) retornaNumero += (texto[i] - 48) * pow(10, len - (i));
        else retornaNumero += (texto[i] - 48) * pow(10, len - (i+1));
    }
    if(texto[0] == 45) retornaNumero *= -1;
    return retornaNumero;
}

//Recebe e altera a quantidade de números que existem no vetor. Retorna um vetor que contém os números que foram digitados na entrada padrão
int* retornaEntradaNumeros(int *qtdNumeros){
    char** entrada = NULL;
    int *numeros = NULL;
    while(!feof(stdin)){
        entrada = (char**)realloc(entrada, (*qtdNumeros+1) * sizeof(char*));
        entrada[*qtdNumeros] = readLine(stdin);
        if(strlen(entrada[*qtdNumeros]) == 0) free(entrada[*qtdNumeros]); //Verifica se é um espaço vazio, nos casos de entrada alguns números possuíam dois espaços entre eles e isso gerava uma linha em branco na minha leitura, corrigi desse jeito caso essa linha em branco seja encontrada
        else{
            numeros = (int*)realloc(numeros, (*qtdNumeros+1) * sizeof(int));
            numeros[*qtdNumeros] = readInt(entrada[*qtdNumeros]);
            free(entrada[*qtdNumeros]);
            *qtdNumeros+=1;
        }
    }
    free(entrada);
    return numeros;
}

//Recebe a quantidade de numeros no vetor e o próprio vetor.Retorna uma struct Repetidos, contendo a os números repetidos, a quantidade de números repetidos, e quantas vezes cada número se repete
Repetidos* retornaNumerosRepetidos(int qtdNumeros, int *numeros){
    Repetidos *repetidos = alocaRepetidos();
    for(int i = 0; i < qtdNumeros; i++){
        BOOL parar = FALSE;
        for(int j = 0; j < repetidos->qtdRepetidos && !parar; j++){ //Impede que seja checado o mesmo número mais de uma vez
            if(numeros[i] == repetidos->numerosRepetidos[j]) parar = TRUE;
        }
        if(!parar){ //Caso o número ainda não tenha sido checado
            repetidos->contadorRepetidos = (int*)realloc(
                                                    repetidos->contadorRepetidos, 
                                    (repetidos->qtdRepetidos+1) * sizeof(int));

            repetidos->contadorRepetidos[repetidos->qtdRepetidos] = 
                                buscaSequencial(numeros[i], numeros, qtdNumeros); //Irá procurar a quantidade de vezes que o número se repete

            if(repetidos->contadorRepetidos[repetidos->qtdRepetidos] != 0){
                repetidos->numerosRepetidos = (int*)realloc(repetidos->numerosRepetidos, 
                                    (repetidos->qtdRepetidos+1) * sizeof(int));

                repetidos->numerosRepetidos[repetidos->qtdRepetidos] = numeros[i];
                repetidos->contadorRepetidos[repetidos->qtdRepetidos] = 
                            repetidos->contadorRepetidos[repetidos->qtdRepetidos];
            }
            repetidos->qtdRepetidos++;
        }
    }
    return repetidos;
}

//Aloca memória para a struct Repetidos
Repetidos *alocaRepetidos(){
    Repetidos *repetidos = (Repetidos*)malloc(sizeof(Repetidos));
        repetidos->contadorRepetidos = (int*)malloc(sizeof(int));
        repetidos->contadorRepetidos[0] = 0;
        repetidos->numerosRepetidos = (int*)malloc(sizeof(int));
        repetidos->numerosRepetidos[0] = 0;
        repetidos->qtdRepetidos = 0;
    return repetidos;
}

//Libera a memória que foi alocada no programa
void freeMemoria(Repetidos* repetidos, int* numeros){
    free(repetidos->contadorRepetidos);
    free(repetidos->numerosRepetidos);
    free(numeros);
    free(repetidos);
}

//Imprime os resultados do programa na tela, obedecendo as instruções do run.codes
void printResultado(Repetidos* repetidos){
    for(int i = 0; i < repetidos->qtdRepetidos; i++){
        printf("%d (%d)\n", repetidos->numerosRepetidos[i], 
                            repetidos->contadorRepetidos[i]);
    }
}