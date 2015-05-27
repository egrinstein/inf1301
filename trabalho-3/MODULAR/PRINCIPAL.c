#include <stdio.h>
#include <stdlib.h>
#include "LISTA.h"
#include "BARALHO.h"
#include "CARTA.h"
#include "MONTE.h"
#include "PILHA_DE_CARTAS.h"
#include "SEQFIM.h"
#include "SEQJOGO.h"

#define TAM_NOME_ARQUIVO 20
#define TAM_X 30
#define TAM_Y 104


//int carregaJogoSalvo ( char arquivoSalvo[] )
//{
//
//}



void CriaPilha( PIL_tppPilha *pilha , BAR_tppBaralho baralho , int numCartas )
{
    CAR_tppCarta carta ;
    int i ;
    PIL_CriarPilhaVazia( pilha ) ;
    for( i=0 ; i<numCartas ; i++)
    {
        BAR_PopCarta( baralho , &carta ) ;
        PIL_PushCarta( *pilha , carta ) ;
    }
}

void CriarMontes( MON_tppMonte monte[] , BAR_tppBaralho baralho )
{
    int i;
    PIL_tppPilha pilhasAux[5];
    
    for( i = 0 ; i < 5 ; i++ )
    {
        CriaPilha( &pilhasAux[i] , baralho, 10 );
        MON_CriarMonte( &monte[i] , pilhasAux[i] );
        PIL_DestruirPilha(pilhasAux[i]) ;
    }
    
    
}

void CriarSeqsJogo( SEQJ_tppSeqJ seqsJogo[] ,BAR_tppBaralho baralho )
{
    int i;
    int numCartas;
    PIL_tppPilha pilhasAux[10];
    
    for( i = 0 ; i < 10 ; i++ )
    {
        if ( i < 4 ) numCartas = 6;
        else numCartas = 5;
        
        CriaPilha( &pilhasAux[i] , baralho, numCartas );
        SEQJ_CriarSeqJogo( &seqsJogo[i] , pilhasAux[i] );
        PIL_DestruirPilha(pilhasAux[i]) ;
    }
    
    
}

void CriarSeqsFinais( SEQFIM_tppSeqFim seqsFinais[] )
{
    int i ;
    
    for( i = 0 ; i < 5 ; i++ )
    {
        SEQFIM_CriarSeqFim( &seqsFinais[i] );
    }
    
}



void ExcluirLista( void * pLista )
{
    LIS_DestruirLista( (LIS_tppLista) pLista );
}

void ExcluirMonte( void * pMonte )
{
    MON_DestruirMonte( (MON_tppMonte) pMonte );
}

void ExcluirSeqJogo( void * pSeqJogo )
{
    SEQJ_DestroiSequencia( (SEQJ_tppSeqJ) pSeqJogo );
}

void ExcluirSeqFim( void * pSeqFim )
{
    SEQFIM_DestroiSeqFim( (SEQFIM_tppSeqFim) pSeqFim );
}

void ExcluirBaralho( void * pBaralho )
{
    BAR_DestruirBaralho( (BAR_tppBaralho) pBaralho);
}



