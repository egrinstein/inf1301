/***************************************************************************
 *  $MCI Módulo de implementação: Módulo de teste específico
 *
 *  Arquivo gerado:              TESTSEQJ.C
 *  Letras identificadoras:      TSEQJ
 *
 *  Autores:
 *       EG - Eric Grinstein
 *       JM - Jordana Mecler
 *       LW - Leonardo Wajnsztok
 *
 *
 *  $ED Descrição do módulo
 *     Este módulo contém as funções específicas para o teste do
 *     módulo sequência de jogo.
 *
 *  $EIU Interface com o usuário pessoa
 *     Comandos de teste específicos para testar o módulo sequência de jogo:
 *
 *     =criarIncompleta <int>
 *                   - chama a função  SEQJ_CriarSeqJogo.
 *                   Irá criar uma sequência de jogo com 3 cartas
 *                   previamente escolhidas a partir de uma pilha 
 *                   criada com tais cartas.
 *                   Como só podemos retirar cartas e não colocá-las
 *                   no monte, não importa quais serão elas.
 *
       =criarCompleta <int>

       =virarPrimeiraCarta

       =pushCarta

       =obterPilha

       =moverPilha

       =verificarCompleta


 *     =pop <char> <int>
 *                    - chama a função MON_PopCartaMonte.
 *                    Onde o parâmetro se refere ao valor do naipe
 *                    e o valor da carta fornecida pelo usuário.
 *                    Esses valores serão testados.
 *
 *     =destruir
 *             - chama a função MON_DestruirMonte.
 *
 ***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

#include    "CARTA.H"
#include    "PILHA_DE_CARTAS.H"
#include    "SEQJOGO.H"

/* Tabela dos nomes dos comandos de teste específicos */

#define     CRIARINCOMPLETA_SEQJ_CMD     "=criarIncompleta"
#define     CRIARCOMPLETA_SEQJ_CMD  "=criarCompleta"
#define     DESTRUIR_SEQJ_CMD       "=destruir"
#define     VIRAR_SEQJ_CMD          "=virarPrimeiraCarta"
#define     PUSH_SEQJ_CMD           "=pushCarta"
#define     OBTER_SEQJ_CMD          "=obterPilha"
#define     MOVER_SEQJ_CMD          "=moverPilha"
#define     VERIFICAR_SEQJ_CMD      "=verificarCompleta"


/* Ponteiro para monte utilizado no teste */

SEQJ_tppSeqJ vSeqJ[3] ;

