/***************************************************************************
 *
 *  $MCD MÃ³dulo de ImplementaÃ§Ã£o: PIL  Pilha de Cartas
 *
 *  Arquivo gerado:              PIL.C
 *  Letras identificadoras:      PIL
 *
 *  Autores: Eric Grinstein,
 *           Jordana Mecler,
 *	    Leonardo Wajnsztok
 *
 ***************************************************************************/

#include "LISTA.h"

#include <stdlib.h>
#include <stdio.h>

#define PILHA_DE_CARTAS_OWN
#include "PILHA_DE_CARTAS.h"
#undef PILHA_DE_CARTAS_OWN

/* DefiniÃ§Ãµes encapsuladas no mÃ³dulo */

/* Tipo referÃªncia para uma pilha de cartas */

typedef struct PIL_tagPilha {
    LIS_tppLista pListaCartas ;
    /*Ponteiro para lista que guardarÃ¡ as cartas*/
} PIL_tpPilha ;

/***** ProtÃ³tipos das funÃ§Ãµes encapuladas no mÃ³dulo *****/

void ExcluirCarta( void * pValor ) ;

/*****  CÃ³digo das funÃ§Ãµes exportadas pelo mÃ³dulo  *****/

/***************************************************************************
 *
 *  FunÃ§Ã£o: PIL Criar Pilha Vazia
 *****/

PIL_tpCondRet PIL_CriarPilhaVazia( PIL_tppPilha * pPilha )
{
    LIS_tpCondRet condRet ;
    
    *pPilha = NULL ;
    
    *pPilha = ( PIL_tpPilha * ) malloc( sizeof( PIL_tpPilha ) ) ;
    if( *pPilha == NULL )
    {
        return PIL_CondRetFaltouMemoria ;
    } /* if */
    
    (*pPilha)->pListaCartas = NULL;
    
    condRet = LIS_CriarLista( &((*pPilha)->pListaCartas) , ExcluirCarta ) ;
    
    if ( condRet == LIS_CondRetFaltouMemoria )
    {
        return PIL_CondRetFaltouMemoria ;
    }
    
    return PIL_CondRetOK ;
    
} /* Fim funÃ§Ã£o: PIL  &Criar Pilha Vazia */

/***************************************************************************
 *
 *  FunÃ§Ã£o: PIL Destruir Pilha de Cartas
 *****/

PIL_tpCondRet PIL_DestruirPilha( PIL_tppPilha pPilha )
{
    
	   LIS_tpCondRet Ret ;
    
    
    if ( pPilha->pListaCartas == NULL )
    {
        free( pPilha ) ;
        return PIL_CondRetOK ;
    }
    
    Ret = LIS_DestruirLista( pPilha->pListaCartas ) ;
    
    if( Ret != LIS_CondRetOK )
    {
        return PIL_CondRetPilhaVazia ;
        
    } /* if */
    
    free(pPilha) ;
    
    return PIL_CondRetOK ;
    
}/* Fim funÃ§Ã£o: PIL Destruir Pilha de Cartas */


/***************************************************************************
 *
 *  FunÃ§Ã£o: PIL Push Carta
 *****/

PIL_tpCondRet PIL_PushCarta( PIL_tppPilha pPilha , CAR_tppCarta pCarta )
{
	   LIS_tpCondRet Ret ;
    
    LIS_IrFinalLista( pPilha->pListaCartas ) ;
    
    Ret = LIS_InserirElementoApos( pPilha->pListaCartas , pCarta ) ;
    if( Ret != LIS_CondRetOK )
    {
        return PIL_CondRetFaltouMemoria ;
    } /* if */
    
    return PIL_CondRetOK ;
    
}/* Fim funÃ§Ã£o: PIL Push Carta */

/***************************************************************************
 *
 *  FunÃ§Ã£o: PIL VerCarta
 *****/

PIL_tpCondRet PIL_VerCarta( PIL_tppPilha pPilha , CAR_tppCarta * pCarta , int posicao )
{
    LIS_tpCondRet Ret ;
    
    if ( posicao < 0 )
    {
        return PIL_CondRetParamIncorreto ;
    }
    
    LIS_IrFinalLista( pPilha->pListaCartas ) ;
    
    Ret = LIS_AvancarElementoCorrente( pPilha->pListaCartas , - posicao ) ;
    
    if ( Ret == LIS_CondRetFimLista )
    {
        return PIL_CondRetFimPilha ;
    }
    
    if ( Ret == LIS_CondRetListaVazia )
    {
        return PIL_CondRetPilhaVazia ;
    }
    
    LIS_ObterValor( pPilha->pListaCartas , (void**)pCarta ) ;
    
    return PIL_CondRetOK ;
    
}/* Fim funÃ§Ã£o: PIL VerCarta */

/***************************************************************************
 *
 *  FunÃ§Ã£o: PIL PopCarta
 *****/

PIL_tpCondRet PIL_PopCarta( PIL_tppPilha pPilha , CAR_tppCarta * pCarta )
{
    int valor ;
    char naipe ;
    
    PIL_tpCondRet condRet = PIL_VerCarta( pPilha , pCarta , 0 ) ;
    
    LIS_IrFinalLista( pPilha->pListaCartas ) ;
    
    if ( condRet != PIL_CondRetOK )
    {
        return condRet ;
    }
    
    
    CAR_ObterNaipe( *pCarta, &naipe );
    CAR_ObterValor( *pCarta, &valor );
    
    LIS_ExcluirElemento( pPilha->pListaCartas );
    
    /*LIS_ExcluirElemento irÃ¡ destruir a carta junto do nÃ³.
     Ã‰ necessÃ¡rio que ela seja criada novamente*/
    
    CAR_CriarCarta( pCarta ) ;
    CAR_PreencheCarta( *pCarta , naipe, valor ) ;
    
    return PIL_CondRetOK ;
    
}/* Fim funÃ§Ã£o: PIL Pop Carta */

/*****  CÃ³digo das funÃ§Ãµes encapsuladas no mÃ³dulo  *****/

void ExcluirCarta( void * pValor ) 
{
    CAR_ExcluirCarta( (CAR_tppCarta) pValor ) ;
}


/********** Fim do mÃ³dulo de implementaÃ§Ã£o: PIL  Pilha de cartas  **********/
