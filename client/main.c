#include "../include/telas.h"

int main(int argc, char** argv){  
    int verbosidade = atoi(argv[1]);                 
    char *fileNameFilmes = "./data/filmes-grande.csv";
    char *fileNameHistorico = "./data/historico.csv";
    char *fileNameUsuarios = "./data/usuarios.csv";
    
    tFilme **filmes = leFilmes(fileNameFilmes);
    
    UFLIX(fileNameUsuarios, fileNameHistorico, fileNameFilmes, filmes, verbosidade);
    
    destroiVetorDeFilmes(filmes, fileNameFilmes);
    
    return 0;
} 
