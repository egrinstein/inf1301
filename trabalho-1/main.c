#include "ARVORE.C"
#include <stdio.h>

int main( void )
{

	ARV_CriarArvore( ) ;

	ARV_InserirEsquerda( 'L' ) ;
	
	ARV_InserirEsquerda('J');

	ARV_InserirEsquerda('E');

	ARV_IrPai( );

	ARV_InserirDireita( 'r' );

	ARV_IrPai( );
	ARV_IrPai( );
	
	ARV_InserirDireita('o');

	ARV_InserirEsquerda('i');

	ARV_IrPai( );

	ARV_InserirDireita( 'c' );

	ARV_CosturaFolhas( ) ; 

	ARV_ImprimeCostura( );

	ARV_DestruirArvore( );

	return 0;
}
