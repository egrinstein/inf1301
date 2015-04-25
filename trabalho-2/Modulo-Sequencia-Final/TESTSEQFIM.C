/***************************************************************************
 *  $MCI Módulo de implementação: Módulo de teste específico
 *
 *  Arquivo gerado:              TESTSEQFIM.C
 *  Letras identificadoras:      TSEQFIM
 *
 *  Autores:
 *       EG - Eric Grinstein
 *       JM - Jordana Mecler
 *       LW - Leonardo Wajnsztok
 *
 *
 *  $ED Descrição do módulo
 *     Este módulo contém as funções específicas para o teste do
 *     módulo sequência final.
 *
 *  $EIU Interface com o usuário pessoa
 *     Comandos de teste específicos para testar o módulo monte:
 *
 *     =criar <int>
 *                   - chama a função  SEQFIM_CriarSeqFim.
 *
 *     =preencher <int>
 *                   - chama a função SEQFIM_PreencheSeqFim.
 *                   Irá preencher uma sequência final com 3 cartas previamente escolhidas
 *                   a partir de uma pilha criada com tais cartas.
 *
 *     =destruir <int>
 *             - chama a função SEQFIM_DestroiSeqFim.
 *
 ***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

#include    "CARTA.H"
#include    "PILHA_DE_CARTAS.H"
#include    "SEQFIM.H"

/* Tabela dos nomes dos comandos de teste específicos */

#define     CRIAR_SEQFIM_CMD          "=criar"
#define     PREENCHER_SEQFIM_CMD      "=preencher"
#define     DESTRUIR_SEQFIM_CMD       "=destruir"

/* Ponteiro para sequencia final utilizado no teste */

SEQFIM_tppSeqFim pSeqFimDada = NULL;

/***********************************************************************
 *
 *  $FC Função: TSEQFIM Efetuar operações de teste específicas para Sequencia final
 *
 *  $ED Descrição da função
 *     Efetua os diversos comandos de teste específicos para o módulo
 *     Sequencia final sendo testado.
 *
 *  $EP Parâmetros
 *     $P ComandoTeste - String contendo o comando
 *
 *  $FV Valor retornado
 *     Ver TST_tpCondRet definido em TST_ESPC.H
 *
 ***********************************************************************/

TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
{
    
    SEQFIM_tpCondRet CondRetObtido   = SEQFIM_CondRetOK ;
    SEQFIM_tpCondRet CondRetEsperada = SEQFIM_CondRetFaltouMemoria ;
    /* inicializa para qualquer coisa */
    
    char NaipeEsperado = '?'  ;
    char NaipeObtido   = '!'  ;
    
    int ValorEsperado = -1  ;
    int ValorObtido   = -2  ;
    
    PIL_tppPilha pilhaAux;
    CAR_tppCarta CartaObtida;
    CAR_tppCarta CartaAux1;
    CAR_tppCarta CartaAux2;
    CAR_tppCarta CartaAux3;
    
    TST_tpCondRet Ret ;
    
    int  NumLidos = -1 ;
    
    /* Testar SEQFIM Criar Sequencia final */
    
    if ( strcmp( ComandoTeste , CRIAR_SEQFIM_CMD ) == 0 )
    {
        
        NumLidos = LER_LerParametros( "i" ,
                                     &CondRetEsperada ) ;
        if ( NumLidos != 1 )
        {
            return TST_CondRetParm ;
        } /* if */
        
        CondRetObtido = SEQFIM_CriarMonte ( &pSeqFimDada );
        
        return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                               "Retorno errado ao criar a sequencia final." );
        
    } /* fim ativa: Testar SEQFIM Criar Sequencia final */
    
    /* Testar SEQFIM Destroi Sequencia final */
    
    else if ( strcmp( ComandoTeste , DESTRUIR_SEQFIM_CMD  ) == 0 )
    {
        
        NumLidos = LER_LerParametros( "i" ,
                                     &CondRetEsperada ) ;
        if ( NumLidos != 1 )
        {
            return TST_CondRetParm ;
        } /* if */
        
        
        CondRetObtido = SEQFIM_DestroiSeqFim ( pSeqFimDada ) ;

        return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                               "Retorno errado ao tentar destruir sequencia final." );
        
    } /* fim ativa: Testar SEQFIM Destroi Sequencia final */
    
    /* Testar SEQFIM Preencher Sequencia final */
    
    else if ( strcmp( ComandoTeste , PREENCHER_SEQFIM_CMD ) == 0 )
    {
        
        
        NumLidos = LER_LerParametros( "i" ,
                                     &CondRetEsperada ) ;
        if ( NumLidos != 1 )
        {
            return TST_CondRetParm ;
        } /* if */
        
        PIL_CriarPilhaVazia( &pilhaAux );
        
        CAR_CriarCarta( &CartaAux1 ) ;
        CAR_PreencheCarta( CartaAux1, 'o' , 12 );
        CAR_CriarCarta( &CartaAux2 ) ;
        CAR_PreencheCarta( CartaAux2, 'e' , 5 );
        CAR_CriarCarta( &CartaAux3 ) ;
        CAR_PreencheCarta( CartaAux3, 'c' , 11 );
        
        PIL_PushCarta( pilhaAux , CartaAux1 ) ;
        PIL_PushCarta( pilhaAux , CartaAux2 ) ;
        PIL_PushCarta( pilhaAux , CartaAux3 ) ;
        
        CondRetObtido = SEQFIM_PreencheSeqFim ( pSeqFimDada , pilhaAux );
        
        return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                               "Retorno errado ao tentar preencher sequencia final." );
        
    } /* fim ativa:  Testar SEQFIM Preencher Sequencia final */
    
    return TST_CondRetNaoConhec ;
    
} /* Fim função: TSEQFIM Efetuar operações de teste específicas para monte */

/********** Fim do módulo de implementação: Módulo de teste específico **********/
