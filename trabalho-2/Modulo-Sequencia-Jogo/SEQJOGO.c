/***************************************************************************
 *  $MCI Módulo de implementação: SEQJ Sequência de Jogo
 *
 *  Arquivo gerado:              SEQJOGO.c
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
 *     1.0       EG,JM,LW        22/abr/2015       Início do desenvolvimento
 *
 ***************************************************************************/


#include "PILHA_DE_CARTAS.h"
#include "CARTA.h"

#define SEQJOGO_OWN
#include "SEQJOGO.h"
#undef SEQJOGO_OWN


/***********************************************************************
*
*  $TC Tipo de dados: SEQJ Sequência de Jogo
*
*
***********************************************************************/

   typedef struct SEQJ_tagSeqJogo {
    
     PIL_tppPilha pPilha; 
     /*Pontei para pilha de cartas*/
    
     int numCartasViradas ;
        /* Número de cartas viradas. Cada sequência irá começar com uma carta virada.
         */
    
} SEQJ_tpSeqJogo ;

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: SEQJ &Criar sequência de jogo a partir de pilha
*  ****/
   SEQJ_tpCondRet SEQJ_CriarSeqJogo ( SEQJ_tppSeqJ * pSeqJ, PIL_tppPilha pPilha ) 
   {
      PIL_tpCondRet condRet;
      CAR_tppCarta pCartaAux;

      *pSeqJ = (SEQJ_tppSeqJ *)malloc(sizeof(SEQJ_tppSeqJ));
      if( *pSeqJ == NULL)
      {
        return SEQJ_CondRetFaltouMemoria;
      }

      *(pSeqJ)->numCartasViradas = 1;

      condRet = PIL_CriarPilhaVazia( &((*pSeqJ)-pPilha) );

      if( condRet == PIL_CondRetFaltouMemoria )
      {
        return SEQJ_CondRetFaltouMemoria;
      }

      while( PIL_PopCarta( pPilha, &pCartaAux) == PIL_CondRetOK)
      {
        PIL_PushCarta((*pSeqJ)->pPilha),pCartaAux);
      }

      return SEQJ_CondRetOK;
   }

    /* Fim função: SEQJ  &Criar sequênca de jogo a partir de pilha */

/***************************************************************************
*
*  Função: SEQJ  &Destruir sequência de jogo
*  ****/

  SEQJ_tpCondRet SEQJ_DestroiSequencia ( SEQJ_tppSeqJ pSeqJ  )
  {
    if(pSeqJ->pLista == NULL)
    {
      free(pSeqJ);
      return SEQJ_CondRetOK;
    }
    PIL_DestroiPilha(pSeqJ->pPilha);
    free(pSeqJ);

    return SEQJ_CondRetOK;
  }

  /* Fim função: SEQJ  &Destruir sequência de jogo */

/***************************************************************************
*
*  Função: MON  SEQJ  &Vira a primeira carta da pilha de sequência de jogo
*  ****/

   SEQJ_tpCondRet SEQJ_ViraPrimeiraCarta( SEQJ_tppSeqJ pSeqJ )
   {
      CAR_tppCarta cartaAux;
      PIL_tpCondRet condRet;

      condRet = PIL_VerCarta(pSeqJ->pPilha, &cartaAux, 0 );

      if(condRet != PIL_CondRetOK)
      {
        return SEQJ_CondRetPilhaVazia;
      }

      pSeqJ->numCartasViradas++;

      return SEQJ_CondRetOK;
   }
  
   /* Fim função: SEQJ  &Vira a primeira carta da pilha de sequência de jogo*/

 /***************************************************************************
 * 
 *  Função: SEQJ &Push carta na sequencia
 *****/

   SEQJ_tpCondRet SEQJ_PushCartaSequencia( SEQJ_tppSeqJ pSeqJ, CAR_tppCarta pCarta )
   {
      PIL_PushCarta( pSeqJ->pPilha, pCarta);

      return SEQJ_CondRetOK;
   }

