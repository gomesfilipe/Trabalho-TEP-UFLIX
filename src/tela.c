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
                    telaPrincipal(usuario);

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

void telaPrincipal(tUsuario* usuario){
    printf("TELA INICIAL\n");
}