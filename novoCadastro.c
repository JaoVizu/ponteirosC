#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct produto
{
    char cvNome[500];
    char cvValidade[100];
    float fValor;
    int iCodigo;
    int iCodigoFornecedor;
    struct Produto *pProximo;
} Produto;

typedef struct fornecedor
{
    char cvNome[101];
    char cvNomeFantasia[101];
    char cvEndereco[101];
    char cvCnpj[20];
    char cvEmail[101];
    char cvTelefone[101];
    char cvCelular[101];
    int iCodigoProduto;
    struct Fornecedor *fProximo;
} Fornecedor;

typedef struct cliente
{
    char cNomeCli[101];
    char cCpf[15];
    char cData_nascimento[101];
    char cEmail[101];
    char cTelefone[101];
    char cCelular[101];
    char cEndereco[101];
} Cliente;

typedef struct funcionario
{
    char cNomeFunc[101];
    char cCargo[101];
    char cCpf[15];
    char cData_nascimento[101];
    char cEmail[101];
    char cTelefone[101];
    char cCelular[101];
    char cEndereco[101];
} Funcionario;

/* DECLARACAO DE STRUCTS */
Produto *pProdutoInicial = NULL;
Fornecedor *fFornecedorInicial = NULL;

/* DECLARACAO DE  FUNCOES */
void sair();
void defaultMessage();
void listarProdutos();
void removeProduto(int iCodigoProduto);
void listarFornecedor();
void flush_in();

/* DECLARACAO DE FUNCOES QUE RETORNAM VALOR */
int menuPrincipal();
int menu();
int menuCadastro();
int cadastrarProduto();
int cadastrarFornecedor();


int main(){
    menu();
    return 0;
}

void sair(){
    printf("\nObrigado por utilizar o programa!!!\n");
}

void defaultMessage(){
    printf("\nPor favor, entre com uma opcao valida!\n");
}

int menuPrincipal()
{
    int iOp;
    printf("**Menu**\n\n");
    printf(" 1-> Cadastro\n");
    printf(" 2-> Caixa\n");
    printf(" 3-> Estoque\n");
    printf("\n Escolha a opcao desejada: ");
    scanf("%d", &iOp);
    return iOp;
}

int menu()
{
    int iOp;
    do
    {
        iOp = menuPrincipal();
        switch (iOp)
        {
        case 0:
            printf("Obrigado por utilizar o software!!\n");
            break;
        case 1:
            system("cls || clear");
            menuCadastro();
            break;
        case 2:
            printf("\n Iniciando Caixa...\n");
            break;
        case 3:
            printf("\n Iniciando Estoque...\n");
            break;
        default: defaultMessage(); break;
        }
    } while (iOp != 0);
}

int menuCadastro(){
    int iOp;

    do{
        printf("\n *** MENU CADASTRO ***");
        printf("\n0- sair");
        printf("\n1- Cadastrar Funcionario");
        printf("\n2- Cadastrar Cliente");
        printf("\n3- Cadastrar Produto");
        printf("\n4- Cadastrar Fornecedor");
        printf("\n5- Listar Produto");
        printf("\n6- Listar Fornecedor");        
        printf("\n\nEntre com a opcao desejada: ");
        scanf("%d", &iOp);
        switch(iOp){
            case 0: break;
            case 2: removeProduto(1); break;
            case 3: cadastrarProduto(); break;
            case 4: cadastrarFornecedor(); break;
            case 5: listarProdutos(); break;
            case 6: listarFornecedor(); break;

            default: defaultMessage(); break;
        }
    }while(iOp != 0);
}

int cadastrarProduto(){
    printf("\n** Cadastro de produtos **\n");
    Produto *pNovoProduto = (Produto*) malloc(sizeof(Produto));
    pNovoProduto->pProximo = NULL;

    printf("\nNome do produto: ");
    flush_in();
    fgets(pNovoProduto->cvNome, sizeof(pNovoProduto->cvNome), stdin);
    pNovoProduto->cvNome[strcspn(pNovoProduto->cvNome, "\n")] = '\0';
    printf("\nData de Validade: ");
    fgets(pNovoProduto->cvValidade, sizeof(pNovoProduto->cvValidade), stdin);
    printf("\nValor do Produto: ");
    scanf("%f", &pNovoProduto->fValor);
    printf("\nCodigo do Produto: ");
    scanf("%d", &pNovoProduto->iCodigo);
    printf("\nCodigo do Fornecedor: ");
    scanf("%d", &pNovoProduto->iCodigoFornecedor);
    flush_in();

    if(pProdutoInicial == NULL){
        pProdutoInicial = pNovoProduto;
    }else{
        Produto *pAux = pProdutoInicial;
        while(pAux->pProximo != NULL){
            pAux = pAux->pProximo;
        }
        pAux->pProximo = pNovoProduto;
    }
}

