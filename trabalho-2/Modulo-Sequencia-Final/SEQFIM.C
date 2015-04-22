/***************************************************************************
 *
 *  $MCD Módulo de Implementação: SEQFIM  Sequência final
 *
 *  Arquivo gerado:              SEQFIM.C
 *  Letras identificadoras:      SEQFIM
 *
 *  Autores: Eric Grinstein,
 *           Jordana Mecler,
 *	    Leonardo Wajnsztok
 *
 ***************************************************************************/

#include <malloc.h>

#define SEQUENCIA_FINAL_OWN
#include "SEQFIM.H"
#undef SEQUENCIA_FINAL_OWN


/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
 *
 *  Função: SEQFIM Criar Sequencia final
 *****/

SEQFIM_tpCondRet SEQFIM_CriarSeqFim ( SEQFIM_tppSeqFim * pSeqFim , PIL_tppPilha pPilha )
{
    
    PIL_tppPilha pPilhaAux ;
    PIL_tpCondRet PilRet ;
    
    *pSeqFim = NULL ;
    
    PilRet = PIL_CriarPilhaVazia( &pPilhaAux );
    
    if ( PilRet == PIL_CondRetFaltouMemoria )
    {
        return SEQFIM_CondRetFaltouMemoria ;
    }
    
    *pSeqFim = ( SEQFIM_tppSeqFim ) pPilhaAux ;
    
    return SEQFIM_CondRetOK ;
    
} /* Fim função: SEQFIM  Criar Sequencia final */

/***************************************************************************
 *
 *  Função: SEQFIM Destruir Sequencia final
 *****/

SEQFIM_tpCondRet SEQFIM_DestroiSeqFim ( SEQFIM_tppSeqFim pSeqFim )
{
    PIL_DestruirPilha( pSeqFim->pPilCartas ) ;
    
    free( pSeqFim ) ;
    
    return SEQFIM_CondRetOK ;
    
}/* Fim função: SEQFIM Destruir Sequencia final */


/***************************************************************************
 *
 *  Função: SEQFIM Preencher Sequencia final
 *****/

SEQFIM_tpCondRet SEQFIM_PreencheSeqFim ( SEQFIM_tppSeqFim pSeqFim , PIL_tppPilha pPilha )
{
    
    pSeqFim = ( SEQFIM_tppSeqFim ) pPilha ;
    
    return SEQFIM_CondRetOK ;
    
}/* Fim função: SEQFIM Preencher Sequencia final */

/********** Fim do módulo de implementação: BAR  Baralho de cartas  **********/
