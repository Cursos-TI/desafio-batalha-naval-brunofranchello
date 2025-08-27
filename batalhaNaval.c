#include <stdio.h>
#include <stdlib.h>

#define TAM_NOVATO 5
#define TAM_AVENTUREIRO 10
#define TAM_HABILIDADE 5

// Prototypes
void nivelNovato();
void nivelAventureiro();
void nivelMestre();
void imprimirTabuleiro(int matriz[][TAM_AVENTUREIRO], int tamanho);
void imprimirMatriz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE], const char* nome);

int main() {
    int escolha;

    do {
        printf("\n🧭 Menu Batalha Naval\n");
        printf("1 - Nível Novato\n");
        printf("2 - Nível Aventureiro\n");
        printf("3 - Nível Mestre\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                nivelNovato();
                break;
            case 2:
                nivelAventureiro();
                break;
            case 3:
                nivelMestre();
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 0);

    return 0;
}

void nivelNovato() {
    int tabuleiro[TAM_NOVATO][TAM_NOVATO] = {0};

    // Navio vertical
    int x_v = 1, y_v = 0;
    for (int i = 0; i < 3; i++) {
        tabuleiro[y_v + i][x_v] = 3;
        printf("Navio Vertical - Parte %d: (%d, %d)\n", i + 1, x_v, y_v + i);
    }

    // Navio horizontal
    int x_h = 0, y_h = 4;
    for (int i = 0; i < 3; i++) {
        tabuleiro[y_h][x_h + i] = 3;
        printf("Navio Horizontal - Parte %d: (%d, %d)\n", i + 1, x_h + i, y_h);
    }
}

void nivelAventureiro() {
    int tabuleiro[TAM_AVENTUREIRO][TAM_AVENTUREIRO] = {0};

    // Vertical
    for (int i = 0; i < 3; i++) tabuleiro[2 + i][1] = 3;

    // Horizontal
    for (int i = 0; i < 3; i++) tabuleiro[7][4 + i] = 3;

    // Diagonal ↘
    for (int i = 0; i < 3; i++) tabuleiro[0 + i][0 + i] = 3;

    // Diagonal ↙
    for (int i = 0; i < 3; i++) tabuleiro[0 + i][9 - i] = 3;

    printf("\n🧭 Tabuleiro Aventureiro:\n");
    imprimirTabuleiro(tabuleiro, TAM_AVENTUREIRO);
}

void imprimirTabuleiro(int matriz[][TAM_AVENTUREIRO], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void nivelMestre() {
    int cone[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE] = {0};

    // Cone
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = TAM_HABILIDADE / 2 - i; j <= TAM_HABILIDADE / 2 + i; j++) {
            if (j >= 0 && j < TAM_HABILIDADE)
                cone[i][j] = 1;
        }
    }

    // Cruz
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        cruz[i][TAM_HABILIDADE / 2] = 1;
        cruz[TAM_HABILIDADE / 2][i] = 1;
    }

    // Octaedro
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - TAM_HABILIDADE / 2) + abs(j - TAM_HABILIDADE / 2) <= 2)
                octaedro[i][j] = 1;
        }
    }

    imprimirMatriz(cone, "Habilidade: Cone");
    imprimirMatriz(cruz, "Habilidade: Cruz");
    imprimirMatriz(octaedro, "Habilidade: Octaedro");
}

void imprimirMatriz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE], const char* nome) {
    printf("\n🔹 %s:\n", nome);
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}