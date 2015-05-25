#if ! defined( PILHA_DE_CARTAS_ )
#define PILHA_DE_CARTAS_
/***************************************************************************
*
*  $MCD MÃ³dulo de definiÃ§Ã£o: PIL  Pilha de Cartas
*
*  Arquivo gerado:              PIL.H
*  Letras identificadoras:      PIL
*
*  Autores: Eric Grinstein,
*           Jordana Mecler,
*	    Leonardo Wajnsztok
*
*
*  $ED DescriÃ§Ã£o do mÃ³dulo
*     Cria pilha homogÃªnea armazenadora de tipo cartas de baralho.
*     O mÃ³dulo permite a criaÃ§Ã£o de mÃºltiplas pilhas.
*   
***************************************************************************/
 
#if defined( PILHA_DE_CARTAS_OWN )
   #define PILHA_DE_CARTAS_EXT
#else
   #define PILHA_DE_CARTAS_EXT extern
#endif

#include "CARTA.h"

/***** DeclaraÃ§Ãµes exportadas pelo mÃ³dulo *****/

/* Tipo referÃªncia para uma pilha de cartas */

typedef struct PIL_tagPilha * PIL_tppPilha ;

/***********************************************************************
*
*  $TC Tipo de dados: PIL CondiÃ§Ãµes de retorno
*
*
*  $ED DescriÃ§Ã£o do tipo
*     CondiÃ§Ãµes de retorno das funÃ§Ãµes da lista
*
***********************************************************************/

   typedef enum {

         PIL_CondRetOK = 0,
               /* Concluiu corretamente */

         PIL_CondRetPilhaVazia = 1 ,
               /* A pilha nÃ£o contÃ©m elementos */

		 PIL_CondRetParamIncorreto = 2,
               /* ParÃ¢metro incorreto ao tentar ver carta na pilha */
	
         PIL_CondRetFimPilha = 3,
	       /* Fim da pilha atingido ao tentar ver carta */

         PIL_CondRetFaltouMemoria = 4
               /* Faltou memÃ³ria ao tentar inserir na pilha */

   } PIL_tpCondRet ;


/***********************************************************************
*
*  $FC FunÃ§Ã£o: PIL Criar Pilha de Cartas Vazia
*
*  $ED DescriÃ§Ã£o da funÃ§Ã£o
*     Cria uma pilha de cartas de baralho vazia
*
*  $EP ParÃ¢metros
*	pPilha - EndereÃ§o que receberÃ¡ um ponteiro para a pilha criada. 
*	
*  $FV Valor retornado
*	PIL_CondRetOK - Criou sem problemas
*	PIL_CondRetFaltouMemoria - Faltou memÃ³ria na criaÃ§Ã£o da pilha
*
*  $AE Assertivas de Entrada - nenhuma
*
*  $AS Assertivas de SaÃ­da - Se condRet == OK:
*							 ponteiro para pilha vazia Ã© criada em *pPilha
*		
*							 CondRet == FaltouMemÃ³ria:
*							 * pPilha = NULL
***********************************************************************/

    PIL_tpCondRet PIL_CriarPilhaVazia( PIL_tppPilha * pPilha ) ;

/***********************************************************************
*
*  $FC FunÃ§Ã£o: PIL Destruir pilha
*
*  $ED DescriÃ§Ã£o da funÃ§Ã£o
*     DestrÃ³i a lista fornecida.
*     O parÃ¢metro ponteiro para a lista nÃ£o Ã© modificado.
*     Se ocorrer algum erro durante a destruiÃ§Ã£o, a pilha resultarÃ¡
*     estruturalmente incorreta.
*     OBS. nÃ£o existe previsÃ£o para possÃ­veis falhas de execuÃ§Ã£o.
*
*  $EP ParÃ¢metros
*     pPilha de Cartas - ponteiro para a pilha a ser destruÃ­da
*
*  $FV Valor retornado
*     PIL_CondRetOK    - destruiu sem problemas
*
*  $AE Assertivas de Entrada - pPilha != NULL
*
*  $AS Assertivas de SaÃ­da - pPilha = NULL
***********************************************************************/

   PIL_tpCondRet PIL_DestruirPilha( PIL_tppPilha pPilha );


