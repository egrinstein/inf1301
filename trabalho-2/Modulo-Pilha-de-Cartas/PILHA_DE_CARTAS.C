
/***************************************************************************
*
*  $MCD Módulo de Implementação: PIL  Pilha de Cartas
*
*  Arquivo gerado:              PIL.C
*  Letras identificadoras:      PIL
*
*  Autores: Eric Grinstein,
*           Jordana Mecler,
*	    Leonardo Wajnsztok
*  
***************************************************************************/
 
#include "lista.h"
#include "CARTA.H"

#define PILHA_DE_CARTAS_OWN
#include "PILHA_DE_CARTAS.H"
#undef PILHA_DE_CARTAS_OWN

#define NULL 0

/* Tipo referência para uma pilha de cartas */

typedef LIS_tppLista PIL_tagPilha ;

/***** Protótipos das funções encapuladas no módulo *****/

void ExcluirCarta( void * pValor ) ;

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: PIL Criar Pilha Vazia 
*****/

   PIL_tpCondRet PIL_CriarPilhaVazia( PIL_tppPilha * pPilha )
   {
      LIS_tpCondRet condRet ;
      LIS_tppLista pLista ;

      *pPilha = NULL ;
	
      condRet = LIS_CriarLista( &pLista , ExcluirCarta ) ; 

      if ( condRet == LIS_CondRetFaltouMemoria )
      {
	   return PIL_CondRetFaltouMemoria ; 
      }       	

      * pPilha = ( PIL_tppPilha ) pLista ; 

      return PIL_CondRetOK ;

   } /* Fim função: PIL  &Criar Pilha Vazia */

/***************************************************************************
*
*  Função: PIL Destruir Pilha de Cartas 
*****/

   PIL_tpCondRet PIL_DestruirPilha( PIL_tppPilha pPilha )
   {
	LIS_tppLista pLista = ( LIS_tppLista ) pPilha ;

	if ( pLista == NULL ) return PIL_CondRetOK ;
 
	LIS_DestruirLista( pLista ) ;

	return PIL_CondRetOK ; 	

   }/* Fim função: PIL Destruir Pilha de Cartas */


/***************************************************************************
*
*  Função: PIL Push Carta 
*****/

   PIL_tpCondRet PIL_PushCarta( PIL_tppPilha pPilha , CAR_tppCarta pCarta )
   {
	LIS_tppLista pLista = ( LIS_tppLista ) pPilha ;

	LIS_IrFinalLista( pLista ) ;

	LIS_InserirElementoApos( pLista , pCarta ) ; 

	return PIL_CondRetOK ; 	

   }/* Fim função: PIL Push Carta */

/***************************************************************************
*
*  Função: PIL VerCarta 
*****/

   PIL_tpCondRet PIL_VerCarta( PIL_tppPilha pPilha , CAR_tppCarta * pCarta , int posicao )
   {
	LIS_tpCondRet Ret ;
	LIS_tppLista pLista = ( LIS_tppLista ) pPilha ;

	if ( pLista == NULL )
	{
		return PIL_CondRetPilhaVazia ;
	}
	if ( posicao < 0 )
	{
		return PIL_CondRetParamIncorreto ;	
	}

	LIS_IrFinalLista( pLista ) ; 

	Ret = LIS_AvancarElementoCorrente( pLista , - posicao ) ;

	if ( Ret = LIS_CondRetFimLista )
	{
		return PIL_CondRetFimPilha ;
	}
	
        * pCarta = ( CAR_tppCarta ) LIS_ObterValor( pLista ) ;

	return PIL_CondRetOK ; 	

   }/* Fim função: PIL VerCarta */

/***************************************************************************
*
*  Função: PIL PopCarta 
*****/

   PIL_tpCondRet PIL_PopCarta( PIL_tppPilha pPilha , CAR_tppCarta * pCarta )
   {
	    int valor ;
		char naipe ;
		LIS_tppLista pLista = ( LIS_tppLista ) pPilha ;
		PIL_tpCondRet condRet = PIL_VerCarta( pPilha , pCarta , 0 ) ;
        
		if ( condRet != PIL_CondRetOK )
		{
			return condRet ;
		}

		CAR_ObterNaipe( *pCarta, &naipe ); //será que tem que tratar condret daqui?
		CAR_ObterValor( *pCarta, &valor );

		LIS_ExcluirElemento( pLista ); 

		/*LIS_ExcluirElemento irá destruir a carta junto do nó.
			 É necessário que ela seja criada novamente*/
		CAR_CriarCarta( pCarta ) ;
		CAR_PreencheCarta( *pCarta , naipe, valor ) ;

		return PIL_CondRetOK ; 	

   }/* Fim função: PIL Pop Carta */
/*****  Código das funções encapsuladas no módulo  *****/

void ExcluirCarta( void * pValor ) 
{
	CAR_ExcluirCarta( (CAR_tppCarta) pValor ) ;
}


/********** Fim do módulo de implementação: PIL  Pilha de cartas  **********/


