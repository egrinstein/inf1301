#if ! defined( LISTA_ )
#define LISTA_
/***************************************************************************
*
*  $MCD Módulo de definição: LIS  Lista duplamente encadeada
*
*  Arquivo gerado:              LISTA.h
*  Letras identificadoras:      LIS
*
*  Nome da base de software:    Arcabouço para a automação de testes de programas redigidos em C
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\LISTA.BSW
*
*  Projeto: INF 1301 / 1628 Automatização dos testes de módulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: avs
*           EG
*           JM
*           LW
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     5    EG,JM,LW 27/abr/2015 todas as funções retornam condições de retorno.
*     4       avs   01/fev/2006 criar linguagem script simbólica
*     3       avs   08/dez/2004 uniformização dos exemplos
*     2       avs   07/jul/2003 unificação de todos os módulos em um só projeto
*     1       avs   16/abr/2003 início desenvolvimento
*
*  $ED Descrição do módulo
*     Implementa listas genéricas duplamente encadeadas.
*     Podem existir n listas em operação simultaneamente.
*     As listas possuem uma cabeÃa encapsulando o seu estado.
*
*     Cada lista é homogênea quanto ao tipo dos dados que armazena.
*     Cada elemento da lista referencia o valor que contém.
*
*     Os ponteiros para os dados sâ€žo copiados para elementos da lista.
*        Nâ€žo Ãˆ copiado o valor apontado por estes ponteiros.
*
*     O controle da destruiÃâ€žo do valor de um elemento a ser excluÃŒdo
*        Ãˆ realizado por uma funÃâ€žo fornecida pelo usuÂ·rio.
*
*     Cada lista referencia uma funÃâ€žo que determina como devem ser
*        desalocados os dados nela contidos.
*
*     A funÃâ€žo de liberaÃâ€žo dos valores contidos nos elementos deve
*        assegurar a liberaÃâ€žo de todos os espaÃos referÃnciados pelo
*        valor contido em um elemento.
*        Esta funÃâ€žo Ãˆ chamada antes de se desalocar um elemento
*        de uma lista.
*        Caso nâ€žo seja necessÂ·rio desalocar o valor referenciado pelo
*        elemento, o ponteiro para a funÃâ€žo de liberaÃâ€žo poderÂ· ser NULL .
*        Caso o elemento da lista seja a Ë™nica â€šncora do valor referenciado,
*        esta funÃâ€žo deve promover a destruiÃâ€žo (free) desse valor e
*        de todos os dados nele ancorados.
*
***************************************************************************/
 
#if defined( LISTA_OWN )
   #define LISTA_EXT
#else
   #define LISTA_EXT extern
#endif

/***** DeclaraÃÄ±es exportadas pelo mÃ›dulo *****/

/* Tipo referÃncia para uma lista */

typedef struct LIS_tagLista * LIS_tppLista ;


/***********************************************************************
*
*  $TC Tipo de dados: LIS CondiÃÄ±es de retorno
*
*
*  $ED DescriÃâ€žo do tipo
*     CondiÃÄ±es de retorno das funÃÄ±es da lista
*
***********************************************************************/

   typedef enum {

         LIS_CondRetOK ,
               /* Concluiu corretamente */

         LIS_CondRetListaVazia ,
               /* A lista nâ€žo contÃˆm elementos */

         LIS_CondRetFimLista ,
               /* Foi atingido o fim de lista */

         LIS_CondRetNaoAchou ,
               /* Nâ€žo encontrou o valor procurado */

         LIS_CondRetFaltouMemoria,
               /* Faltou memÃ›ria ao tentar criar um elemento de lista */
       
         LIS_CondRetListaNaoExiste,
       /* A lista nÃ£o existe */


   } LIS_tpCondRet ;


/***********************************************************************
*
*  $FC FunÃâ€žo: LIS  &Criar lista
*
*  $ED DescriÃâ€žo da funÃâ€žo
*     Cria uma lista genÃˆrica duplamente encadeada.
*     Os possÃŒveis tipos sâ€žo desconhecidos a priori.
*     A tipagem Ãˆ implicita.
*     Nâ€žo existe identificador de tipo associado â€¡ lista.
*
*  $EP Parâ€šmetros
*     $P pLista         - ponteiro para a lista a ser criada.
*     $PExcluirValor    - ponteiro para a funÃâ€žo que processa a
*                       exclusâ€žo do valor referenciado pelo elemento
*                       a ser excluÃŒdo.
*                       Ver descriÃâ€žo do mÃ›dulo.
*
*  $FV Valor retornado
*     LIS_CondRetOK             - se executou ok.
*     LIS_CondRetFaltouMemoria  - se faltou memÃ³ria ao tentar alocar espaÃ§o.
*
***********************************************************************/

   LIS_tpCondRet LIS_CriarLista( LIS_tppLista * pLista,
             void   ( * ExcluirValor ) ( void * pDado ) ) ;


