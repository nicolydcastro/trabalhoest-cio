#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[50];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Carta;

// Função para calcular a densidade populacional
float calcularDensidadePopulacional(int populacao, float area) {
    return populacao / area;
}

// Função para calcular o PIB per capita
float calcularPIBPerCapita(float pib, int populacao) {
    return pib / populacao;
}

// Função para comparar as cartas com base em um atributo numérico
void compararCartas(Carta carta1, Carta carta2, int atributo) {
    float valor1, valor2;

    // Definindo o atributo a ser comparado: 1 - População, 2 - Área, 3 - PIB, 4 - Densidade Populacional, 5 - PIB per capita
    switch (atributo) {
        case 1: // Comparação por População
            valor1 = carta1.populacao;
            valor2 = carta2.populacao;
            printf("Comparação de cartas (Atributo: População):\n");
            break;
        case 2: // Comparação por Área
            valor1 = carta1.area;
            valor2 = carta2.area;
            printf("Comparação de cartas (Atributo: Área):\n");
            break;
        case 3: // Comparação por PIB
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            printf("Comparação de cartas (Atributo: PIB):\n");
            break;
        case 4: // Comparação por Densidade Populacional
            valor1 = calcularDensidadePopulacional(carta1.populacao, carta1.area);
            valor2 = calcularDensidadePopulacional(carta2.populacao, carta2.area);
            printf("Comparação de cartas (Atributo: Densidade Populacional):\n");
            break;
        case 5: // Comparação por PIB per capita
            valor1 = calcularPIBPerCapita(carta1.pib, carta1.populacao);
            valor2 = calcularPIBPerCapita(carta2.pib, carta2.populacao);
            printf("Comparação de cartas (Atributo: PIB per capita):\n");
            break;
        default:
            printf("Atributo inválido!\n");
            return;
    }

    // Exibindo as cartas e seus respectivos valores para o atributo escolhido
    printf("Carta 1 - %s (%s): %.2f\n", carta1.cidade, carta1.estado, valor1);
    printf("Carta 2 - %s (%s): %.2f\n", carta2.cidade, carta2.estado, valor2);

    // Determinando o vencedor com base no atributo
    if (atributo == 4) { // Se for Densidade Populacional, o menor valor vence
        if (valor1 < valor2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
        } else if (valor1 > valor2) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else { // Para os outros atributos, o maior valor vence
        if (valor1 > valor2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
        } else if (valor1 < valor2) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
}

int main() {
    // Definindo as cartas com valores fixos
    Carta carta1 = {"SP", "SP001", "São Paulo", 12300000, 1521.11, 700000, 20};
    Carta carta2 = {"RJ", "RJ001", "Rio de Janeiro", 6000000, 1200.55, 600000, 15};

    // Escolha do atributo para comparação
    int atributo = 1; // 1: População, 2: Área, 3: PIB, 4: Densidade Populacional, 5: PIB per capita
    
    // Chamando a função de comparação
    compararCartas(carta1, carta2, atributo);

    return 0;
}
