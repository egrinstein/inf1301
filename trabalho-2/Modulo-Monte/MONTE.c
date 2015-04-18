/***************************************************************************
 *  $MCI Módulo de implementação: MON Monte de cartas
 *
 *  Arquivo gerado:              MONTE.c
 *  Letras identificadoras:      MON
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
 *     1.0       EG,JM,LW        17/abr/2015       Início do desenvolvimento
 *
 ***************************************************************************/

#include <stdio.h>
#include <malloc.h>

#include "PILHA_DE_CARTAS.h"
#include "CARTA.h"

#define MONTE_OWN
#include "MONTE.h"
#undef MONTE_OWN


/***********************************************************************
*
*  $TC Tipo de dados: MON Monte Pilha de Carta
*
*
***********************************************************************/

   typedef PIL_tppPilha MON_tppMonte ;

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: MON  &Criar monte a partir de pilha
*  ****/

   MON_tpCondRet MON_CriarMonte ( MON_tppMonte * pMonte , PIL_tppPilha pPilha)
   {
      PIL_tpCondRet condRet;
      PIL_tppPilha pPilhaAux;
      CAR_tppCarta pCartaAux;

      *pMonte = NULL;

      condRet = PIL_CriarPilhaVazia( &pPilhaAux );
       
      if ( condRet == PIL_CondRetFaltouMemoria )
      {
        return MON_CondRetFaltouMemoria ; 
      }         

      while( PIL_PopCarta( pPilha, &pCartaAux )  == PIL_CondRetOK )
      {
        PIL_PushCarta( pPilhaAux , pCartaAux );
      }
      
      * pMonte = ( MON_tppMonte ) pPilhaAux ;

      return MON_CondRetOK ;
   }

    /* Fim função: MON  &Criar monte */

/***************************************************************************
*
*  Função: MON  &Destruir monte
*  ****/
   MON_tpCondRet MON_DestruirMonte ( MON_tppMonte pMonte )
   {

      PIL_tppPilha pPilha = ( PIL_tppPilha ) pMonte ;

      PIL_DestroiPilha( pPilha );

      return MON_CondRetOK ; 
   }

  /* Fim função: MON  &Destruir monte */

/***************************************************************************
*
*  Função: MON  &Pop carta do monte
*  ****/

   MON_tpCondRet MON_PopCartaMonte ( MON_tppMonte pMonte, CAR_tppCarta * pCarta ) 
   {
      PIL_tppPilha pPilha = ( PIL_tppPilha ) pMonte ;

      PIL_PopCarta( pPilha, pCarta );

      return MON_CondRetOK ; 
   }
  
   /* Fim função: MON  &Pop carta do monte */

/***************************************************************************
*
*  Função: LIS  &Inserir elemento antes
*  ****/

/********** Fim do módulo de implementação: MON Monte de cartas **********/
