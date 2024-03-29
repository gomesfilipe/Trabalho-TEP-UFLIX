#include "../include/filme.h"

struct filme{
    char *titulo;
    char *descricao;
    float nota;
    int duracao;
    int ano;
    int id;
};

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
    // char *titulo = (char*) malloc(sizeof(char) * 128 + 1); // Antes da entrevista.
    // char *descricao = (char*) malloc(sizeof(char) * 256 + 1); // Antes da entrevista.
    char titulo[129];
    char descricao[257];
    float nota; 
    int duracao;
    int ano; 
    int id;
    int i = 0;
    char c;
    int tam = 500;

    // int qtdFilmes = contaLinhasCSV(fileName); // Antes da entrevista.
    FILE *f = fopen(fileName, "r");  

    if(f == NULL){
        printf("Erro na abertura do arquivo");
        exit(1);
    }
    
    // tFilme **filmes = (tFilme**) malloc(sizeof(tFilme*) * qtdFilmes); // Antes da entrevista.
    tFilme **filmes = (tFilme**) malloc(sizeof(tFilme*) * tam); // Alocando 500 espaços de memória para os filmes inicialmente.

    if(filmes == NULL){
        printf("Ponteiro Nulo\n");
        exit(1);
    }

    
    while(!feof(f)){
        fscanf(f, "%[^,],", titulo);
        fscanf(f, "%d,", &ano);
        fscanf(f, "%d,", &duracao);
        fscanf(f, "%f,", &nota);
        fscanf(f, "%[^\n]\n", descricao); // Casos haja aspas, vamos ler e fazer o tratamento de tirar na impressão da descrição.
        id = i + 1; // Para o primeiro filme ser o 1 e não o 0.
        
        filmes[i] = criaFilme(titulo, descricao, nota, duracao, ano, id);

        i++;
        
        if(feof(f)){
            break;
        }

        // Depois da entrevista.
        if(i == tam){
            tam += 500; // Adicionando 500 espaços no tamanho do vetor de filmes.
            filmes = (tFilme**) realloc(filmes, sizeof(tFilme*) * tam); 
        }
    }

    // free(titulo); // Antes da entrevista.
    // free(descricao); //Antes da entrevista.
    fclose(f);
    return filmes;
}

void imprimeFilme(tFilme *filme){
    printf("Titulo: %s\n", filme->titulo);
    printf("Ano: %d\n", filme->ano);
    printf("Duracao: %d minutos\n", filme->duracao);
    printf("Avaliacao: %.1f\n", filme->nota);
    imprimeDescricao(filme); 
    printf("\n");
}

void listarFilmes(tFilme **filmes, int n1, int n2, int qtdFilmes){
    // n1 e n2 são os índices dos filmes do vetor de filmes que estão na primeira e na última posição da página.
    for(int i = n1; i <= n2 && i < qtdFilmes; i++){     
        printf("%d- %s\n",filmes[i]->id, filmes[i]->titulo);
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
        
        if(n2 >= qtdFilmes){
            n2 = qtdFilmes - 1;
        }
        
        listarFilmes(filmes, n1, n2, qtdFilmes);
    
    } else{
        printf("Fim de filmes disponiveis\n");
    }
}

void pesquisaFilmes(char *busca, tFilme **filmes, int qtdFilmes){
    int cont = 0;
    converteMinuscula(busca); // Convertendo para minúsculo para não distinguir letras maiúsculas de minúsculas durante a busca.
    
    for(int i = 0; i < qtdFilmes; i++){
        char *aux = strdup(filmes[i]->titulo);
        converteMinuscula(aux); // Convertendo para minúsculo para não distinguir letras maiúsculas de minúsculas durante a busca.

        if(strstr(aux, busca) != NULL){
            printf("%d - %s\n", filmes[i]->id, filmes[i]->titulo);
            cont++;
        }
        
        free(aux);
    }

    if(cont == 0){
        printf("Nenhum filme encontrado\n");
    }
}

void imprimeDescricao(tFilme *filme){ 
    printf("Descricao: ");
    for(int i = 0; filme->descricao[i] != '\0' ; i++){
        if(filme->descricao[i] != '"'){
            printf("%c", filme->descricao[i]);  
        }
    }

    printf("\n");
}

void imprimeTituloFilme(tFilme** filmes, int id){
    printf("%s", filmes[id - 1]->titulo); // Id é a posição do filme no vetor, -1 é porque o vetor começa em zero.
}

void destroiFilme(tFilme *filme){
    free(filme->titulo);
    free(filme->descricao);
    free(filme);
}

void destroiVetorDeFilmes(tFilme **filmes, char *fileName){
    for(int i; i < contaLinhasCSV(fileName); i++){
        destroiFilme(filmes[i]);
    }
    free(filmes);
}
