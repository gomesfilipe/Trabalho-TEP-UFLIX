#ifndef USUARIO_H
#define USUARIO_H

#include "historico.h"
#include "../include/utils.h"

#define USUARIONAOCADASTRADO 0
#define LOGINEFETUADO 1
#define SENHAINCORRETA 2

#define USUARIOJACADASTRADO 0
#define CADASTROFEITO 1
#define SENHAERRADA 2
#define LOGINFORADOPADRAO 3
#define SENHAFORADOPADRAO 4



typedef struct usuario tUsuario;

/**
 * @brief Cadastra um novo usuário na UFLIX. 
 * Esta função apenas escreve no arquivo csv de usuários os dados referentes ao cadastro, caso seja válido.
 * @param login Login do usuário.
 * @param senha Senha do usuário.
 * @param confirmaSenha String para verificação se esta e o parâmetro anterior são iguais.
 * @param fileName Caminho para o arquivo csv de usuários.
 * @return 1 caso o cadastro seja válido, 0 caso seja inválido.
 **/
int cadastraUsuario(char *login, char *senha, char *confirmaSenha, char *fileName);

/**
 * @brief Efetua o login de um usuário para acesso ao UFLIX.
 * Esta função faz a verificação se existe no arquivo CSV um par de login e senha iguais aos parâmetros.
 * @param login Login inserido pelo usuário.
 * @param senha senha inserida pelo usuário.
 * @param fileName Caminho para o arquivo CSV de usuários.
 * @return 1, caso o login seja válido e 0 caso o login seja inválido, seja devido ao login não estar cadastrado ou devido a senha estar incorreta.
 **/
int efetuaLogin(char *login, char *senha, char *fileName);

/**
 * @brief Inativa a conta de um usuário (como se fosse excluir a conta).
 * @param usuario Ponteiro para um usuário.
 * @return Ponteiro de usuário com o campo referente a conta estar ativa ou não atualizado.
 **/ 
tUsuario* inativarConta(tUsuario *usuario);

/**
 * @brief Aloca memória para um ponteiro de usuário e seus campos, e os inicializa.
 * @param login Login do usuário.
 * @param senha Senha do usuário.
 * @param fileName Caminho para o arquivo CSV de históricos.
 * @return Ponteiro de usuário com memória alocada e inicializado.
 **/
tUsuario* criaUsuario(char *login, char *senha, char *fileName);

/**
 * @brief Libera memória de um ponteiro de usuário.
 * @param usuario Usuario que será liberado da memória.
 * @return Função sem retorno.
 **/
void destroiUsuario(tUsuario *usuario);

/**
 * @brief Imprime um usuário no terminal.
 * @param usuario Usuário que terá as suas informações impressas na tela.
 * @param filmes Vetor de ponteiros de filme.
 * @return Função sem retorno.
 **/
void imprimeUsuario(tUsuario *usuario, tFilme **filmes);

/**
 * @brief  Captura o campo histórico de um determinado usuário. Esta função serve para evitar o acesso direto
 * ao campo da struct
 * @param usuario É o usuário que terá o histórico capturado.
 * @return Ponteiro que faz referência ao histórico do usuário.
**/
tHistorico* getHistorico(tUsuario* usuario);

/**
 * @brief Captura o campo login de um determinado usuário. Esta função serve para evitar o acesso direto
 * ao campo da struct.
 * @param usuario Usuário que terá o histórico capturado,.
 * @return Ponteiro que faz referência login do usuário.
 **/
char* getLogin(tUsuario* usuario);

#endif