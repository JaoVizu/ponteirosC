#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto{
	char nome[200];
} Produto;

int menu();
int cadastraProduto(Produto *produto, int *cont);
void mostraProdutos(Produto *produto, int *cont);
int pesquisaProduto(Produto *produto, int *cont, char *nome);
void sair();
void flush_in();

Produto *produto;
int main()
{
	int op;
	int max = 100;
	int cont = 0;
	produto = (Produto *) malloc(max * sizeof(Produto));

	do{
		op = menu();
		flush_in();
		switch(op){
			case 0: sair(); break;
			case 1:
				system("cls || clear");
				cadastraProduto(produto, &cont);
				cont++;
				break;
			case 2:
				system("cls || clear");
				mostraProdutos(produto, &cont);
				break;
			case 3:
				system("cls || clear");
				// variavel para receber o nome
				char *nome;
				//so funcionou alocando assim
				nome = (char *) malloc(1 * sizeof(char));
				printf("Digite o nome do produto que quer pesquisar :");
				fgets(nome, sizeof(nome), stdin);
				nome[strcspn(nome, "\n")] = '\0';
				pesquisaProduto(produto, &cont, nome);
				free(nome);
				break;
			default:
				printf("Entre com uma opcao valida !! \n");
				break;
		}
	}while(op != 0);
	return 0;
}

int menu(){
	int op;
	printf("1 -> Cadastrar nome produto \n");
	printf("2 -> Visualizar produtos\n");
	printf("3 -> Pesquisar produto\n");
	printf("0 -> Sair\n");
	printf("Escolha uma opcao: ");
	scanf("%d", &op);
	return op;
}

void sair(){
	printf("Obrigado por usar o programa!!\n");
}

int cadastraProduto(Produto *produto, int *cont){
	int x; 
	printf("Entre com o nome do produto: ");
	fgets(produto[*cont].nome, sizeof(produto[*cont].nome), stdin);
}

void mostraProdutos(Produto *produto, int *cont){
	int x;
	for(x=0; x< *cont; x++){
		produto[x].nome[strcspn(produto[x].nome, "\n")] = '\0';
		printf("Nome: %s\n", produto[x].nome);
	}
}

int pesquisaProduto(Produto *produto, int *cont, char *nome){
	int x;
	int naoTem = 1;
	for(x=0; x<*cont; x++){
		produto[x].nome[strcspn(produto[x].nome, "\n")] = '\0';
		
		if(strcmp(nome, produto[x].nome) == 0){
			printf("Tem o produto!!\n");
		}
	}
}

//Limpa buffer do teclado
void flush_in(){
	int c;

	while((c = fgetc(stdin)) != EOF && c != '\n'){}
}