j = 0;
do{
	//Lê letra da entrada
	letra = getchar();
	//Coloca a letra lida na string
	nome[j] = letra;
	//Aumenta o indice para ler a proxima letra
	j++;
}
//Ler letras até achar o \n (número 10 na tabela ASC II), ou EOF, indicador de fim de arquivo (testes de entrada)
//que indicam que acabou o nome atual
//EOF será explicado em breve na aula de arquivos, apenas entendam que ele é um valor que indica o fim de um arquivo,
//Assim como '\0' indica o fim de uma string
while((letra != 10) && (letra != EOF));
//Como o ultimo caractere lido não é o '\0', deve ser substituido por '\0', para indicar o fim da string
nome[j-1] = '\0';