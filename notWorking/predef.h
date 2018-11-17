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
arvBin inserir_elemento(arvBin *, int);

arvBin loadTreeFromFile(char filename[]){
	//abrir o arquivo e ler ele colocando em uma arvore bin de busca.
	arvBin *arvore;
	arvore = (arvBin *) malloc(sizeof(arvBin));
	
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
	
	
	arvore->filho_direita = NULL;
	arvore->filho_esquerda = NULL;
	arvore->no_pai = NULL;
	
	//ler os numeros do arquivo e saber quantos são no arquivo	
	rewind(arquivo);
	while(!feof(arquivo)){	
	fscanf(arquivo, "%d", &temp_num);
	*arvore = inserir_elemento(arvore,temp_num);
	qtd++;
	}
	printf("quantidade de numeros no arquivo %s: %d\n", filename, qtd);
	//criar uma arvore com a quantidade certa de 
	//*arvore = inserir_elemento(arvore,*temp_num);
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
int is_Empty (arvBin *a){ 
int result;
 if(a==NULL){
	 result=0;
	 printf("Arvere NULL\n");
 }else{
	 printf("Arvere not NULL\n");
	 result=1;
 }
 return result;
}  

arvBin inserir_elemento(arvBin *arvore, int numero){
	/*if(arvore==NULL)
		exit(EXIT_FAILURE);
	
	*/
	arvBin *nova;
	nova = (arvBin*) malloc (sizeof(arvBin));
	
	if(nova==NULL)
		exit(EXIT_FAILURE);
	
	printf("Numero: %d\n", numero);
	
		
			//nova = (arvBin*) malloc (sizeof(arvBin));
			
			
			if(arvore->valor==NULL){
				printf("arvore == NULL \n");
			nova->filho_direita = NULL;
			nova->filho_esquerda = NULL;
			nova->valor = numero;
				return *nova;
			}else{		
			printf("RAIZ JA FOI CRIADA\n");
				if(numero<arvore->valor){
					printf("Inserir na esquerda\n");
					return (inserir_elemento(arvore->filho_esquerda,numero));
				}else{
					printf("Inserir na direita\n");
					return (inserir_elemento(arvore->filho_esquerda,numero));
					}
			
			}
}
	