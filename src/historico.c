#include "../include/historico.h"

#define AUMENTO 10 // Aumento de espaços de memória quando necessário realocar os campos de histórico.

struct historico{
    int *id; // Vetor de ids.
    float *notas; // Vetor de notas.
    tData **data; // Vetor de ponteiros de data.
    int qtd_filmes_atual;
    int qtd_filmes_max;
};

int contaFilmesNoHistoricoCSV(char *fileName, int idUnica){
    int idUnicaAux;
    int counter = 0;
    FILE *f = fopen(fileName, "r");
    if(f == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }

    for(int i = 0; i < contaLinhasCSV(fileName); i++){
        fscanf(f, "%d", &idUnicaAux);
        fscanf(f, "%*[^\n]\n"); 
        if(idUnicaAux == idUnica){
            counter++;
        }
    }

    fclose(f);
    return counter;
}

tHistorico* criaPrimeiroHistorico(){   
    tHistorico *hist = (tHistorico*) malloc(sizeof(tHistorico));
    hist->notas = (float*) malloc(sizeof(float) * AUMENTO);
    hist->data = (tData**) malloc(sizeof(tData*) * AUMENTO);
    hist->id = (int*) malloc(sizeof(int) * AUMENTO);
    hist->qtd_filmes_atual = 0;
    hist->qtd_filmes_max = AUMENTO;
    return hist;
}

tHistorico* resgataHistorico(int idUnica, char *fileName){
    int qtd_filmes_atual = contaFilmesNoHistoricoCSV(fileName, idUnica);

    tHistorico *hist;
    
    if(qtd_filmes_atual == 0){
        hist = criaPrimeiroHistorico();
        return hist;
    }

    hist = (tHistorico*) malloc(sizeof(tHistorico));
    hist->qtd_filmes_atual = qtd_filmes_atual;
    hist->qtd_filmes_max = qtd_filmes_atual + AUMENTO;
    hist->data = (tData**) malloc(sizeof(tData*) * (qtd_filmes_atual + AUMENTO));
    hist->notas = (float*) malloc(sizeof(float) * (qtd_filmes_atual + AUMENTO));
    hist->id = (int*) malloc(sizeof(int) * (qtd_filmes_atual + AUMENTO)); 

    int diaAux, mesAux, anoAux;
    int idUnicaAux;
    
    FILE *f = fopen(fileName, "r");
    if(f == NULL){
        printf("Erro na abertura do arquivo.");
        exit(1);
    }
    
    int posHist = 0;

    for(int i = 0; i < contaLinhasCSV(fileName); i++){
        fscanf(f, "%d,", &idUnicaAux);
        if(idUnicaAux == idUnica){  // Se forem iguais.
            fscanf(f, "%d,", &hist->id[posHist]);
            fscanf(f, "%f,", &hist->notas[posHist]);
            fscanf(f, "%d/%d/%d\n", &diaAux, &mesAux, &anoAux);
            hist->data[posHist] = criaData(diaAux, mesAux, anoAux);
            
            posHist++;
        
        } else{
            fscanf(f, "%*[^\n]\n");
        }
    }
        
    fclose(f);    
    return hist;
}

tHistorico* adicionaFilmeHistorico(tHistorico *hist, int id, float nota, int dia, int mes, int ano, char *fileName, int idUnica){ 
    if(hist->qtd_filmes_atual == hist->qtd_filmes_max){ // Se precisar de mais espaço para adicionar um filme.
        hist->id = (int*) realloc(hist->id, sizeof(int) * (hist->qtd_filmes_atual + AUMENTO));
        hist->notas = (float*) realloc (hist->notas, sizeof(float) * (hist->qtd_filmes_atual + AUMENTO));
        hist->data = (tData**) realloc (hist->data, sizeof(tData*) * (hist->qtd_filmes_atual + AUMENTO));
        hist->qtd_filmes_max += AUMENTO;     
    }
    
    hist->id[hist->qtd_filmes_atual] = id; 
    hist->notas[hist->qtd_filmes_atual] = nota;  
    hist->data[hist->qtd_filmes_atual] = criaData(dia, mes, ano);
    hist->qtd_filmes_atual++;
  
    imprimeHistoricoCSV(id, nota, dia, mes, ano, fileName, idUnica);

    return hist;
}

void ordenaHistoricoPorData(tHistorico *hist){ 
    int idAux;
    float notaAux;
    tData *dataAux;
    for(int i = 0; i < hist->qtd_filmes_atual; i++){
        for(int j = i + 1; j < hist->qtd_filmes_atual; j++){
            if(datacmp(hist->data[i], hist->data[j]) == -1){ // Ou seja, quando a data na posicao i é menor que a data na posição j
                notaAux = hist->notas[j];
                hist->notas[j] = hist->notas[i];
                hist->notas[i] = notaAux;

                idAux = hist->id[j];
                hist->id[j] = hist->id[i];
                hist->id[i] = idAux;

                dataAux = hist->data[j];
                hist->data[j] = hist->data[i];
                hist->data[i] = dataAux;  
            }
        }
    }
}

void ordenaHistoricoPorNota(tHistorico *hist){  
    int idAux;
    float notaAux;
    tData *dataAux;

    for(int i = 0; i < hist->qtd_filmes_atual; i++){
        for(int j = i+1; j < hist->qtd_filmes_atual; j++){
            if(hist->notas[i] < hist->notas[j]){
                notaAux = hist->notas[j];
                hist->notas[j] = hist->notas[i];
                hist->notas[i] = notaAux;

                idAux = hist->id[j];
                hist->id[j] = hist->id[i];
                hist->id[i] = idAux;
                
                dataAux = hist->data[j];
                hist->data[j] = hist->data[i];
                hist->data[i] = dataAux; 
            }
        }
    }
}

void imprimirHistorico(tHistorico *hist, tFilme **filmes){
    printf("Meu historico:\n");
    for(int i = 0; i < hist->qtd_filmes_atual; i++){
        imprimeData(hist->data[i]);
        printf(" - ");
        imprimeTituloFilme(filmes, hist->id[i]);
        printf(": ");
        if(hist->notas[i] == -1){
            printf("Sem avaliacao\n");
        
        } else{
            printf("%.1f\n", hist->notas[i]);
        }
    }
}

void imprimeHistoricoCSV(int id, float nota, int dia, int mes, int ano, char *fileName, int idUsuario){ 
    char *nomeAux = (char*) malloc(sizeof(char) * 100);
    FILE *f = fopen(fileName, "a"); // Modo append.
    if(f == NULL){
        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }
    
    fprintf(f, "%d,%d,%.1f,%02d/%02d/%04d\n", idUsuario, id, nota, dia, mes, ano);
    
    fclose(f);
    free(nomeAux);
}

void destroiHistorico(tHistorico *hist){
    for(int i = 0; i < hist->qtd_filmes_atual; i++){
        destroiData(hist->data[i]);  
    }
    
    free(hist->data);
    free(hist->id);
    free(hist->notas);
    free(hist);
}
