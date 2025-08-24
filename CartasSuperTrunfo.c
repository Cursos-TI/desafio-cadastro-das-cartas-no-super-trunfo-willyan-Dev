#include <stdio.h>
#include <math.h>

typedef struct {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    unsigned long int populacao; // maior capacidade
    float area;
    float pib; // em bilhões
    int pontosTuristicos;
    float densidade;
    float pibPerCapita; // em reais
    float superPoder;
} Carta;

void calcularAtributos(Carta *c) {
    c->densidade = (c->area > 0.0f) ? (float)c->populacao / c->area : 0.0f;
    // PIB está em bilhões -> converto para reais para o per capita
    c->pibPerCapita = (c->populacao > 0UL) ? (c->pib * 1000000000.0f) / (float)c->populacao : 0.0f;

    // Super Poder: soma dos atributos numéricos + inverso da densidade
    float invDens = (c->densidade > 0.0f) ? 1.0f / c->densidade : 0.0f;
    c->superPoder = (float)c->populacao
                  + c->area
                  + c->pib
                  + (float)c->pontosTuristicos
                  + c->pibPerCapita
                  + invDens;
}

int empate_float(float a, float b) {
    return fabsf(a - b) < 1e-6f;
}

void imprime_resultado(const char* rotulo, int venceuCarta1, int empate) {
    if (empate) {
        printf("%s: Empate (0)\n", rotulo);
    } else {
        printf("%s: %s (%d)\n", rotulo, venceuCarta1 ? "Carta 1 venceu" : "Carta 2 venceu", venceuCarta1);
    }
}

void imprime_carta(const char* titulo, const Carta* c) {
    printf("\n%s\n", titulo);
    printf("Estado: %c\nCódigo: %s\nCidade: %s\n", c->estado, c->codigo, c->nomeCidade);
    printf("População: %lu\nÁrea: %.2f km²\nPIB: %.2f bi\nPontos Turísticos: %d\n",
           c->populacao, c->area, c->pib, c->pontosTuristicos);
    printf("Densidade: %.4f hab/km²\nPIB per Capita: R$ %.2f\nSuper Poder: %.4f\n",
           c->densidade, c->pibPerCapita, c->superPoder);
}

int main() {
    Carta c1, c2;

    // Entrada Carta 1
    printf("Carta 1:\n");
    printf("Digite o estado (letra de A a H): ");
    scanf(" %c", &c1.estado);
    printf("Digite o código da carta (ex: A01): ");
    scanf("%3s", c1.codigo);
    printf("Digite o nome da cidade: ");
    scanf(" %49[^\n]", c1.nomeCidade);
    printf("Digite a população: ");
    scanf("%lu", &c1.populacao);
    printf("Digite a área (em km²): ");
    scanf("%f", &c1.area);
    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &c1.pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &c1.pontosTuristicos);

    calcularAtributos(&c1);

    // Entrada Carta 2
    printf("\nCarta 2:\n");
    printf("Digite o estado (letra de A a H): ");
    scanf(" %c", &c2.estado);
    printf("Digite o código da carta (ex: B02): ");
    scanf("%3s", c2.codigo);
    printf("Digite o nome da cidade: ");
    scanf(" %49[^\n]", c2.nomeCidade);
    printf("Digite a população: ");
    scanf("%lu", &c2.populacao);
    printf("Digite a área (em km²): ");
    scanf("%f", &c2.area);
    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &c2.pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &c2.pontosTuristicos);

    calcularAtributos(&c2);

    // (Opcional) Mostrar status das cartas
    imprime_carta("=== Carta 1 ===", &c1);
    imprime_carta("=== Carta 2 ===", &c2);

    // Comparações
    printf("\nComparação de Cartas:\n");

    // População (maior vence)
    int emp_pop = (c1.populacao == c2.populacao);
    imprime_resultado("População", c1.populacao > c2.populacao, emp_pop);

    // Área (maior vence)
    int emp_area = empate_float(c1.area, c2.area);
    imprime_resultado("Área", c1.area > c2.area, emp_area);

    // PIB (maior vence)
    int emp_pib = empate_float(c1.pib, c2.pib);
    imprime_resultado("PIB", c1.pib > c2.pib, emp_pib);

    // Pontos Turísticos (maior vence)
    int emp_pt = (c1.pontosTuristicos == c2.pontosTuristicos);
    imprime_resultado("Pontos Turísticos", c1.pontosTuristicos > c2.pontosTuristicos, emp_pt);

    // Densidade (MENOR vence)
    int emp_dens = empate_float(c1.densidade, c2.densidade);
    imprime_resultado("Densidade Populacional", c1.densidade < c2.densidade, emp_dens);

    // PIB per Capita (maior vence)
    int emp_pibpc = empate_float(c1.pibPerCapita, c2.pibPerCapita);
    imprime_resultado("PIB per Capita", c1.pibPerCapita > c2.pibPerCapita, emp_pibpc);

    // Super Poder (maior vence)
    int emp_sp = empate_float(c1.superPoder, c2.superPoder);
    imprime_resultado("Super Poder", c1.superPoder > c2.superPoder, emp_sp);

    return 0;
}
