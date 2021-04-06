#ifndef HISTORICO_H
#define HISTORICO_H

#include "filme.h"
#include "data.h"

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
 * @param fileName É o caminho do arquivo CSV que possui os filmes no historico
 * @return Número de filmes que o usuário possui no histórico
**/
int contaFilmesNoHistoricoCSV(char *fileName, char *nomeUsuario);

/**
 * @brief Aloca memória para o histórico de um usuário e seus campos, caso ele ainda não tenha assistido nenhum filme.
 * @param -Função sem parâmetros
 * @return tHistorico com memória alocada para armazenar as informações do histórico que o usuário ainda irá assistir.
 **/
tHistorico* criaPrimeiroHistorico();

/**
 * @brief Aloca memória para o histórico de um usuário e seus campos, caso ele já tenha assistido algum filme.
 * Ela difere da função "criaPrimeiroHistorico" pois ela aloca memória para os filmes que o usuário já assistiu
 * e reserva um pouco mais para filmes que ele assistirá posteriormente.
 * @param qtd_filmes_atual Quantidade de filmes assistida.
 * @param data Vetor de ponteiros de tData com as datas de quando o usuário assistiu os filmes. 
 * @param notas Vetor de avaliações feitas aos filmes que o usuário assistiu.
 * @param id Vetor de ids dos filmes que o usuário assistiu.
 * @return tHistorico com memória alocada para armazenar os dados do histórico dos filmes já assistidos e 
 * os dados dos filmes que serão assistidos posteriormente.
 **/
tHistorico* resgataHistorico(int qtd_filmes_atual, tData **data, float *notas, int *id);


/**
 * @brief Acrescenta m
 * @param fileName É o caminho do arquivo CSV que possui os filmes no historico
 * @return Numero de filmes que possui no histórico
**/
tHistorico* adicionaFilmeHistorico(tHistorico* hist, int id, float nota, int dia, int mes, int ano);

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

void imprimeHistoricoCSV(int id, float nota, int dia, int mes, int ano, char *fileName, char *login);

#endif