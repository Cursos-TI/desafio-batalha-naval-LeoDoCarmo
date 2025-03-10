#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Declaração e inicialização do tabuleiro com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas iniciais dos navios (linha, coluna)
    int navio_horizontal_linha = 2;
    int navio_horizontal_coluna = 3;
    int navio_vertical_linha = 5;
    int navio_vertical_coluna = 1;

    // Posicionamento do navio horizontal
    if (navio_horizontal_coluna + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[navio_horizontal_linha][navio_horizontal_coluna + i] = 3;
        }
    } else {
        printf("Erro: Navio horizontal fora dos limites do tabuleiro.\n");
        return 1; // Encerra o programa com código de erro
    }

    // Posicionamento do navio vertical
    if (navio_vertical_linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Verifica se há sobreposição com o navio horizontal
            if (tabuleiro[navio_vertical_linha + i][navio_vertical_coluna] == 3) {
                printf("Erro: Navios se sobrepõem.\n");
                return 1; // Encerra o programa com código de erro
            }
            tabuleiro[navio_vertical_linha + i][navio_vertical_coluna] = 3;
        }
    } else {
        printf("Erro: Navio vertical fora dos limites do tabuleiro.\n");
        return 1; // Encerra o programa com código de erro
    }

    // Exibição do tabuleiro
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}