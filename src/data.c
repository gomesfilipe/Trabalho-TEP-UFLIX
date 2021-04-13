#include "../include/data.h"

#define JANEIRO 1
#define FEVEREIRO 2 
#define MARCO 3
#define ABRIL 4
#define MAIO 5
#define JUNHO 6
#define JULHO 7
#define AGOSTO 8
#define SETEMBRO 9
#define OUTUBRO 10
#define NOVEMBRO 11
#define DEZEMBRO 12

struct data{
    int dia;
    int mes;
    int ano;
};

tData* criaData(int dia, int mes, int ano){
    tData *d = (tData*) malloc(sizeof(tData));

    d->dia = dia;
    d->mes = mes;
    d->ano = ano;

    return d;
}

int ehBissexto(tData *data){
    if( (data->ano % 4 == 0 && data->ano % 100 != 0) ||  data->ano % 400 == 0 ){
        return 1;
    }
    return 0;
}

int dataValida(char *str){ 
    int barras = 0;
    int tam = strlen(str);
    
    for(int i = 0; i < tam; i++){
        if((str[i] < '0' || str[i] > '9') && str[i] != '/'){
            return 0;
        }    
        if(str[i] == '/'){      
            barras++; 
            if(str[i - 1] == '/' && i > 0){
                return 0;
            }   
        }
    }

    if(barras != 2 || str[0] == '/' || str[tam - 1] == '/' ){
        return 0;
    }

    int dia, mes, ano;
    sscanf(str, "%d/%d/%d", &dia, &mes, &ano);

    tData* data = criaData(dia, mes, ano); 

    int meses[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if(ehBissexto(data)){
        meses[1]++; // Ajustando quantidade de dias de fevereiro para 29
    }

    if(data->mes > 12 || data->mes < 1 || data->dia > meses[data->mes - 1] || data->dia < 1){
        free(data);
        return 0;
    }
    free(data);
    return 1;
}


int datacmp(tData *d1, tData *d2){
    if(d1->ano > d2->ano){
        return 1;
    
    } else if(d1->ano < d2->ano){
        return -1;
    
    } else{
        if(d1->mes > d2->mes){
            return 1;
        
        } else if(d1->mes < d2->mes){
            return -1;
        
        } else{
            if(d1->dia > d2->dia){
                return 1;
            
            } else if(d1->dia < d2->dia){
                return -1;
            
            } else{
                return 0; // Datas iguais
            }
        }
    }
}

void imprimeData(tData *data){
    printf("%02d/%02d/%04d", data->dia, data->mes, data->ano);
}

void destroiData(tData *data){
    free(data);
}