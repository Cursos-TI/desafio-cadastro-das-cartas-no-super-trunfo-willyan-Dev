#include <stdio.h>

int main() {

    char estado1, estado2;
    char codigo1[10], codigo2[10];
    char nome1[50], nome2[50];
    int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int pontos1, pontos2;

    // Primeira carta
    printf("Crie a sua primeira carta:\n");

    printf("Digite a letra do estado (A-H):\n");
    scanf(" %c", &estado1);

    printf("Digite o código da carta (ex: A01):\n");
    scanf(" %s", codigo1);

    printf("Digite o nome da cidade:\n");
    scanf(" %[^\n]", nome1); // Permite ler nomes com espaços

    printf("Digite a população:\n");
    scanf("%d", &populacao1);

    printf("Digite a área da cidade (em km²):\n");
    scanf("%f", &area1);

    printf("Digite o PIB da cidade:\n");
    scanf("%f", &pib1);

    printf("Digite o número de pontos turísticos:\n");
    scanf("%d", &pontos1);

    // Segunda carta
    printf("\nCrie a sua segunda carta:\n");

    printf("Digite a letra do estado (A-H):\n");
    scanf(" %c", &estado2);

    printf("Digite o código da carta (ex: B03):\n");
    scanf(" %s", codigo2);

    printf("Digite o nome da cidade:\n");
    scanf(" %[^\n]", nome2);

    printf("Digite a população:\n");
    scanf("%d", &populacao2);

    printf("Digite a área da cidade (em km²):\n");
    scanf("%f", &area2);

    printf("Digite o PIB da cidade:\n");
    scanf("%f", &pib2);

    printf("Digite o número de pontos turísticos:\n");
    scanf("%d", &pontos2);

    // Exibindo os dados
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nome1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontos1);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nome2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontos2);

    return 0;
}
