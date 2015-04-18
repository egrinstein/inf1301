#if ! defined( MON_ )
#define MON_
/***************************************************************************
 *
 *  $MCD Módulo de definição: MON Monte
 *
 *  Arquivo gerado:              MONTE.h
 *  Letras identificadoras:      MON
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
 *     1.0       EG,JM,LW        18/abr/2015       Início do desenvolvimento
 *     
 *  $ED Descrição do módulo
 *     Este módulo implementa funções para criar e manipular um Monte.
 *     Um Monte é uma pilha de 10 cartas.
 *     O monte é criado a partir de uma pilha de cartas.
 *     É possível retirar uma carta de cada vez do monte
 *     e nao pode colocar nenhuma carta no monte.
 *
 ***************************************************************************/

#if defined( MON_OWN )
    #define MON_EXT
#else
    #define MON_EXT extern
#endif

/***** Declarações exportadas pelo módulo *****/

/* Tipo referência para um monte */

typedef PIL_tppPilha MON_tppMonte ;

/***********************************************************************
 *
 *  $TC Tipo de dados: MON Condições de retorno
 *
 *
 *  $ED Descrição do tipo
 *     Condições de retorno das funções de Monte
 *
 ***********************************************************************/

    typedef enum {

        MON_CondRetOK ,
               /* Concluiu corretamente */

        MON_CondRetMonteVazio ,
               /* O monte não contém elementos */

        MON_CondRetFaltouMemoria
               /* Faltou memória ao tentar criar o monte */

   } MON_tpCondRet ;


/***********************************************************************
 *
 *  $FC Função: MON  Criar monte
 *
 *  $ED Descrição da função
 *     Cria um novo monte a partir de uma pilha.
 *
 *  $EP Parâmetros
 *     $P pMonte - ponteira para o monte a ser criado.
 *     $P pPilha - pilha a partir da qual o monte irá ser criado.
 *
 *  $FV Valor retornado
 *     MON_CondRetOk    -   criou ok.
 *     MON_CondRetFaltouMemoria -   faltou memória para alocar espaço para o monte.
 *
 ***********************************************************************/

MON_tpCondRet MON_CriarMonte ( MON_tppMonte * pMonte , PIL_tppPilha pPilha) ;


/***********************************************************************
 *
 *  $FC Função: CAR  Destruir monte
 *
 *  $ED Descrição da função
 *     Destroi um monte.
 *
 *  $EP Parâmetros
 *     $P pMonte - ponteiro para o monte a ser excluída.
 *
 *  $FV Valor retornado
 *     MON_CondRetOk    -   excluiu ok.
 *
 ***********************************************************************/

MON_tpCondRet MON_DestruirMonte ( MON_tppMonte pMonte ) ;


/***********************************************************************
*
*  $FC Função: MON Pop Carta
*
*  $ED Descrição da função
*     Remove carta do topo do monte
*     
*
*  $EP Parâmetros
*     pMonte - ponteiro para o monte.
*     pCarta - endereço que receberá a carta removida.
*              
*
*  $FV Valor retornado
*     MON_CondRetOk     -   pop com sucesso.
*     MON_CondRetMonteVazio     - monte vazio.
*
***********************************************************************/

MON_tpCondRet MON_PopCartaMonte ( MON_tppMonte pMonte, CAR_tppCarta * pCarta ) ;

#undef MON_EXT

/********** Fim do módulo de definição: MON Monte **********/

#else
#endif
