#include "../include/usuario.h"
#include "../include/utils.h"

int main(){
    tFilme **filmes;
    char *fileName = "./data/filmes-grande.csv";
    int qtdFilmes = contaLinhasCSV(fileName);
    filmes = leFilmes(fileName);
    int counter;
    //char *f = "./data/usuarios.csv"; 
    //char *nome = "alan";
    
    // counter = contaFilmesNoHistoricoCSV(f, nome);
    // printf("%d\n", counter);
    int id = 1;
    float nota = 7.3;
    int dia = 5, mes = 4, ano = 2021;
    tHistorico *hist = criaPrimeiroHistorico();
    hist = adicionaFilmeHistorico(hist, id, nota, dia, mes, ano);
    imprimirHistorico(hist, filmes);
    return 0;
} 