/***********************************************************************
*
*  $FC FunÃ§Ã£o: PIL Push Carta
*
*  $ED DescriÃ§Ã£o da funÃ§Ã£o
*      Insere carta no topo da pilha de cartas
*
*  $EP ParÃ¢metros
*     pPilha de Cartas - ponteiro para a pilha onde a carta serÃ¡ inserida
*     pCarta - Carta a ser inserida no topo da pilha
*
*  $FV Valor retornado
*     PIL_CondRetOK    - inseriu sem problemas
*	  PIL_CondRetFaltouMemoria
*
*  $AE Assertivas de Entrada - pCarta Ã© uma carta vÃ¡lida
*							   pPilha Ã© uma pilha vÃ¡lida
*							   (pode ser vazia)
*
*  $AS Assertivas de SaÃ­da - se CondRet == OK
*							 pCarta Ã© inserido no topo da pilha
*
*							 se CondRet == Faltou MemÃ³ria
*							 pCarta nÃ£o Ã© inserido. Pilha continua
*							 no estado que estava.
*
***********************************************************************/

      PIL_tpCondRet PIL_PushCarta( PIL_tppPilha pPilha , CAR_tppCarta pCarta );


/***********************************************************************
*
*  $FC FunÃ§Ã£o: PIL Pop Carta
*
*  $ED DescriÃ§Ã£o da funÃ§Ã£o
*     Remove carta do topo da pilha
*     
*
*  $EP ParÃ¢metros
*     pPilha de Cartas - ponteiro para a pilha onde o topo deve ser removido
*     pCarta - endereÃ§o que receberÃ¡ a carta removida.
*              
*
*  $FV Valor retornado
*     PIL_CondRetOK
*     PIL_CondRetPilhaVazia
*
*  $AE Assertivas de Entrada - pPilha Ã© uma pilha vÃ¡lida (pode ser vazia)
*
*  $AS Assertivas de SaÃ­da - Se condRet == OK:
*							 carta Ã© removida do topo da pilha e colocada em
*							 *pCarta.
*		
*							 Se condRet == PilhaVazia
*							 *pCarta = NULL
*
***********************************************************************/

      PIL_tpCondRet PIL_PopCarta( PIL_tppPilha pPilha , CAR_tppCarta * pCarta );

/***********************************************************************
*
*  $FC FunÃ§Ã£o: PIL  VerCarta
*
*  $ED DescriÃ§Ã£o da funÃ§Ã£o
*      Permite ver uma carta da pilha, mesmo que nÃ£o o topo;
*      Essa funÃ§Ã£o nÃ£o destrÃ³i a carta vista.
*
*  $EP ParÃ¢metros
*     pPilha de Cartas - ponteiro para a pilha onde serÃ¡ vista a carta
*     pCarta - ponteiro que guardarÃ¡ o endereÃ§o da carta a ser vista.
*     posicao - distÃ¢ncia do topo da pilha Ã  carta a ser vista.
*
*  $FV Valor retornado
*     PIL_CondRetOK
*     PIL_CondRetPilhaVazia
*     PIL_CondRetParamIncorreto - posicao Ã© um valor negativo
*     PIL_CondRetFimPilha - a carta a ser vista estÃ¡ alÃ©m do tamanho da pilha
*
*  $AE Assertivas de Entrada - pPilha Ã© uma pilha vÃ¡lida (pode ser vazia)
*
*  $AS Assertivas de SaÃ­da - Se condRet == OK:
*							 pCarta recebe ponteiro para carta da posiÃ§Ã£o 'posiÃ§Ã£o' da 
*							 pPilha. A carta continua na pilha.
*		
*							 Caso contrÃ¡rio:
*							 * pCarta = NULL
***********************************************************************/

     PIL_tpCondRet PIL_VerCarta( PIL_tppPilha pPilha , CAR_tppCarta * pCarta , int posicao );

#undef PILHA_DE_CARTAS_EXT

/********** Fim do mÃ³dulo de definiÃ§Ã£o: PIL Pilha de Cartas  **********/

#else
#endif