int novoJogo ( LIS_tppLista * listaPrincipal)
{
    int numNaipes ;
    int i ;
    LIS_tppLista listaMonte = NULL;
    LIS_tppLista listaBaralho = NULL;
    LIS_tppLista listaSeqJogo = NULL;
    LIS_tppLista listaSeqFim = NULL;
    BAR_tppBaralho baralho = NULL;
    MON_tppMonte montes[5] ;
    SEQJ_tppSeqJ seqsJogo[10] ;
    SEQFIM_tppSeqFim seqsFinais[8] ;
    CAR_tppCarta carta;
    
    printf( "Escolha o numero de naipes [1-4]:\n" ) ;
    scanf( "%d", &numNaipes ) ;
    while( numNaipes < 1 || numNaipes > 4 )
    {
        printf("Numero de naipes invalido\n") ;
        
        printf( "Escolha o numero de naipes [1-4]:\n" ) ;
        scanf( "%d", &numNaipes ) ;
    }
    
    LIS_CriarLista( listaPrincipal , ExcluirLista ) ;
    
    
    LIS_CriarLista( &listaMonte , ExcluirMonte ) ;
    LIS_CriarLista( &listaBaralho , ExcluirBaralho ) ;
    LIS_CriarLista( &listaSeqJogo , ExcluirSeqJogo ) ;
    LIS_CriarLista( &listaSeqFim , ExcluirSeqFim ) ;
    
    LIS_InserirElementoApos( * listaPrincipal , listaBaralho ) ;
    LIS_InserirElementoApos( * listaPrincipal , listaMonte ) ;
    LIS_InserirElementoApos( * listaPrincipal , listaSeqJogo ) ;
    LIS_InserirElementoApos( * listaPrincipal , listaSeqFim ) ;
    
    
    BAR_CriarBaralho( &baralho ) ;
    BAR_PreencherBaralho ( baralho , numNaipes ) ;
    
    BAR_Embaralhar( baralho ) ;
    LIS_InserirElementoApos( listaBaralho , baralho ) ;
    
    CriarMontes( montes , baralho ) ;
    for (i=0 ; i < 5 ; i++)
    {
        LIS_InserirElementoAntes( listaMonte , montes[i] ) ;
    }
    
    
    CriarSeqsJogo( seqsJogo, baralho ) ;
    for (i=0 ; i < 10 ; i++)
    {
        LIS_InserirElementoAntes( listaSeqJogo , seqsJogo[i] ) ;
    }
    
    
    CriarSeqsFinais( seqsFinais ) ;
    for (i=0 ; i < 4 ; i++)
    {
        LIS_InserirElementoAntes( listaSeqFim , seqsFinais[i] ) ;
    }
    
    return 1;
}

int CapturaOpcao(int *SeqOrigem, int *SeqDestino, int *NumCartas)
{
    
    printf("Escolha a pilha origem (0-9), destino (0-9) e o numero de cartas\n");
    scanf("%d %d %d", SeqOrigem, SeqDestino, NumCartas);
    
    if( *SeqOrigem < 0 || *SeqOrigem > 9 )
    {
        return -1;
    }
    
    if (*SeqDestino < 0 || *SeqDestino > 9 )
    {
        return -1;
    }
    
    if (*NumCartas < 1 || *NumCartas > 12 )
    {
        return -1;
    }
    
    return 0;
    
}

int verificaCartasConsecutivas( CAR_tppCarta carta , CAR_tppCarta cartaAnt )
{
    int valorCarta ;
    int valorCartaAnt ;
    char naipeCarta ;
    char naipeCartaAnt ;
    
    CAR_ObterValor( carta, &valorCarta );
    CAR_ObterNaipe( carta, &naipeCarta );
    
    CAR_ObterValor( cartaAnt, &valorCartaAnt );
    CAR_ObterNaipe( cartaAnt, &naipeCartaAnt );
    
    if( valorCarta == (valorCartaAnt+1))
    {
        if( naipeCarta == naipeCartaAnt)
            return 2 ;
        else
            return 1;
    }
    return 0 ;
}

void tratarMoveMonte( LIS_tppLista listaPrincipal )
{
    int i ;
    LIS_tppLista ListaDeMontes ;
    MON_tppMonte monte ;
    CAR_tppCarta cartaAux ;
    LIS_tppLista ListaDeSeq ;
    SEQJ_tppSeqJ SeqAtual ;
    
    LIS_IrInicioLista( listaPrincipal ) ;
    LIS_AvancarElementoCorrente( listaPrincipal , 1 ) ; /* a lista de montes é o segundo
                                                         elemento da lista principal*/
    LIS_ObterValor( listaPrincipal , ( void **)&ListaDeMontes ) ;
    
    LIS_IrInicioLista( listaPrincipal ) ;
    LIS_AvancarElementoCorrente( listaPrincipal , 2 ) ; /* a lista de sequencias de jogo é o 3ª
                                                         elemento da lista principal*/
    LIS_ObterValor( listaPrincipal , ( void **)&ListaDeSeq );
    
    LIS_IrFinalLista( ListaDeMontes ) ;
    LIS_ObterValor( ListaDeMontes , ( void **)&monte ) ;
    
    LIS_IrInicioLista( ListaDeSeq ) ;
    LIS_ObterValor( ListaDeSeq , ( void **)&SeqAtual );
    
    
    for( i = 0 ; i < 10 ; i++ )
    {
        SEQJ_ViraCarta(SeqAtual, 1);
        MON_PopCartaMonte ( monte, &cartaAux ) ;
        SEQJ_PushCartaSequencia( SeqAtual , cartaAux , 0) ;
        LIS_AvancarElementoCorrente( ListaDeSeq, 1 ) ;
        LIS_ObterValor( ListaDeSeq , ( void** )&SeqAtual) ;

    }
    
    
    LIS_ExcluirElemento( ListaDeMontes ) ;
}

