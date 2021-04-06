#include "../include/historico.h"
#include "../include/data.h"
#include "../include/utils.h"

#define AUMENTO 10 // Aumento de espaços de memória quando necessário realocar os campos de histórico.

// no print do historico vai printar a data, o titulo e a nota que o usuario deu

struct historico{
    int *id; // vetor
    float *notas; // vetor
    tData **data; // vetor
    int qtd_filmes_atual;
    int qtd_filmes_max;
};

//conta filmes no histórico de um usuário
int contaFilmesNoHistoricoCSV(char *fileName, char *login){
    char *nomeAux = (char*) malloc(sizeof(char) * 100);
    char c = 'x';
    int virgulas = 0;
    FILE *f = fopen(fileName, "r");
    if(f == NULL){
        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }

    // for(int i=0; i< contaLinhasCSV(fileName); i++){
    //     fscanf(f,"%[^,]", nomeAux);
    //     while(c != '\n'){
    //         fscanf(f, "%c", &c);
    //         if(c == ','){
    //             virgulas++;
    //         }
    //     }  
    //     printf("[%d]\n",(virgulas - 1) / 3);
    //     virgulas=0;
    //     c= 'x'; //resetando c
    // }
   

    do{
        fscanf(f, "%[^,]", nomeAux);
        if(strcmp(nomeAux, login) == 0){        
            while(c != '\n'){
                fscanf(f, "%c", &c);
                if(c == ','){
                    virgulas++;
                }
            }               
            break;
            
        }else{
            fscanf(f, "%*[^\n]\n"); //ignora o resto da linha
        }
        
    }while(strcmp(nomeAux, login) != 0);

    free(nomeAux);
    fclose(f);
    return (virgulas - 1) / 3;
}

tData* leData(){
    int dia, mes, ano;
    scanf("%d %d %d", &dia, &mes, &ano);
    tData *data = criaData(dia, mes, ano);

    return data;
}

tHistorico* criaPrimeiroHistorico(){   //testamos ta ok
    tHistorico *hist = (tHistorico*) malloc(sizeof(tHistorico));
    hist->notas = (float*) malloc(sizeof(float) * AUMENTO);
    hist->data = (tData**) malloc(sizeof(tData*) * AUMENTO);
    hist->id = (int*) malloc(sizeof(int) * AUMENTO);
    hist->qtd_filmes_atual = 0;
    hist->qtd_filmes_max = AUMENTO;
    return hist;
}
//NAO ESQUECER
// Caso que o usuário já tem pelo menos 1 filme no histórico.
//ja deixar as funcoes de leitura de int* notas, int* id aumentadas para evitar realloc
//ja deixamos aumentado pra evitar realloc
//dar free nos paramentros depois
tHistorico* resgataHistorico(int qtd_filmes_atual, tData **data, float *notas, int *id){
    tHistorico *hist = (tHistorico*) malloc(sizeof(tHistorico));
    hist->qtd_filmes_atual = qtd_filmes_atual;
    hist->qtd_filmes_max = qtd_filmes_atual + AUMENTO;
    hist->data = data;
    hist->notas = notas;
    hist->id = id; 
    return hist;
}

tHistorico* adicionaFilmeHistorico(tHistorico *hist, int id, float nota, int dia, int mes, int ano){ 
    if(hist->qtd_filmes_atual == hist->qtd_filmes_max){ //se precisar de mais espaco pra adicionar o filme
        hist->id = (int*) realloc(hist->id, sizeof(int) * (hist->qtd_filmes_atual + AUMENTO));
        hist->notas = (float*) realloc (hist->notas, sizeof(float) * (hist->qtd_filmes_atual + AUMENTO));
        hist->data = (tData**) realloc (hist->data, sizeof(tData*) * (hist->qtd_filmes_atual + AUMENTO));
        hist->qtd_filmes_max += AUMENTO;     
    }
    
    tData **dataAux = hist->data;
    
    hist->id[hist->qtd_filmes_atual] = id; 
    hist->notas[hist->qtd_filmes_atual] = nota;  
    hist->data[hist->qtd_filmes_atual] = criaData(dia, mes, ano); // TALVEZ DÊ PROBLEMA 
    hist->qtd_filmes_atual++;  
    
    for(int i = 0; i < hist->qtd_filmes_atual; i++){
        free(dataAux[i]);
    }

    free(dataAux);
    return hist;
}

void ordenaHistoricoPorData(tHistorico *hist){ 

}

void ordenaHistoricoPorNota(tHistorico *hist){

}

void imprimirHistorico(tHistorico *hist, tFilme **filmes){   //testamos ta ok
    printf("Meu historico:\n");
    for(int i = 0; i < hist->qtd_filmes_atual; i++){
        imprimeData(hist->data[i]);
        printf(" - ");
        imprimeTituloFilme(filmes, hist->id[i]);
        printf(": ");
        if(hist->notas[i] < 0 || hist->notas[i] > 10){
            printf("Sem avaliacao\n");
        
        } else{
            printf("%.1f\n", hist->notas[i]);
        }
    }
}

//Quando adiciona um filme no histórico, é preciso colocar a data e a nota do filme no arquivo csv para quando for resgatar o histórico as informações estarem salvas
void imprimeHistoricoCSV(int id, float nota, int dia, int mes, int ano, char *fileName, char *login){
    char *nomeAux = (char*) malloc(sizeof(char) * 100);
    FILE *f = fopen(fileName, "r+");
    if(f == NULL){
        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }
    fscanf(f, "%[^,]", nomeAux);
    
    do{
        fscanf(f, "%[^,]", nomeAux);
        if(strcmp(nomeAux, login) == 0){ 
            // FILE *f = fopen(fileName, "w");
            fscanf(f, "%*[^\n]");
            fprintf(f, ",%d,%.1f,%02d/%02d/%04d", id, nota, dia, mes, ano);     
            break;
            
        }else{
            fscanf(f, "%*[^\n]\n"); //ignora o resto da linha
        }
        
    }while(strcmp(nomeAux, login) != 0);
    
    fclose(f);
}

   


