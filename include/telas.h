#ifndef TELAS_H
#define TELAS_H

#include "usuario.h"
#include "utils.h"

//TODO FAZER ENUM

#define LOGIN 1
#define CADASTRO 2
#define SAIR 3

#define LISTARFILMES 1
#define MEUPERFIL 2
#define PROCURARFILME 3
#define SAIDA 4 // Para não repetir SAIR

#define ASSISTIR 1
#define VOLTAR 2

#define VOLTA 1

#define HISTORICO 1
#define EXCLUIR 2
#define VOLT 3

void telaInicial(char *fileNameUsuarios, char *fileNameHistorico, char *fileNameFilmes, tFilme **filmes);

void telaPrincipal(tUsuario* usuario, tFilme **filmes, char *fileNameFilmes, char *fileNameHistorico);

void telaMetaDados(tFilme **filmes, int id, tUsuario *usuario, char* fileNameHistorico);

void telaHistorico(tUsuario* usuario, tFilme** filmes);

void UFLIX(char *fileNameUsuarios, char *fileNameHistorico, char *fileNameFilmes, tFilme **filmes);

#endif