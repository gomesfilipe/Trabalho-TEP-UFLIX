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

#endif