/* Fim função: SEQJ &Push carta na sequencia */

/***************************************************************************
* 
*  Função: SEQJ &Obtem pilha da sequência de jogo
*****/

   SEQJ_tpCondRet SEQJ_ObtemPilhaSeqJ( SEQJ _tppSeqJ pSeqJ, PIL_tppPilha *pPilha )
   {
      if(pSeqJ->pPilha == NULL)
      {
        return SEQJ_CondRetPilhaVazia;
      }

      *(pPilha) = pSeqJ->pPilha;

      return SEQJ_CondRetOK;
   }

/* Fim função: SEQJ &Obtem pilha da sequência de jogo */

/***************************************************************************
* 
*  Função: SEQJ &Move Pilha de sequência1 para sequência2
*****/
  SEQJ_tpCondRet SEQJ_MovePilhaCarta(SEQJ_tppSeqJ pSeqJ1, SEQJ_tppSeqJ pSeqJ2, int numCartas)
  {
    PIL_tppPilha pilhaAux;
    CAR_tppCarta cartaAux;
    CAR_tppCarta cartaAnterior;

    char naipeAtual = '?' ;
    char naipeAnterior = '!' ; 

    int valorAtual = 0 ; 
    int valorAnterior = 0 ;

    int numCartasSeq1 = 0;
    int seqComecou = 0;
    int i = 0;

    // 1 ver se pode mover tais cartas
    // 2 ver se podem se colocadas na seq2
    // 3 move-las

    //faltou verificar se cartas estao viradas
    // e dps virar carta, se for o caso

    if( numCartas > pSeqJ1->numCartasViradas)   // verifica caso de pedir mais cartas do que o numero de cartas viradas
    {
      return SEQJ_CondRetNumCartasIncorreto;
    }

    while( PIL_VerCarta( pSeqJ1->pPilha, &cartaAux, numCartasSeq1 ) == PIL_CondRetOK )
    {
      numCartasSeq1++;
    }

    if( numCartasSeq1 < numCartas )  // verifica se existem n numCartas na pilha a ser movida
    {
      return SEQJ_CondRetNumCartasIncorreto;
    }

    while( i < numCartas)   // verifica se as cartas a serem tiradas estão em sequencia
    {
      PIL_VerCarta( pSeqJ1->pPilha, &cartaAux, i );

      if( seqComecou )
      {
        CAR_ObterNaipe(cartaAux, &naipeAtual);
        CAR_ObterNaipe(cartaAnterior, &naipeAnterior);

        CAR_ObterValor(cartaAux, &valorAtual);
        CAR_ObterValor(cartaAnterior, &valorAnterior);

        if( valorAnterior != valorAtual - 1 || naipeAnterior != naipeAtual )
        {
          return SEQJ_CondRetCartasForaDaSequencia;
        }
      }
      cartaAnterior = cartaAux;
      if( !seqComecou ) seqComecou = 1;

      i++;
    }

    i = 0;  //depois de testadas as condições, mover cartas
    PIL_CriarPilhaVazia( &pilhaAux );

    while( i < numCartas )
    {
      PIL_PopCarta( pSeqJ1, &cartaAux );
      PIL_PushCarta( pilhaAux, cartaAux );
    }

    i = 0;

    while( i < numCartas )
    {
      PIL_PopCarta( pilhaAux, &cartaAux );
      PIL_PushCarta( pSeqJ2, cartaAux );
    }

    pSeqJ1->numCartasViradas -= numCartas;
    numCartasSeq1 -= numCartas;

    pSeqJ2->numCartasViradas += numCartas;

    if( pSeqJ1->numCartasViradas == 0  && numCartasSeq1 > 0)
    {
      SEQJ_ViraPrimeiraCarta( pSeqJ1 );
    }

    PIL_DestroiPilha( pilhaAux );

    return SEQJ_CondRetOK;
  }



/* Fim função: SEQJ &Move Pilha de sequência1 para sequência2 */

/*************** Fim do módulo de implementação: SEQJ Sequência de jogo *****************/
