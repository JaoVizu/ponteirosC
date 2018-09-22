#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct produto
{
	char cNome[101];
	char cValidade[101];
	float fValor;
	int iCodigo;
	int iCodigoFornecedor;
} Produto;

typedef struct fornecedor
{
	char cNome[101];
	char cNomeFantasia[101];
	char cEndereco[101];
	char cCnpj[20];
	char cEmail[101];
	char cTelefone[101];
	char cCelular[101];
	int iCodigoProduto;
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

int menu();

/** voids **/
void recebeValorProd(Produto *produto, int *iCont);
void recebeValorForn(Fornecedor *fornecedor, int *contador);
void recebeValorCli(Cliente *cliente, int *contador);
void recebeValorFunc(Funcionario *funcionario, int *contador);
void tiraNCliente(Cliente *cliente, int *cont);
/** cadastro **/
int cadastroProduto();
int cadastroFornecedor();
int cadastroCliente();
int cadastroFuncionario();

/** visualizacao de dados **/
int mostraProduto(Produto *produto, int *contador);
int mostraFornecedor(Fornecedor *fornecedor, int *contador);
int mostraCliente(Cliente *cliente, int *contador);
int mostraFuncionario(Funcionario *funcionario, int *contador);

/** auxiliares **/
char escolha(char *nome);
void flush_in();

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
		system("cls || clear");
		//cadastroProduto();
		//cadastroFornecedor();
		cadastroCliente();
		//cadastroFuncionario();
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
/******************* FUNCOES PARA CADASTRO DE PRODUTOS ********************/
//recebe valor dos produtos
void recebeValorProd(Produto *produto, int *iCont)
{
	printf("Digite o nome do produto: ");
	fgets(produto[*iCont].cNome, sizeof(produto[*iCont].cNome), stdin);
	printf("Digite o valor do produto: ");
	scanf("%f", &produto[*iCont].fValor);
}

//CADASTRA OS PRODUTOS
int cadastroProduto()
{
	//v. auxiliares
	int iCont = 0, iMaximo = 100;
	char retorno;
	Produto *produto = (Produto *)malloc(iMaximo * sizeof(Produto));
	if (!produto)
	{
		printf("Erro na alocacao de memoria! Contate o desenvolvedor do sistema!!\n");
		return 1;
	}

	do
	{
		if (iCont < iMaximo)
		{
			recebeValorProd(produto, &iCont);
			retorno = escolha("produto");
			iCont++;
			flush_in();
		}
		else
		{
			int iNovoMaximo = iMaximo + 100;
			int x;
			Produto *aux = produto;
			produto = (Produto *)malloc(iNovoMaximo * sizeof(Produto));
			if (!produto)
			{
				printf("Erro na alocacao de memoria! Contate o desenvolvedor do sistema!!\n");
				return 1;
			};
			for (x = 0; x < iCont; x++)
			{
				strcpy(produto[x].cNome, aux[x].cNome);
				produto[x].fValor = aux[x].fValor;
			}
			free(aux);
			iMaximo = iNovoMaximo;
			recebeValorProd(produto, &iCont);
			retorno = escolha("produto");
			iCont++;
			flush_in();
		}

	} while (retorno != 'n');
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
		produto[x].cNome[strcspn(produto[x].cNome, "\n")] = '\0';
		printf("%s\t %.2f\n", produto[x].cNome, produto[x].fValor);
	}
}

/******************* FUNCOES PARA CADASTRO DE FORNECEDOR ********************/

void recebeValorForn(Fornecedor *fornecedor, int *contador)
{
	printf("Digite o nome do Fornecedor: ");
	fgets(fornecedor[*contador].cNomeFantasia, sizeof(fornecedor[*contador].cNomeFantasia), stdin);
	printf("Digite o endereco do fornecedor: ");
	fgets(fornecedor[*contador].cEndereco, sizeof(fornecedor[*contador].cEndereco), stdin);
}