int tratarMoveSequencia(LIS_tppLista listaPrincipal, int NumSeqOrigem, int NumSeqDestino, int NumCartas)
{
    int i = 0 ;
    int verSeq ;
    CAR_tppCarta cartaAux ;
    CAR_tppCarta cartaAnt ;
    
    SEQJ_tpCondRet Ret ;
    
    PIL_tppPilha pilhaAux ;
    
    LIS_tppLista ListaDeSeq ;
    SEQJ_tppSeqJ SeqOrigem ;
    SEQJ_tppSeqJ SeqDestino ;
    
    PIL_CriarPilhaVazia( &pilhaAux );
    
    LIS_IrInicioLista( listaPrincipal ) ;
    LIS_AvancarElementoCorrente( listaPrincipal , 2 ) ;
    LIS_ObterValor(listaPrincipal, (void**)&ListaDeSeq) ;
    
    LIS_IrInicioLista( ListaDeSeq ) ;
    LIS_AvancarElementoCorrente( ListaDeSeq , NumSeqOrigem ) ;
    LIS_ObterValor( ListaDeSeq, (void**)&SeqOrigem ) ;
    
    LIS_IrInicioLista( ListaDeSeq ) ;
    LIS_AvancarElementoCorrente( ListaDeSeq , NumSeqDestino ) ;
    LIS_ObterValor( ListaDeSeq, (void**)&SeqDestino ) ;
    
    for( i = 0 ; i < NumCartas ; i++ )
    {
        //Depois teremos que tratar o retorno, pois pode chegar ao ponto da carta estar virada para baixo
        SEQJ_PopCartaSequencia( SeqOrigem, &cartaAux ) ;
        
        PIL_PushCarta( pilhaAux , cartaAux ) ;
        
        if(i > 0)
        {
            verSeq = verificaCartasConsecutivas(cartaAux, cartaAnt); // ver
            if( verSeq != 2 )
            {
                while( PIL_PopCarta( pilhaAux, &cartaAux) == 0 )
                {
                    SEQJ_PushCartaSequencia( SeqOrigem , cartaAux , 0 ) ;
                }
                return 0; //Temos que colocar aviso ao usuário
            }
        }
        cartaAnt = cartaAux ;
    }
    
    Ret = SEQJ_PopCartaSequencia( SeqDestino, &cartaAnt ) ;
    
    verSeq = 2 ;
    if( Ret != 1 ) // nao entra se seq vazia
    {
        verSeq = verificaCartasConsecutivas(cartaAnt, cartaAux );
        SEQJ_PushCartaSequencia( SeqDestino, cartaAnt , 0) ;
    }
    
    if( verSeq > 0 )
    {
        for( i = 0 ; i < NumCartas ; i++ )
        {
            PIL_PopCarta( pilhaAux , &cartaAux ) ;
            
            SEQJ_PushCartaSequencia( SeqDestino , cartaAux , 0) ;
        }
        SEQJ_ViraCarta(SeqDestino, NumCartas);
        SEQJ_ViraCarta(SeqOrigem, -NumCartas);
        SEQJ_NumCartasViradas(SeqOrigem, &i);
        if ( i == 0 )
        {
            SEQJ_ViraCarta(SeqOrigem, 1);
        }
    }
    else
    {
        for( i = 0 ; i < NumCartas ; i++ )
        {
            PIL_PopCarta( pilhaAux , &cartaAux ) ;
            SEQJ_PushCartaSequencia( SeqOrigem , cartaAux , 0) ;
        }
        return 0 ;
    }
    
    return 1 ;
}

