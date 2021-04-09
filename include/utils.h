#ifndef UTILS_H
#define UTILS_H

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

#endif  