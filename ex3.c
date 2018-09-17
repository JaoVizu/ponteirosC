#include <stdio.h>
#include <stdlib.h>

int foo(int *n){
  *n += 5;
}
int ordenaVetor(char or,int vetor[], int tamanho);

int main(){
  int *numeros,op, maximoA = 2;
  //auxiliares
  int x, contN = 0;
  numeros = (int*) malloc( maximoA * sizeof(int));
  if(!numeros){
    printf("\nErro na alocacao de memoria!!");
    return 1;
  }

  do{
    printf("0->Sair\n1-> Adicionar numero\n2->Listar numeros\n");
    printf("Entre com uma opcao: ");
    scanf("%d", &op);
    switch(op){
      case 0:
        printf("Saindo...\n");
        Sleep(500);
        printf("Obrigado por utilizar!!\n");
        break;
      case 1:
          system("cls || clear");
          if(contN < maximoA){
            printf("Entre com um numero para adicionar a lista: ");
            scanf("%d", &numeros[contN]);
            contN++;
            printf("Numero cadastrado com sucesso!!\n");
          }else{
            int *aux = numeros;
            int novoTamanho = maximoA + 10;
            numeros = (int*) malloc(novoTamanho * sizeof(int));
            if(!numeros){
              printf("Erro na alocacao de memoria!!\n");
              return 1;
            }
            for(x=0; x<contN; x++){
              numeros[x] = aux[x];
            }
            free(aux);
            maximoA = novoTamanho;
            printf("Entre com um numero para adicionar a lista: ");
            scanf("%d", &numeros[contN]);
            contN++;
            printf("Numero cadastrado com sucesso!!\n");
          }
        break;
      case 2:
          system("cls || clear");
          /*for(x=0; x<contN; x++){
            printf("Numero %d : %d\n", x+1, numeros[x]);
          }*/
          char or;
          printf("Deseja ordenar o vetor em ordem crescente(PRESS C) ou deseja ordenar em ordem decrescente(PRESS D): ");
          scanf(" %c", &or);
          printf("Ordenando...\n");
          Sleep(800);
          ordenaVetor(or,numeros,contN);
        break;

      default:
        printf("Entre com uma opcao valida!!!\n");
        break;
    }
  }while(op != 0);
  return 0;
}

int ordenaVetor(char or,int vetor[], int tamanho){
  int x,y, aux;
  if(or == 'c'){
    for(x=0; x<tamanho; x++){
      for(y=x+1; y<tamanho; y++){
          if(vetor[x] > vetor[y]){
            aux = vetor[x];
            vetor[x] = vetor[y];
            vetor[y] = aux;
          }
      }
    }
  }else{
    for(x=0; x<tamanho; x++){
      for(y=x+1; y<tamanho; y++){
        if(vetor[x] < vetor[y]){
          aux = vetor[x];
          vetor[x] = vetor[y];
          vetor[y] = aux;
        }
      }
    }
  }

  for(x=0; x<tamanho; x++) printf("%d\n", vetor[x]);
  return 0;
}