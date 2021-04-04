#include "../include/usuario.h"
#include "../include/utils.h"

int main(){
    tFilme **filmes;
    char *fileName = "./data/filmes-grande.csv";
    //char *busca = (char*) malloc(sizeof(char) * 128 + 1);
    //scanf("%[^\n]", busca);
    char passar = 'x';
    int nPagina = 1;
    
    int qtdFilmes = contaLinhasCSV(fileName);

    filmes = leFilmes(fileName);
    //so estamos testando aqui
    // while(passar != '0'){ //pois 0 é comando de voltar para o menu
    //     imprimePagina(filmes, nPagina, qtdFilmes);
    //     //scanf("%c%c", &passar);
    //     passar = getchar(); //leitura de passar
    //     getchar(); //lendo o /n
    //     if(passar == 'M'){ //ver Mais filmes, ir próxima página
    //         nPagina++;
    //         system("cls");
    //     } else if(passar == 'm'){ //ver menos filmes, voltar página
    //         nPagina--;
    //         system("cls");
    //     } else{
            
    //     }
    // }    
    imprimeTodosOsFilmes(filmes, contaLinhasCSV(fileName)); 

    return 0;
} 