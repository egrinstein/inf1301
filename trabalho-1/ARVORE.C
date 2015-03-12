/***************************************************************************
*  $MCI Módulo de implementação: Módulo árvore
*
*  Arquivo gerado:              ARVORE.C
*  Letras identificadoras:      ARV
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\SIMPLES.BSW
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: avs - Arndt von Staa
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       3.00   avs   28/02/2003 Uniformização da interface das funções e
*                               de todas as condições de retorno.
*       2.00   avs   03/08/2002 Eliminação de código duplicado, reestruturação
*       1.00   avs   15/08/2001 Início do desenvolvimento
*
***************************************************************************/

#include   <stdlib.h>
#include   <stdio.h>

#define ARVORE_OWN
#include "ARVORE.H"
#undef ARVORE_OWN

/***********************************************************************
*
*  $TC Tipo de dados: ARV Descritor do nó da árvore
*
*
*  $ED Descrição do tipo
*     Descreve a organização do nó
*
***********************************************************************/

   typedef struct tgNoArvore {

         struct tgNoArvore * pNoPai ;
               /* Ponteiro para pai
               *
               *$EED Assertivas estruturais
               *   É NULL sse o nó é raiz
               *   Se não for raiz, um de pNoEsq ou pNoDir de pNoPai do nó
               *   corrente apontam para o nó corrente */

         struct tgNoArvore * pNoEsq ;
               /* Ponteiro para filho à esquerda
               *
               *$EED Assertivas estruturais
               *   se pNoEsq do nó X != NULL então pNoPai de pNoEsq aponta para o nó X */

         struct tgNoArvore * pNoDir ;
               /* Ponteiro para filho à direita
               *
               *$EED Assertivas estruturais
               *   se pNoDir do nó X != NULL então pNoPai de pNoDir aponta para o nó X */

         struct tgNoArvore * pProxFolha ;
        	   /* Ponteiro para próxima folha
        	   *
        	   *$EED Assertivas estruturais
        	   *   se pProxFolha do nó X == NULL ou X não é folha, ou função costura não foi utilizada
        	       ou X é a folha mais a direita    */


         char Valor ;
               /* Valor do nó */

   } tpNoArvore ;

/***********************************************************************
*
*  $TC Tipo de dados: ARV Descritor da cabeça de uma árvore
*
*
*  $ED Descrição do tipo
*     A cabe‡a da árvore é o ponto de acesso para uma determinada árvore.
*     Por intermédio da referência para o nó corrente e do ponteiro
*     pai pode-se navegar a árvore sem necessitar de uma pilha.
*     Pode-se, inclusive, operar com a árvore em forma de co-rotina.
*
***********************************************************************/

   typedef struct tgArvore {

         tpNoArvore * pNoRaiz ;
               /* Ponteiro para a raiz da árvore */

         tpNoArvore * pNoCorr ;
               /* Ponteiro para o nó corrente da árvore */
         tpNoArvore * pPrimFolha ;

   } tpArvore ;

/*****  Dados encapsulados no módulo  *****/

      static tpArvore * pArvore = NULL ;
            /* Ponteiro para a cabe‡a da árvore */

/***** Protótipos das funções encapuladas no módulo *****/

   static tpNoArvore * CriarNo( char ValorParm ) ;

   static ARV_tpCondRet CriarNoRaiz( char ValorParm ) ;

   static void DestroiArvore( tpNoArvore * pNo ) ;

   static tpNoArvore * CosturaParaEsquerda( tpNoArvore * pNo, tpNoArvore * valor );

   static int EhFolha( tpNoArvore * pNo );

   static int ContaCostura( void );

   static int ComparaFolhasAlfab( const void * vNo1, const void * vNo2);

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: ARV Criar árvore
*  ****/

   ARV_tpCondRet ARV_CriarArvore( void )
   {

      if ( pArvore != NULL )
      {
         ARV_DestruirArvore( ) ;
      } /* if */

      pArvore = ( tpArvore * ) malloc( sizeof( tpArvore )) ;
      if ( pArvore == NULL )
      {
         return ARV_CondRetFaltouMemoria ;
      } /* if */

      pArvore->pNoRaiz = NULL ;
      pArvore->pNoCorr = NULL ;
      pArvore->pPrimFolha = NULL ;
      
      return ARV_CondRetOK ;

   } /* Fim função: ARV Criar árvore */

