#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

// Função para verificar se o email é válido
int verificarEmailValido(char* email, struct Usuario* usuarios, int qtdUsuarios) {
    if (strchr(email, '@') == NULL || strlen(email) >= 80) {
        return 0;
    }

    for (int i = 0; i < qtdUsuarios; i++) {
        if (strcmp(usuarios[i].email, email) == 0) {
            return 0;
        }
    }

    return 1;
}

// Função para fazer login
int login(struct Usuario* usuarios, int qtdUsuarios) {
    char nome[50];
    char senha[50];
    char email[50];
    int tentativas = 3;

    while (tentativas > 0) {
        printf("Digite o nome do usuário: ");
        scanf("%s", nome);
        printf("Digite a senha: ");
        scanf("%s", senha);
        printf("Digite o email: ");
        scanf("%s", email);

        for (int i = 0; i < qtdUsuarios; i++) {
            if (strcmp(usuarios[i].nome, nome) == 0 && strcmp(usuarios[i].senha, senha) == 0 && strcmp(usuarios[i].email, email) == 0) {
                printf("==================================\n");
                printf("Login bem sucedido!\n");
                printf("Bem-vindo, %s!\n", nome);
                printf("==================================\n");
                return 1;
            }
        }

        tentativas--;
        printf("Nome, senha ou email incorretos! Restam %d tentativa(s).\n", tentativas);
    }

    printf("Você excedeu o número de tentativas.\n");
    return 0;
}

// Função para cadastrar um novo usuário
struct Usuario* cadastrarUsuario(struct Usuario* usuarios, int* qtdUsuarios) {
    usuarios = realloc(usuarios, (*qtdUsuarios + 1) * sizeof(struct Usuario));

    if (usuarios == NULL) {
        printf("Erro ao alocar memória!\n");
        return NULL;
    }

    struct Usuario novoUsuario;

    printf("Digite o nome do novo usuário: ");
    scanf("%s", novoUsuario.nome);
    printf("Digite a senha: ");
    scanf("%s", novoUsuario.senha);

    do {
        printf("Digite o email: ");
        scanf("%s", novoUsuario.email);

        if (!verificarEmailValido(novoUsuario.email, usuarios, *qtdUsuarios)) {
            printf("Email inválido ou já existente. Tente novamente.\n");
        }
    } while (!verificarEmailValido(novoUsuario.email, usuarios, *qtdUsuarios));

    usuarios[*qtdUsuarios] = novoUsuario;
    (*qtdUsuarios)++;
    printf("Usuário cadastrado com sucesso!\n");
    return usuarios;
}
