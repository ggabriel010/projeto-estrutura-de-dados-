#ifndef USUARIO_H
#define USUARIO_H

struct Usuario {
    char nome[50];
    char senha[50];
    char email[50];
};

// Declaração das funções relacionadas a usuários
int verificarEmailValido(char* email, struct Usuario* usuarios, int qtdUsuarios);
int login(struct Usuario* usuarios, int qtdUsuarios);
struct Usuario* cadastrarUsuario(struct Usuario* usuarios, int* qtdUsuarios);

#endif