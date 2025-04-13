#include <stdio.h>

int main() {
    // -----------------------
    // Movimento da Torre
    // -----------------------
    // A torre vai se mover 5 casas para a direita, usando o laço for
    int casasTorre = 5;
    printf("Movimento da Torre (5 casas para a direita):\n");
    for (int i = 1; i <= casasTorre; i++) {
        printf("Direita\n");
    }

    printf("\n");

    // -----------------------
    // Movimento do Bispo
    // -----------------------
    // O bispo vai se mover 5 casas na diagonal para cima e à direita, usando o laço while
    int casasBispo = 5;
    int contadorBispo = 0;
    printf("Movimento do Bispo (5 casas para cima e direita):\n");
    while (contadorBispo < casasBispo) {
        printf("Cima Direita\n");
        contadorBispo++;
    }

    printf("\n");

    // -----------------------
    // Movimento da Rainha
    // -----------------------
    // A rainha vai se mover 8 casas para a esquerda, usando o laço do-while
    int casasRainha = 8;
    int contadorRainha = 0;
    printf("Movimento da Rainha (8 casas para a esquerda):\n");
    do {
        printf("Esquerda\n");
        contadorRainha++;
    } while (contadorRainha < casasRainha);

    return 0;
}
