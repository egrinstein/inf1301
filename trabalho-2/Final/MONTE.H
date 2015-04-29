#if ! defined( MON_ )
#define MON_
/***************************************************************************
 *
 *  $MCD MÃ³dulo de definiÃ§Ã£o: MON Monte
 *
 *  Arquivo gerado:              MONTE.h
 *  Letras identificadoras:      MON
 *
 *  Nome da base de software:    ArcabouÃ§o para a automaÃ§Ã£o de testes de programas redigidos em C
 *
 *  Projeto: Trabalho 2 - ProgramaÃ§Ã£o Modular
 *  Autores: EG - Eric Grinstein
             JM - Jordana Mecler
             LW - Leonardo Wajnsztok
 *
 *  $HA HistÃ³rico de evoluÃ§Ã£o:
 *     VersÃ£o      Autor            Data                ObservaÃ§Ãµes
 *     1.0       EG,JM,LW        18/abr/2015       InÃ­cio do desenvolvimento
 *     
 *  $ED DescriÃ§Ã£o do mÃ³dulo
 *     Este mÃ³dulo implementa funÃ§Ãµes para criar e manipular um Monte.
 *     Um Monte Ã© uma pilha de 10 cartas.
 *     O monte Ã© criado a partir de uma pilha de cartas.
 *     Ã‰ possÃ­vel retirar uma carta de cada vez do monte
 *     e nao pode colocar nenhuma carta no monte.
 *
 ***************************************************************************/

#if defined( MON_OWN )
    #define MON_EXT
#else
    #define MON_EXT extern
#endif

/***** DeclaraÃ§Ãµes exportadas pelo mÃ³dulo *****/

/* Tipo referÃªncia para um monte */

typedef struct MON_tagMonte * MON_tppMonte ;

/***********************************************************************
 *
 *  $TC Tipo de dados: MON CondiÃ§Ãµes de retorno
 *
 *
 *  $ED DescriÃ§Ã£o do tipo
 *     CondiÃ§Ãµes de retorno das funÃ§Ãµes de Monte
 *
 ***********************************************************************/

    typedef enum {

        MON_CondRetOK = 0,
               /* Concluiu corretamente */

        MON_CondRetMonteVazio = 1,
               /* O monte nÃ£o contÃ©m elementos */

        MON_CondRetFaltouMemoria = 2
               /* Faltou memÃ³ria ao tentar criar o monte */

   } MON_tpCondRet ;


/***********************************************************************
 *
 *  $FC FunÃ§Ã£o: MON  Criar monte
 *
 *  $ED DescriÃ§Ã£o da funÃ§Ã£o
 *     Cria um novo monte a partir de uma pilha.
 *
 *  $EP ParÃ¢metros
 *     $P pMonte - ponteira para o monte a ser criado.
 *     $P pPilha - pilha a partir da qual o monte irÃ¡ ser criado.
 *
 *  $FV Valor retornado
 *     MON_CondRetOk    -   criou ok.
 *     MON_CondRetFaltouMemoria -   faltou memÃ³ria para alocar espaÃ§o para o monte.
 *
 *  Assertivas de entrada esperadas - pPilha != NULL.
 * 
 *  Assertivas de saída esperadas   - MON_CondRetOk
 *                                     MON_CondRetFaltouMemoria se pMonte == NULL
 *
 ***********************************************************************/

MON_tpCondRet MON_CriarMonte ( MON_tppMonte * pMonte , PIL_tppPilha pPilha) ;


/***********************************************************************
 *
 *  $FC Função: CAR  Destruir monte
 *
 *  $ED Descrição da função
 *     Destroi um monte.
 *
 *  $EP Parâmetros
 *     $P pMonte - ponteiro para o monte a ser excluída.
 *
 *  $FV Valor retornado
 *     MON_CondRetOk    -   excluiu ok.
 * 
 *  Assertivas de entrada esperadas - pMonte != NULL.
 * 
 *  Assertivas de saída esperadas   - pMonte == NULL
 *                                   
 *
 ***********************************************************************/
***********************************************************************/

MON_tpCondRet MON_DestruirMonte ( MON_tppMonte pMonte ) ;


/***********************************************************************
*
*  $FC Função: MON Pop Carta
*
*  $ED Descrição da função
*     Remove carta do topo do monte
*     
*
*  $EP Parâmetros
*     pMonte - ponteiro para o monte.
*     pCarta - endereço que receberá a carta removida.
*              
*
*  $FV Valor retornado
*     MON_CondRetOk     -   pop com sucesso.
*     MON_CondRetMonteVazio     - monte vazio.
* 
*  Assertivas de entrada esperadas - pMonte != NULL.
*                                      pCarta == NULL
* 
*  Assertivas de saída esperadas   - pCarta != NULL
*
***********************************************************************/

MON_tpCondRet MON_PopCartaMonte ( MON_tppMonte pMonte, CAR_tppCarta * pCarta ) ;

#undef MON_EXT

/********** Fim do mÃ³dulo de definiÃ§Ã£o: MON Monte **********/

#else
#endif
