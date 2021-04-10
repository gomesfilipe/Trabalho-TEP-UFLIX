#include "../include/tela.h"

// int telaInicial(char *fileNameUsuarios, char *fileNameHistorico, tUsuario *usuario){
//     char *login = (char*) malloc(sizeof(char) * 100);
//     char *senha = (char*) malloc(sizeof(char) * 100);
//     char *confirmaSenha = (char*) malloc(sizeof(char) * 100);
    
//     printf("1. Login\n");
//     printf("2. Cadastro\n");
//     printf("3. Sair\n");

//     int botao;
//     scanf("%d", &botao);
    
//     switch(botao){
//         case LOGIN:
//             printf("Nome de usuario: ");
//             scanf("%s", login);
        
//             printf("Senha: ");
//             scanf("%s", senha);
        
//             int loginUsuario = efetuaLogin(login, senha, fileNameUsuarios);
        
//             if(loginUsuario == LOGINEFETUADO){
//                 usuario = criaUsuario(login, senha, fileNameHistorico);
//                 printf("\nponteiro function: %p", usuario);
//                 // tFilme **filmes = leFilmes("./data/filmes-grande.csv");
//                 // imprimeUsuario(usuario, filmes);
//                 printf("Login efetuado com sucesso!\n");
                
//                 free(login);
//                 free(senha);
//                 free(confirmaSenha);
                
//                 return PAGINAPRINCIPAL;
//             }
//             else if(loginUsuario == SENHAINCORRETA){
//                 printf("Senha incorreta!\n");

//             } else if(loginUsuario == USUARIONAOCADASTRADO){
//                 printf("Usuario nao cadastrado!\n");
//             } 
            
//             free(login);
//             free(senha);
//             free(confirmaSenha);
            
//             return PAGINAINICIAL;
//             break;
        
//         case CADASTRO:
//             printf("Nome de usuario: ");
//             scanf("%s", login);
        
//             printf("Senha: ");
//             scanf("%s", senha);

//             printf("Confirmacao de senha: ");
//             scanf("%s", confirmaSenha);

//             int cadastro = cadastraUsuario(login, senha, confirmaSenha, fileNameUsuarios);

//             if(cadastro == CADASTROFEITO){
//                 printf("Cadastro feito com sucesso!\n");
//                 usuario = criaUsuario(login, senha, fileNameHistorico);
                
//                 free(login);
//                 free(senha);
//                 free(confirmaSenha);

//                 return PAGINAPRINCIPAL; 
            
//             } else if(cadastro == LOGINFORADOPADRAO){
//                 printf("Login fora do padrao.\n");
            
//             } else if(cadastro == SENHAFORADOPADRAO){
//                 printf("Senha fora do padrao.\n");  
            
//             } else if(cadastro == USUARIOJACADASTRADO){
//                 printf("Usuario ja cadastrado.\n"); 
            
//             } else if( cadastro == SENHAERRADA){
//                 printf("Senha incorreta.\n");
//             }
                
//             free(login);
//             free(senha);
//             free(confirmaSenha); 
            
//             return PAGINAINICIAL;
//             break;
                
//         case SAIR: 
//             printf("Encerrando programa...\n");
            
//             free(login);
//             free(senha);
//             free(confirmaSenha);
            
//             return ENCERRAR;
//             break;
        
//         default: 
//             printf("Botao invalido!");
            
//             free(login);
//             free(senha);
//             free(confirmaSenha);
            
//             return PAGINAINICIAL;
//     }

//     free(login);
//     free(senha);
//     free(confirmaSenha);
//     return 0; // Nunca chegará nesse ponto do código
// }

