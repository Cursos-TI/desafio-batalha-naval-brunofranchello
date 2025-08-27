#include <stdio.h>
#include <stdlib.h> 

#define TAM 5

// Função para imprimir matriz
void imprimirMatriz(int matriz[TAM][TAM], const char* nome);

int main() {
    // Habilidades
    int cone[TAM][TAM] = {0};
    int cruz[TAM][TAM] = {0};
    int octaedro[TAM][TAM] = {0};

    // Cone (base na linha inferior)
    for (int i = 0; i < TAM; i++) {
        for (int j = TAM / 2 - i; j <= TAM / 2 + i; j++) {
            if (j >= 0 && j < TAM && i < TAM)
                cone[i][j] = 1;
        }
    }

    // Cruz (linha e coluna centrais)
    for (int i = 0; i < TAM; i++) {
        cruz[i][TAM / 2] = 1; // Coluna central
        cruz[TAM / 2][i] = 1; // Linha central
    }

    // Octaedro (losango)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (abs(i - TAM / 2) + abs(j - TAM / 2) <= 2)
                octaedro[i][j] = 1;
        }
    }

    // Exibir matrizes
    imprimirMatriz(cone, "Habilidade: Cone");
    imprimirMatriz(cruz, "Habilidade: Cruz");
    imprimirMatriz(octaedro, "Habilidade: Octaedro");

    return 0;
}

void imprimirMatriz(int matriz[TAM][TAM], const char* nome) {
    printf("\n🔹 %s:\n", nome);
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}