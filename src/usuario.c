#include "../include/usuario.h"
//#include "../include/utils.h"

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
        fscanf(f, "%[^,]%*c%s\n", loginAux, senhaAux);
        
        //fscanf(f, "%s[^,]%*c%[^\n]\n", loginAux, senhaAux);
        //printf("loginaux [%s]\nsenhaaux [%s123]", loginAux, senhaAux); 
        if(strcmp(login, loginAux) == 0){ //login existe
            if(strcmp(senha, senhaAux) == 0){
                //printf("Login efetuado com sucesso!\n");
                free(loginAux);
                free(senhaAux);
                fclose(f);
                return LOGINEFETUADO; 
            } else{
                //printf("Senha incorreta!\n");
                free(loginAux);
                free(senhaAux);
                fclose(f);
                return SENHAINCORRETA; 
            }
        }  
    } 
    
    //printf("Usuario nao cadastrado!\n");
    free(loginAux);
    free(senhaAux);
    fclose(f);
    return USUARIONAOCADASTRADO;
}

//se tem uma conta inativa, o cadastro pode ter o mesmo uusario essa conta, acrescentar isso NAO ESQUECER

//retonrar uma string, a string vai ser a mensagem q a gnt quer. resolve o "problema" switch e outros
int cadastraUsuario(char *login, char *senha, char *confirmaSenha, char *fileName){
    char *loginAux = (char*) malloc(sizeof(char) * 100);

    for(int i = 0; i < strlen(login); i++){ 
        if(!isalnum(login[i])){ // Verificando se login é alfanumérico
        return LOGINFORADOPADRAO;
           // printf("Login fora do padrao.\n");  
            free(loginAux);
            return 0;
        }
    }
    
    for(int i = 0; i < strlen(senha); i++){ 
        if(!isalnum(senha[i])){ // Verificando se senha é alfanumérica
            //printf("Senha fora do padrao.\n");  
            free(loginAux);
            return SENHAFORADOPADRAO;
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
            //printf("Usuario ja cadastrado.\n");
            free(loginAux);
            fclose(f);
            return USUARIOJACADASTRADO;

        } else{
            fscanf(f, "%*[^\n]\n"); 
        }
    } //se passou do for é porque é um login que ainda não tem, ou seja, um novo usuário
   
    if(strcmp(senha, confirmaSenha) == 0){ //se senha e confirma senha forem iguais
        fprintf(f, "%s,%s\n", login, senha);
        //printf("Cadastro feito com sucesso!\n");
        free(loginAux);
        fclose(f);
        return CADASTROFEITO;
        
    } else{
        //printf("Senha incorreta.\n");
        free(loginAux);
        fclose(f);
        return SENHAERRADA;
    }

    free(loginAux);
    fclose(f);
    return 0; //poderíamos colocar qualquer return aqui, pois nunca chegará nesse ponto, então não teremos problema na hora de printar
}


tUsuario* inativarConta(tUsuario *usuario){
    usuario->ativo = 0;
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

void imprimeUsuario(tUsuario *usuario, tFilme **filmes){
    printf("%s\n", usuario->login);
    printf("%s\n", usuario->senha);
    imprimirHistorico(usuario->hist, filmes);
    printf("\n%d\n", usuario->ativo);
}

tHistorico* getHistorico(tUsuario *usuario){
    return usuario->hist;
}


char* getLogin(tUsuario* usuario){
    return usuario->login;
}




//corrigir vazamento, filipe desconfia pq vimos mts filmes, problema no realoc.
// colocar pra ver 5 filmes, encerrar programa, ver se teve vazamento, se n teve, sair e assitir 10 filmes, se teve vazamento, é problema no realoc
//verbosidade
//conta ativa e inativa