#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50

// Estrutura de produtos
struct Produtos{
    int idproduto;
    char nomeproduto[50];
    float preçoproduto;
    int qtdestoque;
};

// Função para adicionar produtos
void AdicionarProdutos(struct Produtos produtos[], int *quantidade) {
    int qtdprodutos;
    
    printf("Quantos produtos serao adicionados? ");
    scanf("%d", &qtdprodutos);
    while (getchar() != '\n');  // Limpar buffer de entrada
    
    for (int i = 0; i < qtdprodutos; i++) {
        if (*quantidade >= MAX) {
            printf("Capacidade máxima de produtos atingida.\n");
            break;
        }
        
        struct Produtos *ptrprodutos = &produtos[*quantidade];
        printf("/**************************************************/\n");
        printf("| Nome do produto: ");
        scanf(" %[^\n]%*c", ptrprodutos->nomeproduto);  // Lê até a nova linha

        printf("| Preço: ");
        scanf("%f", &ptrprodutos->preçoproduto);  
        while (getchar() != '\n'); // Limpar buffer de entrada
        
        printf("| Quantidade em Estoque: ");
        scanf("%d", &ptrprodutos->qtdestoque); 
        while (getchar() != '\n'); // Limpar buffer de entrada
        
        printf("/**************************************************/\n");

        ptrprodutos->idproduto = *quantidade + 1; 
        (*quantidade)++;
        printf("Produto com ID %d adicionado com sucesso.\n", ptrprodutos->idproduto);
    }
}

// Função para alterar produto
void AlterarProduto(struct Produtos produtos[], int *quantidade) {
    int id;
    int encontrado = -1;
    printf("Insira o código (id) do produto: ");
    scanf("%d", &id);
    while (getchar() != '\n');  // Limpar buffer de entrada

    for (int i = 0; i < *quantidade; i++) {
        struct Produtos *produtoAtual = &produtos[i];
        if (produtoAtual->idproduto == id) {
            printf("/**************************************************/\n");
            printf("| Nome do produto: ");
            scanf(" %[^\n]%*c", produtoAtual->nomeproduto);

            printf("| Preço: ");
            scanf("%f", &produtoAtual->preçoproduto);
            while (getchar() != '\n'); // Limpar buffer de entrada

            printf("| Quantidade em Estoque: ");
            scanf("%d", &produtoAtual->qtdestoque);
            while (getchar() != '\n'); // Limpar buffer de entrada
            printf("/**************************************************/\n");

            printf("Produto com ID %d alterado com sucesso.\n", produtoAtual->idproduto);
            encontrado = i;
            break;
        }
    }
    if (encontrado == -1) {
        printf("Produto com ID %d não encontrado.\n", id);
    }
}

// Função para consultar produto
void ConsultarProduto(struct Produtos produtos[], int quantidade) {
    int id;
    int encontrado = -1;
    printf("Insira o código (id) do produto: ");
    scanf("%d", &id);
    while (getchar() != '\n');  // Limpar buffer de entrada 
    
    for (int i = 0; i < quantidade; i++) {
        struct Produtos *ptrprodutos = &produtos[i];
        if (ptrprodutos->idproduto == id) {
            printf("/******************** Produto %d ***************************/\n", id);
            printf("| Código: %d\n", ptrprodutos->idproduto);
            printf("| Nome: %s", ptrprodutos->nomeproduto);
            printf("| Preço: %.2f\n", ptrprodutos->preçoproduto);
            printf("| Quantidade em Estoque: %d\n", ptrprodutos->qtdestoque);
            printf("/**************************************************/\n\n");
            encontrado = i;
            break;
        }
    }
    if (encontrado == -1) {
        printf("Produto com ID %d não encontrado.\n", id);
    }
}

// Função para excluir produto
void ExcluirProdutos(struct Produtos *produtos, int *quantidade) {
    int id;
    int encontrado = -1;

    printf("Insira o codigo(id) do produto a ser excluído: ");
    scanf("%d", &id);
    while (getchar() != '\n');  // Limpar buffer de entrada

    for (int i = 0; i < *quantidade; i++) {
        if (produtos[i].idproduto == id) {
            encontrado = i;
            break;
        }
    }
    if (encontrado == -1) {
        printf("Produto com ID %d não encontrado.\n", id);
        return;
    }
    for (int i = encontrado; i < *quantidade - 1; i++) {
        produtos[i] = produtos[i + 1];
    }
    (*quantidade)--;
    printf("Produto com ID %d excluído com sucesso.\n", id);
}

// Função para listar produtos
void ListarProdutos(struct Produtos produtos[], int quantidade) {
    printf("\n\n/******************** Lista de Produtos ********************/\n");
    for (int i = 0; i < quantidade; i++) {
        printf("| Código: %i\n", produtos[i].idproduto);
        printf("| Nome: %s", produtos[i].nomeproduto);
        printf("| Preço: %.2f\n", produtos[i].preçoproduto);
        printf("| Quantidade em Estoque: %i\n", produtos[i].qtdestoque);
        printf("/**************************************************/\n\n");
    }
}

int main(){
    struct Produtos produtos[MAX];
    int quantidade = 0;
    int escolha;

    do {
        printf("Digite um número para executar uma função do programa:\n");
        printf("1 - Cadastrar Produto\n2 - Listar Produtos\n3 - Excluir Produtos\n4 - Alterar Produtos\n5 - Consultar Produtos\n6 - Sair\n");
        printf("Escolha: ");
        scanf("%i", &escolha);
        getchar();
        switch (escolha) {
            case 1:
                printf("Insira um produto:\n");
                AdicionarProdutos(produtos, &quantidade);
                break;
            case 2:
                printf("\nListagem dos produtos:\n");
                ListarProdutos(produtos, quantidade);
                break;
            case 3:
                ExcluirProdutos(produtos, &quantidade);
                break;
            case 4:
                AlterarProduto(produtos, &quantidade);
                break;
            case 5:
                ConsultarProduto(produtos, quantidade);
                break;
            case 6:
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (escolha != 5);
    return 0;
}