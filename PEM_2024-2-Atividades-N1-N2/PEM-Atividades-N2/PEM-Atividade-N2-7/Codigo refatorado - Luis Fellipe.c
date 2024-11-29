#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUTOS 50
#define CARACTERES 50

// Estrutura de produtos
struct produto {
	int idProduto;
	char nomeProduto[CARACTERES];
	float precoProduto;
	int qtdEstoque;
};

int menuOpcoes(struct produto *produtos, int *quantidade, int *produtosExcluidos);
void adicionarProdutos(struct produto *produtos, int *quantidade, int *produtosExcluidos);
void alterarProduto(struct produto *produtos, int *quantidade);
void consultarProduto(struct produto *produtos, int *quantidade);
void excluirProdutos(struct produto *produtos, int *quantidade, int *produtosExcluidos);
void listarProdutos(struct produto *produtos, int *quantidade);
void comprarProduto(struct produto *produtos, int *quantidade);
int confirmarResposta();

int main() {
//Definição das principais variáveis (array de produtos em estoque, quantidade de produtos diferentes, quantidade de produtos excluidos)
	struct produto produtos[MAX_PRODUTOS];
	int produtosExcluidos = 0;
	int quantidade = 0;
//Definição dos ponteiros para as principais variáveis
	struct produto *ponteiroProdutos = produtos;
	int *ponteiroQuantidade = &quantidade;
	int *ponteiroExcluidos = &produtosExcluidos;

	while(menuOpcoes(ponteiroProdutos, ponteiroQuantidade, ponteiroExcluidos) != 7);

	return 0;
}

int menuOpcoes(struct produto *produtos, int *quantidade, int *produtosExcluidos) {
	int escolha;

	printf("Digite um numero para executar uma funcao do programa:\n");
	printf("1 - Cadastrar Produtos\n2 - Listar Produtos\n3 - Excluir Produto\n4 - Alterar Produto\n5 - Consultar Produto\n6 - Comprar Produto\n7 - Sair\n");
	printf("Escolha: ");
	scanf("%i", &escolha);
	getchar();
	switch (escolha)
	{
	case 1:
		printf("Insira um produto:\n");
		adicionarProdutos(produtos, quantidade, produtosExcluidos);
		return escolha;
		break;
	case 2:
		listarProdutos(produtos, quantidade);
		return escolha;
		break;
	case 3:
		excluirProdutos(produtos, quantidade, produtosExcluidos);
		return escolha;
		break;
	case 4:
		alterarProduto(produtos, quantidade);
		return escolha;
		break;
	case 5:
		consultarProduto(produtos, quantidade);
		return escolha;
		break;
	case 6:
		comprarProduto(produtos, quantidade);
		return escolha;
		break;
	case 7:
		printf("Obrigado por utilizar o programa!");
		return escolha;
		break;
	default:
		printf("Opcao invalida. Tente novamente.\n");
		return escolha;
		break;
	}
	return escolha;
}
// Função para adicionar produtos
void adicionarProdutos(struct produto *produtos, int *quantidade, int *produtosExcluidos) {
//Definição das variáveis que armazenarão os dados do produto temporariamente
//Necessário caso o usuário decida não realizar a inclusão
	int qtdProdutos, qtdDesejada;
	float precoDesejado;
	char nomeDesejado[CARACTERES];

	printf("Quantos produtos serao adicionados? ");
	scanf("%d", &qtdProdutos);
	while (getchar() != '\n');  // Limpar buffer de entrada

	for (int i = 0; i < qtdProdutos; i++) {
		if (*quantidade >= MAX_PRODUTOS) {
			printf("Capacidade maxima de produtos atingida.\n");
			break;
		}

		struct produto *ptrProdutos = &produtos[*quantidade];
		printf("/**************************************************/\n");
		printf("| Nome do produto: ");
		scanf(" %[^\n]%*c", nomeDesejado);  // LC* atC) a nova linha

        precoInvalido:
		printf("| Preco: ");
		scanf("%f", &precoDesejado);
		while (getchar() != '\n'); // Limpar buffer de entrada
		if(precoDesejado<0)
		{
		    printf("Preco do produto nao pode ser menor que 0!\n");
		    goto precoInvalido;
		}

        qtdInvalida:
		printf("| Quantidade em Estoque: ");
		scanf("%d", &qtdDesejada);
		while (getchar() != '\n'); // Limpar buffer de entrada
		if(qtdDesejada<=0)
		{
		    printf("Produto deve ter pelo menos 1 unidade em estoque!\n");
		    goto qtdInvalida;
		}

		printf("/**************************************************/\n");
		
		printf("\nDeseja mesmo adicionar esse produto?");
		if(confirmarResposta() == 0)
	    {
	        i--;
	        ("Deseja sair da funcao de cadastrar produtos?\n");
	        if(confirmarResposta() == 1)
	        {
	            return;
	        }
	    }
	    else
	    {
	        strcpy(ptrProdutos->nomeProduto, nomeDesejado);
	        ptrProdutos->precoProduto = precoDesejado;
	        ptrProdutos->qtdEstoque = qtdDesejada;
	        ptrProdutos->idProduto = *quantidade + (*produtosExcluidos+1);
		    (*quantidade)++;
		    printf("Produto com ID %d adicionado com sucesso.\n", ptrProdutos->idProduto);
	    }
	}
	return;
}

