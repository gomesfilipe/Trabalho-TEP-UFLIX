#include "../include/usuario.h"
#include "../include/utils.h"

int main(){
    tFilme **filmes;
    char *fileName1 = "./data/filmes-grande.csv";
    char *fileName = "./data/historico.csv";
    // int qtdFilmes = contaLinhasCSV(fileName);
    filmes = leFilmes(fileName1);
    //int counter = 0;
    //char *f = "./data/usuarios.csv"; 
    //char *nome = "alan";
    
    // counter = contaFilmesNoHistoricoCSV(f, nome);
    // printf("%d\n", counter);
    // int id = 1;
    // float nota = 7.3;
    // int dia = 5, mes = 4, ano = 2021;
    //tHistorico *hist = criaPrimeiroHistorico();
    // hist = adicionaFilmeHistorico(hist, id, nota, dia, mes, ano);
    // imprimirHistorico(hist, filmes);
    //imprimeHistoricoCSV(id, nota, dia, mes, ano, fileName, nome);

    // float notas[6] = {1.2, 5.3, 3.1, 0.8, 4.4, 9.6};
    // int id[6] = {1, 5, 3, 0, 4, 9};
    // tData **data;
    // data[0] = criaData(1, 2, 2000);
    // data[1] = criaData(5, 2, 2000);
    // data[2] = criaData(3, 2, 2000);
    // data[3] = criaData(0, 2, 2000);
    // data[4] = criaData(4, 2, 2000);
    // data[5] = criaData(9, 2, 2000);

 //adicionaFilmeHistorico(tHistorico* hist, int id, float nota, int dia, int mes, int ano);
    //printf("chegou aqui\n");
    // tHistorico *hist;
    // hist = criaPrimeiroHistorico();
    // hist = adicionaFilmeHistorico(hist, 1, 5.2, 1, 2, 2000);
    // hist = adicionaFilmeHistorico(hist, 5, 7.3, 5, 2, 2000);
    // hist = adicionaFilmeHistorico(hist, 3, 3.1, 3, 2, 2000);
    // hist = adicionaFilmeHistorico(hist, 2, 6.8, 2, 2, 2000);
    // hist = adicionaFilmeHistorico(hist, 4, 1.4, 4, 2, 2000);
    // hist = adicionaFilmeHistorico(hist, 9, 8.6, 9, 2, 2000);

    
    // printf("ordenacao por data:\n");
    // ordenaHistoricoPorData(hist);
    // imprimirHistorico(hist, filmes);
    
    // printf("\n-----------------------\n");

    // printf("ordenacao por nota:\n"); 
    // ordenaHistoricoPorNota(hist);
    // imprimirHistorico(hist, filmes);

    // char *login = "filipe";
    // char *senha = "masterchef";
    // char *confirmaSenha = "masterchefi";

    // cadastraUsuario(login, senha, confirmaSenha, fileName);

    // counter= contaFilmesNoHistoricoCSV(fileName, "123456");
    // printf("%d\n", counter);

    //int id= 95, dia= 6, mes=8, ano=2020;
    //float nota= 10;
    //imprimeHistoricoCSV(id, nota, dia, mes, ano, fileName, "elaine");

    tHistorico* hist;
    char *login = "elaine";
    hist= resgataHistorico(login, fileName);
    imprimirHistorico(hist, filmes);
    printf("\n");
    
    hist = adicionaFilmeHistorico(hist, 1, 5.2, 1, 2, 2000, fileName, login);
    hist = adicionaFilmeHistorico(hist, 3, 3.1, 3, 2, 2000, fileName, login);
    hist = adicionaFilmeHistorico(hist, 2, 6.8, 2, 2, 2000, fileName, login);
    hist = adicionaFilmeHistorico(hist, 4, 1.4, 4, 2, 2000, fileName, login);
    hist = adicionaFilmeHistorico(hist, 9, 8.6, 9, 2, 2000, fileName, login);
    hist = adicionaFilmeHistorico(hist, 1, 5.2, 1, 2, 2000, fileName, login); //realoc aqui
    hist = adicionaFilmeHistorico(hist, 5, 7.3, 5, 2, 2000, fileName, login);
    hist = adicionaFilmeHistorico(hist, 3, 3.1, 3, 2, 2000, fileName, login);
    hist = adicionaFilmeHistorico(hist, 2, 6.8, 2, 2, 2000, fileName, login);
    hist = adicionaFilmeHistorico(hist, 4, 1.4, 4, 2, 2000, fileName, login);
    hist = adicionaFilmeHistorico(hist, 9, 8.6, 9, 2, 2000, fileName, login);
    // hist = adicionaFilmeHistorico(hist, 9, 8.6, 9, 2, 2000, fileName, login);
    // hist = adicionaFilmeHistorico(hist, 9, 8.6, 9, 2, 2000, fileName, login);
    // hist = adicionaFilmeHistorico(hist, 9, 8.6, 9, 2, 2000, fileName, login);
   // hist = adicionaFilmeHistorico(hist, 9, 8.6, 9, 2, 2000, fileName, login);
    
    imprimirHistorico(hist, filmes);
    return 0;
} 
