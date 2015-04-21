
/***************************************************************************
*
*  $MCD Módulo de Implementação: BAR  Baralho de Cartas
*
*  Arquivo gerado:              BAR.C
*  Letras identificadoras:      BAR
*
*  Autores: Eric Grinstein,
*           Jordana Mecler,
*	    Leonardo Wajnsztok
*  
***************************************************************************/
 
#include "PILHA_DE_CARTAS.H"
#include "CARTA.H"
#include <time.h>
#include <malloc.h>

#define BARALHO_DE_CARTAS_OWN
#include "BARALHO.H"
#undef BARALHO_DE_CARTAS_OWN


#define TAM_BARALHO 104
#define VALORES_POSSIVEIS 13
	/* A=1, 2=2 ... K=13 */
#define PILHAS_AUX_EMBARALHAMENTO 10

/***********************************************************************
*
*  $TC Tipo de dados: LIS Descritor da cabeça de baralho
*
*
***********************************************************************/

  typedef struct BAR_tagBaralho {

         char numNaipes ;
               /* Número de naipes do baralho */

         BAR_tppBaralho pPilCartas ;
			/* Ponteiro para pilha com todas as cartas do baralho */

   } BAR_tpBaralho ;


/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: BAR Criar Baralho
*****/

   BAR_tpCondRet BAR_CriarBaralho( BAR_tppBaralho * pBaralho  )
   {
      
 
      *pBaralho = NULL ;
	
      *pBaralho = ( BAR_tpBaralho * ) malloc( sizeof( BAR_tpBaralho ) ) ;
      if( *pBaralho == NULL )
      {
          return BAR_CondRetFaltouMemoria ;
      } /* if */

      ( * pBaralho )->numNaipes = 0 ;
      ( * pBaralho )->pPilCartas = NULL ;
      
      return BAR_CondRetOK ;

   } /* Fim função: BAR  &Criar Baralho Vazia */

/***************************************************************************
*
*  Função: BAR Destruir Baralho de Cartas 
*****/

   BAR_tpCondRet BAR_DestruirBaralho( BAR_tppBaralho pBaralho )
   {
	PIL_DestruirPilha( pBaralho->pPilCartas ) ;

	free( pBaralho ) ;

	return BAR_CondRetOK ; 	

   }/* Fim função: BAR Destruir Baralho de Cartas */


/***************************************************************************
*
*  Função: BAR Preencher Baralho de Cartas 
*****/

   BAR_tpCondRet BAR_PreencherBaralho( BAR_tppBaralho pBaralho , int numNaipes )
   {	
	PIL_tpCondRet PilRet ;
	CAR_tpCondRet CarRet ;

	CAR_tppCarta cartaCriada ;	
	
	char auxNaipes,
		 naipeDaVez;
	int valorAux;
	int cartasFaltando = TAM_BARALHO ;

	if ( numNaipes > 4 || numNaipes < 1 )
	{
		return BAR_CondRetParamIncorreto ;
	}

	PilRet = PIL_CriarPilhaVazia( &( pBaralho->pPilCartas ) ) ;

	if ( PilRet == PIL_CondRetFaltouMemoria )
	{
		return BAR_CondRetFaltouMemoria ;
	}

	auxNaipes = 0;
	while ( cartasFaltando )
	{
		naipeDaVez = ( auxNaipes % numNaipes ) + 1
				/* garante que 1 <= naipeDaVez <= numNaipes */

		for (auxValor=1 ; auxValor <= VALORES_POSSIVEIS ; auxValor++ )
		{
			
			CarRet = CAR_CriarCarta( &cartaCriada ) ;
			if ( CarRet == CAR_CondRetFaltouMemoria )
			{
				return BAR_CondRetFaltouMemoria ;
			}

			CAR_PreencheCarta( cartaCriada , naipeDaVez , valor ) ;
			cartasFaltando-- ;
		}
		auxNaipes++ ;
	}

	return BAR_CondRetOK ;

	
   }/* Fim função: BAR Preencher Baralho de Cartas */

/***************************************************************************
*
*  Função: BAR Embaralhar Baralho de Cartas  
*****/

   BAR_tpCondRet BAR_Embaralhar( BAR_tppBaralho pBaralho )
   {
	PIL_tppPilha pilhaAux[PILHAS_AUX_EMBARALHAMENTO] ;
	PIL_tpCondRet ret ;
	int contPilha;

	CAR_tppCarta cartaAux ;

	int numPilhaAleat ;	 

	if ( pBaralho->pPilCartas == NULL )
	{
	     return BAR_CondRetBaralhoVazio ; 
	}
	

	/* Inicialização das pilhas auxiliares */
	for (contPilha = 0 ; contPilha < PILHAS_AUX_EMBARALHAMENTO ; contPilha++ )
	{
		Ret = PIL_CriarPilha( &pilhaAux[contPilha] ) ;
		if ( Ret == PIL_CondRetFaltouMemoria )
		{
			return BAR_CondRetFaltouMemoria ;
		}
	}	
	/* Inicialização das pilhas auxiliares */


	/* Distribuição dos baralhos nas pilhas auxiliares */

	srand( time(NULL) );
		/* usa o tempo atual como 
		   semente para a randomização */

	while ( PIL_PopCarta( pBaralho->pPilCartas , &cartaAux )
			!= PIL_CondRetPilhaVazia )
	{
		numPilhaAleat = rand() % PILHAS_AUX_EMBARALHAMENTO ;
		PIL_PushCarta( pilhaAux[ numPilhaAleat ] , cartaAux ) ;
	}

	/* Distribuição dos baralhos nas pilhas auxiliares */

	
	/* Reinserção das cartas no baralho */
	for ( contPilha = 0 ; contPilha < PILHAS_AUX_EMBARALHAMENTO ;
								 contPilha++ )	
	{
		while ( PIL_PopCarta( pilhaAux[ numPilhaAleat ] , &cartaAux )
			       != PIL_CondRetPilhaVazia )
		{
			PIL_PushCarta( pBaralho->pPilCartas , cartaAux ) ;
		}
		PIL_DestruirPilha( pilhaAux[ numPilhaAleat ] ) ;
	}

	/* Reinserção das cartas no baralho */

	return BAR_CondRetOk ;

   }/* Fim função: BAR Embaralhar Baralho de Cartas */

/***************************************************************************
*
*  Função: BAR PopCarta 
*****/

   BAR_tpCondRet BAR_PopCarta( BAR_tppBaralho pBaralho , CAR_tppCarta * pCarta )
   {
	    if ( pBaralho->pPilCartas == NULL )
	    {
		return BAR_CondRetBaralhoVazio ; 
	    }

	    PIL_PopCarta( pBaralho->pPilCartas , pCarta ) ;

	    return BAR_CondRetOK ;

   }/* Fim função: BAR Pop Carta */

/********** Fim do módulo de implementação: BAR  Baralho de cartas  **********/