// Função para alterar produto
void alterarProduto(struct produto *produtos, int *quantidade) {
    
    int qtdProdutos, qtdDesejada, id;
	float precoDesejado;
	char nomeDesejado[CARACTERES];
	int encontrado = -1;
	
	printf("Insira o codigo (id) do produto: ");
	scanf("%d", &id);
	while (getchar() != '\n');  // Limpar buffer de entrada

	for (int i = 0; i < *quantidade; i++) {
		struct produto *produtoAtual = &produtos[i];
		if (produtoAtual->idProduto == id) {
		    printf("Produto encontrado!\n");
		    printf("Insira as novas informações!\n");
		    
			printf("/**************************************************/\n");
			printf("| Nome do produto\n");
			printf("(Nome atual: %s)\n",produtoAtual->nomeProduto);
			scanf(" %[^\n]%*c", nomeDesejado);

            precoInvalido:
			printf("| Preco\n");
			printf("(Preco atual: %.2f)\n",produtoAtual->precoProduto);
			scanf("%f", &precoDesejado);
			while (getchar() != '\n'); // Limpar buffer de entrada
			if(precoDesejado<0)
		    {
		        printf("Preco do produto nao pode ser menor que 0!\n");
		        goto precoInvalido;
		    }

            qtdInvalida:
			printf("| Quantidade em Estoque\n");
			printf("(Quantidade atual: %i)\n",produtoAtual->qtdEstoque);
			scanf("%d", &qtdDesejada);
			while (getchar() != '\n'); // Limpar buffer de entrada
			if(qtdDesejada<=0)
		    {
		        printf("Produto deve ter pelo menos 1 unidade em estoque!\n");
		        goto qtdInvalida;
		    }
			printf("/**************************************************/\n");
			
            printf("Deseja mesmo realizar essas alterações?\n");
            if(confirmarResposta() == 0)
	        {
		        return;
	        }
	        else
	        {
	            strcpy(produtoAtual->nomeProduto, nomeDesejado);
	            produtoAtual->precoProduto = precoDesejado;
	            produtoAtual->qtdEstoque = qtdDesejada;
	            printf("Produto com ID %d alterado com sucesso.\n", produtoAtual->idProduto);
			    encontrado = i;
			    break;  
	        }
		}
	}
	if (encontrado == -1) {
		printf("Produto com ID %d nao encontrado.\n", id);
	}
	return;
}

// Função para consultar produto
void consultarProduto(struct produto *produtos, int *quantidade) {
	int id;
	int encontrado = -1;
	printf("Insira o codigo (id) do produto: ");
	scanf("%d", &id);
	while (getchar() != '\n');  // Limpar buffer de entrada

	for (int i = 0; i < *quantidade; i++) {
		struct produto *ptrProdutos = &produtos[i];
		if (ptrProdutos->idProduto == id) {
			printf("/******************** Produto %d ***************************/\n", id);
			printf("| Codigo: %d\n", ptrProdutos->idProduto);
			printf("| Nome: %s", ptrProdutos->nomeProduto);
			printf("| Preco: %.2f\n", ptrProdutos->precoProduto);
			printf("| Quantidade em Estoque: %d\n", ptrProdutos->qtdEstoque);
			printf("/**************************************************/\n\n");
			encontrado = i;
			break;
		}
	}
	if (encontrado == -1) {
		printf("Produto com ID %d nao encontrado.\n", id);
	}
}

