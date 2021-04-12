// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>

#include "../include/utils.h"

int contaLinhasCSV(char *fileName){
    FILE *f = fopen(fileName, "r");
    if(f == NULL){
        printf("Erro na abertura do arquivo");
        exit(1);
    }
    
    int linhas = 0;
    while(!feof(f)){
        fscanf(f, "%*[^\n]\n");
        linhas++;
    }

    fclose(f);
    return linhas;
}

char* converteMinuscula(char *str){
    for(int i = 0; str[i] != '\0'; i++){
        str[i] = tolower(str[i]);
    }
    return str;
}

void limpaTela(){
    system("clear"); // adaptar dependendo do SO; cls para windows e clear para linux
}

int ehStringNumerica(char *str){
    int qtdPontos = 0;
    int tam = strlen(str);
    
    for(int i = 0; i < tam; i++){
        if(str[i] == '.'){
            qtdPontos++;
        }
    }
    
    switch(qtdPontos){
        case 0:
            for(int i = 0; i < tam; i++){
                if(str[i] > '9' || str[i] < '0'){
                    return 0; //nao eh float
                }
                return 1; //eh float
            }
            break;
        
        case 1:
            if(str[0] == '.' || str[tam - 1] == '.'){ //se o ponto estiver nas extremidades está errado, por exemplo 1. ou .5
                return 0;
            }
            
            for(int i = 0; i < tam; i++){
                if((str[i] > '9' || str[i] < '0') && str[i] != '.'){ 
                    return 0;
                }
            }
            return 1;
            break; 
        default:
            return 0;       
    }
}