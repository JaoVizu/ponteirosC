#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct produto{
	char nome[101];
	float valor;
} Produto[2];

int ler(Produto *produto);
int mostrar(Produto *produto);

int main(){
	
	Produto *produto = (Produto *) malloc(sizeof(Produto));
	if(!produto){
		printf("Erro ao alocar memoria!!!\n");
		return 1;
	}
	ler(&produto);
	mostra(&produto);
	return 0;
}

int ler(Produto *produto){
	int x;
	for(x=0; x<2; x++){
		printf("Digite o nome do produto: ");
		fgets(produto[x]->nome, sizeof(produto[x]->nome), stdin);
		printf("Digite o valor do produto: ");
		scanf("%f", &produto[x]->valor);
		fflush(stdin);
		system("cls || clear");
	}
	return 0;
}
int mostra(Produto *produto){
	int x;
	printf("\n*** MOSTRANDO PRODUTOS ***\n");
	for(x=0; x<2; x++){
		produto[x]->nome[strcspn(produto[x]->nome, "\n")] = '\0';
		printf("Nome: %s\tValor Unitario: %.2f\n", produto[x]->nome, produto[x]->valor);
	}
	return 0;
}