// Função para excluir produto
void excluirProdutos(struct produto *produtos, int *quantidade, int *produtosExcluidos) {
	int id;
	int encontrado = -1;

	printf("Insira o codigo(id) do produto a ser excluido: ");
	scanf("%d", &id);
	while (getchar() != '\n');  // Limpar buffer de entrada

	for (int i = 0; i < *quantidade; i++) {
		if (produtos[i].idProduto == id) {
			encontrado = i;
			break;
		}
	}
	if (encontrado == -1) {
		printf("Produto com ID %d nao encontrado.\n", id);
		return;
	}
	
	printf("Tem certeza que deseja excluir esse produto?\n");
	if(confirmarResposta() == 0)
	{
		return;
	}
	else
	{
	    for (int i = encontrado; i < *quantidade - 1; i++) {
	        (produtos + i)->idProduto = (produtos + i+1)->idProduto;
	        strcpy((produtos + i)->nomeProduto, (produtos + i+1)->nomeProduto);
		    (produtos + i)->precoProduto = (produtos + i+1)->precoProduto;
		    (produtos + i)->qtdEstoque = (produtos + i+1)->qtdEstoque;
	    }
	    (*quantidade)--;
	    (*produtosExcluidos)++;
	    printf("Produto com ID %d excluido com sucesso.\n", id);
	    return;    
	}
}
// Função para listar produtos
void listarProdutos(struct produto *produtos, int *quantidade) {
    if(*quantidade <= 0)
    {
        printf("Não temos produtos no estoque no momento!\n");
        return;
    }
    else
    {
        printf("\nListagem dos produtos:\n");
	    printf("\n\n/******************** Lista de Produtos ********************/\n");
	    for (int i = 0; i < *quantidade; i++) {
		    printf("| Codigo: %i\n", (produtos + i)->idProduto);
		    printf("| Nome: %s", (produtos + i)->nomeProduto);
		    printf("| Preco: %.2f\n", (produtos + i)->precoProduto);
		    printf("| Quantidade em Estoque: %i\n", (produtos + i)->qtdEstoque);
		    printf("/**************************************************/\n\n");
	    }
    }
    return;
}
// Função para comprar produtos
void comprarProduto(struct produto *produtos, int *quantidade)
{
	int id, qtdCompra;
	int encontrado = -1;
	float precoCompra;

	printf("Insira o codigo (id) do produto: ");
	scanf("%d", &id);
	while (getchar() != '\n');  // Limpar buffer de entrada

	for (int i = 0; i < *quantidade; i++) {
		struct produto *ptrProdutos = &produtos[i];
		if (ptrProdutos->idProduto == id) {
			printf("Produto encontrado!\n");
			encontrado = i;
			break;
		}
	}
	if (encontrado == -1) {
		printf("Produto com ID %d nao encontrado.\n", id);
		return;
	}

	printf("Quantos(as) '%s' deseja comprar?\n",(produtos + encontrado)->nomeProduto);
	printf("(Quantidade em estoque: %i)\n",(produtos + encontrado)->qtdEstoque);
	scanf("%i",&qtdCompra);
	if(qtdCompra > (produtos + encontrado)->qtdEstoque)
	{
		printf("Quantidade insuficiente em estoque\n");
		return;
	}
	if(qtdCompra < 1)
	{
		printf("Impossivel comprar menos de 1 unidade\n");
		return;
	}

	precoCompra = (produtos + encontrado)->precoProduto*qtdCompra;
	printf("Deseja mesmo comprar %i unidade(s) do produto '%s'?\n",qtdCompra, (produtos + encontrado)->nomeProduto);
	printf("A compra ira custar R$%.2f\n",precoCompra);
	if(confirmarResposta() == 0)
	{
		return;
	}
	else
	{
	    (produtos + encontrado)->qtdEstoque = (produtos + encontrado)->qtdEstoque - qtdCompra;
	    printf("Compra realizada com sucesso!\n");
	    return;    
	}
}

int confirmarResposta()
{
    int resposta;
    
    printf("\n0 - Não/ 1 - Sim\n");
    scanf("%i",&resposta);
    if(resposta < 0 || resposta > 1)
    {
        printf("Resposta inválida!\n");
        printf("Digite o numero ao lado da opção que deseja\n");
        confirmarResposta();
    }
    return resposta;
}