int cadastroFornecedor()
{
	int iContF = 0;
	int iMaximo = 100;
	int x;
	char retorno;

	//fazer variavel do tipo fornecedor
	Fornecedor *fornecedor = (Fornecedor *)malloc(iMaximo * sizeof(Fornecedor));
	if (!fornecedor)
	{
		printf("Erro na alocacao de memoria! Contate o desenvolvedor do sistema!!\n");
		return 1;
	}

	do
	{
		//se ultrapassar o limite maximo de cadastro, ira alocar dinamico
		if (iContF < iMaximo)
		{
			recebeValorForn(fornecedor, &iContF);
			retorno = escolha("fornecedor");
			iContF++;
			flush_in();
		}
		else
		{
			Fornecedor *aux = fornecedor;
			int iNovoMaximo = iMaximo + 100;
			fornecedor = (Fornecedor *)malloc(iNovoMaximo * sizeof(Fornecedor));
			if (!fornecedor)
			{
				printf("Erro na alocacao de memoria! Contate o desenvolvedor do sistema!!\n");
				return 1;
			}
			for (x = 0; x < iContF; x++)
			{
				strcpy(fornecedor[x].cNomeFantasia, aux[x].cNomeFantasia);
				strcpy(fornecedor[x].cEndereco, aux[x].cEndereco);
			}
			//liberando memoria
			free(aux);
			iMaximo = iNovoMaximo;
			recebeValorForn(fornecedor, &iContF);
			retorno = escolha("fornecedor");
			iContF++;
			flush_in();
		}
	} while (retorno != 'n');
	mostraFornecedor(fornecedor, &iContF);
}

int mostraFornecedor(Fornecedor *fornecedor, int *contador)
{
	int x;
	printf("\n\t********** FORNECEDORES **********\n");
	for (x = 0; x < *contador; x++)
	{
		fornecedor[x].cNomeFantasia[strcspn(fornecedor[x].cNomeFantasia, "\n")] = '\0';
		fornecedor[x].cEndereco[strcspn(fornecedor[x].cEndereco, "\n")] = '\0';
		printf("Nome Fantasia: %s \t\t Endereco: %s\n", fornecedor[x].cNomeFantasia, fornecedor[x].cEndereco);
	}
}

/******************* FUNCOES PARA CADASTRO DE CLIENTE ********************/

void recebeValorCli(Cliente *cliente, int *contador)
{
	printf("Digite o nome do cliente: ");
	fgets(cliente[*contador].cNomeCli, sizeof(cliente[*contador].cNomeCli), stdin);
	printf("Digite o CPF do cliente: ");
	fgets(cliente[*contador].cCpf, sizeof(cliente[*contador].cCpf), stdin);
	printf("Digite a data de nascimento do cliente: ");
	fgets(cliente[*contador].cData_nascimento, sizeof(cliente[*contador].cData_nascimento), stdin);
	printf("Digite o email do cliente: ");
	fgets(cliente[*contador].cEmail, sizeof(cliente[*contador].cEmail), stdin);
	printf("Digite o endereco do cliente: ");
	fgets(cliente[*contador].cEndereco, sizeof(cliente[*contador].cEndereco), stdin);
	printf("Digite o telefone do cliente: ");
	fgets(cliente[*contador].cTelefone, sizeof(cliente[*contador].cTelefone), stdin);
	printf("Digite o celular do cliente: ");
	fgets(cliente[*contador].cCelular, sizeof(cliente[*contador].cCelular), stdin);
}

int cadastroCliente()
{
	int iContCli = 0;
	int iMaximo = 1;
	int x;
	char retorno;

	Cliente *cliente = (Cliente *)malloc(iMaximo * sizeof(Cliente));
	if (!cliente)
	{
		printf("Erro na alocacao de memoria! Contate o desenvolvedor do sistema!!\n");
		return 1;
	}

	do
	{
		if (iContCli < iMaximo)
		{
			recebeValorCli(cliente, &iContCli);
			retorno = escolha("cliente");
			iContCli++;
			flush_in();
		}
		else
		{
			printf("Entrando no else\n");
			Cliente *aux = cliente;
			int iNovoMaximo = iMaximo + 100;
			cliente = (Cliente *)malloc(iNovoMaximo * sizeof(Cliente *));
			if (!cliente)
			{
				printf("Erro na alocacao de memoria! Contate o desenvolvedor do sistema!!\n");
				return 1;
			}
			for (x = 0; x < iContCli; x++)
			{
				strcpy(cliente[x].cNomeCli, aux[x].cNomeCli);
				strcpy(cliente[x].cData_nascimento, aux[x].cData_nascimento);
				strcpy(cliente[x].cCpf, aux[x].cCpf);
				strcpy(cliente[x].cEmail, aux[x].cEmail);
				strcpy(cliente[x].cTelefone, aux[x].cTelefone);
				strcpy(cliente[x].cCelular, aux[x].cCelular);
				strcpy(cliente[x].cEndereco, aux[x].cEndereco);
			}
			//liberando da memoria
			free(aux);
			iMaximo = iNovoMaximo;
			recebeValorCli(cliente, &iContCli);
			retorno = escolha("cliente");
			iContCli++;
			flush_in();
		}
	} while (retorno != 'n');
	mostraCliente(cliente, &iContCli);
}

