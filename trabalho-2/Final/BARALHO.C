
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

#include <time.h>
#include <stdlib.h>

#define BARALHO_DE_CARTAS_OWN
#include "BARALHO.H"
#undef BARALHO_DE_CARTAS_OWN


#define TAM_BARALHO 104
#define VALORES_POSSIVEIS 13
	/* A=1, 2=2 ... K=13 */
#define PILHAS_AUX_EMBARALHAMENTO 10

/***********************************************************************
*
*  $TC Tipo de dados: LIS Descritor da cabeÃ§a de baralho
*
*
***********************************************************************/

  typedef struct BAR_tagBaralho {

         int numNaipes ;
               /* NÃºmero de naipes do baralho */

         PIL_tppPilha pPilCartas ;
			/* Ponteiro para pilha com todas as cartas do baralho */

   } BAR_tpBaralho ;


/*****  CÃ³digo das funÃ§Ãµes exportadas pelo mÃ³dulo  *****/

/***************************************************************************
*
*  FunÃ§Ã£o: BAR Criar Baralho
*****/

   BAR_tpCondRet BAR_CriarBaralho( BAR_tppBaralho * pBaralho )
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

   } /* Fim funÃ§Ã£o: BAR  &Criar Baralho Vazia */

/***************************************************************************
*
*  FunÃ§Ã£o: BAR Destruir Baralho de Cartas 
*****/

   BAR_tpCondRet BAR_DestruirBaralho( BAR_tppBaralho pBaralho )
   {
	PIL_DestruirPilha( pBaralho->pPilCartas ) ;

	free( pBaralho ) ;

	return BAR_CondRetOK ; 	

   }/* Fim funÃ§Ã£o: BAR Destruir Baralho de Cartas */


/***************************************************************************
*
*  FunÃ§Ã£o: BAR Preencher Baralho de Cartas 
*****/

   BAR_tpCondRet BAR_PreencherBaralho( BAR_tppBaralho pBaralho , int numNaipes )
   {	
	PIL_tpCondRet PilRet ;
	CAR_tpCondRet CarRet ;

	CAR_tppCarta cartaCriada ;	
	
	char auxNaipes,
		 naipeDaVez;

	int auxValor ;

	int cartasFaltando = TAM_BARALHO ;

	if ( numNaipes > 4 || numNaipes < 1 )
	{
		return BAR_CondRetParamIncorreto ;
	}

	pBaralho->numNaipes = numNaipes ;

	PilRet = PIL_CriarPilhaVazia( &( pBaralho->pPilCartas ) ) ;

	if ( PilRet == PIL_CondRetFaltouMemoria )
	{
		return BAR_CondRetFaltouMemoria ;
	}

	auxNaipes = 0;
	while ( cartasFaltando )
	{
		naipeDaVez = ( auxNaipes % numNaipes ) + 1 ;
				/* garante que 1 <= naipeDaVez <= numNaipes */

		for (auxValor=1 ; auxValor <= VALORES_POSSIVEIS ; auxValor++ )
		{
			
			CarRet = CAR_CriarCarta( &cartaCriada ) ;
			if ( CarRet == CAR_CondRetFaltouMemoria )
			{
				return BAR_CondRetFaltouMemoria ;
			}

			CAR_PreencheCarta( cartaCriada , naipeDaVez , auxValor ) ;
			cartasFaltando-- ;
		}
		auxNaipes++ ;
	}

	return BAR_CondRetOK ;

	
   }/* Fim funÃ§Ã£o: BAR Preencher Baralho de Cartas */

/***************************************************************************
*
*  FunÃ§Ã£o: BAR Embaralhar Baralho de Cartas  
*****/

   BAR_tpCondRet BAR_Embaralhar( BAR_tppBaralho pBaralho )
   {
	PIL_tppPilha pilhaAux[ PILHAS_AUX_EMBARALHAMENTO ] ;
	PIL_tpCondRet Ret ;
	int contPilha ;
		

	CAR_tppCarta cartaAux ;

	int numPilhaAleat ;	 

	if ( pBaralho->pPilCartas == NULL )
	{
	     return BAR_CondRetBaralhoVazio ; 
	}
	

	/* InicializaÃ§Ã£o das pilhas auxiliares */
	for (contPilha = 0 ; contPilha < PILHAS_AUX_EMBARALHAMENTO ; contPilha++ )
	{
		Ret = PIL_CriarPilhaVazia( &pilhaAux[contPilha] ) ;
		if ( Ret == PIL_CondRetFaltouMemoria )
		{
			return BAR_CondRetFaltouMemoria ;
		}
	}	
	/* InicializaÃ§Ã£o das pilhas auxiliares */


	/* DistribuiÃ§Ã£o dos baralhos nas pilhas auxiliares */

	srand( time(NULL) );
		/* usa o tempo atual como 
		   semente para a randomizaÃ§Ã£o */

	while ( PIL_PopCarta( pBaralho->pPilCartas , &cartaAux )
			!= PIL_CondRetPilhaVazia )
	{
		numPilhaAleat = rand() % PILHAS_AUX_EMBARALHAMENTO ;
		PIL_PushCarta( pilhaAux[ numPilhaAleat ] , cartaAux ) ;
	}

	/* DistribuiÃ§Ã£o dos baralhos nas pilhas auxiliares */

	
	/* ReinserÃ§Ã£o das cartas no baralho */
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

	/* ReinserÃ§Ã£o das cartas no baralho */

	return BAR_CondRetOK ;

   }/* Fim funÃ§Ã£o: BAR Embaralhar Baralho de Cartas */

/***************************************************************************
*
*  FunÃ§Ã£o: BAR PopCarta 
*****/

   BAR_tpCondRet BAR_PopCarta( BAR_tppBaralho pBaralho , CAR_tppCarta * pCarta )
   {
	    if ( pBaralho->pPilCartas == NULL )
	    {
		return BAR_CondRetBaralhoVazio ; 
	    }

	    PIL_PopCarta( pBaralho->pPilCartas , pCarta ) ;

	    return BAR_CondRetOK ;

   }/* Fim funÃ§Ã£o: BAR Pop Carta */

/********** Fim do mÃ³dulo de implementaÃ§Ã£o: BAR  Baralho de cartas  **********/
