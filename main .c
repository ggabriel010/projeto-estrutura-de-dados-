//ALuno: Gabriel Souza Almeida. matricula:2022010788
#include <stdio.h>
#include <stdlib.h>
#include "produto.c"
#include "usuario.c"

int main() {
    struct Produto* produtos = NULL;
    struct Usuario* usuarios = NULL;
    int qtdProdutos = 0;
    int qtdUsuarios = 0;
    int opcao, logado = 0;

    produtos = carregarProdutos(produtos, &qtdProdutos);

    while (1) {
        printf("\n=== MENU ===\n");
        printf("1. Login\n");
        printf("2. Cadastrar Usuário\n");
        printf("3. Listar Produtos\n");
        printf("4. Adicionar Produto\n");
        printf("5. Excluir Produto\n");
        printf("6. Editar Produto\n");
        printf("7. Ordenar Produtos\n");
        printf("8. Buscar Produto\n");
        printf("9. Salvar Produtos\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                logado = login(usuarios, qtdUsuarios);
                break;
            case 2:
                usuarios = cadastrarUsuario(usuarios, &qtdUsuarios);
                break;
            case 3:
                listarProdutos(produtos, qtdProdutos);
                break;
            case 4:
                if (logado) produtos = adicionarProduto(produtos, &qtdProdutos);
                else printf("Você precisa estar logado para adicionar um produto.\n");
                break;
            case 5:
                if (logado) produtos = excluirProduto(produtos, &qtdProdutos);
                else printf("Você precisa estar logado para excluir um produto.\n");
                break;
            case 6:
                if (logado) editarProduto(produtos, qtdProdutos);
                else printf("Você precisa estar logado para editar um produto.\n");
                break;
            case 7:
                break;
            case 8: {
                char nome[50];
                printf("Digite o nome do produto a ser buscado: ");
                scanf("%s", nome);
                int indice = 0;
                if (indice != -1) {
                    printf("Produto encontrado: %s - R$ %.2f - %s\n", produtos[indice].nome, produtos[indice].preco, produtos[indice].categoria);
                } else {
                    printf("Produto não encontrado!\n");
                }
                break;
            }
            case 9:
                salvarProdutos(produtos, qtdProdutos);
                break;
            case 0:
                printf("Saindo do programa...\n");
                free(produtos);
                free(usuarios);
                return 0;
            default:
                printf("Opção inválida!\n");
        }
    }

    return 0;
}
