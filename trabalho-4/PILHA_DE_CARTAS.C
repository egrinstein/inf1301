/***************************************************************************
 *
 *  $MCD Módulo de Implementação: PIL  Pilha de Cartas
 *
 *  Arquivo gerado:          	PIL.C
 *  Letras identificadoras:  	PIL
 *
 *  Autores: Eric Grinstein,
 *       	Jordana Mecler,
 *    	Leonardo Wajnsztok
 *
 ***************************************************************************/

#include "lista.h"

#include <stdlib.h>
#include <stdio.h>

#define PILHA_DE_CARTAS_OWN
#include "PILHA_DE_CARTAS.H"
#undef PILHA_DE_CARTAS_OWN

#ifdef _DEBUG
    #include "Generico.h"
    #include "Conta.h"
    #include "CESPDIN.H"
#endif

/* Definições encapsuladas no módulo */

/* Tipo referência para uma pilha de cartas */

typedef struct PIL_tagPilha {

    #ifdef _DEBUG
   	 int tipo;
   	 int qtdNos;
    #endif

	LIS_tppLista pListaCartas ;
	/*Ponteiro para lista que guardará as cartas*/
} PIL_tpPilha ;

/***** Protótipos das funções encapsuladas no módulo *****/

void ExcluirCarta( void * pValor ) ;

/*****  Código das funções exportadas pelo módulo  *****/

#ifdef _DEBUG

PIL_tpCondRet PIL_Deturpa ( PIL_tppPilha pPilha , int acao )
{
	if( acao == 1 )
	{
		LIS_LiberaElemCorr( pPilha->pListaCartas ) ;
	}
	else if( acao == 2 )
	{
		LIS_AlteraSucessor( pPilha->pListaCartas ) ;
	}
	else if( acao == 3 )
	{
		LIS_AlteraPredecessor( pPilha->pListaCartas ) ;
	}
	else if( acao == 4 )
	{
		LIS_AtribuiLixoSucessor( pPilha->pListaCartas ) ;
	}
	else if( acao == 5 )
	{
		LIS_AtribuiLixoPredecessor( pPilha->pListaCartas ) ;
	}
	else if( acao == 6 )
	{
		LIS_AtribuiNULLCarta( pPilha->pListaCartas ) ;
	}
	else if( acao == 7 )
	{
		LIS_AlteraTipoCarta( pPilha->pListaCartas ) ;
	}
	else if( acao == 8 )
	{
		LIS_DestacaCarta( pPilha->pListaCartas ) ;
	}
	else if( acao == 9 )
	{
		LIS_AtribuiNULLCorrente( pPilha->pListaCartas ) ;
	}
	else if( acao == 10 )
	{
		LIS_AtribuiNULLOrigem( pPilha->pListaCartas ) ;
	}
	return PIL_CondRetOK ;
}

PIL_tpCondRet PIL_Verifica ( PIL_tppPilha pPilha , int *numErros )
{
	LIS_tpCondRet retLis, retLis2;
    CAR_tppCarta pCarta;
	*numErros = 0;

	retLis = LIS_IrInicioLista(pPilha->pListaCartas);
	(*numErros) = 0;

	if( pPilha->qtdNos > 0)
	{
		//pilha->pListaCartas != NULL
		if( retLis == 5)
		{
			CNT_CONTAR("Erro: pilha nula quando qtdNos > 0");
			(*numErros) ++;
		}
		else if (retLis == 1)
		{
			CNT_CONTAR("Erro: pilha sem nós quando qtdNos > 0");
			(*numErros) ++;
		}
		else
		{
			CNT_CONTAR("OK: pilha correta quando qtdNos > 0");
		}
	}
	else if( pPilha->qtdNos == 0)
	{
		// pilha->pListaCartas == NULL 
		//ou 
		//pListaCartas->Corr == NULL e pListaCartas->pOrigemLista == NULL e pListaCartas->pFimLista == NULL

		retLis2 = LIS_ObterValor( pPilha->pListaCartas, &pCarta);
		if (retLis == 5 )
		{
			CNT_CONTAR("OK: pilha não existe");	
		}
		else if ( retLis == 1)
		{
			CNT_CONTAR("OK: pilha existe mas nao tem nós");
		}
		else if ( retLis == 0 && retLis2 == 0)
		{
			CNT_CONTAR("Erro: pilha tem nós quando nao deveria");
			(*numErros) ++;
		}
	}
	
	// pilha->tipo == x e celula->tipo == x
	retLis = LIS_ObterValor( pPilha->pListaCartas, &pCarta);
	if (retLis == 0)
	{
		if (pPilha->tipo == CAR_ObterTipo(pCarta))
		{
			CNT_CONTAR("OK: tipo da pilha é o mesmo dos seus nós");
		}
		else
		{
			CNT_CONTAR("Erro: tipo da pilha é diferente dos seus nós");
			(*numErros) ++;
		}
	}

}

#endif

/***************************************************************************
 *
 *  Função: PIL Criar Pilha Vazia
 *****/

PIL_tpCondRet PIL_CriarPilhaVazia( PIL_tppPilha * pPilha )
{
	LIS_tpCondRet condRet ;
#ifdef _DEBUG
	CNT_CONTAR( "PIL_CriarPilhaVazia" ) ;
#endif

	*pPilha = NULL ;
    
	*pPilha = ( PIL_tpPilha * ) malloc( sizeof( PIL_tpPilha ) ) ;
	if( *pPilha == NULL )
	{
    	return PIL_CondRetFaltouMemoria ;
	} /* if */

    
	(*pPilha)->pListaCartas = NULL;
	#ifdef _DEBUG

		(*pPilha)->tipo = 'c';
    
    #endif

	condRet = LIS_CriarLista( &((*pPilha)->pListaCartas) , ExcluirCarta ) ;
    
	if ( condRet == LIS_CondRetFaltouMemoria )
	{
    	return PIL_CondRetFaltouMemoria ;
	}

    #ifdef _DEBUG
		CNT_CONTAR("PIL_CriarPilhaVazia-pr0") ;
		CED_MarcarEspacoAtivo(pPilha) ;
    #endif

	return PIL_CondRetOK ;
    
} /* Fim função: PIL  &Criar Pilha Vazia */

