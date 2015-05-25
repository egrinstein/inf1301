#include <stdio.h>
#include <stdlib.h>
#include "LISTA.H"
#include "BARALHO.H"
#include "CARTA.H"
#include "MONTE.H"
#include "PILHA_DE_CARTAS.H"
#include "SEQFIM.H"
#include "SEQJOGO.H"

#define TAM_NOME_ARQUIVO 20


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

void ExcluirLista( void * pLista )
{
    LIS_DestruirLista( (LIS_tppLista) pLista );
}

void ExcluirMonte( void * pMonte )
{
    LIS_DestruirLista( (LIS_tppLista) pMonte );
}

void ExcluirSeqJogo( void * pSeqJogo )
{
    LIS_DestruirLista( (LIS_tppLista) pSeqJogo );
}

void ExcluirSeqFim( void * pSeqFim )
{
    LIS_DestruirLista( (LIS_tppLista) pSeqFim);
}

void ExcluirBaralho( void * pBaralho )
{
    LIS_DestruirLista( (LIS_tppLista) pBaralho);
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
        printf("Numero de naipes inválido\n") ;

        printf( "Escolha o numero de naipes [1-4]:\n" ) ;
        scanf( "%d", &numNaipes ) ;
    }

    LIS_CriarLista( listaPrincipal , ExcluirLista ) ;


    LIS_CriarLista( &listaMonte , ExcluirMonte ) ;
    LIS_CriarLista( &listaBaralho , ExcluirBaralho ) ;
    LIS_CriarLista( &listaSeqJogo , ExcluirSeqJogo ) ;
    LIS_CriarLista( &listaSeqFim , ExcluirSeqFim ) ;

    LIS_InserirElementoAntes( * listaPrincipal , listaMonte ) ;
    LIS_InserirElementoAntes( * listaPrincipal , listaBaralho ) ;
    LIS_InserirElementoAntes( * listaPrincipal , listaSeqJogo ) ;
    LIS_InserirElementoAntes( * listaPrincipal , listaSeqFim ) ;

    BAR_CriarBaralho( &baralho ) ;
    BAR_PreencherBaralho ( baralho , numNaipes ) ;

    BAR_Embaralhar( baralho ) ;
    LIS_InserirElementoAntes( listaBaralho , baralho ) ;

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
	LIS_ObterValor( listaPrincipal , (void**)&ListaDeMontes ) ;

	LIS_IrFinalLista( listaPrincipal ) ;
	LIS_ObterValor( listaPrincipal , (void**)&ListaDeSeq );

	LIS_IrFinalLista( ListaDeMontes ) ;
	LIS_ObterValor( ListaDeMontes , (void**)&monte ) ;

	LIS_IrInicioLista( ListaDeSeq ) ;
	LIS_ObterValor( ListaDeSeq , (void**)&SeqAtual );

	for( i = 0 ; i < 10 ; i++ )
	{
		MON_PopCartaMonte ( monte, &cartaAux ) ;
		SEQJ_PushCartaSequencia( SeqAtual , cartaAux ) ;
		LIS_AvancarElementoCorrente( ListaDeSeq, 1 ) ;
		LIS_ObterValor( ListaDeSeq , (void**)SeqAtual) ;
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
    
    LIS_IrFinalLista( ListaDeSeq ) ;
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
			verSeq = verificaCartasConsecutivas(cartaAux, cartaAnt);
			if( verSeq != 2 )
			{
				while( PIL_PopCarta( pilhaAux, &cartaAux) == 0 )
				{
					SEQJ_PushCartaSequencia( SeqOrigem , cartaAux ) ;
				}
				return 0; //Temos que colocar aviso ao usuário
			}
		}
		cartaAnt = cartaAux ;
    }

	Ret = SEQJ_PopCartaSequencia( SeqDestino, &cartaAnt ) ;

	verSeq = 2 ;
	if( Ret != 1 )
	{
		verSeq = verificaCartasConsecutivas(cartaAux, cartaAnt );
		SEQJ_PushCartaSequencia( SeqDestino, cartaAnt ) ;
	}

	if( verSeq > 0 )
	{
		for( i = 0 ; i < NumCartas ; i++ )
		{
			PIL_PopCarta( pilhaAux , &cartaAux ) ;

			SEQJ_PushCartaSequencia( SeqDestino , cartaAux ) ;
		}
	}
	else
	{
		PIL_PopCarta( pilhaAux , &cartaAux ) ;
		SEQJ_PushCartaSequencia( SeqOrigem , cartaAux ) ;
		return 0 ;
	}

	return 1 ;
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
    if( opcaoEscolhida == 1 )
    {
        printf( "Digite o nome do arquivo a ser carregado:\n" ) ;
        scanf( "%s", arquivoSalvo ) ;
        //carregaJogoSalvo( arquivoSalvo ) ;
    }
    else
    {
        novoJogo( &listaPrincipal ) ;
    }


	printf("'t' para transferir cartas da sequencia 'm' para transferir cartas do monte ou 's' para salvar o jogo\n");
    scanf(" %c",&caracterLido);

	while( caracterLido != 's' )
	{
		if( caracterLido == 'm' )
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
		if( caracterLido == 't' )
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
		printf("'m' para mover cartas ou 's' para salvar o jogo\n") ;
		scanf(" %c",&caracterLido);
	}

	return 0 ;
}