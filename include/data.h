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
