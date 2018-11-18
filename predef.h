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
		struct no *filho_esquerda;
		struct no *filho_direita;
	} NO;
	
typedef	NO *arvBin;

//funcoes
arvBin loadTreeFromFile(char[]);
void get_filename(int, char*);	
arvBin inserir_elemento(arvBin , int);

arvBin loadTreeFromFile(char filename[]){
	//abrir o arquivo e ler ele colocando em uma arvore bin de busca.
	arvBin arvore=NULL;
	//arvore = (arvBin *) malloc(sizeof(arvBin));
	
	int temp_num;
	int qtd = 0;
	
	
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
	
	
	
	//ler os numeros do arquivo e saber quantos são no arquivo	
	rewind(arquivo);
	while(!feof(arquivo)){	
	fscanf(arquivo, "%d", &temp_num); 
	printf("valor: %d\n",temp_num);
	arvore = inserir_elemento(arvore,temp_num);
	qtd++;
	}
	printf("quantidade de numeros no arquivo %s: %d\n", filename, qtd);
	//criar uma arvore com a quantidade certa de 
	//arvore = inserir_elemento(arvore,*temp_num);
	printf("aaaa\n");
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


arvBin inserir_elemento(arvBin arvore, int numero){
	arvBin nova;
	//printf("debug\n");
	
		if(arvore==NULL){				
			nova = (arvBin)malloc(sizeof(NO));
			nova->filho_direita = NULL;
			nova->filho_esquerda = NULL;
			nova->valor = numero;
			printf("Valor alocado:%d\n",numero);
			return nova;
		}else{
			if(numero>arvore->valor){
				arvore->filho_direita = inserir_elemento(arvore->filho_direita,numero);
			}else{
				arvore->filho_esquerda = inserir_elemento(arvore->filho_esquerda,numero);	
			}				
			return arvore;						
		}
}

