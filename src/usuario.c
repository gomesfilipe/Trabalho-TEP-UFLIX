#include "../include/usuario.h"
#include "../include/utils.h"

struct usuario{
    char *login; // vetor de caracteres
    char *senha; // vetor de caracteres
    tHistorico *hist; // único elemento
    int ativo; // 1 ta ativo e 0 inativo
};

int efetuaLogin(char* login, char* senha, char* fileName){
    char *loginAux = (char*) malloc(sizeof(char) * 100);
    char *senhaAux = (char*) malloc(sizeof(char) * 100);

   FILE *f = fopen(fileName, "r");
    if(f== NULL){
    printf("Erro na abertura do arquivo!\n");
    exit(1);
    }
    
    for(int i=0; i < contaLinhasCSV(fileName); i++){
        fscanf(f, "%[^,],%[^\n]\n" , loginAux, senhaAux); 
        fscanf(f, "%*[^,]" );
        if(strcmp(login, loginAux)== 0){ //login existe
            if(strcmp(senha, senhaAux )== 0){
               return 1; //vai para o menu pricipal, fazemos isso na main
            }
            else{
                printf("Senha incorreta!\n");
                return 0;
            }
        }  
    } 
    printf("Usuário não cadastrado!\n");

    free(loginAux);
    free(senhaAux);
}

//se tem uma conta inativa, o cadastro pode ter o mesmo uusario essa conta, acrescentar isso NAO ESQUECER
//cadastra um usuario por vez
void cadastraUsuario(char *login, char *senha, char *confirmaSenha, char *fileName){
    int encerra = 0; //Essa variavel é setada quando encontramos alguma condição que impede a continuação do cadastro. 
    char *loginAux = (char*) malloc(sizeof(char) * 100);
    
    for(int i = 0; i < strlen(login); i++){ 
        if(!isalnum(login[i])){ // Verificando se login é alfanumérico
            printf("Login deve ser alfanumerico!\n");  
            encerra = 1;
            break;
        }
    }
    if(encerra == 0){ 
        for(int i = 0; i < strlen(senha); i++){ 
            if(!isalnum(senha[i])){ // Verificando se senha é alfanumérica
                printf("Senha deve ser alfanumerica!\n");  
                encerra = 1;
                break;
            }
        } 
    }
    FILE *f = fopen(fileName, "r+");
    if(f == NULL){
        printf("Erro na abertura do aruqivo!\n");
        exit(1);
    }
    
    if(encerra == 0){   
        for(int i = 0; i < contaLinhasCSV(fileName); i++){
            fscanf(f, "%[^,],", loginAux);
            if(strcmp(login, loginAux) == 0){ //se forem iguais
                printf("Login ja existente!\n");
                encerra = 1;
                break;
                
            } else{
                fscanf(f, "%*[^\n]\n");
                
            }
        } //se passou do for é porque é um login que ainda não tem, ou seja, um novo usuário
    }

    if(encerra == 0){
        if(strcmp(senha, confirmaSenha) == 0){ //se senha e confirma senha forem iguais
            fprintf(f, "%s,%s\n", login, senha);
            printf("Cadastro feito com sucesso!\n");
        } else{
            printf("Senha errada!\n");
        }
    }

    free(loginAux);
    fclose(f);
}

tUsuario* inativarConta(tUsuario *usuario){
    usuario->ativo = 0; //inativando usuario
    return usuario;
}

tUsuario* criaUsuario(char *login, char *senha){
    tUsuario *usuario = (tUsuario*) malloc(sizeof(tUsuario));
    usuario->login = login;
    usuario->senha = senha;
    int qtdFilmesAtual = contaFilmesNoHistoricoCSV();
    if(qtdFilmesAtual == 0){ //consideramos aqui que conseguimos escrever o filme na frente do login e da sala
        usuario->hist = criaPrimeiroHistorico();
    } else{
        // fazer alguma coisa que leia o csv de historico e capture os dados que sao os parametros da funcao abaixo 
        usuario->hist = resgataHistorico(qtdFilmesAtual, data, nota);
    }
    // chamar função de criar historico ou resgatahistorico
    usuario->ativo = 1;
    return usuario;
}
char *login; // vetor de caracteres
    char *senha; // vetor de caracteres
    tHistorico *hist; // único elemento
    int ativo; // 1 ta ativo e 0 inativo
tUsuario* destroiUsuario(tUsuario usuario){
    
}

// char *login; // vetor de caracteres
// char *senha; // vetor de caracteres
// tHistorico *hist; // único elemento
// int ativo; // 1 ta ativo e 0 inativo


//TODO cadastrar usuario 
//TODO ativar e inativar conta ok
//TODO sair da conta
//TODO criar usuario ok
//TODO criar funções para desalocar filme, historico, data e usuario



//roteiro
//csv
//testar funcao resgata no filme ou no historico
//usuario
//makefile
//main 
//funcao em cada TAD para destruir a TAD
//verbosidade