/***************************************************************************
 *
 *  Função: PIL Destruir Pilha de Cartas
 *****/

PIL_tpCondRet PIL_DestruirPilha( PIL_tppPilha pPilha )
{
    
   	LIS_tpCondRet Ret ;

#ifdef _DEBUG
	CNT_CONTAR("PIL_DestruirPilha");
#endif
    
	if ( pPilha->pListaCartas == NULL )
	{
#ifdef _DEBUG
		CNT_CONTAR( "PIL_DestruirPilha-if0" ) ;
#endif
    	return PIL_CondRetOK ;
	}


	Ret = LIS_DestruirLista( pPilha->pListaCartas ) ;
    
	if( Ret != LIS_CondRetOK )
	{
#ifdef _DEBUG
	   	CNT_CONTAR( "PIL_DestruirPilha-if1" ) ;
#endif
    	return PIL_CondRetPilhaVazia ;
   	 
	} /* if */
    
	free(pPilha) ;
    
	#ifdef _DEBUG
		CNT_CONTAR( "PIL_DestruirPilha-pr0" ) ;
		CED_MarcarEspacoNaoAtivo(pPilha);
    #endif

	return PIL_CondRetOK ;
    
}/* Fim função: PIL Destruir Pilha de Cartas */


/***************************************************************************
 *
 *  Função: PIL Push Carta
 *****/

PIL_tpCondRet PIL_PushCarta( PIL_tppPilha pPilha , CAR_tppCarta pCarta )
{
   	LIS_tpCondRet Ret ;

#ifdef _DEBUG
	CNT_CONTAR( "PIL_PushCarta" ) ;
#endif

    
	LIS_IrFinalLista( pPilha->pListaCartas ) ;
    
	Ret = LIS_InserirElementoApos( pPilha->pListaCartas , pCarta ) ;
	if( Ret != LIS_CondRetOK )
	{
    	return PIL_CondRetFaltouMemoria ;
	} /* if */
    
#ifdef _DEBUG
    CNT_CONTAR( "PIL_PushCarta-pr0" ) ;
#endif

	return PIL_CondRetOK ;


    
}/* Fim função: PIL Push Carta */

/***************************************************************************
 *
 *  Função: PIL VerCarta
 *****/

PIL_tpCondRet PIL_VerCarta( PIL_tppPilha pPilha , CAR_tppCarta * pCarta , int posicao )
{
	LIS_tpCondRet Ret ;

#ifdef _DEBUG
	CNT_CONTAR( "PIL_VerCarta" ) ;
#endif

    
	if ( posicao < 0 )
	{
#ifdef _DEBUG
		CNT_CONTAR( "PIL_VerCarta-if0" ) ;
#endif

    	return PIL_CondRetParamIncorreto ;
	}
    
	LIS_IrFinalLista( pPilha->pListaCartas ) ;
    
	Ret = LIS_AvancarElementoCorrente( pPilha->pListaCartas , - posicao ) ;
    
	if ( Ret == LIS_CondRetFimLista )
	{
#ifdef _DEBUG
		CNT_CONTAR( "PIL_VerCarta-if1" ) ;
#endif
    	return PIL_CondRetFimPilha ;
	}
    
	if ( Ret == LIS_CondRetListaVazia )
	{
#ifdef _DEBUG
		CNT_CONTAR( "PIL_VerCarta-if2" ) ;
#endif
    	return PIL_CondRetPilhaVazia ;
	}
    
	LIS_ObterValor( pPilha->pListaCartas , (void**)pCarta ) ;
#ifdef _DEBUG
	CNT_CONTAR( "PIL_VerCarta-pr0" ) ;
#endif

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
    
	PIL_tpCondRet condRet = PIL_VerCarta( pPilha , pCarta , 0 ) ;

#ifdef _DEBUG
	CNT_CONTAR( "PIL_PopCarta" ) ;
#endif
	LIS_IrFinalLista( pPilha->pListaCartas ) ;
    
	if ( condRet != PIL_CondRetOK )
	{
#ifdef _DEBUG
		CNT_CONTAR( "PIL_PopCarta-if0" ) ;
#endif
    	return condRet ;
	}
    
    
	CAR_ObterNaipe( *pCarta, &naipe );
	CAR_ObterValor( *pCarta, &valor );
    
	LIS_ExcluirElemento( pPilha->pListaCartas );
    
	/*LIS_ExcluirElemento irá destruir a carta junto do nó.
 	É necessário que ela seja criada novamente*/
    
	CAR_CriarCarta( pCarta ) ;
	CAR_PreencheCarta( *pCarta , naipe, valor ) ;
#ifdef _DEBUG
	CNT_CONTAR( "PIL_PopCarta-pr0" ) ;
#endif

	return PIL_CondRetOK ;
    
}/* Fim função: PIL Pop Carta */

/*****  Código das funções encapsuladas no módulo  *****/

#ifdef _DEBUG
void ExcluirCarta( void * pValor , void * espaco )
#else
void ExcluirCarta( void * pValor )
#endif
{
	CAR_ExcluirCarta( (CAR_tppCarta) pValor ) ;

#ifdef _DEBUG
	CED_MarcarEspacoNaoAtivo(espaco);
#endif
}


/********** Fim do módulo de implementação: PIL  Pilha de cartas  **********/




