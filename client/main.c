#include "../include/usuario.h"
#include "../include/utils.h"
#include "../include/tela.h"

int main(){
    char *fileNameFilmes = "./data/filmes-grande.csv";
    char *fileNameHistorico = "./data/historico.csv";
    char *fileNameUsuarios = "./data/usuarios.csv";

    tFilme **filmes = leFilmes(fileNameFilmes);
    //tUsuario **usuario = (tUsuario**) malloc(sizeof(tUsuario*));
    tUsuario *usuario = NULL;
    // printf("ponteiro antes: %p\n", usuario);

    // while(1){
    //     if(telaInicial(fileNameUsuarios, fileNameHistorico, usuario) == PAGINAPRINCIPAL){
    //         printf("ponteiro: %p", usuario);
    //         //imprimeUsuario(usuario, filmes);
    //         printf("\nfoi pra pagina principal\n");
        
    //         return 0;
        
    //     } else{
    //         printf("\nnao foi\n");
    //         return 0;
    //     }
    // }

    telaInicial(fileNameUsuarios, fileNameHistorico, fileNameFilmes, filmes);



    return 0;
} 