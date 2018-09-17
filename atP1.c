#include <stdio.h>
#include <stdlib.h>
int main(){
	int op;
	int *idade, tamanhoM = 2, cont = 0,x;
	idade = (int*) malloc(tamanhoM * sizeof(int));
	if(!idade){
		printf("Nao foi possivel alocar na memoria!!\n");
		return 1;
	}			
	do{
		printf("\n\t------------------------------\n");
		printf("\t|\t ***** MENU *****    |");
		printf("\n\t| 0 - Sair                   |");
		printf("\n\t| 1 - Adicionar Idade        |");
		printf("\n\t| 2 - Listar idades          |");
		printf("\n\t------------------------------");
		printf("\n\tENTRE COM A OPCAO DESEJADA: ");
		scanf("%d", &op);
		switch(op){
			case 0:
				printf("Saindo...");
				Sleep(500);
				printf("Obrigado por utilizar o programa");
				break;
			case 1:
				system("cls || clear");
				if(cont < tamanhoM){	
					printf("Entre com a idade: ");
					scanf("%d", &idade[cont]);
					cont++;
					printf("Idade %d cadastrada com sucesso!!\n", cont);
				}else{
					int *aux = idade;
					int novoTamanho = tamanhoM + 2;
					idade = (int*) malloc(novoTamanho * sizeof(int));
					if(!idade){
						printf("Nao foi possivel alocar em memoria!!\n");
						return 1;
					}
					for(x=0; x<cont; x++){
						idade[x] = aux[x];
					}
					free(aux);
					tamanhoM = novoTamanho;
					printf("Entre com a idade: ");
					scanf("%d", &idade[cont]);
					cont++;
					printf("Idade %d cadastrada com sucesso!!\n", cont);
				}
				break;
			case 2:
				system("cls || clear");
				printf("Idades:\n");
				int y;
				for(x=0; x<cont; x++){
					for(y=x+1; y<cont; y++){
						if(idade[x] > idade[y]){
							int aux = idade[x];
							idade[x] = idade[y];
							idade[y] = aux;
						}
					}
				}
				
				for(x=0; x<cont; x++){
					printf("%d\n", idade[x]);
				}
				printf("\n");
				break;
			default:
				printf("Opcao invalida!!\n");
				break;
		}
	}while(op != 0);
	return 0;
}
