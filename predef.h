#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define EXIT_SUCCESS 		0
#define EXIT_FAILURE 		1

typedef struct no{
		int valor;
		struct no *no_pai;
		struct no *filho_esquerda;
		struct no *filho_direita;
	} arvBin;

//funcoes
arvBin loadTreeFromFile(char[]);
void get_filename(int, char*);	

arvBin loadTreeFromFile(char filename[]){
	//abrir o arquivo e ler ele colocando em uma arvore bin de busca.
	FILE *arquivo;
	char path[] = "BSTs/";
	strcat(path,filename);
	printf("path : %s\n",path);
	arquivo = fopen(path,"r");
	if (arquivo==NULL){	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		printf("ERRO AO ABRIR O ARQUIVO");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		exit(EXIT_FAILURE);		
	}	
	//aqui ainda nao esta pronto, falta ler o arquivo e montar a arvore
}

void get_filename(int choice2, char* resultado){	
	char arquivo[6] = "bst";
	char txt[5] = ".txt";
	char id_file[6];
	//printf("function running...\n");
		itoa(choice2,id_file,10);		
		strcat(id_file,txt);		
		strcat(arquivo,id_file);	
		strcpy(resultado,arquivo);
		
	//printf("done!\n");
	
}

int isEmpty(arvBin a){
	return (a == NULL);
	} 

arvBin inserir_elemento(arvBin arvore, int numero){
	arvBin nova;
		//Parei aqui pra fazer
}
	