void clearScreen(void)
{
}

void zeraMatriz( CAR_tppCarta matriz[][6] )
{
    int i, j;
    CAR_tppCarta cartaAux;
    
    CAR_CriarCarta( &cartaAux );
    
    for(i=0;i<10;i++)
    {
        for(j=0;j<6;j++)
        {
            matriz[i][j] = cartaAux ;
        }
    }
    
}
void zeraMatriz2( CAR_tppCarta matriz[][10] )
{
    int i, j;
    CAR_tppCarta cartaAux;
    
    CAR_CriarCarta( &cartaAux );
    
    for(i=0;i<6;i++)
    {
        for(j=0;j<10;j++)
        {
            matriz[i][j] = cartaAux ;
        }
    }
    
}

void imprimeJogo(LIS_tppLista listaPrincipal)
{
    int i = 0, j = 0, k =0, z=0;
    
    LIS_tppLista listaSeqJogo;
    LIS_tppLista listaAux;
    SEQJ_tppSeqJ seqJogoAux;
    PIL_tppPilha pilhaAux;
    PIL_tppPilha pilhaAux2;
    CAR_tppCarta cartaAux;
    CAR_tppCarta matrizDisplay[10][6];
    CAR_tppCarta matrizNova[6][10];
    CAR_tpCondRet ret;
    SEQJ_tpCondRet retSeqJogo;
    int numCartasViradas;
    int valor;
    char naipe;
    
    LIS_IrInicioLista( listaPrincipal ) ;
    LIS_AvancarElementoCorrente( listaPrincipal , 2 ) ; /* a lista de sequencias de jogo é o 3ª
                                                         elemento da lista principal*/
    LIS_ObterValor( listaPrincipal , ( void **)&listaSeqJogo );
    
    PIL_CriarPilhaVazia( &pilhaAux );
    PIL_CriarPilhaVazia( &pilhaAux2 );
    SEQJ_CriarSeqJogo( &seqJogoAux, pilhaAux );
    
    LIS_IrInicioLista( listaSeqJogo );
    LIS_ObterValor( listaSeqJogo , (void **)&seqJogoAux);
    
    for(i=0;i<10;i++)
    {
        SEQJ_NumCartasViradas( seqJogoAux , &numCartasViradas );
        j = totalCartasNaSeq( seqJogoAux );
        k = j - numCartasViradas;
        while (SEQJ_PopCartaSequencia(seqJogoAux, &cartaAux) == 0) {
            PIL_PushCarta(pilhaAux, cartaAux);
            while(PIL_PopCarta(pilhaAux, &cartaAux) == 0)
            {
                PIL_PushCarta(pilhaAux2, cartaAux);
            }
            
        }
        while(PIL_PopCarta(pilhaAux2, &cartaAux) == 0)
        {
            if( k > 0 )
            {
                printf("* ");
                k--;
            }
            else
            {
                CAR_ImprimeCarta(cartaAux);
            }
            PIL_PushCarta(pilhaAux, cartaAux);
            while (PIL_PopCarta(pilhaAux, &cartaAux)==0) {
            SEQJ_PushCartaSequencia(seqJogoAux, cartaAux, 0);
            }
        }
        printf("\n");
        LIS_AvancarElementoCorrente(listaSeqJogo, 1);
        LIS_ObterValor( listaSeqJogo , (void**)&seqJogoAux);
    }
    //	zeraMatriz( matrizDisplay );
    //	zeraMatriz2(matrizNova);
    //
    //	for(i=0;i<10;i++)
    //	{
    //		retSeqJogo = SEQJ_PopCartaSequencia( seqJogoAux , &cartaAux );
    //		if(retSeqJogo == 0)
    //			PIL_PushCarta( pilhaAux, cartaAux );
    //		j=0;
    //		while( retSeqJogo == 0 && j < 6)
    //		{
    //			matrizDisplay[i][j] = cartaAux;
    //			CAR_ImprimeCarta( matrizDisplay[i][j] );
    //			retSeqJogo = SEQJ_PopCartaSequencia( seqJogoAux , &cartaAux );
    //			if(retSeqJogo == 0)
    //				PIL_PushCarta( pilhaAux, cartaAux );
    //			j++;
    //		}
    //		printf("\n");
    //		while( PIL_PopCarta( pilhaAux, &cartaAux ) == 0 )
    //		{
    //			SEQJ_PushCartaSequencia( seqJogoAux , cartaAux , 0 );
    //		}
    //		LIS_AvancarElementoCorrente( listaSeqJogo , 1 );
    //		LIS_ObterValor( listaSeqJogo , (void **)&seqJogoAux);
    //	}
    //
    //	for( i = 0; i<10 ; i++)
    //	{
    //		for (j=0;j<6;j++)
    //		{
    //			matrizNova[j][i] = matrizDisplay[i][j];
    //			CAR_ImprimeCarta( matrizNova[j][i] );
    //		}
    //		printf("\n");
    //	}
    
    /*for(i=0;i<10;i++)
     {
     j=0;
     while( j<6 )
     {
     ret = CAR_ImprimeCarta( matrizDisplay[i][j] );
     if(ret != 0)
     {
     printf("  ");
     }
     j++;
     }
     printf("\n");
     }*/
    
}
int main (void)
{
    char arquivoSalvo[TAM_NOME_ARQUIVO] ;
    char opcaoEscolhida ;
    char caracterLido ;
    int SeqOrigem, SeqDestino, NumCartas;
    int retMoveSeq ;
    int retMoveMonte ;
    int numMontes = 5;
    LIS_tppLista listaPrincipal = NULL;
    
    printf( "Bem vindo ao paciencia spider.\n" ) ;
    printf( "Digite c para carregar um jogo salvou ou n para iniciar um novo jogo:\n" ) ;
    scanf(" %c", &opcaoEscolhida) ;
    while((opcaoEscolhida != 'c') && (opcaoEscolhida != 'n'))
    {
        printf( "Digite c para carregar um jogo salvou ou n para iniciar um novo jogo:\n" ) ;
        scanf(" %c", &opcaoEscolhida);
    }
    if( opcaoEscolhida == 'c' )
    {
        printf( "Digite o nome do arquivo a ser carregado:\n" ) ;
        scanf( "%s", arquivoSalvo ) ;
        //carregaJogoSalvo( arquivoSalvo ) ;
    }
    else
    {
        novoJogo( &listaPrincipal ) ;
    }
    clearScreen();
    imprimeJogo( listaPrincipal );
    
    printf("'t' para transferir cartas da sequencia 'm' para transferir cartas do monte ou 's' para salvar o jogo\n");
    scanf(" %c",&caracterLido);
    
    while( caracterLido != 's' )
    {
        clearScreen();
        if( caracterLido == 't' )
        {
            if(CapturaOpcao(&SeqOrigem, &SeqDestino, &NumCartas) == 0)
            {
                retMoveSeq = tratarMoveSequencia(listaPrincipal, SeqOrigem, SeqDestino, NumCartas);
                
            } /* if */
            else
            {
                printf("Erro de leitura\n");
            }
        }
        
        if( caracterLido == 'm' )
        {
            if(numMontes > 0)
            {
                tratarMoveMonte( listaPrincipal ) ;
                numMontes--;
            }
            else
            {
                printf("Nao existem mais montes para mover\n") ;
            }
            
        }
        imprimeJogo( listaPrincipal );
        printf("'t' para transferir cartas da sequencia 'm' para transferir cartas do monte ou 's' para salvar o jogo\n") ;
        scanf(" %c",&caracterLido);
    }
    
    return 0 ;
}


