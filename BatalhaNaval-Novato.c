#include <stdio.h>

#define TAMANHO_NAVIO 3

int main() {
    // Tabuleiro 10x10
    int tabuleiro[10][10] = {0};

    // Coordenadas iniciais dos navios
    int x_vertical = 2, y_vertical = 4;     // Navio vertical começa em (2,4)
    int x_horizontal = 6, y_horizontal = 1; // Navio horizontal começa em (6,1)

    printf("🚢 Coordenadas do Navio Vertical:\n");
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        printf("Parte %d: (%d, %d)\n", i + 1, x_vertical, y_vertical + i);
    }

    printf("\n🚢 Coordenadas do Navio Horizontal:\n");
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        printf("Parte %d: (%d, %d)\n", i + 1, x_horizontal + i, y_horizontal);
    }

    return 0;
}