/***************************************************************************
*
*  Função: ARV Destruir árvore
*  ****/

   void ARV_DestruirArvore( void )
   {

      if ( pArvore != NULL )
      {
         if ( pArvore->pNoRaiz != NULL )
         {
            DestroiArvore( pArvore->pNoRaiz ) ;
         } /* if */
         free( pArvore ) ;
         pArvore = NULL ;
      } /* if */

   } /* Fim função: ARV Destruir árvore */

/***************************************************************************
*
*  Função: ARV Adicionar filho à esquerda
*  ****/

   ARV_tpCondRet ARV_InserirEsquerda( char ValorParm )
   {

      ARV_tpCondRet CondRet ;

      tpNoArvore * pCorr ;
      tpNoArvore * pNo ;

      /* Tratar vazio, esquerda */

         CondRet = CriarNoRaiz( ValorParm ) ;
         if ( CondRet != ARV_CondRetNaoCriouRaiz )
         {
            return CondRet ;
         } /* if */

      /* Criar nó à esquerda de folha */

         pCorr = pArvore->pNoCorr ;
         if ( pCorr == NULL )
         {
            return ARV_CondRetErroEstrutura ;
         } /* if */
               
         if ( pCorr->pNoEsq == NULL )
         {
            pNo = CriarNo( ValorParm ) ;
            if ( pNo == NULL )
            {
               return ARV_CondRetFaltouMemoria ;
            } /* if */
            pNo->pNoPai      = pCorr ;
            pCorr->pNoEsq    = pNo ;
            pArvore->pNoCorr = pNo ;

            return ARV_CondRetOK ;
         } /* if */

      /* Tratar não folha à esquerda */

         return ARV_CondRetNaoEhFolha ;

   } /* Fim função: ARV Adicionar filho à esquerda */

/***************************************************************************
*
*  Função: ARV Adicionar filho à direita
*  ****/

   ARV_tpCondRet ARV_InserirDireita( char ValorParm )
   {

      ARV_tpCondRet CondRet ;

      tpNoArvore * pCorr ;
      tpNoArvore * pNo ;

      /* Tratar vazio, direita */

         CondRet = CriarNoRaiz( ValorParm ) ;
         if ( CondRet != ARV_CondRetNaoCriouRaiz )
         {
            return CondRet ;
         } /* if */

      /* Criar nó à direita de folha */

         pCorr = pArvore->pNoCorr ;
         if ( pCorr == NULL )
         {
            return ARV_CondRetErroEstrutura ;
         } /* if */

         if ( pCorr->pNoDir == NULL )
         {
            pNo = CriarNo( ValorParm ) ;
            if ( pNo == NULL )
            {
               return ARV_CondRetFaltouMemoria ;
            } /* if */
            pNo->pNoPai      = pCorr ;
            pCorr->pNoDir    = pNo ;
            pArvore->pNoCorr = pNo ;

            return ARV_CondRetOK ;
         } /* if */

      /* Tratar não folha à direita */

         return ARV_CondRetNaoEhFolha ;

   } /* Fim função: ARV Adicionar filho à direita */

/***************************************************************************
*
*  Função: ARV Ir para nó pai
*  ****/

   ARV_tpCondRet ARV_IrPai( void )
   {

      if ( pArvore == NULL )
      {
         return ARV_CondRetArvoreNaoExiste ;
      } /* if */
      if ( pArvore->pNoCorr == NULL )
      {
         return ARV_CondRetArvoreVazia ;
      } /* if */

      if ( pArvore->pNoCorr->pNoPai != NULL )
      {
         pArvore->pNoCorr = pArvore->pNoCorr->pNoPai ;
         return ARV_CondRetOK ;
      } else {
         return ARV_CondRetNohEhRaiz ;
      } /* if */

   } /* Fim função: ARV Ir para nó pai */

/***************************************************************************
*
*  Função: ARV Ir para nó à esquerda
*  ****/

   ARV_tpCondRet ARV_IrNoEsquerda( void )
   {

      if ( pArvore == NULL )
      {
         return ARV_CondRetArvoreNaoExiste ;
      } /* if */

      if ( pArvore->pNoCorr == NULL )
      {
         return ARV_CondRetArvoreVazia ;
      } /* if */

      if ( pArvore->pNoCorr->pNoEsq == NULL )
      {
         return ARV_CondRetNaoPossuiFilho ;
      } /* if */

      pArvore->pNoCorr = pArvore->pNoCorr->pNoEsq ;
      return ARV_CondRetOK ;

   } /* Fim função: ARV Ir para nó à esquerda */

