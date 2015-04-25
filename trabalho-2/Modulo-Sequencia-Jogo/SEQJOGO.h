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
 *     2.0       EG,JM,LW        25/abr/2015       Revisão das funções
 *     1.0       EG,JM,LW        23/abr/2015       Início do desenvolvimento
 *     
 *  $ED Descrição do módulo
 *      Este módulo implementa funções para criar e manipular uma Sequencia de Jogo.
 *      Uma sequencia de jogo começa com 5 ou 6 cartas, criada a partir de uma pilha
 *      distribuída por um baralho completo.
 *      É possivel mover as cartas entre as sequencias de jogo existentes e quando
 *      umas delas possuir uma sequencia completa do mesmo naipe, está sequencia 
 *      será levada a sequencia final.
 *
 ***************************************************************************/

#if defined( SEQJ_OWN )
    #define SEQJ_EXT
#else
    #define SEQJ_EXT extern
#endif

#include "CARTA.H"
#include "PILHA_DE_CARTAS.H"

/***** Declarações exportadas pelo módulo *****/

/* Tipo referência para uma Sequência de jogo */

typedef SEQJ_tagSeqJogo * SEQJ_tppSeqJogo ;

/***********************************************************************
 *
 *  $TC Tipo de dados: SEQJ Condições de retorno
 *
 *
 *  $ED Descrição do tipo
 *     Condições de retorno das funções de Sequência de jogo
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

   } SEQJ_tpCondRet ;


/***********************************************************************
 *
 *  $FC Função: MON  Criar monte
 *
 *  $ED Descrição da função
 *     Cria uma nova sequência de jogo a partir de uma pilha.
 *
 *  $EP Parâmetros
 *     $P pSeqJ - ponteiro para a sequênca a ser criada.
 *     $P pPilha - pilha a partir da qual a seqûencia irá ser criada.
 *
 *  $FV Valor retornado
 *     MON_CondRetOk    -   criou ok.
 *     MON_CondRetFaltouMemoria -   faltou memória para alocar espaço para a sequência.
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

SEQJ_tpCondRet SEQJ_VerificaSeqCompleta( SEQJ_tppSeqJ pSeqJ, int *completa);

#undef SEQJ_EXT

/********** Fim do módulo de definição: SEQJ Sequência de jogo **********/

#else
#endif
