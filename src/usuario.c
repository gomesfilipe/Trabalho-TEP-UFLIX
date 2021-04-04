#include "../include/usuario.h"

struct usuario{
    char *login; // vetor de caracteres
    char *senha; // vetor de caracteres
    tHistorico *hist; // único elemento
    int ativo; // 1 ta ativo e 0 inativo
};
