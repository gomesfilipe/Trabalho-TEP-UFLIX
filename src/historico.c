#include "../include/historico.h"
#include "../include/data.h"

#define AUMENTO 10 // Aumento de espaços de memória quando necessário realocar os campos de histórico.

// no print do historico vai printar a data, o titulo e a nota que o usuario deu

struct historico{
    int *id; // vetor
    float *notas; // vetor
    tData *data; // vetor
    int qtd_filmes_atual;
    int qtd_filmes_max;
};

tData* leData(){
    int dia, mes, ano;
    scanf("%d %d %d", &dia, &mes, &ano);
    tData *data = criaData(dia, mes, ano);

    return data;
}

tHistorico* criaPrimeiroHistorico(){
    tHistorico *hist = (tHistorico*) malloc(sizeof(tHistorico));
    hist->notas = (float*) malloc(sizeof(float) * AUMENTO);
    hist->data = criaData(); // criaData só aloca 1 espaço, tem q alocar 10
    hist->id = (int*) malloc(sizeof(int) * AUMENTO);
}

//tem fazer funcao do primiero historico q n tem nada, nem data nem nota
// Caso que o usuário já tem pelo menos 1 filme no histórico.
//ja deixar as funcoes de leitura de int* notas, int* id aumentadas para evitar realloc
//ja deixamos aumentado pra evitar realloc
tHistorico* resgataHistorico(int qtd_filmes_atual, tData *data, int *notas, int* id){
    tHistorico *hist = (tHistorico*) malloc(sizeof(tHistorico));
    hist->qtd_filmes_atual = qtd_filmes_atual;
    hist->qtd_filmes_max = qtd_filmes_atual + AUMENTO;
    hist->data = data;
    hist->notas = notas;
    hist->id = id; 
    return hist;
}

tHistorico* adicionaFilmeHistorico(tHistorico* hist, tFilme **filmes, int id, float nota, int dia, int mes, int ano){
    hist->qtd_filmes_max = qtd_filmes_atual + AUMENTO;
    
    hist->data = criaData(dia, mes, ano);
    

}

ordenaHistoricoPorData(){

}

ordenaHistoricoPorNota(){

}
