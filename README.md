# 1. Dupla
Aluna: Elaine Dias Pires\
Matrícula: 2020101903

Aluno: Filipe Gomes Arante de Souza\
Matrícula: 2020100625


# 2. Organização do trabalho

## 2.1 TADS criadas
Para facilitar a implementação do trabalho, criamos as seguintes TADS:

### 2.1.1 TAD Data
Nessa TAD implementamos todas as operações que foram necessárias aplicar sobre um tipo data, por exemplo na hora do usuário inserir a data que assistiu ou filme, ordenar o histórico de um usuário por data e alocar memória para esse tipo.

### 2.1.2 TAD Filme
Nessa TAD foram implementadas todas as operações sobre um tipo filme, por exemplo, listá-los, pesquisá-los, carregá-los na memória e liberá-los da memória, dentre outros.

### 2.1.3 TAD Historico
Nessa TAD foram implementadas todas as operações sobre um histórico de um usuário. Por exemplo, alocar ou desalocar memória para um histórico, adicionar filmes assistidos no histórico, escrevê-los num arquivo CSV para armazená-los, dentre outros.

### 2.1.4 TAD Usuario
Nessa TAD foram implementadas todas as operações sobre um tipo usuário, por exemplo, criar, cadastrar, logar um usuário, dentre outros.


## 2.2 Bibliotecas criadas
Também criamos duas bibliotecas auxiliares que nos permitiu maior facilidade para desenvolver o programa:

###  2.2.1 Biblioteca Telas
Biblioteca que faz controle de todos os menus do sistema UFLIX. Cada função dessa biblioteca imprime os botões na tela, recebe as entradas do usuário, bem como o direciona para outro menu, se necessário. Criamos essa biblioteca para deixar o programa cliente mais claro. Os botões são impressos dependendo da verbosidade.

### 2.2.2 Biblioteca Utils
Biblioteca que possui funções auxiliares que foram necessárias, mas não se encaixavam em nenhuma TAD.

# 3. Observações importantes

## 3.1 Verbosidade
Quando o programa é executado com verbosidade, optamos por fazer limpeza do terminal para a interface ficar mais amigável ao usuário. Além disso, quando conveniente utilizamos a função **"sleep"** da biblioteca **"unistd.h"** para apresentar algumas mensagens aparecerem por alguns segundos. Por exemplo, caso seja feito algum login com senha errada, programamos para aparecer a mensagem **"Senha incorreta."** por 2 segundos, e em seguida o terminal era limpo e o menu inicial era impresso novamente na tela.

## 3.2 Tratamento de possíveis entradas inválidas dos usuários
 Implementamos todos os "botões" (entradas numéricas em cada tela esperadas do usuário) como strings, para prevenir uma possível entrada não numérica. Caso isso ocorresse, colocamos printfs de **"Botao inválido"** pelo programa. Se fosse uma entrada válida, ela seria convertida no tipo dessa determinada entrada. Por exemplo, na situação cujo botão represente um número inteiro ou float, convertemos utilizando a função **“atoi”** e **“atof”**, respectivamente. Não tratamos desse jeito na parte do histórico e na parte de tela de metadados, pois nesses casos, de fato, o programa esperava strings, **D** ou **N** e **M** ou **m**. Quando o botão representava uma data, primeiro tratamos como string também para verificar erros do usuário e se de fato fosse uma data, fizemos os devidos tratamentos para capturar o dia, mês e ano daquela entrada com auxílio da função **"sscanf"**. Fizemos mais um tratamento para checar se os números da data eram válidos. Desse modo, conseguimos resolver a questão de possíveis erros do usuário ao utilizar o programa.
 Acrescentamos 1 caso de impressão de erro de cadastro que não constava na especificação:
**"Login fora do padrão."**, quando o login inserido não era alfanumérico.


## 3.3 Carregamento de usuários na memória 
Em relação ao carregamento de usuários na memória, havia 2 opções: 
- Ao iniciar o programa, carregar na memória todos os usuários cadastrados num vetor;
- Carregar somente um usuário, que seria o que fazia login ou cadastro no sistema; 

Optamos pela segunda opção, pois essa alternativa gastaria menos memória, e, além disso, diminuiria a chance de problemas com vazamento de memória no desenvolvimento do trabalho.

## 3.4 Listagem de filmes
Na listagem de filmes, é especificado que o usuário pode ir para a próxima página utilizando a entrada **"M"**, visulizando os filmes apenas em ordem crescente de id de filmes. Achamos interessante implementar o botão **"m"**, que faz o inverso. Desse modo, o usuário pode navegar do jeito que preferir para visualizar os filmes do programa.  Caso ele esteja na primeira página de filmes, e tente voltar, programamos para imprimir na tela a mensagem **"Fim de filmes disponíveis."**, assim como se o usuário tentasse visualizar mais filmes do que o disponível no catálogo, ou seja, estar na última página do catálogo e tentar avançar.