/***************************************************************************
*
*  Função: ARV Ir para nó à direita
*  ****/

   ARV_tpCondRet ARV_IrNoDireita( void )
   {

      if ( pArvore == NULL )
      {
         return ARV_CondRetArvoreNaoExiste ;
      } /* if */

      if ( pArvore->pNoCorr == NULL )
      {
         return ARV_CondRetArvoreVazia ;
      } /* if */

      if ( pArvore->pNoCorr->pNoDir == NULL )
      {
         return ARV_CondRetNaoPossuiFilho ;
      } /* if */

      pArvore->pNoCorr = pArvore->pNoCorr->pNoDir ;
      return ARV_CondRetOK ;

   } /* Fim função: ARV Ir para nó à direita */

/***************************************************************************
*
*  Função: ARV Obter valor corrente
*  ****/

   ARV_tpCondRet ARV_ObterValorCorr( char * ValorParm )
   {

      if ( pArvore == NULL )
      {
         return ARV_CondRetArvoreNaoExiste ;
      } /* if */
      if ( pArvore->pNoCorr == NULL )
      {
         return ARV_CondRetArvoreVazia ;
      } /* if */
      * ValorParm = pArvore->pNoCorr->Valor ;

      return ARV_CondRetOK ;

   } /* Fim função: ARV Obter valor corrente */

/***************************************************************************
*
*  Função: ARV Costura Folhas
*  ****/

   ARV_tpCondRet ARV_CosturaFolhas( void )
   {
   	  int numFolhas,i;
   	  tpNoArvore * pFolha;
   	  tpNoArvore ** pVetFolhas;

      if ( pArvore == NULL )
      {
         return ARV_CondRetArvoreNaoExiste ;
      } /* if */
      if ( pArvore->pNoCorr == NULL )
      {
         return ARV_CondRetArvoreVazia ;
      } /* if */

      pArvore->pPrimFolha = CosturaParaEsquerda( pArvore->pNoRaiz, NULL );
      
      numFolhas = ContaCostura( );
      

      pVetFolhas = (tpNoArvore **) malloc(numFolhas*sizeof(tpNoArvore *));

      pFolha = pArvore->pPrimFolha;
      i = 0;
      while (pFolha != NULL && i < numFolhas)
      {
      	pVetFolhas[i] = pFolha;
      	pFolha = pFolha->pProxFolha;
      	i++;
      }

      qsort(pVetFolhas,numFolhas,sizeof(tpNoArvore *), ComparaFolhasAlfab);
      

      pFolha = pArvore->pPrimFolha;
      for (i = 0; i < numFolhas-1; i++)
      {
      	  pVetFolhas[i]->pProxFolha = pVetFolhas[i+1];
      }
      
      pVetFolhas[i]->pProxFolha = NULL;

      free( pVetFolhas );
      return ARV_CondRetOK;
      

   } /* Fim função: ARV Costura Folhas */


/***************************************************************************
*
*  Função: ARV Imprime Costura
*  ****/

   ARV_tpCondRet ARV_ImprimeCostura( void )
   {
   	  tpNoArvore * pNo;

      if ( pArvore == NULL )
      {
         return ARV_CondRetArvoreNaoExiste ;
      } /* if */
      if ( pArvore->pNoCorr == NULL )
      {
         return ARV_CondRetArvoreVazia ;
      } /* if */

      pNo = pArvore->pNoRaiz;

      pNo = pArvore->pPrimFolha;
      
     
      while ( pNo != NULL )
      {
      	 printf("%c\n", pNo->Valor );
      	 pNo = pNo->pProxFolha;
      }

      return ARV_CondRetOK;
      

   } /* Fim função: ARV Costura Folhas */

/*****  Código das funções encapsuladas no módulo  *****/


/***********************************************************************
*
*  $FC Função: ARV Criar nó da árvore
*
*  $FV Valor retornado
*     Ponteiro para o nó criado.
*     Será NULL caso a memória tenha se esgotado.
*     Os ponteiros do nó criado estarão nulos e o valor é igual ao do
*     parâmetro.
*
***********************************************************************/

   tpNoArvore * CriarNo( char ValorParm )
   {

      tpNoArvore * pNo ;

      pNo = ( tpNoArvore * ) malloc( sizeof( tpNoArvore )) ;
      if ( pNo == NULL )
      {
         return NULL ;
      } /* if */

      pNo->pNoPai = NULL ;
      pNo->pNoEsq = NULL ;
      pNo->pNoDir = NULL ;
      pNo->Valor  = ValorParm ;
      pNo->pProxFolha = NULL;
      return pNo ;

   } /* Fim função: ARV Criar nó da árvore */


