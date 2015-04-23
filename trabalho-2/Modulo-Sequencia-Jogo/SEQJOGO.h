#if ! defined( SEQJ_ )
#define SEQJ_
/***************************************************************************
 *
 *  $MCD Módulo de definição: SEQJ Sequência de jogo
 *
 *  Arquivo gerado:              SEQJOGO.h
 *  Letras identificadoras:      SEQJ
 *
 *  Nome da base de software:    Arcabouço para a automação de testes de programas redigidos em C
 *
 *  Projeto: Trabalho 2 - Programação Modular
 *  Autores: EG - Eric Grinstein
             JM - Jordana Mecler
             LW - Leonardo Wajnsztok
 *
 *  $HA Histórico de evolução:
 *     Versão      Autor            Data                Observações
 *     1.0       EG,JM,LW        23/abr/2015       Início do desenvolvimento
 *     
 *  $ED Descrição do módulo
 *     Este módulo implementa funções para criar e manipular um Monte.
 *     Um Monte é uma pilha de 10 cartas.
 *     O monte é criado a partir de uma pilha de cartas.
 *     É possível retirar uma carta de cada vez do monte
 *     e nao pode colocar nenhuma carta no monte.
 *
 ***************************************************************************/

#if defined( SEQJ_OWN )
    #define SEQJ_EXT
#else
    #define SEQJ_EXT extern
#endif

/***** Declarações exportadas pelo módulo *****/

/* Tipo referência para um monte */

typedef SEQJ_tagSeqJogo * SEQJ_tppSeqJogo ;

/***********************************************************************
 *
 *  $TC Tipo de dados: MON Condições de retorno
 *
 *
 *  $ED Descrição do tipo
 *     Condições de retorno das funções de Monte
 *
 ***********************************************************************/

    typedef enum {

        SEQJ_CondRetOK = 0,
               /* Concluiu corretamente */

        SEQJ_CondRetSequenciaVazia = 1,
               /* Sequência não contém elementos */

        SEQJ_CondRetFaltouMemoria = 2,
               /* Faltou memória ao tentar criar o sequência */

        SEQJ_CondRetNumCartasIncorreto = 3,
               /* Número de cartas a serem movidas está incorreto */

        SEQJ_CondRetCartasForaDaSequencia = 4
               /* Cartas escolhidas estão fora da sequência */

   } MON_tpCondRet ;


/***********************************************************************
 *
 *  $FC Função: MON  Criar monte
 *
 *  $ED Descrição da função
 *     Cria um novo monte a partir de uma pilha.
 *
 *  $EP Parâmetros
 *     $P pMonte - ponteira para o monte a ser criado.
 *     $P pPilha - pilha a partir da qual o monte irá ser criado.
 *
 *  $FV Valor retornado
 *     MON_CondRetOk    -   criou ok.
 *     MON_CondRetFaltouMemoria -   faltou memória para alocar espaço para o monte.
 *
 ***********************************************************************/

SEQJ_tpCondRet SEQJ_CriarSeqJogo ( SEQJ_tppSeqJ * pSeqJ, PIL_tppPilha pPilha ) ;


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
 ***********************************************************************/

SEQJ_tpCondRet SEQJ_DestroiSequencia ( SEQJ_tppSeqJ pSeqJ ) ;


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
***********************************************************************/

SEQJ_tpCondRet SEQJ_ViraPrimeiraCarta( SEQJ_tppSeqJ pSeqJ ) ;

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
***********************************************************************/

SEQJ_tpCondRet SEQJ_PushCartaSequencia( SEQJ_tppSeqJ pSeqJ, CAR_tppCarta pCarta ) ;

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
***********************************************************************/

SEQJ_tpCondRet SEQJ_ObtemPilhaSeqJ( SEQJ _tppSeqJ pSeqJ, PIL_tppPilha *pPilha ) ;

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
***********************************************************************/

SEQJ_tpCondRet SEQJ_MovePilhaCarta(SEQJ_tppSeqJ pSeqJ1, SEQJ_tppSeqJ pSeqJ2, int numCartas) ;


#undef SEQJ_EXT

/********** Fim do módulo de definição: SEQJ Sequência de jogo **********/

#else
#endif
