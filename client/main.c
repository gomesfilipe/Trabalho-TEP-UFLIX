#include "../include/usuario.h"
#include "../include/utils.h"

int main(){
    char *fileNameFilmes = "./filmes-grande.csv";
    char *fileNameHistorico = "./historico.csv";
    char *fileNameUsuarios = "./usuarios.csv";

    tFilme **filmes = leFilmes(fileNameFilmes);



    return 0;
} 
