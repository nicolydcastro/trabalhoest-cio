#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VALOR_NAVIO 3
#define AGUA 0

int main() {
    // -----------------------------------
    // Parte 1: Movimento das Peças de Xadrez
    // -----------------------------------

    // Torre - 5 casas para a direita (usando for)
    int casasTorre = 5;
    printf("Movimento da Torre (5 casas para a direita):\n");
    for (int i = 1; i <= casasTorre; i++) {
        printf("Direita\n");
    }
    printf("\n");

    // Bispo - 5 casas na diagonal cima-direita (usando while)
    int casasBispo = 5;
    int contadorBispo = 0;
    printf("Movimento do Bispo (5 casas para cima e direita):\n");
    while (contadorBispo < casasBispo) {
        printf("Cima Direita\n");
        contadorBispo++;
    }
    printf("\n");

    // Rainha - 8 casas para a esquerda (usando do-while)
    int casasRainha = 8;
    int contadorRainha = 0;
    printf("Movimento da Rainha (8 casas para a esquerda):\n");
    do {
        printf("Esquerda\n");
        contadorRainha++;
    } while (contadorRainha < casasRainha);

    printf("\n");

    // -----------------------------------
    // Parte 2: Batalha Naval - Posicionamento de Navios
    // -----------------------------------

    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Coordenadas iniciais definidas diretamente no código
    int linhaNavioHorizontal = 2;
    int colunaNavioHorizontal = 4;

    int linhaNavioVertical = 5;
    int colunaNavioVertical = 1;

    // Verificação de validade e sobreposição (horizontal)
    if (colunaNavioHorizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] = VALOR_NAVIO;
        }
    }

    // Verificação de validade e sobreposição (vertical)
    if (linhaNavioVertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaNavioVertical + i][colunaNavioVertical] == VALOR_NAVIO) {
                sobreposicao = 1;
                break;
            }
        }

        // Posiciona o navio apenas se não houver sobreposição
        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaNavioVertical + i][colunaNavioVertical] = VALOR_NAVIO;
            }
        } else {
            printf("Erro: Sobreposição detectada! O navio vertical não será posicionado.\n");
        }
    }

    // Exibe o tabuleiro
    printf("\nTabuleiro (0 = água, 3 = navio):\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
