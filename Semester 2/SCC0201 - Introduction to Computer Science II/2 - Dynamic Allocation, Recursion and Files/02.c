#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

//define TRUE e FALSE para operacoes booleanas
#define FALSE 0
#define TRUE 1

//struct LABIRINTO,contendo as informacoes do labirinto
typedef struct{
    char** linhas;
    int* numeros;
    int pessoas;
    int espacos_livres;
    int espacos_visitados;
    double porcentagem;
}LABIRINTO;

//definicao das funcoes que serao usadas no programa
void exiberesultado(LABIRINTO*);
void liberamemoria(LABIRINTO*, FILE*);
char* readline(FILE*);
int readint(const char*);
int procuralabirinto(char***, int, int, int, int);
int atualizaposicao(int, int);
int isSaida(char***, int, int, int, int);
FILE* openfile(void);
LABIRINTO* alocalabirinto(void);
LABIRINTO* definelabirinto(FILE*);

//funcao main
int main(int argc, char** argv){
    FILE* arquivo = openfile();
    LABIRINTO* labirinto = definelabirinto(arquivo);
    procuralabirinto(&labirinto->linhas, labirinto->numeros[2], labirinto->numeros[3], 
                    labirinto->numeros[0], labirinto->numeros[1]);
    exiberesultado(labirinto);
    liberamemoria(labirinto, arquivo);    
}

//recebe um FILE*, aloca e armazaena os dados lidos ate encontrar um espaco, uma quebra de linha ou o fim do arquivo. retorna uma string contendo os valores lidos
char* readline(FILE* in){
    int BUFFER = 4096;
    char* string = NULL;
    char caracter = 0;
    int aux = 0;
	do {
		if (aux % BUFFER == 0) {
			string = (char*)realloc(string, ((aux / BUFFER) + 1) * BUFFER);
		}
        caracter = (char)fgetc(in);
        if(caracter != 13) string[aux++] = caracter;
	}while(string[aux-1] != 32 && string[aux-1] != 10 && !feof(in));
	string[aux-1] = '\0';
	string = (char*)realloc(string, aux);
    return string;
}

//recebe uma string e a transforma em um numero inteiro
int readint(const char* STRING){
    int len = strlen(STRING)+1, retornaNumero = 0;
    for(int i = 0; STRING[i] != '\0'; i++) retornaNumero += (STRING[i] - 48) * pow(10, len - (i+2));
    return retornaNumero;
}

//anre um arquivo, com nome lido da entrada padrao, em formato de leitura. caso o arquivo nao exista, uma mensagem é exibida e o programa é encerrado. retorna um FILE* contendo as informacoes desse arquivo
FILE* openfile(void){
    char* nome_arquivo = readline(stdin);
    FILE* arquivo = fopen(nome_arquivo, "r");
    if(!arquivo){
        printf("Arquivo nao encontrado...");
        exit(1);
    }
    free(nome_arquivo);
    return arquivo;
}

//aloca a quantidade de memoria necessaria para um struct labirinto
LABIRINTO* alocalabirinto(void){
    LABIRINTO* labirinto = (LABIRINTO*)malloc(sizeof(LABIRINTO));
        labirinto->linhas = NULL;
        labirinto->numeros = (int*)malloc(4 * sizeof(int));
        labirinto->pessoas = 0;
        labirinto->espacos_livres = 0;
        labirinto->espacos_visitados = 0;
        labirinto->porcentagem = 0;
    return labirinto;
}

//recebe um FILE* e com base em suas informacoes define o struct labirinto. retorna um LABIRINTO* contendo as informacoes
LABIRINTO* definelabirinto(FILE* arquivo){
    LABIRINTO* labirinto = alocalabirinto();
    char** entrada_arquivo = NULL;
    int tam_entrada = 0, pos_numeros = 0, pos_linhas = 0;
    while(!feof(arquivo)){
        entrada_arquivo = (char**)realloc(entrada_arquivo, (tam_entrada+1) * sizeof(char*));
        entrada_arquivo[tam_entrada++] = readline(arquivo);
        if(isdigit(entrada_arquivo[tam_entrada-1][0])){
            labirinto->numeros[pos_numeros++] = readint(entrada_arquivo[tam_entrada-1]);
        }
        else{
            labirinto->linhas = (char**)realloc(labirinto->linhas, (pos_linhas+1) * sizeof(char*));
            labirinto->linhas[pos_linhas] = (char*)malloc((labirinto->numeros[1]+1) * sizeof(char));
            strcpy(labirinto->linhas[pos_linhas++], entrada_arquivo[tam_entrada-1]);
        }
        free(entrada_arquivo[tam_entrada-1]);
    }
    free(entrada_arquivo);
    return labirinto;
}

