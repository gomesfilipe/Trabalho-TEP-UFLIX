#ifndef FILME_H
#define FILME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/utils.h"

#define TAMPAG 10

typedef struct filme tFilme;
/**
 * @brief Aloca memória para um tFilme e inicializa seus campos.
 * @param titulo Título do filme.
 * @param descricao Sinopse do filme.
 * @param nota Nota do filme.
 * @param duracao Duração do filme em minutos.
 * @param ano Ano de lançamento do filme.
 * @param id Id do filme, que corresponde a posição dele no arquivo CSV.
 * @return Ponteiro para tFilme inicializado.
 * */
tFilme* criaFilme(char *titulo, char *descricao, float nota, int duracao, int ano, int id);


/**
 * @brief Faz a leitura de todos os filmes presentes no arquivo CSV e os armazena num vetor de ponteiros de filme.
 * @param fileName String que representa o caminho para o arquivo CSV.
 * @return Um vetor de ponteiros de filme inicializado. 
 **/
tFilme** leFilmes(char *fileName);

/**
 * @brief Imprime a descrição de um determinado Filme ignorando o caractere ' " '.
 * @param filme Ponteiro do filme que contém a descrição em questão.
 **/
void imprimeDescricao(tFilme *filme);

/**
 * @brief Imprime os dados de um ponteiro para filme.
 * @param filme Ponteiro do filme a ser imprimido.
 **/
void imprimeFilme(tFilme *filme);

/**
 * @brief Imprime na tela os filmes de índice n1 até os filmes de índice n2.
 * Esta função faz tratamento quando o índice n2 ultrapassa a quantidade de filmes e quando n1 é menor que 0.
 * @param filmes Vetor de ponteiros de filme.
 * @param n1 Índice do primeiro filme a ser imprimido.
 * @param n2 Índice do último filme a ser imprimido.
 * @param qtdFilmes Quantidade de filmes presente no vetor.
 **/
void listarFilmes(tFilme **filmes, int n1, int n2, int qtdFilmes);

/**
 * @brief Imprime na tela todos os filmes de uma página.
 * @param filmes Vetor de ponteiros de filme.
 * @param nPagina  Número da página da qual os filmes serão impressos.
 * @param qtdFilmes Quantidade de filmes no vetor.
 **/
void imprimePagina(tFilme **filmes, int nPagina, int qtdFilmes);

/**
 * @brief Imprime da tela os filmes que contêm uma string digitada.
 * @param busca String que representa a busca feita pelo usuário.
 * @param filmes Vetor de ponteiros de filme.
 * @param qtdFilmes Quantidade de filmes no vetor.
 **/
void pesquisaFilmes(char *busca, tFilme **filmes, int qtdFilmes);

/**
 * @brief Imprime o título de um filme com determinada id.
 * @param filmes Vetor de ponteiro de filmes.
 * @param id Id do filme a ser imprimido.
 **/
void imprimeTituloFilme(tFilme** filmes, int id);

/**
 * @brief Libera da memória um ponteiro de tFilme.
 * @param filme Filme que será desalocado da memória.
 * @return Função sem retorno.
 **/
void destroiFilme(tFilme *filme);

/**
 * @brief Libera da memória um vetor de ponteiros de tFilme.
 * @param fileName É o caminho do arquivo filmes CSV.
 * @param filmes É o vetor de que armazena todos os filmes do arquivo CSV.
 * @return Função sem retorno.
 **/
void destroiVetorDeFilmes(tFilme **filmes, char *fileName);

#endif