/***********************************************************************
*
*  $FC FunÃâ€žo: LIS  &Destruir lista
*
*  $ED DescriÃâ€žo da funÃâ€žo
*     DestrÃ›i a lista fornecida.
*     O parâ€šmetro ponteiro para a lista nâ€žo Ãˆ modificado.
*     Se ocorrer algum erro durante a destruiÃâ€žo, a lista resultarÂ·
*     estruturalmente incorreta.
*     OBS. nâ€žo existe previsâ€žo para possÃŒveis falhas de execuÃâ€žo.
*
*  $EP ParÃ¢metros
*     $P pLista - ponteiro para a lista a ser destruÃ­da.
*
*  $FV Valor retornado
*     LIS_CondRetOK             - destruiu ok.
*     LIS_CondRetListaNaoExiste - se a lista a ser destruÃ­da nÃ£o existe.
*
***********************************************************************/

   LIS_tpCondRet LIS_DestruirLista( LIS_tppLista pLista ) ;


/***********************************************************************
*
*  $FC FunÃâ€žo: LIS  &Esvaziar lista
*
*  $ED DescriÃâ€žo da funÃâ€žo
*     Elimina todos os elementos, sem contudo eliminar a lista
*
*  $EP Parâ€šmetros
*     pLista - ponteiro para a lista a ser esvaziada
*
*  $FV Valor retornado
*     LIS_CondRetOK             - se esvaziou ok.
*     LIS_CondRetListaNaoExiste - se a lista a ser esvaziada nÃ£o existe.
*
***********************************************************************/

   LIS_tpCondRet LIS_EsvaziarLista( LIS_tppLista pLista ) ;


/***********************************************************************
*
*  $FC FunÃâ€žo: LIS  &Inserir elemento antes
*
*  $ED DescriÃâ€žo da funÃâ€žo
*     Insere novo elemento antes do elemento corrente.
*     Caso a lista esteja vazia, insere o primeiro elemento da lista.
*
*  $EP Parâ€šmetros
*     pLista - ponteiro para a lista onde deve ser inserido o elemento
*     pValor - ponteiro para o valor do novo elemento
*              Pode ser NULL
*
*  $FV Valor retornado
*     LIS_CondRetOK
*     LIS_CondRetFaltouMemoria
*
***********************************************************************/

   LIS_tpCondRet LIS_InserirElementoAntes( LIS_tppLista pLista ,
                                           void * pValor        ) ;


/***********************************************************************
*
*  $FC FunÃâ€žo: LIS  &Inserir elemento apÃ›s
*
*  $ED DescriÃâ€žo da funÃâ€žo
*     Insere novo elemento apÂ·s o elemento corrente.
*     Caso a lista esteja vazia, insere o primeiro elemento da lista.
*
*  $EP Parâ€šmetros
*     Parâ€šmetros
*        pLista - ponteiro para a lista onde deve ser inserido o elemento
*        pValor - ponteiro para o valor do novo elemento
*                 Pode ser NULL
*           
*
*  $FV Valor retornado
*     Valor retornado
*        LIS_CondRetOK
*        LIS_CondRetFaltouMemoria
*
***********************************************************************/

   LIS_tpCondRet LIS_InserirElementoApos( LIS_tppLista pLista ,
                                          void * pValor        )
       ;


/***********************************************************************
*
*  $FC FunÃâ€žo: LIS  &Excluir elemento
*
*  $ED DescriÃâ€žo da funÃâ€žo
*     Exclui o elemento corrente da lista dada.
*     Se existir o elemento aa esquerda do corrente serÂ· o novo corrente.
*     Se nâ€žo existir e existir o elemento â€¡ direita, este se tornarÂ· corrente.
*     Se este tambÃˆm nâ€žo existir a lista tornou-se vazia.
*
*  $EP Parâ€šmetros
*     pLista    - ponteiro para a lista na qual deve excluir.
*
*  $FV Valor retornado
*     LIS_CondRetOK
*     LIS_CondRetListaVazia
*
***********************************************************************/

   LIS_tpCondRet LIS_ExcluirElemento( LIS_tppLista pLista ) ;


