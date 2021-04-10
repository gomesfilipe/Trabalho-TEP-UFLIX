#ifndef TELA_H
#define TELA_H

#include "usuario.h"

#define LOGIN 1
#define CADASTRO 2
#define SAIR 3

#define LISTARFILMES 1
#define MEUPERFIL 2
#define PROCURARFILME 3
#define SAIDA 4 // Para não repetir SAIR

#define ASSISTIR 1
#define VOLTAR 2

// #define PAGINAINICIAL 0
// #define PAGINAPRINCIPAL 1
// #define ENCERRAR 2

void telaInicial(char *fileNameUsuarios, char *fileNameHistorico, char *fileNameFilmes, tFilme **filmes);

//void telaPrincipal(tUsuario* usuario, );



#endif