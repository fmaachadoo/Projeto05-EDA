#include "predef.h"

	int main(){
		//inicializar a raiz da árvore
		arvBin raiz;
		raiz = (arvBin)malloc(sizeof(arvBin));

		
		
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
			printf("\n");
			printf("Escolha uma Arvore Binaria:\n");
					for(i=1;i<7;i++){
						printf("%d)Arvore Binaria %d\n",i,i);
					}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			printf("%d)Fechar o Programa;\n",i);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			
			
			fflush(stdin);
			scanf("%d",&choice);
			
			if(choice < 7){
				do{
					get_filename(choice,filename);
					raiz = loadTreeFromFile(filename);
					printf("\n");
					printf("MENU DE OPCOES:\n");
					if(choice2>10){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					printf("Escolha algum valor valido!\n");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					}else{
						printf("\n");
					}
					printf("1)Mostrar Arvore Atual;\n");
					printf("2)Imprimir na tela se a arvore eh cheia;\n");
					printf("3)Procurar Valor;\n");
					printf("4)Imprimir na tela a altura da arvore;\n");
					printf("5)Remover Valor;\n");
					printf("6)Print In-Order;\n");
					printf("7)Print Pre-Order;\n");
					printf("8)Print Post-Order;\n");
					printf("9)Balancear Arvore;\n");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
					printf("10) Voltar para o menu anterior;\n");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					printf("\n");
					scanf("%d",&choice2);
				
					switch(choice2){
							case 1:{					
						
							break;
							}
							case 10:{
							break;
							}
					}
				
				}while(choice2 != 10);
			}else if(choice>7){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("Escolha algum valor valido!\n");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
		}while(choice!=7);
		
		printf("Fim do programa\n");
		
		return EXIT_SUCCESS;
	}














