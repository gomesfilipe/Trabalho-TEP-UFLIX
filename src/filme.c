#include "../include/filme.h"
#include "../include/utils.h"

#define TAMPAG 10

struct filme{
    char *titulo; // vetor de caracteres
    char *descricao; // vetor de caracteres
    float nota;
    int duracao;
    int ano;
    int id;
};

// imprimir filme ta feita
// listar filmes ta feita
// pesquisar filmes
// avançar pagina de filmes ta feita eh imprime pagina ta feita
// voltar pagina de filmes 

// lembrar de fazer comentarios

//! LEMBRAR DE INVERTER A ORDEM DA DURACAO E ANO DO FILME NAS FUNCOES POIS NO CSV GRANDE TA INVERTIDO

tFilme* criaFilme(char *titulo, char *descricao, float nota, int duracao, int ano, int id){
    tFilme *filme = (tFilme*) malloc(sizeof(tFilme));
    filme->titulo = strdup(titulo); 
    filme->descricao = strdup(descricao);
    filme->nota = nota;
    filme->duracao = duracao;
    filme->ano = ano;
    filme->id = id;

    return filme;
}

tFilme** leFilmes(char *fileName){
    char *titulo = (char*) malloc(sizeof(char) * 128 + 1); 
    char *descricao = (char*) malloc(sizeof(char) * 256 + 1); 
    float nota; 
    int duracao;
    int ano; 
    int id;
    int i = 0;
    
    int qtdFilmes = contaLinhasCSV(fileName);
    FILE *f = fopen(fileName, "r");

    if(f == NULL){
        printf("Erro na abertura do arquivo");
        exit(1);
    }
    
    tFilme **filmes = (tFilme**) malloc(sizeof(tFilme*) * qtdFilmes);

    if(filmes == NULL){
        printf("Ponteiro Nulo\n");
        exit(1);
    }

    while(!feof(f)){
        fscanf(f, "%[^,],", titulo);
        //printf("titulo: %s\n", titulo);
        
        fscanf(f, "%d,", &duracao);
        //printf("duracao %d\n", duracao);
        
        fscanf(f, "%d,", &ano);
        //printf("ano: %d\n", ano);
        
        fscanf(f, "%f,\"", &nota); //!verificar esse consumo de aspas
        //printf("nota: %.2f\n", nota);
        
        // fscanf(f, "%[^\"]\"\n", descricao);
        fscanf(f, "%[^\n]\n", descricao);
        //printf("descricao: %s\n", descricao);
        
        id = i + 1; // Para o primeiro filme ser o 1 e não o 0.
        //printf("id: %d\n", id);
        // printf("\n");
    
        filmes[i] = criaFilme(titulo, descricao, nota, duracao, ano, id);

        if(feof(f)){
            break;
        }

        i++;
    }

    free(titulo);
    free(descricao);
    fclose(f);
    return filmes;
}

void imprimeFilme(tFilme *filme){ //ver se a formatacao ta certa
    printf("titulo: %s\n", filme->titulo);
    printf("duracao %d\n", filme->duracao);
    printf("ano: %d\n", filme->ano);
    printf("nota: %.2f\n", filme->nota);
    printf("descricao: %s\n", filme->descricao);
    printf("id: %d\n", filme->id);
    printf("\n");
}

void imprimeTodosOsFilmes(tFilme **filmes, int qtdFilmes){
    for(int i = 0; i < qtdFilmes; i++){
        imprimeFilme(filmes[i]);
    }
}

void listarFilmes(tFilme **filmes, int n1, int n2, int qtdFilmes){ // n1 e n2 são os índices dos filmes no vetor
    for(int i = n1; i <= n2 && i < qtdFilmes; i++){
        printf("%s\n",filmes[i]->titulo);
    }
}

void imprimePagina(tFilme **filmes, int nPagina, int qtdFilmes){
    int maxPaginas;
    if(qtdFilmes % TAMPAG == 0){
        maxPaginas = qtdFilmes / TAMPAG;
    } else{
        maxPaginas = qtdFilmes / TAMPAG + 1;
    }
    
    if(nPagina > 0 && nPagina <= maxPaginas){
        int n1 = (nPagina - 1) * TAMPAG;
        int n2 = nPagina * TAMPAG - 1;  
        listarFilmes(filmes, n1, n2, qtdFilmes);
    
    } else{
        printf("Pagina invalida!");
    }
}

// pesquisar filmes
void pesquisaFilmes(char *busca, tFilme **filmes, int qtdFilmes){
    int cont = 1;
    converteMinuscula(busca); // Convertendo para minúsculo para não distinguir letras maiúsculas de minúsculas durante a busca.
    
    for(int i = 0; i < qtdFilmes; i++){
        char *aux = strdup(filmes[i]->titulo);
        converteMinuscula(aux); // Convertendo para minúsculo para não distinguir letras maiúsculas de minúsculas durante a busca.

        if(strstr(aux, busca) != NULL){
            printf("%d - %s\n", cont, filmes[i]->titulo);
            cont++;
        }
        
        free(aux);
    }
}



