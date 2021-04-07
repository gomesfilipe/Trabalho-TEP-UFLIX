#ifndef USUARIO_H
#define USUARIO_H

#include "historico.h"

typedef struct usuario tUsuario;

void cadastraUsuario(char *login, char *senha, char *confirmaSenha, char *fileName);

#endif