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
      /* Número de cartas viradas. Cada sequência irá começar com uma carta virada. */
    
} SEQJ_tpSeqJogo ;

/***** Protótipos das funções encapuladas no módulo *****/

int totalCartasNaSeq( SEQJ_tppSeqJogo pSeqJ );

int ehSequenciaValor( CAR_tppCarta carta1, CAR_tppCarta carta2 ) ;

int ehMesmoNaipe( CAR_tppCarta carta1, CAR_tppCarta carta2 ) ;

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: SEQJ &Criar sequência de jogo a partir de pilha
*  ****/
   SEQJ_tpCondRet SEQJ_CriarSeqJogo ( SEQJ_tppSeqJogo * pSeqJ, PIL_tppPilha pPilha ) 
   {
      PIL_tpCondRet condRet;
      CAR_tppCarta pCartaAux;

      *pSeqJ = (SEQJ_tppSeqJogo *)malloc(sizeof(SEQJ_tppSeqJogo));
      if( *pSeqJ == NULL)
      {
        return SEQJ_CondRetFaltouMemoria;
      }

      (*pSeqJ)->numCartasViradas = 1;

      condRet = PIL_CriarPilhaVazia( &((*pSeqJ)->pPilha) );

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

  SEQJ_tpCondRet SEQJ_DestroiSequencia ( SEQJ_tppSeqJogo pSeqJ )
  {
    if(pSeqJ->pPilha != NULL)
    {
      PIL_DestroiPilha(pSeqJ->pPilha);
      
    }
    free(pSeqJ);

    return SEQJ_CondRetOK;
  }

  /* Fim função: SEQJ  &Destruir sequência de jogo */

/***************************************************************************
*
*  Função:  SEQJ  &Vira a primeira carta da pilha de sequência de jogo
*  ****/

   SEQJ_tpCondRet SEQJ_ViraPrimeiraCarta( SEQJ_tppSeqJogo pSeqJ )
   {
      CAR_tppCarta cartaAux;
      PIL_tpCondRet condRet;

      condRet = PIL_VerCarta(pSeqJ->pPilha, &cartaAux, 0 );

      if(condRet != PIL_CondRetOK)
      {
        return SEQJ_CondRetSequenciaVazia;
      }

      pSeqJ->numCartasViradas++;

      return SEQJ_CondRetOK;
   }
  
   /* Fim função: SEQJ  &Vira a primeira carta da pilha de sequência de jogo*/

 /***************************************************************************
 * 
 *  Função: SEQJ &Push carta na sequencia
 *****/

   SEQJ_tpCondRet SEQJ_PushCartaSequencia( SEQJ_tppSeqJogo pSeqJ, CAR_tppCarta pCarta )
   {
      PIL_PushCarta( pSeqJ->pPilha, pCarta);
      pSeqJ->numCartasViradas++;

      return SEQJ_CondRetOK;
   }

/* Fim função: SEQJ &Push carta na sequencia */

/***************************************************************************
* 
*  Função: SEQJ &Obtem pilha da sequência de jogo
*****/

   SEQJ_tpCondRet SEQJ_ObtemPilhaSeqJ( SEQJ _tppSeqJ pSeqJ, PIL_tppPilha *pPilha )
   {
      PIL_tppPilha pilhaAux;
      CAR_tppCarta cartaAux;
      int i;

      if(pSeqJ->pPilha == NULL || totalCartasNaSeq( pSeqJ ) == 0 )
      {
        return SEQJ_CondRetSequenciaVazia;
      }

      if (  pSeqJ->numCartasViradas < 13)
      {
        return SEQJ_CondRetNumCartasIncorreto;
      }
     /* fazer só para 13 cartas */

      PIL_CriarPilhaVazia( &pilhaAux );
      for( i = 0 ; i < 13 ; i++ )
      {
        PIL_PopCarta( pSeqJ->pPilha, &cartaAux );
        PIL_PushCarta( pilhaAux, cartaAux );
      }

      *pPilha = pilhaAux;

      pSeqJ->numCartasViradas -= 13 ;

    
      if( pSeqJ->numCartasViradas == 0  && totalCartasNaSeq( pSeqJ ) > 0)
      {
        SEQJ_ViraPrimeiraCarta( pSeqJ );
      }

      return SEQJ_CondRetOK;
   }

/* Fim função: SEQJ &Obtem pilha da sequência de jogo */

/***************************************************************************
* 
*  Função: SEQJ &Verifica sequência completa     
*****/

   SEQJ_tpCondRet SEQJ_VerificaSeqCompleta( SEQJ_tppSeqJogo pSeqJ )
   {
      int i ;
      int seqComecou ;
      int valor ;
      CAR_tppCarta cartaAux;
      CAR_tppCarta cartaAnterior;

      seqComecou = 0;
      valor = 0;

      for (i = 0 ; i < 13 ; i++)
      {
        PIL_VerCarta( pSeqJ1->pPilha, &cartaAux, i );
        CAR_ObterValor(cartaAux, &valor);
        if( valor != i+1 )
        {
          return SEQJ_CondRetCartasForaDaSequencia;
        }

        if( seqComecou )
        {
          if( !ehSequenciaValor(cartaAux, cartaAnterior) || !ehMesmoNaipe(cartaAux, cartaAnterior))
          {
             return SEQJ_CondRetCartasForaDaSequencia;
          }
        }
        cartaAnterior = cartaAux;
        if( !seqComecou ) seqComecou = 1;
      }

      return SEQJ_CondRetOK;
   }

/* Fim função: SEQJ &Verifica sequência completa */

/***************************************************************************
* 
*  Função: SEQJ &Move Pilha de sequência1 para sequência2
*****/
  SEQJ_tpCondRet SEQJ_MovePilhaCarta(SEQJ_tppSeqJogo pSeqJ1, SEQJ_tppSeqJogo pSeqJ2, int numCartas)
  {
    PIL_tppPilha pilhaAux;
    CAR_tppCarta cartaAux;
    CAR_tppCarta cartaAnterior;

    int numCartasSeq1 = 0;
    int seqComecou = 0;
    int i = 0;

    // 1 ver se pode mover tais cartas
    // 2 ver se podem se colocadas na seq2
    // 3 move-las

    if( numCartas > pSeqJ1->numCartasViradas)   // verifica caso de pedir mais cartas do que o numero de cartas viradas
    {
      return SEQJ_CondRetNumCartasIncorreto;
    }

   numCartasSeq1 = totalCartasNaSeq( pSeqJ1 );  //numero de cartas inicial da seq1


    for( i=0 ; i < numCartas ; i++)   // verifica se as cartas a serem tiradas estão em sequencia e sao mesmo naipe
    {
      PIL_VerCarta( pSeqJ1->pPilha, &cartaAux, i );

      if( seqComecou )
      {
        if( !ehSequenciaValor(cartaAux, cartaAnterior) || !ehMesmoNaipe(cartaAux, cartaAnterior))
        {
          return SEQJ_CondRetCartasForaDaSequencia;
        }
      }
      cartaAnterior = cartaAux;
      if( !seqComecou ) seqComecou = 1;
    }

    // ver se pode colocar na seq2
    // ultima carta testada fica em cartaAux, entao comparar cartaAux com a primeira da pseqj2
    //cartaAnterior deve ser maior do q cartaAux, nao importa o naipe

    PIL_VerCarta( pSeqJ2->pPilha, &cartaAnterior, 0 ); 

    if ( !ehSequenciaValor( cartaAnterior, cartaAux ))
    {
        return SEQJ_CondRetCartasForaDaSequencia;
    }


  //depois de testadas as condições, mover cartas

    PIL_CriarPilhaVazia( &pilhaAux );

    for( i = 0 ; i < numCartas ; i++ )
    {
      PIL_PopCarta( pSeqJ1->pPilha, &cartaAux );
      PIL_PushCarta( pilhaAux, cartaAux );
    }

    for( i = 0 ; i < numCartas ; i++)
    {
      PIL_PopCarta( pilhaAux, &cartaAux );
      PIL_PushCarta( pSeqJ2->pPilha, cartaAux );
    }

    pSeqJ1->numCartasViradas -= numCartas;
    pSeqJ2->numCartasViradas += numCartas;

    numCartasSeq1 -= numCartas;

    if( pSeqJ1->numCartasViradas == 0  && numCartasSeq1 > 0)
    {
      SEQJ_ViraPrimeiraCarta( pSeqJ1 );
    }

    PIL_DestroiPilha( pilhaAux );

    return SEQJ_CondRetOK;
  }

/* Fim função: SEQJ &Move Pilha de sequência1 para sequência2 */


  /*****  Código das funções encapsuladas no módulo  *****/

/***********************************************************************
 *
 *  $FC Função: SEQJ  -Total de cartas na sequência
 *
 *  $ED Descrição da função
 *    Dada um sequência, a função conta o total de cartas em sua pilha.
 *
 ***********************************************************************/

int totalCartasNaSeq( SEQJ_tppSeqJogo pSeqJ )
{
  CAR_tppCarta cartaAux ;
  int numCartasSeq = 0 ;

  while( PIL_VerCarta( pSeqJ->pPilha, &cartaAux, numCartasSeq ) == PIL_CondRetOK )
  {
    numCartasSeq++;
  }

  return numCartasSeq ;
}

/***********************************************************************
 *
 *  $FC Função: SEQJ  Verifica cartas sequência relação ao valor
 *
 *  $ED Descrição da função
 *    Dadas duas cartas, a função verifica se a primeira é sequência da segunda.
 *    Ex: carta1 = 6 de ouro e carta2 = 5 de ouro é sequencia
 *    Ex: carta1 = 6 de ouro e carta2 = 5 de copas é sequencia
 *    Ex: carta1 = 4 de ouro e carta2 = 6 de ouro não é sequencia
 *
 ***********************************************************************/

int ehSequenciaValor( CAR_tppCarta carta1, CAR_tppCarta carta2 )
{
  int valor1 = 0 ; 
  int valor2 = 0 ;

   CAR_ObterValor(carta1, &valor1);
   CAR_ObterValor(carta2, &valor2);

   if( valor1 -1  == valor2 ) 
   {
      return 1;   // carta1 é sequencia e maior do que carta2
   }
   return 0;
}

/***********************************************************************
 *
 *  $FC Função: SEQJ  Verifica cartas possuem mesmo naipe
 *
 *  $ED Descrição da função
 *    Dadas duas cartas, a função verifica ambas possuem mesmo naipe.
 *
 ***********************************************************************/

int ehMesmoNaipe( CAR_tppCarta carta1, CAR_tppCarta carta2 )
{
   char naipe1 = '?' ;
   char naipe2 = '!' ; 

   CAR_ObterNaipe(carta1, &naipe1);
   CAR_ObterNaipe(carta2, &naipe2);

   if( naipe1 == naipe2 ) 
   {
      return 1;
   }
   return 0;
}

/*************** Fim do módulo de implementação: SEQJ Sequência de jogo *****************/
