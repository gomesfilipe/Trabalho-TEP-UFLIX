#include "../include/usuario.h"
#include "../include/utils.h"

struct usuario{
    char *login; // vetor de caracteres
    char *senha; // vetor de caracteres
    tHistorico *hist; // único elemento
    int ativo; // 1 ta ativo e 0 inativo
};

int efetuaLogin(){
    
}

//cadastra um usuario por vez
void cadastraUsuario(char *login, char *senha, char *confirmaSenha, char *fileName){
    int aux = 0;
    char *loginAux = (char*) malloc(sizeof(char) * 100);
    FILE *f = fopen(fileName, "r+");
    if(f == NULL){
        printf("Erro na abertura do aruqivo!\n");
        exit(1);
    }
    
    for(int i = 0; i < contaLinhasCSV(fileName); i++){
        fscanf(f, "%[^,],", loginAux);
        if(strcmp(login, loginAux) == 0){ //se forem iguais
            printf("Login ja existente!\n");
            aux = 1;
            break;
            
        } else{
            fscanf(f, "%*[^\n]\n");
            
        }
    } //se passou do for é porque é um login que ainda não tem, ou seja, um novo usuário

    if(aux == 0){
        if(strcmp(senha, confirmaSenha) == 0){ //se senha e confirma senha forem iguais
            fprintf(f, "%s,%s\n", login, senha);
            printf("Cadastro feito com sucesso!\n");
        } else{
            printf("Senha errada!\n");
        }
    }

    fclose(f);
}



tUsuario inativarConta(){

}


//TODO cadastrar usuario
//TODO ativar e inativar conta
//TODO sair da conta


