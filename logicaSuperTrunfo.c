#include <stdio.h>

// Função auxiliar para exibir o nome do atributo
const char* nomeAtributo(int opcao) {
    switch (opcao) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

int main() {
    // Dados das cartas
    char pais1[50] = "Brasil", pais2[50] = "Canadá";
    unsigned long int populacao1 = 210000000, populacao2 = 38000000;
    float area1 = 8515767, area2 = 9984670;
    float pib1 = 2200, pib2 = 1800;
    int pontos1 = 15, pontos2 = 12;
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;

    int opcao1, opcao2;
    float valor1_attr1, valor2_attr1;
    float valor1_attr2, valor2_attr2;

    // Menu para o primeiro atributo
    printf("Escolha o primeiro atributo:\n");
    printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade Demográfica\n");
    printf("Digite a opção: ");
    scanf("%d", &opcao1);

    // Validação
    if (opcao1 < 1 || opcao1 > 5) {
        printf("Opção inválida.\n");
        return 1;
    }

    // Menu para o segundo atributo, dinâmico
    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != opcao1) {
            printf("%d. %s\n", i, nomeAtributo(i));
        }
    }
    printf("Digite a opção: ");
    scanf("%d", &opcao2);

    // Validação
    if (opcao2 < 1 || opcao2 > 5 || opcao2 == opcao1) {
        printf("Opção inválida ou repetida.\n");
        return 1;
    }

    // Atribuindo valores com switch
    switch (opcao1) {
        case 1: valor1_attr1 = populacao1; valor2_attr1 = populacao2; break;
        case 2: valor1_attr1 = area1; valor2_attr1 = area2; break;
        case 3: valor1_attr1 = pib1; valor2_attr1 = pib2; break;
        case 4: valor1_attr1 = pontos1; valor2_attr1 = pontos2; break;
        case 5: valor1_attr1 = densidade1; valor2_attr1 = densidade2; break;
    }
    switch (opcao2) {
        case 1: valor1_attr2 = populacao1; valor2_attr2 = populacao2; break;
        case 2: valor1_attr2 = area1; valor2_attr2 = area2; break;
        case 3: valor1_attr2 = pib1; valor2_attr2 = pib2; break;
        case 4: valor1_attr2 = pontos1; valor2_attr2 = pontos2; break;
        case 5: valor1_attr2 = densidade1; valor2_attr2 = densidade2; break;
    }

    // Ajuste de valor para densidade (menor = melhor)
    float pontos1_total = 0;
    float pontos2_total = 0;

    // Primeira comparação
    if (opcao1 == 5) {
        pontos1_total += (valor1_attr1 < valor2_attr1) ? 1 : (valor1_attr1 > valor2_attr1) ? 0 : 0.5;
        pontos2_total += (valor2_attr1 < valor1_attr1) ? 1 : (valor2_attr1 > valor1_attr1) ? 0 : 0.5;
    } else {
        pontos1_total += (valor1_attr1 > valor2_attr1) ? 1 : (valor1_attr1 < valor2_attr1) ? 0 : 0.5;
        pontos2_total += (valor2_attr1 > valor1_attr1) ? 1 : (valor2_attr1 < valor1_attr1) ? 0 : 0.5;
    }

    // Segunda comparação
    if (opcao2 == 5) {
        pontos1_total += (valor1_attr2 < valor2_attr2) ? 1 : (valor1_attr2 > valor2_attr2) ? 0 : 0.5;
        pontos2_total += (valor2_attr2 < valor1_attr2) ? 1 : (valor2_attr2 > valor1_attr2) ? 0 : 0.5;
    } else {
        pontos1_total += (valor1_attr2 > valor2_attr2) ? 1 : (valor1_attr2 < valor2_attr2) ? 0 : 0.5;
        pontos2_total += (valor2_attr2 > valor1_attr2) ? 1 : (valor2_attr2 < valor1_attr2) ? 0 : 0.5;
    }

    // Exibição dos resultados
    printf("\n--- Resultado da Rodada ---\n");
    printf("Comparando %s e %s\n", nomeAtributo(opcao1), nomeAtributo(opcao2));

    printf("\n%s:\n  %s: %.2f\n  %s: %.2f\n  Soma: %.2f\n",
        pais1, nomeAtributo(opcao1), valor1_attr1, nomeAtributo(opcao2), valor1_attr2, valor1_attr1 + valor1_attr2);

    printf("\n%s:\n  %s: %.2f\n  %s: %.2f\n  Soma: %.2f\n",
        pais2, nomeAtributo(opcao1), valor2_attr1, nomeAtributo(opcao2), valor2_attr2, valor2_attr1 + valor2_attr2);

    printf("\n--- Resultado Final ---\n");
    if (pontos1_total > pontos2_total) {
        printf("Vencedor: %s\n", pais1);
    } else if (pontos2_total > pontos1_total) {
        printf("Vencedor: %s\n", pais2);
    } else {
        printf("Empate!\n");
    }

    return 0;
}

