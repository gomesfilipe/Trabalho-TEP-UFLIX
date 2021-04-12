#ifndef TELAS_H
#define TELAS_H

#include "usuario.h"
#include "utils.h"
#include <unistd.h>

enum TelaInicial{LOGIN = 1, CADASTRO, SAIR};
enum TelaPrinciapal{LISTARFILMES = 1, MEUPERFIL, PROCURARFILME, SAIDA};
enum TelaMetaDados{ASSISTIR = 1, VOLTAR};
enum ProcuraFilmes{VOLTA = 1};
enum TelaHistorico{HISTORICO = 1, EXCLUIR, VOLT};

/**
 * @brief Faz o controle do menu inicial da UFLIX, tanto da parte visual quanto das entradas do usuário, realizando
 * login ou casdastro ou sair do programa. Se o login estiver correto ou se o usuário tiver feito cadastro, essa função 
 * direciona para a tela principal da UFLIX.
 * @param fileNameUsuarios É o caminho para o arquico CSV de usuários.
 * @param fileNameUsuarios É o caminho para o arquico CSV de filmes.
 * @param fileNameFilmes É o caminho para o arquico CSV de filmes.
 * @param filmes É o vetor de ponteiros de filme.
 * @return Função sem retorno. 
 **/
void telaInicial(char *fileNameUsuarios, char *fileNameHistorico, char *fileNameFilmes, tFilme **filmes, int verbosidade);

/**
 * @brief Faz o controle do menu principal da UFLIX, tanto da parte visual quanto das entradas do usuário,
 * e direciona para as páginas que efetuam operações, como listar filmes ou pesquisa de filmes. Além disso, 
 * essa função faz verificação caso alguma entrada seja inválida.
 * @param usuario Usuário logado na UFLIX.
 * @param filmes Vetor de ponteiros de filme.
 * @param fileNameFilmes Caminho para o arquivo CSV de filmes.
 * @param fileNameHistorico Caminho para o arquivo CSV de histórico.
 * @param verbosidade Define se haverá verbosidade ou não na tela. Se for igual a 0, não terá, se for 1, terá.
 * @return Função sem retorno.
 **/ 
void telaPrincipal(tUsuario* usuario, tFilme **filmes, char *fileNameFilmes, char *fileNameHistorico, int verbosidade);

/**
 * @brief Tela referente aos metadados de um determinado filme. Nessa janela, o usuário pode escolher para assistir
 * um filme ou retornar para o menu principal. Caso assista, ele pode dar nota e inserir a data que assistiu. Após isso,
 * o usuário retorna para o menu principal. Além disso, essa função faz verificação caso alguma entrada seja inválida.
 * @param filmes Vetor de ponteiros de filme.
 * @param id Id do filme cujos metadados estão sendo mostrados.
 * @param usuario Usuario logado na UFLIX.
 * @param fileNameHistorico Caminho para o arquivo CSV de histórico.
 * @param verbosidade Define se haverá verbosidade ou não na tela. Se for igual a 0, não terá, se for 1, terá.
 * @return Função sem retorno.
 **/
void telaMetaDados(tFilme **filmes, int id, tUsuario *usuario, char* fileNameHistorico, int verbosidade);

/**
 * @brief Tela referente a consulta do histórico do usuário logado. Nela, você pode retornar ao menu principal ou ver 
 * o histórico ordenado por data ou ordenado por nota. Além disso, essa função faz verificação caso alguma entrada seja inválida.
 * @param usuario Usuario logado na UFLIX.
 * @param filmes Vetor de ponteiros de filme.
 * @param verbosidade Define se haverá verbosidade ou não na tela. Se for igual a 0, não terá, se for 1, terá.
 * @return Função sem retorno.
 **/
void telaHistorico(tUsuario* usuario, tFilme** filmes, int verbosidade);

/**
 * @brief Executa o sistema UFLIX. Nessa função é contida todo o programa cliente, ou seja, permite acesso a todas as telas e
 * são efetuadas todas as operações solicitadas pelo usuário.
 * @param fileNameUsuarios Caminho para o arquivo CSV de usuários.
 * @param fileNameHistorico Caminho para o arquivo CSV de históricos.
 * @param fileNameFilmes Caminho para o arquivo CSV de filmes.
 * @param filmes Vetor de ponteiros de filme.
 * @param verbosidade Define se haverá verbosidade ou não na tela. Se for igual a 0, não terá, se for 1, terá.
 * @return Função sem retorno.
 **/
void UFLIX(char *fileNameUsuarios, char *fileNameHistorico, char *fileNameFilmes, tFilme **filmes, int verbosidade);

#endif