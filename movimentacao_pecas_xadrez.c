#include <stdio.h>

int main()
{
    //Variáveis
    int movimentoTorre = 5, movimentoBispo = 5, movimentoRainha = 8;
    char direcaoTorre[] = "Direita",  direcaoRainha[] = "Esquerda";
    char direcaoBispo1[] = "Cima", direcaoBispo2[] = "Direita";
    
    int contador;
    
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
    No xadez, a rainha se movem em qualquer direção */
    printf("\n\n==== Movimento Rainha: ====\n");
    contador = 1;
    
    for (contador = 1; contador <= movimentoRainha; contador++){
        printf("\nPasso %d: Rainha -> %s\n", contador, direcaoRainha);
        
    }
    
    printf("\n**********************************");
    
    return 0;
}