void telaInicial(char *fileNameUsuarios, char *fileNameHistorico, char *fileNameFilmes, tFilme **filmes){
    // TELA INICIAL
    char *login = (char*) malloc(sizeof(char) * 100);
    char *senha = (char*) malloc(sizeof(char) * 100);
    char *confirmaSenha = (char*) malloc(sizeof(char) * 100);
    
    tUsuario *usuario;

    int success = 0;

    while(success == 0){
        printf("1. Login\n");
        printf("2. Cadastro\n");
        printf("3. Sair\n");

        int botao;
        scanf("%d", &botao);
        
        switch(botao){
            case LOGIN:
                printf("Nome de usuario: ");
                scanf("%s", login);
            
                printf("Senha: ");
                scanf("%s", senha);
            
                int loginUsuario = efetuaLogin(login, senha, fileNameUsuarios);
            
                if(loginUsuario == LOGINEFETUADO){
                    success = 1;
                    tUsuario *usuario = criaUsuario(login, senha, fileNameHistorico);
                    printf("Login efetuado com sucesso!\n");
                    telaPrincipal(usuario, filmes, fileNameFilmes, fileNameHistorico);

                } else if(loginUsuario == SENHAINCORRETA){
                    printf("Senha incorreta!\n");

                } else if(loginUsuario == USUARIONAOCADASTRADO){
                    printf("Usuario nao cadastrado!\n");
                }
                break;
            
            case CADASTRO:
                printf("Nome de usuario: ");
                scanf("%s", login);
            
                printf("Senha: ");
                scanf("%s", senha);

                printf("Confirmacao de senha: ");
                scanf("%s", confirmaSenha);

                int cadastro = cadastraUsuario(login, senha, confirmaSenha, fileNameUsuarios);

                if(cadastro == CADASTROFEITO){
                    success = 1;
                    usuario = criaUsuario(login, senha, fileNameHistorico);
                    printf("Cadastro feito com sucesso!\n");
                    telaPrincipal(usuario);
                
                } else if(cadastro == LOGINFORADOPADRAO){
                    printf("Login fora do padrao.\n");
                
                } else if(cadastro == SENHAFORADOPADRAO){
                    printf("Senha fora do padrao.\n");  
                
                } else if(cadastro == USUARIOJACADASTRADO){
                    printf("Usuario ja cadastrado.\n"); 
                
                } else if( cadastro == SENHAERRADA){
                    printf("Senha incorreta.\n");
                }
                break;
                    
            case SAIR: 
                success = 1;
                printf("Encerrando programa...\n");
                break;
            
            default: 
                printf("Botao invalido!");
        }
    }

    free(login);
    free(senha);
    free(confirmaSenha);
    destroiUsuario(usuario);
    destroiVetorDeFilmes(filmes, fileNameFilmes);
}

   
void telaPrincipal(tUsuario* usuario, tFilme **filmes, char *fileNameFilmes, char *fileNameHistorico){
    printf("1. Listar filmes\n");
    printf("2. Meu perfil\n");
    printf("3. Procurar filme\n");
    printf("4. Sair\n");

    int botao, success = 0, botao3;
    char *botao2 = (char*) malloc(sizeof(char) * 10);
    int botao2int = atoi(botao2);
    int qtdFilmes = contaLinhasCSV(fileNameFilmes);

    scanf("%d", &botao);

    while(success == 0){
        switch(botao){
            case LISTARFILMES:
                int nPagina = 1;
                int idMin = (nPagina - 1) * TAMPAG + 1;
                int idMax = nPagina * TAMPAG; 
                
                while(1){
                    imprimePagina(filmes, nPagina, qtdFilmes);

                    scanf("%s", botao2);

                    if(strcmp(botao2, 'M') == 0){ 
                        nPagina++;
                        idMin += TAMPAG;
                        idMax += TAMPAG;
                    
                    } else if(strcmp(botao2, 'm') == 0){
                        nPagina--;
                        idMin -= TAMPAG;
                        idMax -= TAMPAG;
                    
                    } else if(botao2int == 0){ // voltar
                        break;
                    
                    } else if(botao2int < idMin || botao2int > idMax || botao2int < 0 || botao2int > qtdFilmes){
                        printf("Botao invalido\n");
                    
                    } else{ // mostrar metadados do filme
                        telaMetaDados(filmes, botao2int, usuario, fileNameHistorico);
                    }

                }
                
                break;
            
            case MEUPERFIL: 
                
                break;
            
            case PROCURARFILME: 
                char *busca = (char*) malloc(sizeof(char) * 128);
                scanf("%s", busca);
                pesquisaFilmes(busca, filmes, qtdFilmes);
                printf("\n1- Voltar\n");
                printf("2- Assistir filme");

                scanf("%d", &botao3);

                if(botao3){

                }
                
                break;
            
            case SAIDA: 
                
                break;
            
            default: 
                printf("Botão invalido!\n");
        }
    }
}

void telaMetaDados(tFilme **filmes, int id, tUsuario *usuario, char* fileNameHistorico){
    imprimeFilme(filmes[id - 1]);

    printf("1- Assistir\n");
    printf("2- Voltar\n");

    int botao, encerra = 0;
    scanf("%d", botao);

    while(encerra == 0){
        switch(botao){
            case ASSISTIR: 
                encerra = 1;
                float nota;
                tData *data;
                scanf("%f", &nota);
                while(1){
                    data = leData(); //falta ver se a data eh valida
                    if(dataValida(data)){
                        break;
                    } else{
                        printf("Data invalida! Digite novamente\n");
                    }
                }

                int dia = getDia(data);
                int mes = getMes(data);
                int ano = getAno(data);

                adicionaFilmeHistorico( getHistorico(usuario), id, nota, dia, mes, ano, fileNameHistorico, getLogin(usuario));
                break;
            
            case VOLTAR:
                encerra = 1; //habilita para sair do while e voltar para a tela principal, pois vamos chamar essa funcao dentro da funcao da tela principal
                break; 
            
            default: 
                printf("Botao invalido\n");
        }
    }
}

