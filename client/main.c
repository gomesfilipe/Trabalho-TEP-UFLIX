#include "../include/telas.h"

int main(int argc, char** argv){ //argv é vetor de string   
    int verbosidade = atoi(argv[1]);                    
    char *fileNameFilmes = "./data/filmes-grande.csv";
    char *fileNameHistorico = "./data/historico.csv";
    char *fileNameUsuarios = "./data/usuarios.csv";
    
    tFilme **filmes = leFilmes(fileNameFilmes);
    
    UFLIX(fileNameUsuarios, fileNameHistorico, fileNameFilmes, filmes, verbosidade);
    
    destroiVetorDeFilmes(filmes, fileNameFilmes);
    
    // printf("compilou1\n");
    // char *fileNameUsuarios = "./data/usuarios.csv";
    // char *login = "joaozinho";
    // char *senha = "goiaba";
    //char *confirmaSenha = "goiaba";
    //printf("id unica: %d\n", getIdUnicaUsuario(fileNameUsuarios, login));
    //printf("cadastrou? [%d]\n", cadastraUsuario(login, senha, confirmaSenha, fileNameUsuarios));

    // tUsuario *u = criaUsuario(login, senha, fileNameHistorico, fileNameUsuarios);
    // u = inativarConta(u, fileNameUsuarios); //ver no CSV
    // destroiUsuario(u);
    // int idUnica = 10;
    // tHistorico* h = resgataHistorico(idUnica, fileNameHistorico);

    // imprimirHistorico(h, filmes);
    //imprimeHistoricoCSV(15, 10.0, 12 , 04 , 2021, fileNameHistorico, 10);

    return 0;
} 


// verbosidade 1 exibe menus
// verbosidade 0 nao exibe menus