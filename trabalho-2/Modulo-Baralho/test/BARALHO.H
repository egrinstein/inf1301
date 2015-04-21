#if ! defined( BARALHO_DE_CARTAS_ )
#define BARALHO_DE_CARTAS_
/***************************************************************************
*
*  $MCD Módulo de definição: BAR  Baralho de Cartas
*
*  Arquivo gerado:              BAR.H
*  Letras identificadoras:      BAR
*
*  Autores: Eric Grinstein,
*           Jordana Mecler,
*	    Leonardo Wajnsztok
*
*
*  $ED Descrição do módulo
*     Cria um baralho de 52 cartas com número de naipes 
*     podendo variar de 1 a 4.
*     
***************************************************************************/
 
#if defined( BARALHO_DE_CARTAS_OWN )
   #define BARALHO_DE_CARTAS_EXT
#else
   #define BARALHO_DE_CARTAS_EXT extern
#endif



/***** Declarações exportadas pelo módulo *****/

/* Tipo referência para um baralho de cartas */

typedef BAR_tagBaralho BAR_tppBaralho ;

/***********************************************************************
*
*  $TC Tipo de dados: BAR Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções da lista
*
***********************************************************************/

   typedef enum {

         BAR_CondRetOK ,
               /* Concluiu corretamente */

         BAR_CondRetBaralhoVazio ,
               /* O baralho não foi preenchido */

	 BAR_CondRetParamIncorreto ,
               /* Número de naipes incorretos  */

         BAR_CondRetFaltouMemoria
               /* Faltou memória ao criar baralho */

   } BAR_tpCondRet ;


/***********************************************************************
*
*  $FC Função: BAR Criar Baralho de Cartas
*
*  $ED Descrição da função
*     Cria um baralho de cartas de baralho vazio
*
*  $EP Parâmetros
*	pBaralho - Endereço que receberá um ponteiro para o baralho criado 
*	
*  $FV Valor retornado
*	BAR_CondRetOK - Criou sem problemas
*	BAR_CondRetFaltouMemoria - Faltou memória na criação do baralho
*	BAR_CondRetParamIncorreto - Número de naipes diferente de [1,4]
*
***********************************************************************/

    BAR_tpCondRet BAR_CriarBaralho( BAR_tppBaralho * pBaralho , int numNaipes ) ;

/***********************************************************************
*
*  $FC Função: BAR Destruir baralho
*
*  $ED Descrição da função
*	Destrói baralho de cartas
*
*  $EP Parâmetros
*     pBaralho de Cartas - ponteiro para o baralho a ser destruído
*
*  $FV Valor retornado
*     BAR_CondRetOK    - destruiu sem problemas
*
***********************************************************************/

   BAR_tpCondRet BAR_DestruirBaralho( BAR_tppBaralho pBaralho ) ;


/***********************************************************************
*
*  $FC Função: BAR Preencher Baralho de Cartas
*
*  $ED Descrição da função
*      Preenche baralho de cartas homogêneamente com
*      os naipes fornecidos na criação do baralho.
*
*  $EP Parâmetros
*     pBaralho - ponteiro para o baralho a ser preenchido
*
*  $FV Valor retornado
*     BAR_CondRetOK    - preencheu sem problemas
*     BAR_CondRetFaltouMemória - Faltou memória no 
*				 preenchimento do baralho
*
***********************************************************************/

      BAR_tpCondRet BAR_PreencherBaralho( BAR_tppBaralho pBaralho ) ;


/***********************************************************************
*
*  $FC Função: BAR Pop Carta
*
*  $ED Descrição da função
*     Remove carta do topo do baralho
*     
*
*  $EP Parâmetros
*     pBaralho de Cartas - ponteiro para o baralho onde o topo deve ser removido
*     pCarta - endereço que receberá a carta removida.
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
*  $FC Função: BAR Embaralhar
*
*  $ED Descrição da função
*      Randomiza a posição das cartas no baralho. Para a randomização,
*      as cartas são separadas aleatoriamente em 5 pilhas e depois juntas.
*      
*
*  $EP Parâmetros
*     pBaralho de Cartas - ponteiro para o baralho a ser embaralhado
*
*  $FV Valor retornado
*     BAR_CondRetOK
*     BAR_CondRetBaralhoVazio
*     BAR_CondRetFaltouMemoria - Faltou memória durante o embaralhamento
*
***********************************************************************/

     BAR_tpCondRet BAR_Embaralhar( BAR_tppBaralho pBaralho );

#undef BARALHO_DE_CARTAS_EXT

/********** Fim do módulo de definição: BAR Baralho de Cartas  **********/

#else
#endif
