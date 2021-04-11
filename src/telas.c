#include "../include/telas.h"

void telaInicial(char *fileNameUsuarios, char *fileNameHistorico, char *fileNameFilmes, tFilme **filmes){
    char *login = (char*) malloc(sizeof(char) * 100);
    char *senha = (char*) malloc(sizeof(char) * 100);
    char *confirmaSenha = (char*) malloc(sizeof(char) * 100);
    
    tUsuario *usuario = NULL;
    //tUsuario *usuario = criaUsuario("x", "y", fileNameHistorico);
    //tUsuario *usuario2 = usuario;

    int success = 0;
    int botao;

    while(success == 0){
        printf("1. Login\n");
        printf("2. Cadastro\n");
        printf("3. Sair\n");

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
                    usuario = criaUsuario(login, senha, fileNameHistorico);
                    printf("Login efetuado com sucesso!\n");
                    //limpaTela();
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
                    telaPrincipal(usuario, filmes, fileNameFilmes, fileNameHistorico);
                
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
                printf("Botao invalido\n");
        }
    }

    free(confirmaSenha);
    if(usuario != NULL){
        destroiUsuario(usuario);
    } else{
        free(login);
        free(senha);
    }
}
 
void telaPrincipal(tUsuario* usuario, tFilme **filmes, char *fileNameFilmes, char *fileNameHistorico){
    char *botao2 = (char*) malloc(sizeof(char) * 10);
    char *busca = (char*) malloc(sizeof(char) * 128);
    int botao, success = 0, botao3, botao4;
    int botao2int;
    int qtdFilmes = contaLinhasCSV(fileNameFilmes);
    int nPagina = 1;
    int idMin = (nPagina - 1) * TAMPAG + 1;
    int idMax = nPagina * TAMPAG; 
    int maxPaginas;
    
    if(qtdFilmes % TAMPAG == 0){
        maxPaginas = qtdFilmes / TAMPAG;
    } else{
        maxPaginas = qtdFilmes / TAMPAG + 1;
    }

    while(success == 0){
        printf("1. Listar filmes\n");
        printf("2. Meu perfil\n");
        printf("3. Procurar filme\n");
        printf("4. Sair\n");
        
        scanf("%d", &botao);
        nPagina = 1;
        idMin = (nPagina - 1) * TAMPAG + 1;
        idMax = nPagina * TAMPAG; 
        
        switch(botao){
            case LISTARFILMES:
                
                while(1){
                    //limpaTela();
                    imprimePagina(filmes, nPagina, qtdFilmes);
                    printf("M - Mais filmes\n");
                    printf("m - Menos filmes\n");
                    printf("0 - Voltar\n");
                    
                    scanf("%s", botao2);
                    botao2int = atoi(botao2);
                    
                    if(strcmp(botao2, "M") == 0){ 
                        if(nPagina <= maxPaginas ){
                            nPagina++;
                            idMin += TAMPAG;
                            idMax += TAMPAG;
                        }
                    
                    } else if(strcmp(botao2, "m") == 0){
                        if(nPagina > 0){
                            nPagina--;
                            idMin -= TAMPAG;
                            idMax -= TAMPAG;
                        }
                    
                    } else if(strcmp(botao2, "0") == 0){ // voltar
                        //free(botao2);
                        break;
                    
                    } else if(botao2int < idMin || botao2int > idMax || botao2int < 0 || botao2int > qtdFilmes){
                        printf("Botao invalido\n");
                    
                    } else{
                        telaMetaDados(filmes, botao2int, usuario, fileNameHistorico);
                        break;
                    }
                }
                
                break;
            
            case MEUPERFIL: 
                while(1){
                    printf("1. Historico\n");
                    printf("2. Excluir conta\n");
                    printf("3. Voltar\n");
                    
                    scanf("%d", &botao3);
                    
                    if(botao3 == HISTORICO){
                        telaHistorico(usuario, filmes);
                    
                    }else if(botao3 == EXCLUIR){
                        success = 1;
                        usuario = inativarConta(usuario);
                        printf("Encerrando programa...\n");
                        break;
                    
                    }else if(botao3 == VOLT){
                        break;    //volta para a tela principal    
                    
                    }else {
                        printf("Botao invalido\n");
                    }
                }

                break;
            
            case PROCURARFILME: 
                getchar();
                printf("Pesquisar: ");
                scanf("%[^\n]", busca);
                pesquisaFilmes(busca, filmes, qtdFilmes);
                printf("\n1- Voltar\n");

                while(1){
                    scanf("%d", &botao4);

                    if(botao4 == VOLTA){
                        //free(busca);
                        break;
                    }
                    
                    printf("Botao invalido\n");
                }

                break;
            
            case SAIDA: 
                success = 1;
                printf("Encerrando programa...\n");
                break;
            
            default: 
                printf("Botao invalido!\n");
        }
    }

    free(botao2);
    free(busca);
}

void telaMetaDados(tFilme **filmes, int id, tUsuario *usuario, char* fileNameHistorico){
    int botao, encerra = 0;
    imprimeFilme(filmes[id - 1]);


    while(encerra == 0){
        printf("1- Assistir\n");
        printf("2- Voltar\n");

        scanf("%d", &botao);

        switch(botao){
            case ASSISTIR: 
                encerra = 1;
                float nota;
                tData *data;
                printf("Qual a sua avaliacao do filme? ");
                scanf("%f", &nota);
                while(1){
                    printf("Qual a data que voce assistiu o filme? ");
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
                tHistorico *hist = getHistorico(usuario);
                char *login = getLogin(usuario);

                adicionaFilmeHistorico(hist, id, nota, dia, mes, ano, fileNameHistorico, login);
                free(data);
                break;
            
            case VOLTAR:
                encerra = 1; //habilita para sair do while e voltar para a tela principal, pois vamos chamar essa funcao dentro da funcao da tela principal
                break; 
            
            default: 
                printf("Botao invalido\n");
        }
    }
}

void telaHistorico(tUsuario* usuario, tFilme** filmes){
    char ordena;
    int botao;
    tHistorico *hist = getHistorico(usuario);
    getchar(); //para consumir o /n do ultimo botao
    while(1){
        printf("D - Ordenar historico por data\n");
        printf("N - Ordenar historico por nota\n");
        ordena = getchar();
        
        if(ordena == 'D'){
            ordenaHistoricoPorData(hist);
            break;
        
        } else if(ordena == 'N'){
            ordenaHistoricoPorNota(hist);
            break;                     
        
        }else{
            printf("Botao invalido\n");
        }
    }

    imprimirHistorico(hist, filmes);

    printf("\n1- Voltar\n");
    while(1){
        scanf("%d", &botao);
        if(botao == VOLTA){
            break;
        }

        printf("Botao invalido\n");
    }
}

void UFLIX(char *fileNameUsuarios, char *fileNameHistorico, char *fileNameFilmes, tFilme **filmes){
    telaInicial(fileNameUsuarios, fileNameHistorico, fileNameFilmes, filmes);
}
