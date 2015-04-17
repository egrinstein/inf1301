/***************************************************************************
*  $MCI Módulo de implementação: MON  Monte de cartas
*
*  Arquivo gerado:              MONTE.c
*  Letras identificadoras:      MON
*
*  Nome da base de software:    Arcabouço para a automação de testes de programas redigidos em C
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\LISTA.BSW
*
*  Projeto: INF 1301 Paciência Spider
*  Autores: 
*
*
***************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "MONTE.h"
#include "PILHADECARTAS.h"
#include "CARTA.h"

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
*  Função: MON  &Criar monte
*  ****/

   MON_tppMonte MON_CriarMonte ( MON_tppMonte * pMonte , PIL_tppPilha pPilha)
   {
      *pMonte = PIL_CriarPilhaVazia( pPilha );
       if ( pMonte == NULL)
       {
         return NULL;
       }
       return pMonte;
   }

    /* Fim função: MON  &Criar monte */

/***************************************************************************
*
*  Função: MON  &Destruir monte
*  ****/
   MON_tpCondRet MON_DestruirMonte ( MON_tppMonte pMonte )
   {
      PIL_DestroiPilha( pMonte );
   }

  /* Fim função: MON  &Destruir monte */

/***************************************************************************
*
*  Função: MON  &Pop carta do monte
*  ****/

   MON_tpCondRet MON_PopCartaMonte ( MON_tppMonte pMonte, CAR_tppCarta * pCarta ) 
   {
      PIL_PopCarta( pMonte, pCarta );
   }
  
   /* Fim função: MON  &Pop carta do monte */

/***************************************************************************
*
*  Função: LIS  &Inserir elemento antes
*  ****/

/********** Fim do módulo de implementação: MON Monte de cartas **********/
