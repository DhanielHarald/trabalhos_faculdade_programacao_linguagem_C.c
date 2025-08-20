#include <stdio.h>

int main() {
    int tabuleiro[10][10]; // Tabuleiro 10x10
    int i, j;

    // Inicializa tabuleiro com 0 (água)
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posiciona navios (tamanho 3)
    // Horizontal
    for(i = 0; i < 3; i++) {
        tabuleiro[1][1 + i] = 3;
    }
    // Vertical
    for(i = 0; i < 3; i++) {
        tabuleiro[3 + i][5] = 3;
    }
    // Diagonal principal
    for(i = 0; i < 3; i++) {
        tabuleiro[6 + i][2 + i] = 3;
    }
    // Diagonal secundária
    for(i = 0; i < 3; i++) {
        tabuleiro[i][9 - i] = 3;
    }

    // Cria matrizes de habilidades 5x5
    int cone[5][5], cruz[5][5], octaedro[5][5];
    int meio = 2; // posição central (5/2)

    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            // Cone: forma de triângulo apontando para baixo
            if(j >= meio - i && j <= meio + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;

            // Cruz: linhas e colunas centrais
            if(i == meio || j == meio)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;

            // Octaedro: forma de losango
            int limite = (i < meio) ? i : 4 - i;
            if(j >= meio - limite && j <= meio + limite)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // Aplicar habilidades no tabuleiro
    // Definindo pontos de origem
    int origemConeL = 2, origemConeC = 7;
    int origemCruzL = 7, origemCruzC = 3;
    int origemOctaL = 5, origemOctaC = 5;

    // Aplicar cone
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            int lin = origemConeL - meio + i;
            int col = origemConeC - meio + j;
            if(lin >= 0 && lin < 10 && col >= 0 && col < 10) {
                if(cone[i][j] == 1 && tabuleiro[lin][col] == 0)
                    tabuleiro[lin][col] = 5;
            }
        }
    }

    // Aplicar cruz
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            int lin = origemCruzL - meio + i;
            int col = origemCruzC - meio + j;
            if(lin >= 0 && lin < 10 && col >= 0 && col < 10) {
                if(cruz[i][j] == 1 && tabuleiro[lin][col] == 0)
                    tabuleiro[lin][col] = 5;
            }
        }
    }

    // Aplicar octaedro
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            int lin = origemOctaL - meio + i;
            int col = origemOctaC - meio + j;
            if(lin >= 0 && lin < 10 && col >= 0 && col < 10) {
                if(octaedro[i][j] == 1 && tabuleiro[lin][col] == 0)
                    tabuleiro[lin][col] = 5;
            }
        }
    }

    // Exibe tabuleiro final
    printf("Tabuleiro final:\n");
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}