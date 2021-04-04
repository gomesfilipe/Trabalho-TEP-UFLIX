#include "../include/historico.h"
#include "../include/data.h"

//dar nota

struct historico{
    tFilme *filme; // vetor
    float *notas; // vetor
    tData *data; // vetor
};

tData* leData(){
    int dia, mes, ano;
    scanf("%d %d %d", &dia, &mes, &ano);
    tData *d = criaData(dia, mes, ano);

    return d;
}

void adicionaHistorico(){
    //setFilme
    //setNota
    //leData
} 
