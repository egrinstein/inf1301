#if ! defined( BARALHO_DE_CARTAS_ )
#define BARALHO_DE_CARTAS_
/***************************************************************************
*
*  $MCD MÃ³dulo de definiÃ§Ã£o: BAR  Baralho de Cartas
*
*  Arquivo gerado:              BAR.H
*  Letras identificadoras:      BAR
*
*  Autores: Eric Grinstein,
*           Jordana Mecler,
*	    Leonardo Wajnsztok
*
*
*  $ED DescriÃ§Ã£o do mÃ³dulo
*     Cria um baralho de 104 cartas com nÃºmero de naipes 
*     podendo variar de 1 a 4.
*     
***************************************************************************/
 
#if defined( BARALHO_DE_CARTAS_OWN )
   #define BARALHO_DE_CARTAS_EXT
#else
   #define BARALHO_DE_CARTAS_EXT extern
#endif

#include "CARTA.h"

/***** DeclaraÃ§Ãµes exportadas pelo mÃ³dulo *****/

/* Tipo referÃªncia para um baralho de cartas */

typedef struct BAR_tagBaralho * BAR_tppBaralho ;

/***********************************************************************
*
*  $TC Tipo de dados: BAR CondiÃ§Ãµes de retorno
*
*
*  $ED DescriÃ§Ã£o do tipo
*     CondiÃ§Ãµes de retorno das funÃ§Ãµes da lista
*
***********************************************************************/

   typedef enum {

         BAR_CondRetOK ,
               /* Concluiu corretamente */

         BAR_CondRetBaralhoVazio ,
               /* O baralho nÃ£o foi preenchido */

		 BAR_CondRetParamIncorreto ,
               /* NÃºmero de naipes incorretos  */

         BAR_CondRetFaltouMemoria
               /* Faltou memÃ³ria ao criar baralho */

   } BAR_tpCondRet ;


/***********************************************************************
*
*  $FC FunÃ§Ã£o: BAR Criar Baralho de Cartas
*
*  $ED DescriÃ§Ã£o da funÃ§Ã£o
*     Cria um baralho de cartas de baralho vazio
*
*  $EP ParÃ¢metros
*	pBaralho - EndereÃ§o que receberÃ¡ um ponteiro para o baralho criado 
*	
*  $FV Valor retornado
*	BAR_CondRetOK - Criou sem problemas
*	BAR_CondRetFaltouMemoria - Faltou memÃ³ria na criaÃ§Ã£o do baralho
*	BAR_CondRetParamIncorreto - NÃºmero de naipes diferente de [1,4]
*
***********************************************************************/

    BAR_tpCondRet BAR_CriarBaralho( BAR_tppBaralho * pBaralho ) ;

/***********************************************************************
*
*  $FC FunÃ§Ã£o: BAR Destruir baralho
*
*  $ED DescriÃ§Ã£o da funÃ§Ã£o
*	DestrÃ³i baralho de cartas
*
*  $EP ParÃ¢metros
*     pBaralho de Cartas - ponteiro para o baralho a ser destruÃ­do
*
*  $FV Valor retornado
*     BAR_CondRetOK    - destruiu sem problemas
*
***********************************************************************/

   BAR_tpCondRet BAR_DestruirBaralho( BAR_tppBaralho pBaralho ) ;


/***********************************************************************
*
*  $FC FunÃ§Ã£o: BAR Preencher Baralho de Cartas
*
*  $ED DescriÃ§Ã£o da funÃ§Ã£o
*      Preenche baralho de cartas homogÃªneamente com
*      os naipes fornecidos na criaÃ§Ã£o do baralho.
*
*  $EP ParÃ¢metros
*     pBaralho - ponteiro para o baralho a ser preenchido
*     numNaipes - nÃºmero de naipes que terÃ¡ o baralho
*
*  $FV Valor retornado
*     BAR_CondRetOK    - preencheu sem problemas
*     BAR_CondRetFaltouMemÃ³ria - Faltou memÃ³ria no 
*				 preenchimento do baralho
*
***********************************************************************/

      BAR_tpCondRet BAR_PreencherBaralho( BAR_tppBaralho pBaralho , int numNaipes ) ;


/***********************************************************************
*
*  $FC FunÃ§Ã£o: BAR Pop Carta
*
*  $ED DescriÃ§Ã£o da funÃ§Ã£o
*     Remove carta do topo do baralho
*     
*
*  $EP ParÃ¢metros
*     pBaralho de Cartas - ponteiro para o baralho onde o topo deve ser removido
*     pCarta - endereÃ§o que receberÃ¡ a carta removida.
*              
*
*  $FV Valor retornado
*     BAR_CondRetOK
*     BAR_CondRetBaralhoVazio
*
***********************************************************************/

      BAR_tpCondRet BAR_PopCarta( BAR_tppBaralho pBaralho , CAR_tppCarta * pCarta );

/***********************************************************************
*
*  $FC FunÃ§Ã£o: BAR Embaralhar
*
*  $ED DescriÃ§Ã£o da funÃ§Ã£o
*      Randomiza a posiÃ§Ã£o das cartas no baralho. Para a randomizaÃ§Ã£o,
*      as cartas sÃ£o separadas aleatoriamente em 5 pilhas e depois juntas.
*      
*
*  $EP ParÃ¢metros
*     pBaralho de Cartas - ponteiro para o baralho a ser embaralhado
*
*  $FV Valor retornado
*     BAR_CondRetOK
*     BAR_CondRetBaralhoVazio
*     BAR_CondRetFaltouMemoria - Faltou memÃ³ria durante o embaralhamento
*
***********************************************************************/

     BAR_tpCondRet BAR_Embaralhar( BAR_tppBaralho pBaralho );

#undef BARALHO_DE_CARTAS_EXT

/********** Fim do mÃ³dulo de definiÃ§Ã£o: BAR Baralho de Cartas  **********/

#else
#endif
