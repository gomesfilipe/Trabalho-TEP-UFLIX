#include "../include/telas.h"

#define TIME 2

void telaInicial(char *fileNameUsuarios, char *fileNameHistorico, char *fileNameFilmes, tFilme **filmes, int verbosidade){
    char *login = (char*) malloc(sizeof(char) * 100);
    char *senha = (char*) malloc(sizeof(char) * 100);
    char *confirmaSenha = (char*) malloc(sizeof(char) * 100);
    
    tUsuario *usuario = NULL;

    int success = 0;
    char botaoAux[100]; //só para testar se é não númérico
    int botao;

    while(success == 0){
        if(verbosidade){
            limpaTela();
            printf("1. Login\n");
            printf("2. Cadastro\n");
            printf("3. Sair\n");
        }

        scanf("%s", botaoAux);
        botao = atoi(botaoAux); //retorna 0 se não for número e cai em default
        
        switch(botao){
            case LOGIN:
                if(verbosidade) printf("Nome de usuario: ");
                scanf("%s", login);
            
                if(verbosidade) printf("Senha: ");
                scanf("%s", senha);
            
                int loginUsuario = efetuaLogin(login, senha, fileNameUsuarios);
            
                if(loginUsuario == LOGINEFETUADO){
                    success = 1;
                    usuario = criaUsuario(login, senha, fileNameHistorico, fileNameUsuarios);
                    if(verbosidade){
                        printf("Login efetuado com sucesso!\n");
                        sleep(TIME);
                    }
                        
                    telaPrincipal(usuario, filmes, fileNameFilmes, fileNameHistorico, verbosidade, fileNameUsuarios);

                } else if(loginUsuario == SENHAINCORRETA){
                    if(verbosidade){
                        printf("Senha incorreta!\n");
                        sleep(TIME);
                    }

                } else if(loginUsuario == USUARIONAOCADASTRADO){
                    if(verbosidade){
                        printf("Usuario nao cadastrado!\n");
                        sleep(TIME);
                    } 
                }
                break;
            
            case CADASTRO:
                if(verbosidade) printf("Nome de usuario: ");
                scanf("%s", login);
            
                if(verbosidade) printf("Senha: ");
                scanf("%s", senha);

                if(verbosidade) printf("Confirmacao de senha: ");
                scanf("%s", confirmaSenha);

                int cadastro = cadastraUsuario(login, senha, confirmaSenha, fileNameUsuarios);

                if(cadastro == CADASTROFEITO){
                    success = 1;
                    usuario = criaUsuario(login, senha, fileNameHistorico, fileNameUsuarios);
                    if(verbosidade){
                        printf("Cadastro feito com sucesso!\n");
                        sleep(TIME);
                    }
                    
                    telaPrincipal(usuario, filmes, fileNameFilmes, fileNameHistorico, verbosidade, fileNameUsuarios);
                
                } else if(cadastro == LOGINFORADOPADRAO){
                    if(verbosidade){
                        printf("Login fora do padrao.\n");
                        sleep(TIME);
                    }
                
                } else if(cadastro == SENHAFORADOPADRAO){
                    if(verbosidade){
                        printf("Senha fora do padrao.\n");  
                        sleep(TIME);
                    }
                
                } else if(cadastro == USUARIOJACADASTRADO){
                    if(verbosidade){
                        printf("Usuario ja cadastrado.\n"); 
                        sleep(TIME);
                    }
                
                } else if( cadastro == SENHAERRADA){
                    if(verbosidade){
                        printf("Senha incorreta.\n");
                        sleep(TIME);
                    }
                }
                break;
                    
            case SAIR: 
                success = 1;
                if(verbosidade) printf("Encerrando programa...\n");
                break;
            
            default: 
                if(verbosidade){ 
                    printf("Botao invalido\n");
                    sleep(TIME);
                }
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
 
void telaPrincipal(tUsuario* usuario, tFilme **filmes, char *fileNameFilmes, char *fileNameHistorico, int verbosidade, char *fileNameUsuarios){
    char *botao2 = (char*) malloc(sizeof(char) * 100);
    char *busca = (char*) malloc(sizeof(char) * 128);
    int qtdFilmes = contaLinhasCSV(fileNameFilmes);
    int success = 0;
    int botao2int;
    int nPagina = 1;
    int idMin = (nPagina - 1) * TAMPAG + 1;
    int idMax = nPagina * TAMPAG; 
    int maxPaginas;
    char botaoAux[100], botao3Aux[100], botao4Aux[100];
    int botao, botao3, botao4;

    if(qtdFilmes % TAMPAG == 0){
        maxPaginas = qtdFilmes / TAMPAG;
    } else{
        maxPaginas = qtdFilmes / TAMPAG + 1;
    }

    while(success == 0){
            if(verbosidade){
                limpaTela();
                printf("1. Listar filmes\n");
                printf("2. Meu perfil\n");
                printf("3. Procurar filme\n");
                printf("4. Sair\n");
            } 
        nPagina = 1;
        idMin = (nPagina - 1) * TAMPAG + 1;
        idMax = nPagina * TAMPAG; 
        
        scanf("%s", botaoAux); //talvez dê problema
        botao = atoi(botaoAux);
        
        switch(botao){
            case LISTARFILMES:
                
                while(1){ 
                    if(verbosidade) limpaTela();
                    imprimePagina(filmes, nPagina, qtdFilmes);
                    if(verbosidade){
                        printf("M - Mais filmes\n");
                        printf("m - Menos filmes\n");
                        printf("0 - Voltar\n");
                    }
                    
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
                        
                        break;
                    
                    } else if(botao2int < idMin || botao2int > idMax || botao2int < 0 || botao2int > qtdFilmes){
                        if(verbosidade){
                            printf("Botao invalido\n");
                            sleep(TIME);
                        }
                    
                    } else{
                        telaMetaDados(filmes, botao2int, usuario, fileNameHistorico, verbosidade);
                        break;
                    }
                }
                
                break;
            
            case MEUPERFIL: 
                while(1){
                    if(verbosidade){
                        limpaTela();
                        printf("1. Historico\n");
                        printf("2. Excluir conta\n");
                        printf("3. Voltar\n");
                    }
                    
                    scanf("%s", botao3Aux);
                    botao3 = atoi(botao3Aux); 
                    
                    if(botao3 == HISTORICO){
                        telaHistorico(usuario, filmes, verbosidade);
                    
                    }else if(botao3 == EXCLUIR){
                        success = 1;
                        usuario = inativarConta(usuario, fileNameUsuarios);
                        if(verbosidade) printf("Encerrando programa...\n");
                        break;
                    
                    }else if(botao3 == VOLT){
                        break;    //volta para a tela principal    
                    
                    }else {
                        if(verbosidade){
                            printf("Botao invalido\n");
                            sleep(TIME);
                        }
                    }
                }

                break;
            
            case PROCURARFILME: 
                //scanf("%*c");
                //getchar();
                if(verbosidade){
                    getchar();
                    limpaTela();
                    printf("Pesquisar: ");
                    scanf("%[^\n]", busca);
                
                } else{
                    // getchar();
                    // scanf("%*c");
                    // strtok(busca, '\n'); %[^/n] // um jeito que nao pegue o \n e pegue espaço
                    // char buscar[100];
                    // for(int i = 0; ; i++){
                    //     //buscar[i] = getchar();
                    //     scanf("%c", &buscar[i]);
                    //     if(buscar[i] == '\n'){
                    //         buscar[i] = '\0';
                    //         break;
                    //     }
                    // }
                    //getchar();
                   // strcpy(busca, buscar);
                   // fgets(busca, 128, stdin); //o filme pode ter até 128 caracteres 
                    //scanf("%s", busca);
                }
                
                //printf("(%s)\n", busca);
                printf("%s\n", busca);
                pesquisaFilmes(busca, filmes, qtdFilmes);
                if(verbosidade) printf("\n1- Voltar\n");

                while(1){
                    scanf("%s", botao4Aux);
                    botao4= atoi(botao4Aux);

                    if(botao4 == VOLTA){
                        break;
                    }
                    
                    if(verbosidade) printf("Botao invalido\n");
                }

                break;
            
            case SAIDA: 
                success = 1;
                if(verbosidade) printf("Encerrando programa...\n");
                break;
            
            default: 
                if(verbosidade){
                    printf("Botao invalido!\n");
                    sleep(TIME);
                }
        }
    }

    free(botao2);
    free(busca);
}

void telaMetaDados(tFilme **filmes, int id, tUsuario *usuario, char* fileNameHistorico, int verbosidade){
    int botao, encerra = 0;
    char botaoAux[100];
    imprimeFilme(filmes[id - 1]);

    while(encerra == 0){
        if(verbosidade){
            printf("1- Assistir\n");
            printf("2- Voltar\n");
        }

        scanf("%s", botaoAux);
        botao = atoi(botaoAux);

        switch(botao){
            case ASSISTIR: 
                limpaTela();
                encerra = 1;
                char notaAux[100];
                float nota;
                tData *data;
                while(1){ 
                    if(verbosidade) printf("Qual a sua avaliacao do filme? ");
                    scanf("%s", notaAux);
                    if(ehStringNumerica(notaAux) == 1){ // Para diferenciar o '0 float' do retorno 0 da função atof quando seu parâmetro é uma string não numérica
                        nota = atof(notaAux);
                        if(nota <= 10.0){
                            break;
                        }
                    }
                        
                    if(verbosidade) printf("Nota invalida! Digite novamente\n");
                }
                
                while(1){
                    if(verbosidade) printf("Qual a data que voce assistiu o filme? ");
                    data = leData(); //falta ver se a data eh valida
                    if(dataValida(data)){
                        break;
                    } else{
                        if(verbosidade) printf("Data invalida! Digite novamente\n");
                    }
                }

                int dia = getDia(data);
                int mes = getMes(data);
                int ano = getAno(data);
                tHistorico *hist = getHistorico(usuario);
                //char *login = getLogin(usuario);
                int idUsuario = getIdUnicaDaStructUsuario(usuario);

                adicionaFilmeHistorico(hist, id, nota, dia, mes, ano, fileNameHistorico, idUsuario);
                free(data);
                break;
            
            case VOLTAR:
                encerra = 1; //habilita para sair do while e voltar para a tela principal, pois vamos chamar essa funcao dentro da funcao da tela principal
                break; 
            
            default: 
                if(verbosidade) printf("Botao invalido\n");
        }
    }
}

void telaHistorico(tUsuario* usuario, tFilme** filmes, int verbosidade){
    char ordena[100];
    int botao;
    char botaoAux[100];
    tHistorico *hist = getHistorico(usuario);
    getchar(); //para consumir o /n do ultimo botao
    while(1){
        if(verbosidade){
            limpaTela();
            printf("D - Ordenar historico por data\n");
            printf("N - Ordenar historico por nota\n");
        }
        scanf("%s", ordena);
        
        if(strcmp(ordena, "D") == 0){
            ordenaHistoricoPorData(hist);
            break;
        
        } else if(strcmp(ordena, "N") == 0){
            ordenaHistoricoPorNota(hist);
            break;                     
        
        }else{
            if(verbosidade){
                printf("Botao invalido\n");
                sleep(TIME);
            }
        }
    }

    imprimirHistorico(hist, filmes);

    if(verbosidade) printf("\n1- Voltar\n");
    while(1){
        scanf("%s", botaoAux);
        botao = atoi(botaoAux);
        if(botao == VOLTA){
            break;
        }

        if(verbosidade) printf("Botao invalido\n");
    }
}

void UFLIX(char *fileNameUsuarios, char *fileNameHistorico, char *fileNameFilmes, tFilme **filmes, int verbosidade){
    telaInicial(fileNameUsuarios, fileNameHistorico, fileNameFilmes, filmes, verbosidade);
}
