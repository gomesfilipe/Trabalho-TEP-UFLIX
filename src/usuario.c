#include "../include/usuario.h"

struct usuario{
    char *login; // String.
    char *senha; // String.
    tHistorico *hist; // Ponteiro para histórico.
    int ativo; // 1 significa ativo, enquanto 0 significa inativo.
    int idUnica; // Correspondente a linha do usuário no arquivo usuarios.csv.
};

int efetuaLogin(char* login, char* senha, char* fileName){
    char *loginAux = (char*) malloc(sizeof(char) * 128);
    char *senhaAux = (char*) malloc(sizeof(char) * 128);
    int ativo;
    FILE *f = fopen(fileName, "r");
    if(f== NULL){
        printf("Erro na abertura do arquivo!\n");
        exit(1);
    } 
    
    for(int i=0; i < contaLinhasCSV(fileName); i++){
        fscanf(f, "%[^,]%*c%[^,]%*c%d\n", loginAux, senhaAux, &ativo);
        
        if(ativo == 1){ // Só podem logar usuários ativos.
            if(strcmp(login, loginAux) == 0){ // Login existe.
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

int cadastraUsuario(char *login, char *senha, char *confirmaSenha, char *fileName){
    char *loginAux = (char*) malloc(sizeof(char) * 128);
    int ativo;
    for(int i = 0; i < strlen(login); i++){ 
        if(!isalnum(login[i])){ // Verificando se login é alfanumérico.
        return LOGINFORADOPADRAO;  
            free(loginAux);
            return 0;
        }
    }
    
    for(int i = 0; i < strlen(senha); i++){ 
        if(!isalnum(senha[i])){ // Verificando se senha é alfanumérica.
            free(loginAux);
            return SENHAFORADOPADRAO;
        }
    } 
    
    FILE *f = fopen(fileName, "r+");
    if(f == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
      
    for(int i = 0; i < contaLinhasCSV(fileName); i++){
        fscanf(f, "%[^,]%*c%*[^,]%*c%d\n", loginAux, &ativo);
        if(strcmp(login, loginAux) == 0 && ativo == 1){ // Se for igual ao usuário.
            free(loginAux);
            fclose(f);
            return USUARIOJACADASTRADO;
        }
    } // Se passou do for é porque é um login que ainda não tem, ou seja, um novo usuário.
   
    if(strcmp(senha, confirmaSenha) == 0){ // Se senha e confirmaSenha senha forem iguais.
        fprintf(f, "%s,%s,%d\n", login, senha, 1);
        free(loginAux);
        fclose(f);
        return CADASTROFEITO;
        
    } else{
        free(loginAux);
        fclose(f);
        return SENHAERRADA;
    }

    free(loginAux);
    fclose(f);
    return 0;//Poderíamos colocar qualquer return aqui, pois nunca chegará nesse ponto, então não teremos problema na hora de printar
}

tUsuario* inativarConta(tUsuario *usuario, char *fileNameUsuarios){
    FILE *f = fopen(fileNameUsuarios, "r+");
    if(f == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    usuario->ativo = 0;
    
    for(int i = 1; i < usuario->idUnica; i++){ 
        fscanf(f, "%*[^\n]\n"); // Ignora até chegar na linha de interesse.
    }
    
    fscanf(f, "%*[^,]%*c%*[^,]%*c"); // Ignora até a parte de ativo.
    fprintf(f, "%d", usuario->ativo); // Sobrescreve o caractere 0 sobre o 1, e inativa a conta.
    
    fclose(f);
    return usuario;
}

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
