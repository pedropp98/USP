#include<stdio.h>
#include<stdlib.h>

int inputPalavra(FILE* in){
    int input;
    input = getc(stdin);
    if(input > 64 && input < 91) input += 32;
    return input;
}

int maiorTamanho(int p1, int p2){
    if(p1 > p2) return 1;
    else if(p2 > p1) return 2;
    else return 0;
}

int ordemAlfabetica(char* p1, char* p2){

    int i = 0;

    while(p1[i] == p2[i] && p1[i] != '\n' && p1[i] != EOF && p2[i] != '\n' && p2[i] != EOF){
                                                                                            
                                                                                            
        i++;
    }
    if(p1[i] < p2[i]) return 1;
                            
    else if(p2[i] < p1[i]) return 2;
                                    
    else return 0;
}

int maiorSoma(char* p1, char* p2){

    int i = 0, size1 = 0, size2 = 0;

    do{
        size1 += (p1[i++] - 97);
    }while(p1[i-1] != '\n' && p1[i-1] != EOF);
    i = 0;

    do{
        size2 += (p2[i++] - 97);
    }while(p2[i-1] != '\n' && p2[i-1] != EOF);

    if(size1 > size2) return 1;
    else if(size2 > size1) return 2;
    else return 0;
}

int repeticoesLetra(char* p1, char* p2){
    int i = 0, size1 = 0, size2 = 0;
    int letra = inputPalavra(stdin);
    do{
        if(p1[i] == letra) size1++;
        i++;
    }while(p1[i-1] != '\n' && p1[i-1] != EOF);
    i = 0;
    do{
        if(p2[i] == letra) size2++;
        i++;
    }while(p2[i-1] != '\n' && p2[i-1] != EOF);

    if(size1 > size2) return 1;
    else if(size2 > size1) return 2;
    else return 0;
}

int primeiroLetra(char* p1, char* p2){

    int i = 0, size1 = 0, size2 = 0;
    int letra = inputPalavra(stdin);
                                    
    do{
        i++;
    }while(p1[i-1] != letra && (p1[i-1] != '\n' && p1[i-1] != EOF));
                                                                    

    if(p1[i-1] == '\n' || p1[i-1] == EOF) size1 = 0;
    else size1 = i;
    i = 0;

    do{
        i++;
    }while(p2[i-1] != letra && (p2[i-1] != '\n' && p2[i-1] != EOF));
                                                                    

    if(p2[i-1] == '\n' || p2[i-1] == EOF) size2 = 0;
    else size2 = i;

    if(size1 < size2) return 1;
    else if(size2 < size1) return 2;
    else return 0;
}

int main(int argc, char** argv){

    int op, result, p1Length = 0, p2Length = 0;
    char* p1 = NULL,* p2 = NULL;

    scanf("%d [^\n]", &op);


    do{
        p1 = (char*)realloc(p1, p1Length + 1);
        p1[p1Length] = inputPalavra(stdin);
        p1Length++;
    }while(p1[p1Length-1] != '\n' && p1[p1Length-1] != EOF);
                                                            
                                                            


    do{
        p2 = (char*)realloc(p2, p2Length + 1);
        p2[p2Length++] = inputPalavra(stdin);
    }while(p2[p2Length-1] != '\n' && p2[p2Length-1] != EOF);
                                                            
    switch(op){
    case 1:
        result = maiorTamanho(p1Length, p2Length);
        break;
    case 2:
        result = ordemAlfabetica(p1, p2);
        break;
    case 3:
        result = maiorSoma(p1, p2);
        break;
    case 4:
        result = repeticoesLetra(p1, p2);
        break;
    case 5:
        result = primeiroLetra(p1, p2);
        break;
    default:
        break;
    }
    free(p1);
    free(p2);
    printf("%d\n", result);
    return 0;
}
