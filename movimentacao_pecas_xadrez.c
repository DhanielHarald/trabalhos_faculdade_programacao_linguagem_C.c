#include <stdio.h>

int main()
{
    //Declaração de variáveis para movimentação da Torre, Bispo e Rainha
    int movimentoTorre = 5, movimentoBispo = 5, movimentoRainha = 8;
    char direcaoTorre[] = "Direita",  direcaoRainha[] = "Esquerda";
    char direcaoBispo1[] = "Cima", direcaoBispo2[] = "Direita";
    
    // Declaração de variáveis para movimentação do Cavalo
    int casasBaixo = 2;
    int casasEsquerda = 1;
    int contador, i;
    int passo = 1; // atualização da numeração dos movimentos
    
    /* Movimentação da Torre: estrutura while
    No xadrez, a torre se move em linha reta horizontal ou verticalmente */
    printf("==== Movimento Torre: ====\n");
    contador = 1; // resetar o contador
    
    while (contador <= movimentoTorre) {
        printf("\nPasso %d: Torre -> %s\n", contador, direcaoTorre);
        contador++;
    }
    
    printf("\n**********************************");
    
    /* Movimentação do Bispo: estrutura do...while
    No xadez, o bispo se move na diagonal */
    printf("\n\n==== Movimento Bispo: ====\n");
    contador = 1; // resetar o contador
    
    do {
            printf("\nPasso %d: Bispo -> %s %s\n", contador, direcaoBispo1, direcaoBispo2);
            contador++;
            
    } while (contador <= movimentoBispo);
    
    printf("\n**********************************");
    
    /* Movimentação da Rainha: estrutura for
    No xadez, a rainha se move em qualquer direção */
    printf("\n\n==== Movimento Rainha: ====\n");
    contador = 1;
    
    for (contador = 1; contador <= movimentoRainha; contador++){
        printf("\nPasso %d: Rainha -> %s\n", contador, direcaoRainha);
        
    }
    
    printf("\n**********************************");
    
    /* Movimentação do Cavalo: estruturas for e while
    No xadrez, o cavalo se move duas casas em uma direção (horizontal ou vertical) e depois uma casa perpendicularmente */
    printf("\n\n==== Movimento Cavalo: ====\n");
    
    // Movimento para baixo
    for (contador = 1; contador <= casasBaixo; contador++) {
        printf("Passo %d: Baixo\n", passo);
        passo++;
        
        // Na última casa para baixo, faz o movimento para a esquerda usando while
        if (contador == casasBaixo) {
            i = 1;
            while (i <= casasEsquerda) {
                printf("Passo %d: Esquerda\n", passo);
                passo++;
                i++;
            }
        }
    }
    
     printf("\n**********************************");
    
    return 0;
}

