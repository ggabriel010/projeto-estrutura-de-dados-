//ALuno: Gabriel Souza Almeida. matricula:2022010788
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

// Função para listar os produtos
void listarProdutos(struct Produto* produtos, int qtdProdutos) {
    printf("=== Lista de Produtos ===\n");
    for (int i = 0; i < qtdProdutos; i++) {
        printf("%d. %s - R$ %.2f - %s\n", i + 1, produtos[i].nome, produtos[i].preco, produtos[i].categoria);
    }
    printf("=========================\n");
}

// Função para adicionar um produto à lista
struct Produto* adicionarProduto(struct Produto* produtos, int* qtdProdutos) {
    produtos = realloc(produtos, (*qtdProdutos + 1) * sizeof(struct Produto));

    if (produtos == NULL) {
        printf("Erro ao alocar memória!\n");
        return NULL;
    }

    printf("Digite o nome do produto: ");
    scanf("%s", produtos[*qtdProdutos].nome);
    printf("Digite o preço do produto: ");
    scanf("%f", &produtos[*qtdProdutos].preco);
    printf("Digite a categoria do produto: ");
    scanf("%s", produtos[*qtdProdutos].categoria);

    (*qtdProdutos)++;
    printf("Produto adicionado com sucesso!\n");
    return produtos;
}

// Função para excluir um produto da lista
struct Produto* excluirProduto(struct Produto* produtos, int* qtdProdutos) {
    int escolha;
    listarProdutos(produtos, *qtdProdutos);
    printf("Digite o número do produto que deseja excluir: ");
    scanf("%d", &escolha);

    if (escolha > 0 && escolha <= *qtdProdutos) {
        for (int i = escolha - 1; i < *qtdProdutos - 1; i++) {
            produtos[i] = produtos[i + 1];
        }
        (*qtdProdutos)--;
        produtos = realloc(produtos, (*qtdProdutos) * sizeof(struct Produto));

        if (produtos == NULL && *qtdProdutos > 0) {
            printf("Erro ao realocar memória!\n");
            return NULL;
        }

        printf("Produto excluído com sucesso!\n");
    } else {
        printf("Número do produto inválido!\n");
    }

    return produtos;
}

// Função para editar um produto
void editarProduto(struct Produto* produtos, int qtdProdutos) {
    int escolha;
    listarProdutos(produtos, qtdProdutos);
    printf("Digite o número do produto que deseja editar: ");
    scanf("%d", &escolha);

    if (escolha > 0 && escolha <= qtdProdutos) {
        printf("Digite o novo nome do produto: ");
        scanf("%s", produtos[escolha - 1].nome);
        printf("Digite o novo preço do produto: ");
        scanf("%f", &produtos[escolha - 1].preco);
        printf("Digite a nova categoria do produto: ");
        scanf("%s", produtos[escolha - 1].categoria);
        printf("Produto editado com sucesso!\n");
    } else {
        printf("Número do produto inválido!\n");
    }
}

// Função para salvar produtos em arquivo
void salvarProdutos(struct Produto* produtos, int qtdProdutos) {
    FILE* file = fopen("produtos.txt", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    for (int i = 0; i < qtdProdutos; i++) {
        fprintf(file, "%s %.2f %s\n", produtos[i].nome, produtos[i].preco, produtos[i].categoria);
    }

    fclose(file);
    printf("Produtos salvos com sucesso!\n");
}

// Função para carregar produtos de arquivo
struct Produto* carregarProdutos(struct Produto* produtos, int* qtdProdutos) {
    FILE* file = fopen("produtos.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return NULL;
    }

    *qtdProdutos = 0;
    while (!feof(file)) {
        produtos = realloc(produtos, (*qtdProdutos + 1) * sizeof(struct Produto));
        if (produtos == NULL) {
            printf("Erro ao alocar memória!\n");
            fclose(file);
            return NULL;
        }

        fscanf(file, "%s %f %s", produtos[*qtdProdutos].nome, &produtos[*qtdProdutos].preco, produtos[*qtdProdutos].categoria);
        (*qtdProdutos)++;
    }

    fclose(file);
    printf("Produtos carregados com sucesso!\n");
    return produtos;
}
