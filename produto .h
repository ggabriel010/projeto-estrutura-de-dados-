#ifndef PRODUTO_H
#define PRODUTO_H

struct Produto {
    char nome[50];
    float preco;
    char categoria[50];
};

// Declaração das funções relacionadas a produtos
void listarProdutos(struct Produto* produtos, int qtdProdutos);
struct Produto* adicionarProduto(struct Produto* produtos, int* qtdProdutos);
struct Produto* excluirProduto(struct Produto* produtos, int* qtdProdutos);
void editarProduto(struct Produto* produtos, int qtdProdutos);
void salvarProdutos(struct Produto* produtos, int qtdProdutos);
struct Produto* carregarProdutos(struct Produto* produtos, int* qtdProdutos);

#endif
