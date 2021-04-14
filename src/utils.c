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
    system("clear"); // Adaptar dependendo do SO: "cls" para windows e "clear" para linux.
}

int ehStringNumerica(char *str){
    int qtdPontos = 0, qtdTracos = 0;
    int tam = strlen(str);
    
    for(int i = 0; i < tam; i++){ // Contando quantidade de pontos e de traços.
        if(str[i] == '.'){
            qtdPontos++;
        }

        if(str[i] == '-'){
            qtdTracos++;
        }
    }

    if(qtdTracos != 1 && qtdTracos != 0){ // Se qtdTracos for diferente de 0 e de 1, não é string que representa float.
        return 0;
    
    } else if(qtdTracos == 0){ // Se for um float positivo ou nulo.
        switch(qtdPontos){
            case 0:
                for(int i = 0; i < tam; i++){
                    if(str[i] > '9' || str[i] < '0'){
                        return 0; // Não é float.
                    }
                }
                return 1; // É float.
                break;
            
            case 1:
                if(str[0] == '.' || str[tam - 1] == '.'){ // Se o ponto estiver nas extremidades está errado, por exemplo "1." ou ".5".
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

    } else if(qtdTracos == 1 && str[0] == '-'){ // Se for um float negativo.
        switch(qtdPontos){
            case 0:
                for(int i = 1; i < tam; i++){
                    if(str[i] > '9' || str[i] < '0'){
                        return 0; // Não é float.
                    }
                }
                return 1; // É float.
                break;
            
            case 1:
                if(str[1] == '.' || str[tam - 1] == '.'){ // Se o ponto estiver nas extremidades está errado, por exemplo "1." ou ".5".
                    return 0;
                }
                
                for(int i = 1; i < tam; i++){
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

    return 0;
}
