#ifndef DATA_H
#define DATA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data tData;

/**
 * @brief Inicializa a struct data a partir de três inteiros, alocando memória para ela.
 * Esta função não faz tratamento de datas inválidas.
 * @param dia Dia da determinada data.
 * @param mes Mês da determinada data.
 * @param ano Ano da determinada data.
 * @return Ponteiro para tData inicializado.
 * */
tData* criaData(int dia, int mes, int ano);

/**
* @brief  Obtém o dia de uma data.
* @param data Ponteiro de tData.
* @return Número inteiro que é o dia da data.
**/
int getDia(tData *data);

/**
* @brief  Obtém o mês de uma data.
* @param data Ponteiro de tData.
* @return Número inteiro que é o mês da data.
**/
int getMes(tData *data);

/**
* @brief  Obtém o ano de uma data.
* @param data Ponteiro de tData.
* @return Número inteiro que é o ano da data.
**/
int getAno(tData *data);

/**
 * @brief Atualiza o valor do campo dia de tData.
 * Esta função não faz tratamento caso o dia seja inválido.
 * @param data Ponteiro tData cujo dia será atualizado.
 * @param dia Novo valor do dia para a data.
 * @return tData atualizada.
 * */
tData* setDia(tData *data, int dia);

/**
 * @brief Atualiza o valor do campo mês de tData.
 * Esta função não faz tratamento caso o mês seja inválido.
 * @param data Ponteiro tData cujo mês será atualizado.
 * @param mes Novo valor do mês para a data.
 * @return tData atualizada.
 * */
tData* setMes(tData *data, int mes);

/**
 * @brief Atualiza o valor do campo ano de tData.
 * Esta função não faz tratamento caso o dia seja inválido.
 * @param data Ponteiro tData cujo ano será atualizado.
 * @param ano Novo valor do ano para a data.
 * @return tData atualizada.
 * */
tData* setAno(tData *data, int ano);

/**
 * @brief Verifica se um ano é bissexto.
 * @param data Ponteiro tData.
 * @return 1 se o ano é bissexto e 0 se não é bissexto.
 * */
int EhBissexto(tData *data);


/**
 * @brief Verifica se uma string representa uma data válida.
 * @param str String a ser avaliada.
 * @return 1 se a string represente uma data válida, e 0 caso contrário.
 * */
int dataValida(char *str);

/**
 * @brief Verifica se d1 é maior, menor ou igual a d2.
 * Esta função não faz tratamento caso a data seja inválida.
 * @param d1 Ponteiro de tData. É uma das datas que será comparada.
 * @param d2 Ponteiro de tData. É uma das datas que será comparada.
 * @return 1 se data d1 é maior, -1 se data d2 é menor e 0 se as duas datas são iguais.
 * */
int datacmp(tData *d1, tData *d2);

/**
 * @brief Imprime uma data.
 * Esta função não faz tratamento caso a data seja inválida.
 * @param data Ponteiro tData data.
 * @return Essa função não possui retorno.
 * */
void imprimeData(tData *data);

/**
 * @brief Libera da memória um ponteiro de tData.
 * @param data Ponteiro de data a ser destruído.
 * @return Função sem retorno.
 **/
void destroiData(tData *data);

#endif