int mostraCliente(Cliente *cliente, int *contador)
{
	int x;
	int cont = *contador;
	printf("\n\t********** CLIENTES **********\n");
	for (x = 0; x < *contador; x++)
	{
		tiraNCliente(cliente, &cont);
		printf("Nome Cliente: %s\nCPF: %s\nData Nascimento: %s\n", cliente[x].cNomeCli, cliente[x].cCpf, cliente[x].cData_nascimento);
		printf("Endereco: %s\nTelefone: %s\nCelular: %s\n", cliente[x].cEndereco, cliente[x].cTelefone, cliente[x].cCelular);
		printf("Email: %s\n", cliente[x].cEmail);
	}
}

//retira os \n do final das strings
void tiraNCliente(Cliente *cliente, int *cont)
{
	int x;
	for (x = 0; x < *cont; x++)
	{
		cliente[x].cNomeCli[strcspn(cliente[x].cNomeCli, "\n")] = '\0';
		cliente[x].cCpf[strcspn(cliente[x].cCpf, "\n")] = '\0';
		cliente[x].cEndereco[strcspn(cliente[x].cEndereco, "\n")] = '\0';
		cliente[x].cEmail[strcspn(cliente[x].cEmail, "\n")] = '\0';
		cliente[x].cData_nascimento[strcspn(cliente[x].cData_nascimento, "\n")] = '\0';
		cliente[x].cTelefone[strcspn(cliente[x].cTelefone, "\n")] = '\0';
		cliente[x].cCelular[strcspn(cliente[x].cCelular, "\n")] = '\0';
	}
}

/******************* FUNCOES PARA CADASTRO DE CLIENTE ********************/
void recebeValorFunc(Funcionario *funcionario, int *contador)
{
	printf("Entre com o nome do funcionario: ");
	fgets(funcionario[*contador].cNomeFunc, sizeof(funcionario[*contador].cNomeFunc), stdin);
	printf("Entre com o cargo do funcionario: ");
	fgets(funcionario[*contador].cCargo, sizeof(funcionario[*contador].cCargo), stdin);
}

int cadastroFuncionario()
{
	int iContFunc = 0;
	int iMaximo = 100;
	int x;
	char retorno;
	//variavel do tipo funcionario
	Funcionario *funcionario = (Funcionario *)malloc(iMaximo * sizeof(Funcionario));
	if (!funcionario)
	{
		printf("Erro na alocacao de memoria! Contate o desenvolvedor do sistema!!\n");
		return 1;
	}

	do
	{
		if (iContFunc < iMaximo)
		{
			recebeValorFunc(funcionario, &iContFunc);
			retorno = escolha("funcionario");
			iContFunc++;
			flush_in();
		}
		else
		{
			Funcionario *aux = funcionario;
			int iNovoMaximo = iMaximo + 100;
			funcionario = (Funcionario *)malloc(iNovoMaximo * sizeof(Funcionario));
			if (!funcionario)
			{
				printf("Erro na alocacao de memoria! Contate o desenvolvedor do sistema!!\n");
				return 1;
			}
			for (x = 0; x < iContFunc; x++)
			{
				strcpy(funcionario[x].cNomeFunc, aux[x].cNomeFunc);
				strcpy(funcionario[x].cCargo, aux[x].cCargo);
			}
			//libera da memoria
			free(aux);
			iMaximo = iNovoMaximo;
			recebeValorFunc(funcionario, &iContFunc);
			retorno = escolha("funcionario");
			iContFunc++;
			flush_in();
		}
	} while (retorno != 'n');
	mostraFuncionario(funcionario, &iContFunc);
}

int mostraFuncionario(Funcionario *funcionario, int *contador)
{
	int x;
	printf("\n\t********** FUNCIONARIOS **********\n");
	for (x = 0; x < *contador; x++)
	{
		//retirar o \n do final e adiciona o caracter nulo
		funcionario[x].cNomeFunc[strcspn(funcionario[x].cNomeFunc, "\n")] = '\0';
		funcionario[x].cCargo[strcspn(funcionario[x].cCargo, "\n")] = '\0';
		printf("Nome Funcionario: %s \t Cargo: %s\n", funcionario[x].cNomeFunc, funcionario[x].cCargo);
	}
}

char escolha(char *nome)
{
	char cEscolha;
	printf("Deseja cadastrar mais um %s? (s/n)", nome);
	scanf(" %c", &cEscolha);
	printf("\n");
	return cEscolha;
}

//Limpa buffer do teclado
void flush_in()
{
	int ch;
	while ((ch = fgetc(stdin)) != EOF && ch != '\n')
	{
	}
}
