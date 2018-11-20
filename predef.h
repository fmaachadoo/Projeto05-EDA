
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

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
int getHeight(arvBin);
void printLevel(arvBin,int,arvBin);
int getLevel(arvBin, int);

arvBin loadTreeFromFile(char filename[]){
	system("cls");
	//abrir o arquivo e ler ele colocando em uma arvore bin de busca.
	arvBin arvore=NULL;
	//arvore = (arvBin *) malloc(sizeof(arvBin));
	printf("eoq\n");
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
	fclose(arquivo);
	return arvore;
	
}

void get_filename(int choice2, char* resultado){	

	char arquivo[3] = "bst";
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



/*void showTree(arvBin raiz){
	int space;
	int i=0;
	int j=0;
	int levelmax = getHeight(raiz)+1;
	arvBin elem;
	elem = raiz;
	for(j=2;j<=levelmax+2;j++){
	printLevel(raiz, j, elem);
	printf("\n");
	
	}
	//fflush(stdin); //funcao incompleta
	
	
}*/
int print_tree(arvBin raiz, int is_left, int offset, int profnd, char s[20][255])
{
    char b[20];
    int width = 5;

    if(raiz==NULL){ 
	return 0;
	}
    sprintf(b, "(%03d)", raiz->valor);
    int filho_esquerda  = print_tree(raiz->filho_esquerda,  1, offset,                profnd + 1, s);
    int filho_direita = print_tree(raiz->filho_direita, 0, offset + filho_esquerda + width, profnd + 1, s);

#ifdef COMPACT
    for (int i = 0; i < width; i++)
        s[profnd][offset + filho_esquerda + i] = b[i];

    if (profnd && is_left) {

        for (int i = 0; i < width + filho_direita; i++)
            s[profnd - 1][offset + filho_esquerda + width/2 + i] = '-';

        s[profnd - 1][offset + filho_esquerda + width/2] = '.';

    } else if (profnd && !is_left) {

        for (int i = 0; i < filho_esquerda + width; i++)
            s[profnd - 1][offset - width/2 + i] = '-';

        s[profnd - 1][offset + filho_esquerda + width/2] = '.';
    }
#else
    for (int i = 0; i < width; i++)
        s[2 * profnd][offset + filho_esquerda + i] = b[i];

    if (profnd && is_left) {

        for (int i = 0; i < width + filho_direita; i++)
            s[2 * profnd - 1][offset + filho_esquerda + width/2 + i] = '-';

        s[2 * profnd - 1][offset + filho_esquerda + width/2] = '+';
        s[2 * profnd - 1][offset + filho_esquerda + width + filho_direita + width/2] = '+';

    } else if (profnd && !is_left) {

        for (int i = 0; i < filho_esquerda + width; i++)
            s[2 * profnd - 1][offset - width/2 + i] = '-';

        s[2 * profnd - 1][offset + filho_esquerda + width/2] = '+';
        s[2 * profnd - 1][offset - width/2 - 1] = '+';
    }
#endif

    return filho_esquerda + width + filho_direita;
}

void showTree(arvBin raiz)
{
	printf("Print da Arvore Binaria\n");
    char s[20][255];
    for (int i = 0; i < 20; i++)
        sprintf(s[i], "%80s", " ");

    print_tree(raiz, 0, 0, 0, s);

    for (int i = 0; i < 20; i++)
        printf("%s\n", s[i]);
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
			if(raiz->no_pai!=NULL){
				printf("Valor do no pai: %d\n",raiz->no_pai->valor);
				if(raiz->valor==raiz->no_pai->filho_esquerda->valor){
					printf("Valor do no irmao(a direita): %d\n",raiz->no_pai->filho_direita->valor);
				}else{
					printf("Valor do no irmao(a esquerda): %d\n",raiz->no_pai->filho_esquerda->valor);
				}
			}else{
				printf("Esse eh o no raiz da arvore e nao possui no pai e nem irmaos\n");
			}
			retorno = 1; 
		}else{
			
			retorno += searchValue(raiz->filho_esquerda,valor);
			retorno += searchValue(raiz->filho_direita,valor);
		}		
	}
	return retorno;
}

int getHeight(arvBin raiz){
    if (raiz == NULL) {
        return -1;
    }

    int esquerda = getHeight(raiz->filho_esquerda);
    int direita = getHeight(raiz->filho_direita);

    if (esquerda > direita) {
        return esquerda + 1;
    } else {
        return direita + 1;
    }
}









