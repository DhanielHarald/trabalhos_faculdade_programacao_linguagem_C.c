#include <stdio.h>

// Recursão simples para a Torre
void movimentaTorre(int passo, int total, char direcao[]) {
    if (passo > total) return; // condição de parada
    printf("Passo %d: Torre -> %s\n", passo, direcao);
    movimentaTorre(passo + 1, total, direcao);
}

// Recursão simples para a Rainha
void movimentaRainha(int passo, int total, char direcao[]) {
    if (passo > total) return;
    printf("Passo %d: Rainha -> %s\n", passo, direcao);
    movimentaRainha(passo + 1, total, direcao);
}

// Bispo: recursão com loops aninhados (vertical + horizontal)
void movimentaBispo(int passo, int total, char vertical[], char horizontal[]) {
    if (passo > total) return;

    for (int v = 0; v < 1; v++) {       // vertical
        for (int h = 0; h < 1; h++) {   // horizontal
            printf("Passo %d: Bispo -> %s %s\n", passo, vertical, horizontal);
        }
    }

    movimentaBispo(passo + 1, total, vertical, horizontal);
}

// Cavalo: loops aninhados simples, "L" para cima e direita
void movimentaCavalo(int casasCima, int casasDireita) {
    int passo = 1;
    for (int i = 1; i <= casasCima; i++) {
        printf("Passo %d: Cima\n", passo++);
        if (i == casasCima) {
            for (int j = 1; j <= casasDireita; j++) {
                printf("Passo %d: Direita\n", passo++);
            }
        }
    }
}

int main() {
    int movimentoTorre = 5, movimentoBispo = 5, movimentoRainha = 8;
    char direcaoTorre[] = "Direita";
    char direcaoRainha[] = "Esquerda";
    char direcaoBispoVertical[] = "Cima";
    char direcaoBispoHorizontal[] = "Direita";

    // No xadrez, a torre se move em linha reta horizontal ou verticalmente 
    printf("==== Movimento Torre ====\n");
    movimentaTorre(1, movimentoTorre, direcaoTorre);

    // No xadez, o bispo se move na diagonal 
    printf("\n==== Movimento Bispo ====\n");
    movimentaBispo(1, movimentoBispo, direcaoBispoVertical, direcaoBispoHorizontal);

    // No xadez, a rainha se move em qualquer direção 
    printf("\n==== Movimento Rainha ====\n");
    movimentaRainha(1, movimentoRainha, direcaoRainha);

    // No xadrez, o cavalo se move duas casas em uma direção (horizontal ou vertical) e depois uma casa perpendicularmente
    printf("\n==== Movimento Cavalo ====\n");
    movimentaCavalo(2, 1);

    return 0;
}