//funcao recursiva que vai procurar os casos base tentando encontrar uma saída do labirinto
int procuralabirinto(char*** labirinto, int linha_inicial, int coluna_inicial, int qtd_linhas, int qtd_colunas){
    char** auxiliar = *labirinto;
    //Caso Base - encontrou pessoa #
    if(auxiliar[linha_inicial][coluna_inicial] == 35) return FALSE;
    //Caso Base - encontrou local visitado *
    if(auxiliar[linha_inicial][coluna_inicial] == 42) return FALSE;
    //Caso Base - encontrou a saída
    if(isSaida(labirinto, linha_inicial, coluna_inicial, qtd_linhas,qtd_colunas)){
        auxiliar[linha_inicial][coluna_inicial] = 42;
        return TRUE;
    }

    //Caso nada funcione
    auxiliar[linha_inicial][coluna_inicial] = 42;

    int procurar = procuralabirinto(labirinto, linha_inicial-1, coluna_inicial, qtd_linhas, qtd_colunas) ||
                   procuralabirinto(labirinto, linha_inicial, coluna_inicial+1, qtd_linhas,qtd_colunas) ||
                   procuralabirinto(labirinto, linha_inicial+1, coluna_inicial, qtd_linhas,qtd_colunas) ||
                   procuralabirinto(labirinto, linha_inicial, coluna_inicial-1, qtd_linhas,qtd_colunas);

    return procurar;
}

//verifica se a posicao atual é a ultima posicao do labirinto com base no tamanho do labirinto
int isSaida(char*** labirinto, int posicao_linha, int posicao_coluna, int qtd_linhas, int qtd_colunas){
    char** auxiliar = *labirinto;
    int boolean = FALSE;
    if(posicao_linha > 0 && posicao_coluna > 0 && posicao_linha < qtd_linhas-1 && posicao_coluna < qtd_colunas-1) boolean = FALSE;
    else if(auxiliar[posicao_linha][posicao_coluna] == 46) boolean = TRUE;
    return boolean;
}

//exibe os resultados na tela
void exiberesultado(LABIRINTO* labirinto){
    for(int i = 0; i < labirinto->numeros[0]; i++){
        for(int j = 0; j < labirinto->numeros[1]; j++){
            if(labirinto->linhas[i][j] == 35) labirinto->pessoas++;
            if(labirinto->linhas[i][j] == 42){
                labirinto->espacos_visitados++;
                labirinto->espacos_livres++;
            }
            if(labirinto->linhas[i][j] == 46) labirinto->espacos_livres++;
        }
        printf("%s\n", labirinto->linhas[i]);
    }
    labirinto->porcentagem = round((labirinto->espacos_visitados * 100) / labirinto->espacos_livres);
    printf("\nVoce escapou de todos! Ninguem conseguiu te segurar!\nVeja abaixo os detalhes da sua fuga:\n");
    printf("----Pessoas te procurando: %d\n----Numero total de caminhos validos:   %d\n----Numero total de caminhos visitados: %d\n----Exploracao total do labirinto: %.1lf%%\n", 
            labirinto->pessoas, labirinto->espacos_livres,labirinto->espacos_visitados, labirinto->porcentagem);
}

//libera a memoria alocada para o programa
void liberamemoria(LABIRINTO* labirinto, FILE* arquivo){    
    for(int i = 0; i < labirinto->numeros[0]; i++){
        free(labirinto->linhas[i]);
    }
    free(labirinto->linhas);
    free(labirinto->numeros);
    free(labirinto);
    fclose(arquivo);
}

