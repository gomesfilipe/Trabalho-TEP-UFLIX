#include "../include/usuario.h"
//#include "../include/utils.h"

struct usuario{
    char *login; // vetor de caracteres
    char *senha; // vetor de caracteres
    tHistorico *hist; // único elemento
    int ativo; // 1 ta ativo e 0 inativo
    int idUnica;
};

//temso que destruit o historico e tratatr usuarios ativos e inativos, fazer tratamento disso
//TODO OK
int efetuaLogin(char* login, char* senha, char* fileName){
    char *loginAux = (char*) malloc(sizeof(char) * 100);
    char *senhaAux = (char*) malloc(sizeof(char) * 100);
    int ativo;
    FILE *f = fopen(fileName, "r");
    if(f== NULL){
        printf("Erro na abertura do arquivo!\n");
        exit(1);
    } 
    
    for(int i=0; i < contaLinhasCSV(fileName); i++){
        fscanf(f, "%[^,]%*c%[^,]%*c%d\n", loginAux, senhaAux, &ativo);
        
        if(ativo == 1){ //só pode logar usuários ativos
            if(strcmp(login, loginAux) == 0){ //login existe
                if(strcmp(senha, senhaAux) == 0 && ativo == 1){
                    free(loginAux);
                    free(senhaAux);
                    fclose(f);
                    return LOGINEFETUADO;
                }else{
                    free(loginAux);
                    free(senhaAux);
                    fclose(f);
                    return SENHAINCORRETA; 
                }
            }       
        }
    }

    free(loginAux);
    free(senhaAux);
    fclose(f);
    return USUARIONAOCADASTRADO;
}

//se tem uma conta inativa, o cadastro pode ter o mesmo uusario essa conta, acrescentar isso NAO ESQUECER

//retonrar uma string, a string vai ser a mensagem q a gnt quer. resolve o "problema" switch e outros
//TODO  OK
int cadastraUsuario(char *login, char *senha, char *confirmaSenha, char *fileName){
    char *loginAux = (char*) malloc(sizeof(char) * 100);
    int ativo;
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
        fscanf(f, "%[^,]%*c%*[^,]%*c%d", loginAux, &ativo);
        if(strcmp(login, loginAux) == 0 && ativo == 1){ //se for igual de usuário
            //printf("Usuario ja cadastrado.\n");
            free(loginAux);
            fclose(f);
            return USUARIOJACADASTRADO;

        } else{
            fscanf(f, "%*[^\n]\n"); 
        }
    } //se passou do for é porque é um login que ainda não tem, ou seja, um novo usuário
   
    if(strcmp(senha, confirmaSenha) == 0){ //se senha e confirma senha forem iguais
        fprintf(f, "%s,%s,%d\n", login, senha, 1);
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

//TODO VAI PRECISAR SOBRESCREVER NO CSV OK
tUsuario* inativarConta(tUsuario *usuario, char *fileNameUsuarios){
    FILE *f = fopen(fileNameUsuarios, "r+");
    if(f == NULL){
        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }
    
    usuario->ativo = 0;
    
    for(int i = 1; i < usuario->idUnica; i++){ // chegando até o início da linha de interesse
        fscanf(f, "%*[^\n]\n"); //ignora até chegar na linha de interesse
    }
    
    fscanf(f, "%*[^,]%*c%*[^,]%*c"); //ignora até a parte de ativo
    fprintf(f, "%d", usuario->ativo); //inativa a conta
    
    fclose(f);
    return usuario;
}

//TODO OK
tUsuario* criaUsuario(char *login, char *senha, char *fileNameHistorico, char *fileNameUsuarios){
    tUsuario *usuario = (tUsuario*) malloc(sizeof(tUsuario));
    usuario->login = login;
    usuario->senha = senha;
    usuario->ativo = 1;
    usuario->idUnica = getIdUnicaUsuarioAtivo(fileNameUsuarios, login); 
    usuario->hist = resgataHistorico(usuario->idUnica, fileNameHistorico);

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
    printf("%d\n", usuario->idUnica);
}

tHistorico* getHistorico(tUsuario *usuario){
    return usuario->hist;
}

char* getLogin(tUsuario* usuario){
    return usuario->login;
}

int getIdUnicaUsuarioAtivo(char *fileName, char *login){  
    char loginAux[100];
    int ativo, idUnica;
    FILE *f = fopen(fileName, "r");
    if(f == NULL){
        printf("Erro na abertura do arquivo\n");
        exit(1);
    }

    for(int i = 0; i < contaLinhasCSV(fileName); i++){
        fscanf(f, "%[^,]%*c%*[^,]%*c%d\n", loginAux, &ativo);
        if(strcmp(login, loginAux) == 0 && ativo == 1){
            idUnica = i + 1;
            break;
        }
    }

    fclose(f);
    return idUnica;
}

int getIdUnicaDaStructUsuario(tUsuario* usuario){
    return usuario->idUnica;
}

//verbosidade , um dos botoes n foi

//conta ativa e inativa