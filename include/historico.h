#ifndef HISTORICO_H
#define HISTORICO_H

#include "filme.h"
#include "data.h"
#include "utils.h"

typedef struct historico tHistorico;

/**
 * @brief Faz a leitura de uma data.
 * Esta função não faz tratamento caso a data seja inválida.
 * @param *Essa função não possui parâmetro.
 * @return Ponteiro de tData.
 * */
tData* leData();

/**
 * @brief Conta quantos filmes têm no histórico de um determinado usuário com base em seus dados presentes no arquivo CSV.
 * @param fileName É o caminho do arquivo CSV de históricos.
 * @param idUnica É a idÚnica de um usuário.
 * @return Número de filmes que o usuário possui no histórico.
**/
int contaFilmesNoHistoricoCSV(char *fileName, int idUnica);

/**
 * @brief Aloca memória para o histórico de um usuário e seus campos, caso ele ainda não tenha assistido nenhum filme.
 * @param -Função sem parâmetros
 * @return tHistorico com memória alocada para armazenar as informações do histórico que o usuário ainda irá assistir.
 **/
tHistorico* criaPrimeiroHistorico();

/**
 * @brief Aloca memória para o histórico de um usuário e seus campos.
 * Ela aloca memória para a quantidade de filmes que o usuário já tinha assistido antes e para mais alguns filmes que ele ainda irá assistir.
 * @param idUnica Id do usuário.
 * @param fileName Caminho para o arquivo CSV de históricos.
 * @return tHistorico com memória alocada para armazenar os dados do histórico dos filmes já assistidos e 
 * os dados dos filmes que serão assistidos posteriormente.
 **/
tHistorico* resgataHistorico(int idUnica, char *fileName);


/**
 * @brief Adiciona um filme no histórico de um usuário quando ele assiste a algum filme.
 * Esta função escreve no arquivo CSV de usuários para armazenamento dos dados e também realoca a memória caso seja necesário.
 * @param hist Histórico do usuário.
 * @param id Id do filme assistido pelo usuário.
 * @param nota Avaliação do usuário.
 * @param dia Dia que o usuário assistiu o filme.
 * @param mes Mês que o usuário assistiu o filme.
 * @param ano Ano que o usário assistiu o filme.
 * @param fileName É o caminho do arquivo CSV que possui os filmes no histórico.
 * @param idUnica É o id do usuário.
 * @return Histórico do usuário atualizado.
**/
tHistorico* adicionaFilmeHistorico(tHistorico* hist, int id, float nota, int dia, int mes, int ano, char *fileName, int idUnica);

/**
 * @brief Imprime o histórico de um usuário, com todos filme que assistiu, a respectiva nota e data de cada filme. A data se refere ao dia que o usuário assistiu o filme.
 * @param hist É o histórico de um usuário.
 * @param filmes É o vetor de filmes que possui todos os filmes do catálogo. Os filmes que o usuário assistiu vericamos a partir da ID do filme, sendo que colocamos a ID como campo da struct histórico.
 * @return Essa função não possui retorno.
**/
void imprimirHistorico(tHistorico *hist, tFilme **filmes);

/**
 * @brief Ordena o histórico do usuário de acordo com a data que ele assistiu os filmes.
 * O histórico fica organizado a partir do filme assistido mais recentemente para o filme assistido menos recentemente.
 * @param hist Histórico do usuário.
 * @return -Função sem retorno, pois a ordenação é feita por meio de ponteiros.
 **/
void ordenaHistoricoPorData(tHistorico *hist);

/**
 * @brief Ordena o histórico do usuário de acordo com a nota que ele deu aos filmes.
 * O histórico fica organizado a partir do filme assistido com maior nota para o filme assistido com  menor nota.
 * @param hist Histórico do usuário.
 * @return -Função sem retorno, pois a ordenação é feita por meio de ponteiros.
 **/
void ordenaHistoricoPorNota(tHistorico *hist);

/**
 * @brief Escreve os dados referentes ao histórico do usuário no arquivo CSV.
 * Essa função permite o armazenamento dos dados quando o programa cliente é encerrado.
 * @param id Id do filme assistido.
 * @param nota Avaliação do usuário.
 * @param dia Dia que assistiu o filme.
 * @param mes Mês que assistiu o filme.
 * @param ano Ano que assistiu o filme.
 * @param fileName Caminho para o arquivo CSV que contém os dados dos usuários.
 * @param idUsuario É id única do usuário. Usuários ativos podem ter o mesmo login de usuários inativos, mas não a mesma id.
 * @return Função sem retorno, pois somente escreve no arquivo CSV.
 **/
void imprimeHistoricoCSV(int id, float nota, int dia, int mes, int ano, char *fileName, int idUsuario);

/**
 * @brief Libera da memória um ponteiro de tHistorico.
 * @param hist É o histórico de um usuário.
 * @return Função sem retorno.
 **/
void destroiHistorico(tHistorico *hist);

#endif