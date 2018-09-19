#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXIMO 1500
typedef struct produto
{
  char nome[101];
  float valor;
} Produto;

typedef struct aux {
  char cNome[101];
  float fValor;
} Aux;

int menu();
void flush_in();
void recebeValor(Produto *produto, int *iCont);
int cadastraProduto();
int mostraProduto(Produto *produto, int *contador);

int main()
{
  menu();
  return 0;
}

int menu()
{
  
  int menu;

  printf("**Menu**\n\n");
  printf(" 1-> Administrativo\n");
  printf(" 2-> Caixa\n");
  printf(" 3-> Estoque\n");
  printf("\n Escolha a opcao desejada: ");
  scanf("%d", &menu);
  flush_in();

  switch (menu)
  {

  case 1:
    printf("\n Iniciando Administrativo...\n");
    cadastraProduto();
    break;
  case 2:
    printf("\n Iniciando Caixa...\n");
    break;
  case 3:
    printf("\n Iniciando Estoque...\n");
    break;
  default:
    printf("\n Opcao invalida...\n");
  }
}

void recebeValor(Produto *produto, int *iCont){
  printf("Digite o nome do produto: ");
  fgets(produto[*iCont].nome, sizeof(produto[*iCont].nome), stdin);
  printf("Digite o valor do produto: ");
  scanf("%f", &produto[*iCont].valor);
  *iCont = *iCont + 1; //nao pode usar ++
}

//CADASTRA OS PRODUTOS
int cadastraProduto()
{
  int iCont = 0, iMaximo = 2;
  Produto *produto = (Produto *)malloc(iMaximo * sizeof(Produto));
  if (!produto)
  {
    printf("Erro ao alocar memoria!!!\n");
    return 1;
  }

  char cEscolha;

  do{
    if(iCont < iMaximo){
      recebeValor(produto, &iCont);
      printf("Deseja cadastrar mais um produto? (s/n)");
      scanf(" %c", &cEscolha);
      flush_in();
    }else{
      int iNovoMaximo = iMaximo + 100, x;
      Aux *aux = (Aux *)malloc(iNovoMaximo * sizeof(Aux));
      Produto *produto = (Produto *)malloc(iNovoMaximo * sizeof(Produto));
      aux = produto;
      if (!produto && !aux)
      {
        printf("Erro na alocacao de memoria! Contate o desenvolvedor do sistema!!\n");
        return 1;
      };
      for (x = 0; x < iCont; x++)
      {
        *produto[x].nome = aux[x].cNome;
      }
      free(aux);
      iMaximo = iNovoMaximo;
      recebeValor(produto, &iCont);
      printf("Deseja cadastrar mais um produto? (s/n)");
      scanf(" %c", &cEscolha);
      flush_in();
    }
  } while (cEscolha != 'n');

  mostraProduto(produto, &iCont);
}

//MOSTRA OS PRODUTOS CADASTRADOS
int mostraProduto(Produto *produto, int *contador)
{
  int x;
  printf("\n*** MOSTRANDO PRODUTOS ***\n");
  printf("Nome \t\t Valor Unitario\n\n");
  for (x = 0; x < *contador; x++)
  {
    produto[x].nome[strcspn(produto[x].nome, "\n")] = '\0';
    printf("%s\t %.2f\n", produto[x].nome, produto[x].valor);
  }
  
}


//Limpa buffer do teclado
void flush_in()
{
  int ch;
  while ((ch = fgetc(stdin)) != EOF && ch != '\n'){}
  
}