## 3.5 idUnica
No programa, há a opção de inativar contas. Uma vez que isso acontece, o login dessa conta fica disponível para cadastro. Inicialmente, implementamos todas funções de caregar o histórico a partir da login do usuário, entretanto, caso uma conta fosse criada com um login que já existiu, seriam carregados no histórico desse novo usuário os filmes que foram assistidos pela conta que foi inativada. Para resolver esse problema, trocamos a lógica do programa para a **idUnica**. Ou seja, no arquivo **"historico.csv"**, explicado mais adiante, a referência passa a ser a idUnica de cada usuário. Essa idUnica é definida a partir da linha que consta o usuário no arquivo usuarios.csv.

## 3.6 Armazenamento de dados
Para o armazenamento dos dados que precisam persistir no programa após seu encerramento, utilizamos os arquivos CSV fornecidos na especificação. Também criamos um outro, **"historico.csv"** para auxiliar o armazenamento dos filmes assistidos por todos os usuários sistema.\ Por conta de termos criado um arquivo csv auxiliar, vamos enviá-lo já inicializado com alguns filmes assistidos.

- O arquivo usuarios.csv possui 3 colunas, que representam, respectivamente, o login, a senha e o estado da conta (ativa ou inativa).

- Já o arquivo historico.csv possui 4 colunas, que representam, respectivamente, a idUnica do usuário, a id do filme, a nota que o usuário deu ao filme e a data que o usuário assistiu o filme, no padrão:
**"idUsuario,idFilme,nota,data"**.
Cada filme está em uma linha desse arquivo, sendo que o arquivo contém os filmes assistidos por todos os usuários. Filmes em sequência não necessariamente são do mesmo usuário. O que determina o usuário é a sua idUnica.

## 3.7 Tratamento de datas
Foi sugerido usar a biblioteca **"time.h"** para fazer a ordenação do histórico do usuário em função da data. Entretanto, optamos por fazer sem ela e criamos uma função análoga a **"strcmp"**, da biblioteca **"string.h"**. Chamamos essa função de **"datacmp"**, e ela compara duas datas e nos diz se uma data é anterior, igual, ou posterior a outra. 

## 3.8 Procurar filmes
Nessa parte, tivemos um problema na entrada de dados. Quando o programa era executado com verbosidade, entrada e saída ocorriam conforme o esperado. Entretanto, sem verbosidade, a entrada não era capturada corretamente devido a um **"/n"**. Para resolver essa questão, utilizamos a função **fgets** que capturava esse mesmo **\n**, entretanto, essa função insere um caracter NULL na string. Para ignorar esses dois caracteres, deslocamos o caractere **"\0** duas casas para a esquerda. 
Dessa forma, na busca de filmes, implementamos formas diferentes de leitura quando havia e quando não havia verbosidade com auxílio de um if else. 
Também tivemos uma dúvida se a partir desse ponto o usuário poderia assistir ou não algum filme que tenha buscado. Como essa opção não estava presente na especificação, optamos por seguí-la e após a pesquisa de um filme o usuário tem apenas a opção de **"voltar"**.\
Optamos por imprimir os filmes buscados pelo usuário acompanhados pela sua respectiva id e não pela ordem de busca (1,2,3,...), pois caso o usuário se interesse por algum filme, ele já sabe qual a sua Id para assistir o filme pela listagem.

## 3.9 Realloc no histórico de filmes do usuário
Utilizamos a função realloc caso o usuário assista mais filmes do que seu histórico pode armazenar. Mas, para evitar ao máximo o uso dessa função, programamos para inicializar o histórico com todos os seus filmes já assistidos, além de mais 10 espaços de memória reservados. Em outras palavras, caso o usuário ao logar, já tenha assistido **n filmes**, serão reservados **n+10** espaços na memória. Se ele assistir filmes até preencher todo o vetor, o realloc é acionado e reserva mais 10 espaços de memória para o histórico.

# 4. Envio dos arquivos
Estamos enviando todos os arquivos **".h"**, **".c"**, o **Makefile**, o programa cliente **(main.c)** e também os arquivos **"filmes-grande.csv"**, **"filmes-pequeno.csv"**, **"usuarios.csv"** e **"historico.csv"**.

# 5. Considerações finais
A compilação do arquivo está gerando diversos warnings, do tipo:

*warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result*

Como se estivesse esperando um retorno da função scanf, mas o programa está compilando corretamente e isto não está atrapalhando a execução do programa.