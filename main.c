#include "predef.h"

	int main(){
		//inicializar a raiz da Arvore
		arvBin raiz;
		raiz = (arvBin) malloc(sizeof(NO));
		
		//menu
		int choice;
		int choice2;
		int choice3;
		int aux=0;
		char *filename = (char*) malloc(5 * sizeof(char));
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
			
			if(choice<7 && choice>0){
				//printf("%s",filename);
				get_filename(choice,filename);
				raiz = loadTreeFromFile(filename);
				do{
					system("cls");
					
					printf("\n");
					printf("MENU DE OPCOES:\n");
					if(choice2>10){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					printf("Escolha algum valor valido!\n");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					}else{
						printf("\n");
					}
					printf("1)Mostrar Arvore Atual;\n");//OK
					printf("2)Imprimir na tela se a arvore eh cheia;\n");	//OK
					printf("3)Procurar Valor;\n"); 		//OK
					printf("4)Imprimir na tela a altura da arvore;\n"); 	//OK
					printf("5)Remover Valor;\n");		//OK
					printf("6)Print In-Order;\n");		//OK
					printf("7)Print Pre-Order;\n");		//OK
					printf("8)Print Post-Order;\n");	//OK
					printf("9)Balancear Arvore;\n"); //FALTA ESSA
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
					printf("10) Voltar para o menu anterior;\n");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					printf("\n");
					fflush(stdin);
					scanf("%d",&choice2);
				
					switch(choice2){
							case 1:{												
								showTree(raiz);
								break;
							}
							case 2:{
								aux = isFull(raiz);
								if(aux==0){
									printf("Arvore nao-cheia\n");
								}else{
									printf("Arvore cheia\n");
								}
								break;
							}
							case 3:{
								aux = 0;
								printf("Digite o valor a ser procurado: ");
								fflush(stdin);
								scanf("%d",&choice3);								
								aux = searchValue(raiz,choice3);
								if(aux==0){
									printf("Valor nao encontrado!\n");
								}else{
									printf("O valor do nivel do no eh: %d\n",getLevel(raiz, choice3));
								}
							break;
							}
							case 4:{
								aux = getHeight(raiz);
								printf("A altura da arvore eh: %d", aux);
								break;
							}
							case 5:{								
								
								printf("Digite o valor a ser excluido: ");
								fflush(stdin);
								scanf("%d",&choice3);
								
								raiz = removeValue(raiz, choice3);
								
							break;
							}
							case 6:{
								printf("\n");
								printf("Print In-Order: ");
								printInOrder(raiz);
								break;
							}
							case 7:{
								printf("\n");
								printf("Print Pre-Order: ");
								printPreOrder(raiz);
								break;
							}
							case 8:{
								printf("\n");
								printf("Print Post-Order: ");
								printPostOrder(raiz);
								break;
							}
							case 9:{
								balanceTree(raiz);
							}
							case 10:{
							break;
							}
					}
					printf("\n");
					printf("Pressione qualquer tecla para continuar... ");
					fflush(stdin);
					getchar();
				}while(choice2 != 10);
			}else if(choice>7 || choice<1){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("Erro: escolha algum valor valido!\n");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			
				printf("\n");
				printf("Pressione qualquer tecla para retornar... ");
				fflush(stdin);
				getchar();
			}
			
		}while(choice!=7);
		
		printf("Fim do programa\n");
		
		return EXIT_SUCCESS;
	}








