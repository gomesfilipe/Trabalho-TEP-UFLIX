#include "../include/usuario.h"
#include "../include/utils.h"

// TRATAR DO PROBLEMA NAS ASPAS NA LEITURA DO CSV
int main(){
    tFilme **filmes;
    char *fileName = "./data/filmes-grande.csv";
    char *busca = (char*) malloc(sizeof(char) * 128 + 1);
    scanf("%[^\n]", busca);
    
    //busca = converteMinuscula(busca);

    int qtdFilmes = contaLinhasCSV(fileName);

    filmes = leFilmes(fileName);

    //imprimeTodosOsFilmes(filmes, contaLinhasCSV(fileName)); 

    pesquisaFilmes(busca, filmes, qtdFilmes);

    return 0;
}