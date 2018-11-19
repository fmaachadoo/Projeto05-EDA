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
	} NO;
	
typedef	NO *arvBin;

//funcoes
arvBin loadTreeFromFile(char[]);
void get_filename(int, char*);	
arvBin inserir_elemento(arvBin , int, arvBin);
void showTree(arvBin);
void printInOrder(arvBin);
void printPreOrder(arvBin);
void printPostOrder(arvBin raiz);
int searchValue(arvBin,int);

arvBin loadTreeFromFile(char filename[]){
	system("cls");
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
	arvore = inserir_elemento(arvore,temp_num,NULL);
	qtd++;
	}
	printf("Quantidade de numeros no arquivo %s: %d\n", filename, qtd);
	return arvore;
	
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


arvBin inserir_elemento(arvBin arvore, int numero, arvBin no_pai){
	arvBin nova;
	
	//printf("debug\n");
	
		if(arvore==NULL){				
			nova = (arvBin)malloc(sizeof(NO));
			nova->filho_direita = NULL;
			nova->filho_esquerda = NULL;
			nova->valor = numero;
			nova->no_pai = no_pai;
			return nova;
		}else{
			if(numero>arvore->valor){
				arvore->filho_direita = inserir_elemento(arvore->filho_direita,numero,arvore);
			}else{
				arvore->filho_esquerda = inserir_elemento(arvore->filho_esquerda,numero,arvore);	
			}				
			return arvore;						
		}
}


void showTree(arvBin raiz){
	printf("%d\n",raiz->valor);
	fflush(stdin); //funcao incompleta
	
	
}

void showTree3(arvBin raiz, int spcNmbr){
	int i;
	
	if(raiz!=NULL){
		showTree3(raiz->filho_direita, spcNmbr - 10);
		printf("\n");
		
		for(i = 0; i < spcNmbr; i++)
			putchar(' ');
			
		printf("%d",raiz->valor);	
		showTree3(raiz->filho_esquerda, spcNmbr + 10);
		printf("\n");
	}
	printf("\n");
}

int getLevelAux(arvBin raiz, int valor, int nivel){ 
    if (raiz == NULL) 
        return 0; 
  
    if (raiz->valor == valor) 
        return nivel;
  
    int niveldown = getLevelAux(raiz->filho_esquerda, valor, nivel + 1); 
    if (niveldown != 0) 
        return niveldown; 
  
    niveldown = getLevelAux(raiz->filho_direita, valor, nivel + 1); 
    return niveldown; 
}

int getLevel(arvBin raiz, int valor){ 
    return getLevelAux(raiz, valor, 1);
}

void printInOrder(arvBin raiz){
	//printf("debug1\n");
	if(raiz!=NULL){
		//printf("debug2\n");
		printInOrder(raiz->filho_esquerda);
		fflush(stdin);
		//printf("debug3\n");		
		printf("%d ",raiz->valor);		
		printInOrder(raiz->filho_direita);
	}
}

void printPreOrder(arvBin raiz){
	if (raiz!=NULL){
	fflush(stdin);
	printf("%d ",raiz->valor); 
    printPreOrder(raiz->filho_esquerda); 
    printPreOrder(raiz->filho_direita); 
    } 	
}

void printPostOrder(arvBin raiz){
	if(raiz!=NULL){
	fflush(stdin);
	printPostOrder(raiz->filho_esquerda);
    printPostOrder(raiz->filho_direita); 
    printf("%d ",raiz->valor);
	}	
}

int searchValue(arvBin raiz,int valor){
	int retorno = 0;
	if(raiz!=NULL){		
		if(raiz->valor==valor){
			printf("Valor Encontrado!\n");
			printf("Valor: %d\n", raiz->valor);
			//falta colocar aqui o print nivel do nó
			printf("Valor do no pai: %d\n",raiz->no_pai->valor);
			if(raiz->valor==raiz->no_pai->filho_esquerda->valor){
				printf("Valor do no irmao(a direita): %d\n",raiz->no_pai->filho_direita->valor);
			}else{
				printf("Valor do no irmao(a esquerda): %d\n",raiz->no_pai->filho_esquerda->valor);
			}
			retorno = 1; 
		}else{
			retorno += searchValue(raiz->filho_esquerda,valor);
			retorno += searchValue(raiz->filho_direita,valor);
		}		
	}
	return retorno;
}