/***********************************************************************
*
*  $FC Função: ARV Criar nó raiz da árvore
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetFaltouMemoria
*     ARV_CondRetNaoCriouRaiz
*
***********************************************************************/

   ARV_tpCondRet CriarNoRaiz( char ValorParm )
   {

      ARV_tpCondRet CondRet ;
      tpNoArvore * pNo ;

      if ( pArvore == NULL )
      {
         CondRet = ARV_CriarArvore( ) ;

         if ( CondRet != ARV_CondRetOK )
         {
            return CondRet ;
         } /* if */
      } /* if */

      if ( pArvore->pNoRaiz == NULL )
      {
         pNo = CriarNo( ValorParm ) ;
         if ( pNo == NULL )
         {
            return ARV_CondRetFaltouMemoria ;
         } /* if */
         pArvore->pNoRaiz = pNo ;
         pArvore->pNoCorr = pNo ;

         return ARV_CondRetOK ;
      } /* if */

      return ARV_CondRetNaoCriouRaiz ;

   } /* Fim função: ARV Criar nó raiz da árvore */


/***********************************************************************
*
*  $FC Função: ARV Destruir a estrutura da árvore
*
*  $EAE Assertivas de entradas esperadas
*     pNoArvore != NULL
*
***********************************************************************/

   void DestroiArvore( tpNoArvore * pNo )
   {

      if ( pNo->pNoEsq != NULL )
      {
         DestroiArvore( pNo->pNoEsq ) ;
      } /* if */

      if ( pNo->pNoDir != NULL )
      {
         DestroiArvore( pNo->pNoDir ) ;
      } /* if */

      free( pNo ) ;

   } /* Fim função: ARV Destruir a estrutura da árvore */

/***********************************************************************
*
*  $FC Função: ARV CosturaParaEsquerda
*
*
***********************************************************************/

   tpNoArvore * CosturaParaEsquerda( tpNoArvore * pNo, tpNoArvore * valor )
   {

   		if ( pNo == NULL )
   		{
   			return valor;
   		}

   		if ( EhFolha( pNo ) )
   		{
   			pNo->pProxFolha = valor;
   			return pNo;
   		}
   		else
   		{
   			valor = CosturaParaEsquerda( pNo->pNoDir , valor );
   			valor = CosturaParaEsquerda( pNo->pNoEsq , valor );
   		}

   } /* Fim função: ARV Costurar árvore da direita para a esquerda*/


/***********************************************************************
*
*  $FC Função: ARV ComparaFolhasAlfab
*
*
***********************************************************************/

   int ComparaFolhasAlfab( const void * vNo1, const void * vNo2)
   {
   		
   		tpNoArvore ** pNo1 = ( tpNoArvore ** ) vNo1;
   		tpNoArvore ** pNo2 = ( tpNoArvore ** ) vNo2;

   		if ( (*pNo1)->Valor < (*pNo2)->Valor )
   		{
   			return -1;
   		}
   		else if ((*pNo1)->Valor > (*pNo2)->Valor)
   		{
   			return 1;
   		}
   		else
   		{
   			return 0;
   		}		

   } /* Fim função: ARV Conta Número de Folhas na Árvore */

/***********************************************************************
*
*  $FC Função: ARV No é folha
*
*  $EAE Assertivas de entradas esperadas
*     pNoArvore != NULL
*
***********************************************************************/

   int EhFolha( tpNoArvore * pNo )
   {
   	   return ( pNo->pNoDir == NULL && pNo->pNoEsq == NULL);
   } /* Fim função: ARV Nó é folha */

/***********************************************************************
*
*  $FC Função: ARV Conta folhas da costura
*
*  $EAE Assertivas de entradas esperadas
*     pNoArvore != NULL
*
***********************************************************************/

   int ContaCostura( void )
   {
   	   int i = 0;
   	   tpNoArvore * pFolha;
   	   pFolha = pArvore->pPrimFolha;
   	   while (pFolha != NULL)
   	   {
   	   		i++;
   	   		pFolha = pFolha->pProxFolha;
   	   }
   	   return i;

   } /* Fim função: ARV Conta folhas da costura */

/********** Fim do módulo de implementação: Módulo árvore **********/

