#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 *@brief Conta a quantidade de linhas preenchidas de um arquivo CSV.
 *@param fileName String com caminho até o arquivo CSV.
 *@return Quantidade de linhas preenchidas do arquivo CSV.
 */
int contaLinhasCSV(char *fileName);

/**
 * @brief Converte as letras maiúsculas de uma string em minúsculas, caso haja letras maiúsculas.
 * @param string É a string que faremos a conversão das letras.
 * @return Essa função não possui retorno.
 **/
char* converteMinuscula(char *string);

/**
 * @brief Limpa o terminal.
 * @param -Função sem parâmetros.
 * @return Função sem retorno.
 **/
void limpaTela();

/**
 * @brief Verifica se uma determinada string representa um número.
 * @param str String a ser verificada.
 * @return 1, caso a string represente um float, e 0 caso contrário.
 **/
int ehStringNumerica(char *str);

#endif  