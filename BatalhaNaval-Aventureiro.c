#include <stdio.h>

#define TAM 10
#define NAVIO 3

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // Navio vertical (coluna fixa)
    int x_v = 1, y_v = 2;
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[y_v + i][x_v] = 3;
    }

    // Navio horizontal (linha fixa)
    int x_h = 4, y_h = 7;
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[y_h][x_h + i] = 3;
    }

    // Navio diagonal ↘ (descendo linha e coluna)
    int x_d1 = 0, y_d1 = 0;
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[y_d1 + i][x_d1 + i] = 3;
    }

    // Navio diagonal ↙ (descendo linha, subindo coluna)
    int x_d2 = 9, y_d2 = 0;
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[y_d2 + i][x_d2 - i] = 3;
    }

    // Exibição do tabuleiro
    printf("🧭 Tabuleiro 10x10:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}