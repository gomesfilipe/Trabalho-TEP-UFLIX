#include "../include/historico.h"
#include "../include/data.h"

#define AUMENTO 10 // Aumento de espaços de memória quando necessário realocar os campos de histórico.

// no print do historico vai printar a data, o titulo e a nota que o usuario deu

struct historico{
    int *id; // vetor
    float *notas; // vetor
    tData **data; // vetor
    int qtd_filmes_atual;
    int qtd_filmes_max;
};

int contaFilmesNoHistoricoCSV(char *fileName){
    char c;
    int virgulas = 0;
    FILE *f = fopen(fileName, "r");
    if(f == NULL){
        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }
    
    while(c != '\n'){
        fscanf(f, "%c", &c);
        if(c == ','){
            virgulas++;
        }
    }

    fclose(f);
    return (virgulas - 1) / 3;
}

tData* leData(){
    int dia, mes, ano;
    scanf("%d %d %d", &dia, &mes, &ano);
    tData *data = criaData(dia, mes, ano);

    return data;
}

tHistorico* criaPrimeiroHistorico(){
    tHistorico *hist = (tHistorico*) malloc(sizeof(tHistorico));
    hist->notas = (float*) malloc(sizeof(float) * AUMENTO);
    hist->data = (tData**) malloc(sizeof(tData*) * AUMENTO);
    hist->id = (int*) malloc(sizeof(int) * AUMENTO);
    hist->qtd_filmes_atual = 0;
    hist->qtd_filmes_max = AUMENTO;
}
//NAO ESQUECER
// Caso que o usuário já tem pelo menos 1 filme no histórico.
//ja deixar as funcoes de leitura de int* notas, int* id aumentadas para evitar realloc
//ja deixamos aumentado pra evitar realloc
//dar free nos paramentros depois
tHistorico* resgataHistorico(int qtd_filmes_atual, tData **data, int *notas, int *id){
    tHistorico *hist = (tHistorico*) malloc(sizeof(tHistorico));
    hist->qtd_filmes_atual = qtd_filmes_atual;
    hist->qtd_filmes_max = qtd_filmes_atual + AUMENTO;
    hist->data = data;
    hist->notas = notas;
    hist->id = id; 
    return hist;
}

tHistorico* adicionaFilmeHistorico(tHistorico* hist, tFilme **filmes, int id, float nota, int dia, int mes, int ano){
    //hist->qtd_filmes_max = qtd_filmes_atual + AUMENTO;
    
    //hist->data = criaData(dia, mes, ano);
    

}

void ordenaHistoricoPorData(){ 

}

void ordenaHistoricoPorNota(){

}

// data, titulo, nota
void imprimirHistorico(tHistorico *hist, tFilme **filmes){
    printf("Meu historico:\n");
    for(int i = 0; i < hist->qtd_filmes_atual; i++){
        imprimeData(hist->data[i]);
        printf(" - %s: ", filmes[hist->id[i] - 1]->titulo); // fazer funçao pra evitar o acesso direto 
        if(hist->notas[i] < 0){
            printf("Sem avaliacao\n");
        
        } else{
            printf("%.1f\n", hist->notas[i]);
        }
    }
}

   