void listarProdutos(){
    printf("\n*** Listando Produtos ***\n");
    printf("\n--------------------------------------------------------------------------------\n");
    Produto *pAux = pProdutoInicial;
    while(pAux != NULL){
        printf("\nNome: %s |\tValidade: %s", pAux->cvNome, pAux->cvValidade);
        printf("\nValor: %.2f |\tCodigo: %d |\tCodigo Fornecedor: %d", pAux->fValor, pAux->iCodigo, pAux->iCodigoFornecedor);
        printf("\n------------------------------------------------------------------------------\n");
        pAux = pAux->pProximo;
    }
}

void removeProduto(int iCodigoProduto)
{
    printf("\nRemover produto");
    if (pProdutoInicial == NULL)
    {
        printf("\nA lista ja esta vazia!");
    }
    else
    {
        if (pProdutoInicial->pProximo == NULL)
        {
            pProdutoInicial = NULL;
        }
        else
        {
            Produto *pAux = pProdutoInicial;
            pProdutoInicial = pProdutoInicial->pProximo;
            free(pAux);
            pAux = NULL;
        }
    }
}

int cadastrarFornecedor(){
    printf("\nCadastro de Fornecedor");
    Fornecedor *novoFornecedor = (Fornecedor*) malloc(sizeof(Fornecedor));
    novoFornecedor->fProximo = NULL;

    printf("\nNome Fornecedor: ");
    flush_in();
    fgets(novoFornecedor->cvNome, sizeof(novoFornecedor->cvNome), stdin);
    novoFornecedor->cvNome[strcspn(novoFornecedor->cvNome, "\n")] = '\0';
    printf("\nNome Fantasia: ");
    fgets(novoFornecedor->cvNomeFantasia, sizeof(novoFornecedor->cvNomeFantasia), stdin);
    novoFornecedor->cvNomeFantasia[strcspn(novoFornecedor->cvNomeFantasia, "\n")] = '\0';
    printf("\nEndereco: ");
    fgets(novoFornecedor->cvEndereco, sizeof(novoFornecedor->cvEndereco), stdin);
    novoFornecedor->cvEndereco[strcspn(novoFornecedor->cvEndereco, "\n")] = '\0';
    printf("\nCNPJ: ");
    fgets(novoFornecedor->cvCnpj, sizeof(novoFornecedor->cvCnpj), stdin);
    novoFornecedor->cvCnpj[strcspn(novoFornecedor->cvCnpj, "\n")] = '\0';
    printf("\nEmail: ");
    fgets(novoFornecedor->cvEmail, sizeof(novoFornecedor->cvNome), stdin);
    novoFornecedor->cvEmail[strcspn(novoFornecedor->cvEmail, "\n")] = '\0';
    printf("\nTelefone: ");
    fgets(novoFornecedor->cvTelefone, sizeof(novoFornecedor->cvTelefone), stdin);
    novoFornecedor->cvTelefone[strcspn(novoFornecedor->cvTelefone, "\n")] = '\0';
    printf("\nCelular: ");
    fgets(novoFornecedor->cvCelular, sizeof(novoFornecedor->cvCelular), stdin);
    novoFornecedor->cvCelular[strcspn(novoFornecedor->cvCelular, "\n")] = '\0';
    printf("\nCodigo Produto: ");
    scanf("%d", &novoFornecedor->iCodigoProduto);

    if(fFornecedorInicial == NULL) {
        fFornecedorInicial = novoFornecedor;
    }else{
        Fornecedor *fAux = fFornecedorInicial;
        while(fAux->fProximo != NULL){
            fAux = fAux->fProximo;
        }
        fAux->fProximo = novoFornecedor;
    }
}

void listarFornecedor(){
    printf("\nListando Fornecedores");
    printf("\n--------------------------------------------------------------------------------\n");
    Fornecedor *fAux = fFornecedorInicial;
    while(fAux != NULL){
        printf("\nNome: %s |\tNome Fantasia: %s", fAux->cvNome, fAux->cvNomeFantasia);
        printf("\nEndereco: %s |\tCNPJ: %s", fAux->cvEndereco, fAux->cvCnpj);
        printf("\nEmail: %s |\tTelefone: %s ",  fAux->cvEmail, fAux->cvTelefone);
        printf("\nCelular: %s |\tCodigo Produto: %d", fAux->cvCelular, fAux->iCodigoProduto);
        printf("\n------------------------------------------------------------------------------\n");
        fAux = fAux->fProximo;
    }
}

//Limpa buffer do teclado
void flush_in()
{
    int ch;
    while ((ch = fgetc(stdin)) != EOF && ch != '\n')
    {
    }
}
