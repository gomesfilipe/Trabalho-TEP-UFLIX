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
 