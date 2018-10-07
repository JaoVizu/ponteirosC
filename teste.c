#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno {
    char *nome;
    struct Aluno *proximo;
} Aluno;

Aluno *alunoInicial = NULL;

void cadastraAluno();

int main(){
    cadastraAluno();
    return 0;
}

void cadastraAluno()
{
    Aluno *novoAluno = (Aluno *)malloc(sizeof(Aluno));
    novoAluno->proximo = NULL;
    printf("\nDigite o nome do novo aluno:");
    fgets(novoAluno->nome, sizeof(novoAluno->nome), stdin);
    if (alunoInicial == NULL){
        alunoInicial = novoAluno;
    }else{
        Aluno *aux = alunoInicial;
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        aux->proximo = novoAluno;
    }
}