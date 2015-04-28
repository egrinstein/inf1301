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
 *                   Irá criar uma sequência de jogo com uma carta K de copas.
 *                   O parametro indica a posicao de um vetor, onde cabem 3 
 *                   sequências de jogo para os testes.
 *
       =criarCompleta <int>
                     - chama a função SEQJ_CriarSeqJogo.
                     Irá criar um sequência de jogo com 13 cartas de Ás a K de espadas.
                     O parametro indica a posicao de um vetor, onde cabem 3 
 *                   sequências de jogo para os testes.
 * 
       =destruir <int>
                     - chama a função SEQJ_DestroiSequencia. O parametro indica a posicao
                     de um vetor, onde cabem 3 sequências de jogo para os testes.
                     
                     
       =pushCarta <char> <char> <int>
                     -
                     
       =popCarta  <char> <char> <int>
                     -
                     
       =obterPilha <int>
                     -
                     
       =verificarCompleta <int>
 *                    - chama a função MON_PopCartaMonte.
 *                    Onde o parâmetro se refere ao valor do naipe
 *                    e o valor da carta fornecida pelo usuário.
 *                    Esses valores serão testados.
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

#define     CRIARINCOMPLETA_SEQJ_CMD  "=criarIncompleta"
#define     CRIARCOMPLETA_SEQJ_CMD  "=criarCompleta"
#define     DESTRUIR_SEQJ_CMD       "=destruir"
#define     PUSH_SEQJ_CMD           "=pushCarta"
#define     POP_SEQJ_CMD           "=popCarta"
#define     OBTER_SEQJ_CMD          "=obterPilha"
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
   int posVetorSeqJ2  = -1  ;
   int numCartasMover = -1 ;
   int i = 0;

    PIL_tppPilha pilhaAux;
    CAR_tppCarta cartaDada;
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

        PIL_DestruirPilha(pilhaAux);
        
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

        CondRetObtido = SEQJ_CriarSeqJogo ( &(vSeqJ[posVetorSeqJ]) , pilhaAux);

        PIL_DestruirPilha(pilhaAux);
        
        return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                               "Retorno errado ao criar a sequencia de jogo." );
       
    } /* fim ativa: Testar SEQJ Criar Sequência de jogo incompleta */
    
    /* Testar SEQJ Destruir Sequência de jogo */
    
    else if ( strcmp( ComandoTeste , DESTRUIR_SEQJ_CMD ) == 0 )
    {
        
        NumLidos = LER_LerParametros( "ii" ,&posVetorSeqJ,
                                     &CondRetEsperada ) ;
        if ( NumLidos != 2 )
        {
            return TST_CondRetParm ;
        } /* if */

        if (posVetorSeqJ > 2 || posVetorSeqJ < 0 )
        {
            return TST_CondRetParm ;
        }
        
        CondRetObtido = SEQJ_DestroiSequencia(vSeqJ[posVetorSeqJ]) ;
        
        return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                              "Retorno errado ao tentar destruir a sequencia.") ;
        
    } /* fim ativa:  Testar SEQJ Destruir Sequência de jogo*/

    /* Testar SEQJ Push carta Sequencia*/

    else if ( strcmp( ComandoTeste , PUSH_SEQJ_CMD ) == 0 )
    {
        
        NumLidos = LER_LerParametros( "ciii" ,&NaipeEsperado, &ValorEsperado,&posVetorSeqJ,
                                     &CondRetEsperada ) ;
        if ( NumLidos != 4 )
        {
            return TST_CondRetParm ;
        } /* if */

        if (posVetorSeqJ > 2 || posVetorSeqJ < 0 )
        {
            return TST_CondRetParm ;
        }
        
        CAR_CriarCarta( &cartaDada );
        CAR_PreencheCarta(cartaDada, NaipeEsperado, ValorEsperado) ;

        CondRetObtido = SEQJ_PushCartaSequencia(vSeqJ[posVetorSeqJ], cartaDada ) ;
        
        return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                              "Retorno errado ao dar push na sequencia.") ;
        
    } /* fim ativa:  Testar SEQJ Push carta Sequencia*/

    /* Testar SEQJ Pop carta Sequencia*/

    else if ( strcmp( ComandoTeste , POP_SEQJ_CMD ) == 0 )
    {
        
        NumLidos = LER_LerParametros( "ciii" ,&NaipeEsperado, &ValorEsperado,&posVetorSeqJ,
                                     &CondRetEsperada ) ;
        if ( NumLidos != 4 )
        {
            return TST_CondRetParm ;
        } /* if */

        if (posVetorSeqJ > 2 || posVetorSeqJ < 0 )
        {
            return TST_CondRetParm ;
        }
        CondRetObtido = SEQJ_PopCartaSequencia(vSeqJ[posVetorSeqJ],&cartaDada);
        
        Ret =  TST_CompararInt( CondRetEsperada , CondRetObtido ,
                               "Retorno errado ao dar pop na sequencia." );

        if ( Ret != TST_CondRetOK )
            {
               return Ret ;
            } /* if */

         if ( CondRetObtido != PIL_CondRetOK )
            {
               return CondRetObtido ;
            } /* if */

         CAR_ObterNaipe( cartaDada , &NaipeObtido );
            Ret = TST_CompararInt( NaipeEsperado , NaipeObtido ,
                                    "Carta obtida está errada." );

         if ( Ret != TST_CondRetOK )
            {
               return Ret ;
            } /* if */

         CAR_ObterValor( cartaDada , &ValorObtido );
            return TST_CompararInt( ValorEsperado , ValorObtido ,
                                    "Carta obtida está errada." );

        
    } /* fim ativa:  Testar SEQJ Pop carta Sequencia*/

     /* Testar SEQJ Obtem pilha da sequência de jogo*/

    else if ( strcmp( ComandoTeste , OBTER_SEQJ_CMD ) == 0 )
    {
        
        NumLidos = LER_LerParametros( "ii" ,&posVetorSeqJ,
                                     &CondRetEsperada ) ;
        if ( NumLidos != 2 )
        {
            return TST_CondRetParm ;
        } /* if */

        if (posVetorSeqJ > 2 || posVetorSeqJ < 0 )
        {
            return TST_CondRetParm ;
        }


        CondRetObtido = SEQJ_ObtemPilhaSeqJ(vSeqJ[posVetorSeqJ], &pilhaAux ) ;
        //PIL_DestruirPilha(pilhaAux);

        return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                              "Retorno errado ao obter pilha.") ;
        
    } /* fim ativa:  Testar SEQJ Obtem pilha da sequência de jogo*/

    /* Testar SEQJ Verifica sequência completa */

    else if ( strcmp( ComandoTeste ,  VERIFICAR_SEQJ_CMD ) == 0 )
    {
        
        NumLidos = LER_LerParametros( "ii" ,&posVetorSeqJ,
                                     &CondRetEsperada ) ;
        if ( NumLidos != 2 )
        {
            return TST_CondRetParm ;
        } /* if */

        if (posVetorSeqJ > 2 || posVetorSeqJ < 0 )
        {
            return TST_CondRetParm ;
        }


        CondRetObtido = SEQJ_VerificaSeqCompleta( vSeqJ[posVetorSeqJ] ) ;
        
        return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                              "Retorno errado ao verificar se pilha completa.") ;
        
    } /* fim ativa:  Testar SEQJ Verifica sequência completa */

    return TST_CondRetNaoConhec ;
    
} /* Fim função: TSEQJ Efetuar operações de teste específicas para sequência de jogo  */

/********** Fim do módulo de implementação: Módulo de teste específico **********/
