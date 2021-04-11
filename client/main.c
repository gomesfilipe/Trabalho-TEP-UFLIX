#include "../include/telas.h"

int main(){
    printf("entrou main2\n");
    printf(".\n");
    char *fileNameFilmes = "./data/filmes-grande.csv";
    char *fileNameHistorico = "./data/historico.csv";
    char *fileNameUsuarios = "./data/usuarios.csv";
    
    tFilme **filmes = leFilmes(fileNameFilmes);
    
    UFLIX(fileNameUsuarios, fileNameHistorico, fileNameFilmes, filmes);
    
    destroiVetorDeFilmes(filmes, fileNameFilmes);
    
    return 0;

} 