/***********************************************************************
 *
 *  $FC Função: TCAR Efetuar operações de teste específicas para Monte
 *
 *  $ED Descrição da função
 *     Efetua os diversos comandos de teste específicos para o módulo
 *     Monte sendo testado.
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
    
    SEQJ_tpCondRet CondRetObtido   = SEQJ_CondRetOK ;
    SEQJ_tpCondRet CondRetEsperada = SEQJ_CondRetFaltouMemoria ;
    /* inicializa para qualquer coisa */
    
   char NaipeEsperado = '?'  ;
   char NaipeObtido   = '!'  ;  

   int ValorEsperado = -1  ;
   int ValorObtido   = -2  ;  
   int posVetorSeqJ  = -1  ;
   int i = 0;

    PIL_tppPilha pilhaAux;
    CAR_tppCarta CartaObtida;
    CAR_tppCarta CartaAux[13];
    CAR_tppCarta CartaAux2[13];

    TST_tpCondRet Ret ;

    int  NumLidos = -1 ;
    
    /* Testar SEQJ Criar Sequência de jogo completa */
    
    if ( strcmp( ComandoTeste , CRIARCOMPLETA_SEQJ_CMD ) == 0 )
    {
        
        NumLidos = LER_LerParametros( "ii" , &posVetorSeqJ,
                                     &CondRetEsperada ) ;
        if ( NumLidos != 2 )
        {
            return TST_CondRetParm ;
        } /* if */
        
        if (posVetorSeqJ > 2 || posVetorSeqJ < 0 || vSeqJ[posVetorSeqJ] != NULL)
        {
            return TST_CondRetParm ;
        }

        PIL_CriarPilhaVazia( &pilhaAux );

        for(i = 0 ; i < 13 ; i++)
        {
            CAR_CriarCarta( &(CartaAux[i]) ) ;
            CAR_PreencheCarta( CartaAux[i], 'e' , i+1 );
            PIL_PushCarta( pilhaAux , CartaAux[i] ) ;
        }

        CondRetObtido = SEQJ_CriarSeqJogo ( &(vSeqJ[posVetorSeqJ]) , pilhaAux);

        PIL_DestroiPilha(pilhaAux);
        
        return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                               "Retorno errado ao criar a sequencia de jogo." );
        
    } /* fim ativa: Testar SEQJ Criar Sequência de jogo completa*/
    
    /* Testar SEQJ Criar Sequência de jogo incompleta */
    
    else if ( strcmp( ComandoTeste , CRIARINCOMPLETA_SEQJ_CMD  ) == 0 )
    {
        
        NumLidos = LER_LerParametros( "ii" ,&posVetorSeqJ, &CondRetEsperada ) ;
        if ( NumLidos != 2 )
        {
            return TST_CondRetParm ;
        } /* if */
        
        if (posVetorSeqJ > 2 || posVetorSeqJ < 0 || vSeqJ[posVetorSeqJ] != NULL)
        {
            return TST_CondRetParm ;
        }
        
        PIL_CriarPilhaVazia( &pilhaAux );
    
        CAR_CriarCarta( &(CartaAux2[0]) ) ;
        CAR_PreencheCarta( CartaAux2[0], 'c' , 13 );
        PIL_PushCarta( pilhaAux , CartaAux2[0] ) ;

        CAR_CriarCarta( &(CartaAux2[1]) ) ;
        CAR_PreencheCarta( CartaAux2[1], 'c' , 12 );
        PIL_PushCarta( pilhaAux , CartaAux2[1] ) ;

        CAR_CriarCarta( &(CartaAux2[1]) ) ;
        CAR_PreencheCarta( CartaAux2[1], 'c' , 11 );
        PIL_PushCarta( pilhaAux , CartaAux2[1] ) ;

        CAR_CriarCarta( &(CartaAux2[1]) ) ;
        CAR_PreencheCarta( CartaAux2[1], 'c' , 10 );
        PIL_PushCarta( pilhaAux , CartaAux2[1] ) ;

        CondRetObtido = SEQJ_CriarSeqJogo ( &(vSeqJ[posVetorSeqJ]) , pilhaAux);

        PIL_DestroiPilha(pilhaAux);
        
        return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                               "Retorno errado ao criar a sequencia de jogo." );
       
    } /* fim ativa: Testar SEQJ Criar Sequência de jogo incompleta */
    
    /* Testar MON Destruir Monte */
    
    else if ( strcmp( ComandoTeste , DESTRUIR_SEQJ_CMD ) == 0 )
    {
        
        NumLidos = LER_LerParametros( "ii" ,&posVetorSeqJ,
                                     &CondRetEsperada ) ;
        if ( NumLidos != 1 )
        {
            return TST_CondRetParm ;
        } /* if */

        if (posVetorSeqJ > 2 || posVetorSeqJ < 0 )
        {
            return TST_CondRetParm ;
        }
        
        CondRetObtido = SEQJ_DestroiSequencia(vSeqJ[posVetorSeqJ]) ;
        
        return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                              "Retorno errado ao tentar destruir monte.") ;
        
    } /* fim ativa:  Testar MON Destruir monte*/
    
    return TST_CondRetNaoConhec ;
    
} /* Fim função: TMON Efetuar operações de teste específicas para monte */

/********** Fim do módulo de implementação: Módulo de teste específico **********/