/***********************************************************************
*
*  $FC FunÃâ€žo: LIS  &Obter referÃncia para o valor contido no elemento
*
*  $ED DescriÃâ€žo da funÃâ€žo
*     Obtem a referÃncia para o valor contido no elemento corrente da lista
*
*  $EP Parâ€šmetros
*     pLista - ponteiro para a lista de onde se quer o valor
*     pValor - ponteiro que receberÃ¡ a referÃªncia para o valor contido no elemento.
*
*  $FV Valor retornado
*     LIS_CondRetOK             - se o valor foi passado ok.
*     LIS_CondRetListaNaoExiste - se a lista passada nÃ£o existe.
*     LIS_CondRetListaVazia     - se a lista estÃ¡ vazia.
*
***********************************************************************/

   LIS_tpCondRet LIS_ObterValor( LIS_tppLista pLista , void ** pValor ) ;


/***********************************************************************
*
*  $FC FunÃâ€žo: LIS  &Ir para o elemento inicial
*
*  $ED DescriÃâ€žo da funÃâ€žo
*     Torna corrente o primeiro elemento da lista.
*     Faz nada se a lista estÂ· vazia.
*
*  $EP Parâ€šmetros
*     pLista - ponteiro para a lista a manipular
*
*  $FV Valor retornado
*     LIS_CondRetOK             - se foi para o Ã­nicio ok.
*     LIS_CondRetListaNaoExiste - se a lista nÃ£o existe.
*     LIS_CondRetListaVazia     - se a lista estÃ¡ vazia.
*
***********************************************************************/

   LIS_tpCondRet LIS_IrInicioLista( LIS_tppLista pLista ) ;


/***********************************************************************
*
*  $FC FunÃâ€žo: LIS  &Ir para o elemento final
*
*  $ED DescriÃâ€žo da funÃâ€žo
*     Torna corrente o elemento final da lista.
*     Faz nada se a lista estÂ· vazia.
*
*  $EP Parâ€šmetros
*     pLista - ponteiro para a lista a manipular
*  
*  $FV Valor retornado
*     LIS_CondRetOK             - se foi para o final ok.
*     LIS_CondRetListaNaoExiste - se a lista nÃ£o existe.
*     LIS_CondRetListaVazia     - se a lista estÃ¡ vazia.
*
***********************************************************************/

   LIS_tpCondRet LIS_IrFinalLista( LIS_tppLista pLista ) ;


/***********************************************************************
*
*  $FC FunÃâ€žo: LIS  &AvanÃar elemento
*
*  $ED DescriÃâ€žo da funÃâ€žo
*     AvanÃa o elemento corrente numElem elementos na lista
*     Se numElem for positivo avanÃa em direÃâ€žo ao final
*     Se numElem for negativo avanÃa em direÃâ€žo ao inÃŒcio
*     numElem pode ser maior do que o nË™mro de elementos existentes na
*               direÃâ€žo desejada
*     Se numElem for zero somente verifica se a lista estÂ· vazia
*
*  $EP Parâ€šmetros
*     pLista  - ponteiro para a lista a ser manipulada
*     numElem - o nË™mero de elementos a andar
*
*  $FV Valor retornado
*     CondRetOK         - se numElem elementos tiverem sido andados
*     CondRetFimLista   - se encontrou o fim da lista antes de andar numElem
*                         elementos
*     CondRetListaVazia - se a lista estÂ· vazia
*
***********************************************************************/

   LIS_tpCondRet LIS_AvancarElementoCorrente( LIS_tppLista pLista ,
                                              int numElem ) ;


/***********************************************************************
*
*  $FC FunÃâ€žo: LIS  &Procurar elemento contendo valor
*
*  $ED DescriÃâ€žo da funÃâ€žo
*     Procura o elemento que referencia o valor dado.
*     A funÃâ€žo compara ponteiro e nâ€žo conteË™do apontado.
*
*  $EP Parâ€šmetros
*     pLista  - ponteiro para a lista onde procura
*     pValor  - ponteiro para o valor procurado
*               Pode ser NULL
*
*  $FV Valor retornado
*     LIS_CondRetOK  - se encontrou.
*                      O elemento corrente Ãˆ o primeiro elemento do
*                      elemento corrente inclusive para o fim da lista
*                      e que contÃˆm o ponteiro procurado
*
*     LIS_CondRetNaoEncontrou - se o ponteiro nâ€žo foi encontrado
*                      O elemento corrente continua o mesmo
*     LIS_CondRetListaVazia   - se a lista estiver vazia
*
***********************************************************************/

   LIS_tpCondRet LIS_ProcurarValor( LIS_tppLista pLista ,
                                    void * pValor        ) ;

#undef LISTA_EXT

/********** Fim do mÃ›dulo de definiÃâ€žo: LIS  Lista duplamente encadeada **********/

#else
#endif
