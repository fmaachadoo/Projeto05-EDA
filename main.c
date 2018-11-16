#include "predef.h"

	int main(){
		//inicializar a raiz da árvore
		arvBin* raiz;
		raiz = (arvBin *)malloc(sizeof(arvBin));
		raiz->no_pai=NULL;
		raiz->filho_esquerda=NULL;
		raiz->filho_direita=NULL;
		
		
		//menu
		int choice;
		int choice2;
		char *filename = (char*)malloc(5*sizeof(char));
		do{
			int choice2 = 0;
			int i;
			i=0;
			printf("			#Arvore Binaria de Busca\n");
			printf("\n");
			printf("MENU DE OPCOES:\n");
			printf("1)Mostrar Arvore.\n");
			printf("2)Procurar Valor.\n");
			printf("3)Inserir Valor.\n");
			printf("10) Sair.\n");
			fflush(stdin);
			scanf("%d",&choice);
			
			switch(choice)
				case 1:{
					printf("Escolha uma Arvore Binaria:\n");
					for(i=1;i<7;i++){
						printf("%d)Arvore Binaria %d\n",i,i);
					}
					scanf("%d",&choice2);					
					get_filename(choice2,filename);
					*raiz = loadTreeFromFile(filename);
					
					break;
				}
			
			
		}while(choice!=10);
		
		
		
		return EXIT_SUCCESS;
	}







