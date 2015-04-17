/***************************************************************************
 *  $MCI Módulo de implementação: CAR  Carta
 *
 *  Arquivo gerado:              CARTA.c
 *  Letras identificadoras:      CAR
 *
 *  Nome da base de software:    Arcabouço para a automação de testes de programas redigidos em C
 *
 *  Projeto: Trabalho 2 - Programação Modular
 *  Autores: EG - Eric Grinstein
             JM - Jordana Mecler
             LW - Leonardo Wajnsztok
 *
 *  $HA Histórico de evolução:
 *     Versão      Autor            Data                Observações
 *     1.0       EG,JM,LW        17/abr/2015       Correção de condições de retorno
 *     1.0       EG,JM,LW        16/abr/2015       início do desenvolvimento
 *
 ***************************************************************************/

#include <stdio.h>
#include <malloc.h>

#define CARTA_OWN
#include "CARTA.h"
#undef CARTA_OWN

/***********************************************************************
 *
 *  $TC Tipo de dados: CAR Carta
 *
 *
 ***********************************************************************/

typedef struct CAR_carta {
    
    char naipe ;
        /* Naipe da carta */
    
    int valor ;
        /* Valor da carta */
    
} CAR_tpCarta ;

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
 *
 *  Função: CAR  Criar carta
 *  ****/

CAR_tpCondRet CAR_CriarCarta( CAR_tppCarta * pCarta )
{
    
    *pCarta = NULL ;
    
    *pCarta = ( CAR_tpCarta * ) malloc( sizeof( CAR_tpCarta )) ;
    if( *pCarta == NULL )
    {
        return CAR_CondRetFaltouMemoria ;
    } /* if */
    
    (*pCarta)->naipe = '0' ;
    (*pCarta)->valor = 0 ;
    
    return CAR_CondRetOK ;
    
} /* Fim função: CAR  Criar carta */

/***************************************************************************
 *
 *  Função: CAR  Preencher carta
 *  ****/

CAR_tpCondRet CAR_PreencheCarta ( CAR_tppCarta pCarta , char naipe , int valor )
{
    
    if( pCarta == NULL )
    {
        return CAR_CondRetCartaNaoExiste ;
    } /* if */
    
    pCarta->naipe = naipe ;
    pCarta->valor = valor ;
    
    return CAR_CondRetOK ;
    
} /* Fim função: CAR  Preencher carta */

/***************************************************************************
 *
 *  Função: CAR  Excluir carta
 *  ****/

CAR_tpCondRet CAR_ExcluirCarta( CAR_tppCarta pCarta )
{
    
    if( pCarta != NULL )
    {
        free( pCarta ) ;
        pCarta = NULL ;
    } /* if */
    
    return CAR_CondRetOK ;
    
} /* Fim função: CAR  Excluir carta */

/***************************************************************************
 *
 *  Função: CAR  Obter naipe da carta
 *  ****/

CAR_tpCondRet CAR_ObterNaipe( CAR_tppCarta pCarta , char * pNaipe )
{
    
    if( pCarta == NULL )
    {
        return CAR_CondRetCartaNaoExiste ;
    } /* if */
    
    *pNaipe = pCarta->naipe ;
    
    return CAR_CondRetOK ;
    
} /* Fim função: CAR  Obter naipe da carta */

/***************************************************************************
 *
 *  Função: CAR  Obter valor da carta
 *  ****/

CAR_tpCondRet CAR_ObterValor( CAR_tppCarta pCarta , int * pValor )
{
    
    if( pCarta == NULL )
    {
        return CAR_CondRetCartaNaoExiste ;
    } /* if */
    
    *pValor = pCarta->valor ;
    
    return CAR_CondRetOK ;
    
} /* Fim função: CAR  Obter valor da carta */

/***************************************************************************
 *
 *  Função: CAR  Imprimir carta
 *  ****/

CAR_tpCondRet CAR_ImprimeCarta( CAR_tppCarta pCarta )
{
    
    if( pCarta == NULL )
    {
        return CAR_CondRetCartaNaoExiste ;
    } /* if */
    
    printf("%d %c" , pCarta->valor , pCarta->naipe ) ;
    
    return CAR_CondRetOK ;
    
} /* Fim função: CAR  Imprimir carta */

/********** Fim do módulo de implementação: CAR  Carta **********/
