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
 *  $FC Função: SEQJ  Criar Sequência de jogo
 *
 *  $ED Descrição da função
 *     Cria uma nova sequência de jogo a partir de uma pilha.
 *
 *  $EP Parâmetros
 *     $P pSeqJ - ponteiro para a sequênca a ser criada.
 *     $P pPilha - pilha a partir da qual a seqûencia irá ser criada.
 *
 *  $FV Valor retornado
 *     SEQJ_CondRetOk    -   criou ok.
 *     SEQJ_CondRetFaltouMemoria -   faltou memória para alocar espaço para a sequência.
 *
 ***********************************************************************/

SEQJ_tpCondRet SEQJ_CriarSeqJogo ( SEQJ_tppSeqJ * pSeqJ, PIL_tppPilha pPilha ) ;


/***********************************************************************
 *
 *  $FC Função: SEQJ Destruir Sequência de jogo
 *
 *  $ED Descrição da função
 *     Destroi uma sequência de jogo.
 *
 *  $EP Parâmetros
 *     $P pSeqJ - sequência de jogo a ser excluída.
 *
 *  $FV Valor retornado
 *     SEQJ_CondRetOk    -   excluiu ok.
 *
 ***********************************************************************/

SEQJ_tpCondRet SEQJ_DestroiSequencia ( SEQJ_tppSeqJ pSeqJ ) ;


/***********************************************************************
*
*  $FC Função: SEQJ Vira a primeira carta 

*  $ED Descrição da função
*     Vira a primeira carta da sequência de jogo, caso houver.
*     
*
*  $EP Parâmetros
*     pSeqJ - a sequência de jogo.
*              
*
*  $FV Valor retornado
*     SEQJ_CondRetSequenciaVazia  -   sequência vazia, nenhuma carta para virar.
*     SEQJ_CondRetOK              -    virou com sucesso.
*
***********************************************************************/

SEQJ_tpCondRet SEQJ_ViraPrimeiraCarta( SEQJ_tppSeqJ pSeqJ ) ;

/***********************************************************************
*
*  $FC Função: SEQJ Push Carta na sequência de jogo
*
*  $ED Descrição da função
*     A função da push em uma carta no inicio da Sequencia.
*     É usada para trazer uma carta do Monte de cartas para
*     sequência de jogo.
*     
*
*  $EP Parâmetros
*     pSeqJ   - sequência de jogo.
*     pCarta  - carta a ser colocada na sequência de jogo.
*              
*
*  $FV Valor retornado
*     SEQJ_CondRetOK      - push com sucesso.
*
***********************************************************************/

SEQJ_tpCondRet SEQJ_PushCartaSequencia( SEQJ_tppSeqJ pSeqJ, CAR_tppCarta pCarta ) ;

/***********************************************************************
*
*  $FC Função: SEQJ Obtem Pilha da Sequência de jogo
*
*  $ED Descrição da função
*     A função irá preencher uma pilha com uma sequência completa.
*     É usada para levar a sequência que foi completa para a sequência final.
*     
*
*  $EP Parâmetros
*     pSeqJ   - sequência de jogo.
*     pPilha -  ponteiro para a pilha a ser preenchida.
*              
*
*  $FV Valor retornado
*     SEQJ_CondRetOK                 - preencheu pilha com sucesso com sucesso.
*     SEQJ_CondRetSequenciaVazia;    - sequência vazia.
*
***********************************************************************/

SEQJ_tpCondRet SEQJ_ObtemPilhaSeqJ( SEQJ _tppSeqJ pSeqJ, PIL_tppPilha *pPilha ) ;

/***********************************************************************
*
*  $FC Função: SEQJ Move pilha de cartas
*
*  $ED Descrição da função
*     A função irá mover uma pilha de cartas entre duas sequências de jogo.
*     A quantidade de cartas que serão movidas é dada como parâmetro da função.
*     A pilha de cartas irá da sequência 1 para a sequência 2.
*     Só será possivel mover as cartas se elas estiverem na ordem correta e
*     possuirem o mesmo naipe. A mesma pilha de carta poderá ser colocada em 
*     qualquer outra sequência de jogo em que a primeira carta esteja de acordo
*     com a ultima carta da pilha movida, mesmo sendo de naipes diferentes.
*     Só podem ser movidas as cartas que estiverem viradas.
*     
*
*  $EP Parâmetros
*     pSeqJ1    - sequência 1, de onde sairá a pilha movida.
*     pSeqJ2    - sequência 2, para onde irá a pilha movida.
*     numCartas - número de cartas a serem movidas.
*              
*
*  $FV Valor retornado
*     SEQJ_CondRetOK                     - preencheu pilha com sucesso com sucesso.
*     SEQJ_CondRetNumCartasIncorreto     - número de cartas pedido é maior do que
*                                          o número de cartas viradas na sequência 1.
*     SEQJ_CondRetCartasForaDaSequencia  - as cartas escolhidas estão fora de ordem
*                                          ou não compatíveis com a sequência 2.
*
***********************************************************************/

SEQJ_tpCondRet SEQJ_MovePilhaCarta(SEQJ_tppSeqJ pSeqJ1, SEQJ_tppSeqJ pSeqJ2, int numCartas) ;

/***********************************************************************
*
*  $FC Função: SEQJ Verifica Sequência completa
*
*  $ED Descrição da função
*     A função irá verificar se existe uma sequência de cartas
*     no início da sequência de jogo, que esteja completa, na 
*     ordem correta e mesmo naipe.
*     
*
*  $EP Parâmetros
*     pSeqJ - sequência de jogo a ser verificada.
*              
*
*  $FV Valor retornado
*     SEQJ_CondRetOk                      -   pop com sucesso.
*     SEQJ_CondRetCartasForaDaSequencia   - nao existe sequência completa.
*
***********************************************************************/

SEQJ_tpCondRet SEQJ_VerificaSeqCompleta( SEQJ_tppSeqJ pSeqJ );

#undef SEQJ_EXT

/********** Fim do módulo de definição: SEQJ Sequência de jogo **********/

#else
#endif
