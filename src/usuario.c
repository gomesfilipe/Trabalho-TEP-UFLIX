#include "../include/usuario.h"
#include "../include/utils.h"

struct usuario{
    char *login; // vetor de caracteres
    char *senha; // vetor de caracteres
    tHistorico *hist; // único elemento
    int ativo; // 1 ta ativo e 0 inativo
};

//temso que destruit o historico e tratatr usuarios ativos e inativos, fazer tratamento disso

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
        if(strcmp(login, loginAux) == 0){ //login existe
            if(strcmp(senha, senhaAux) == 0){
                free(loginAux);
                free(senhaAux);
                printf("Login efetuado com sucesso!\n");
                return 1; //vai para o menu pricipal, fazemos isso na main
            
            } else{
                printf("Senha incorreta!\n");
                free(loginAux);
                free(senhaAux);
                return 0;
            }
        }  
    } 
    
    printf("Usuario nao cadastrado!\n");
    free(loginAux);
    free(senhaAux);
    return 0;
}

//se tem uma conta inativa, o cadastro pode ter o mesmo uusario essa conta, acrescentar isso NAO ESQUECER

//retonrar uma string, a string vai ser a mensagem q a gnt quer. resolve o "problema" switch e outros
int cadastraUsuario(char *login, char *senha, char *confirmaSenha, char *fileName){
    char *loginAux = (char*) malloc(sizeof(char) * 100);

    for(int i = 0; i < strlen(login); i++){ 
        if(!isalnum(login[i])){ // Verificando se login é alfanumérico
            printf("Login fora do padrao.\n");  
            free(loginAux);
            return 0;
        }
    }
    
    for(int i = 0; i < strlen(senha); i++){ 
        if(!isalnum(senha[i])){ // Verificando se senha é alfanumérica
            printf("Senha fora do padrao.\n");  
            free(loginAux);
            return 0;
        }
    } 
    
    FILE *f = fopen(fileName, "r+");
    if(f == NULL){
        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }
      
    for(int i = 0; i < contaLinhasCSV(fileName); i++){
        fscanf(f, "%[^,]", loginAux);
        if(strcmp(login, loginAux) == 0){ //se forem iguais
            printf("Usuario ja cadastrado.\n");
            free(loginAux);
            fclose(f);
            return 0;

        } else{
            fscanf(f, "%*[^\n]\n"); 
        }
    } //se passou do for é porque é um login que ainda não tem, ou seja, um novo usuário
   
    if(strcmp(senha, confirmaSenha) == 0){ //se senha e confirma senha forem iguais
        fprintf(f, "%s,%s\n", login, senha);
        //printf("Cadastro feito com sucesso!\n");
        free(loginAux);
        fclose(f);
        return 1;
        
    } else{
        printf("Senha incorreta.\n");
        free(loginAux);
        fclose(f);
        return 0;
    }

    free(loginAux);
    fclose(f);
    return 0;
}

tUsuario* inativarConta(tUsuario *usuario){
    usuario->ativo = 0; //inativando usuario
    return usuario;
}

tUsuario* criaUsuario(char *login, char *senha, char *fileName){
    tUsuario *usuario = (tUsuario*) malloc(sizeof(tUsuario));
    usuario->login = login;
    usuario->senha = senha;
    usuario->hist = resgataHistorico(login, fileName);
    usuario->ativo = 1;
    return usuario;
}

void destroiUsuario(tUsuario *usuario){
    free(usuario->login);
    free(usuario->senha);
    destroiHistorico(usuario->hist);
    free(usuario);
}

//usuario
//makefile
//main
//verbosidade
//conta ativa e inativa
//tirar os printf da funçoes q n sao void, deixar eles na main para n misturar aparte visual coma logica