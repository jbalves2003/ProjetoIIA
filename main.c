#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algoritmo.h"
#include "utils.h"

#define DEFAULT_RUNS 10

int main(int argc, char *argv[]) {
    char nome_fich[100];
    int n_moedas, num_iter, k, runs, custo, best_custo;
    float *valores_moedas, valor_objetivo;
    int *sol, *best;
    float mbf = 0.0;

    if (argc == 3) {
        runs = atoi(argv[2]);
        strcpy(nome_fich, argv[1]);
    } else if (argc == 2) {
        runs = DEFAULT_RUNS;
        strcpy(nome_fich, argv[1]);
    } else {
        runs = DEFAULT_RUNS;
        printf("Nome do Ficheiro: ");
        gets(nome_fich);
    }
    if (runs <= 0)
        return 0;

    init_rand();
    // Lê dados do problema
    valores_moedas = ler_moedas(nome_fich, &n_moedas, &valor_objetivo);
    printf("Numero de moedas: %d\nValor objetivo: %.2f\n", n_moedas, valor_objetivo);

    num_iter = 1000; // Número de iterações fixado
    sol = malloc(sizeof(int) * n_moedas);
    best = malloc(sizeof(int) * n_moedas);
    if (sol == NULL || best == NULL) {
        printf("Erro na alocação de memória\n");
        exit(1);
    }

    for (k = 0; k < runs; k++) {
        // Gera solução inicial
        gera_sol_inicial(sol, n_moedas);
        escreve_sol(sol, n_moedas);

        // Trepa-colinas
        custo = trepa_colinas(sol, valores_moedas, n_moedas, valor_objetivo, num_iter);

        // Resultados da repetição
        printf("\nRepeticao %d:", k);
        escreve_sol(sol, n_moedas);
        printf("Custo final: %2d\n", custo);

        mbf += custo;
        if (k == 0 || best_custo > custo) {
            best_custo = custo;
            substitui(best, sol, n_moedas);
        }
    }

    // Resultados globais
    printf("\n\nMBF: %f\n", mbf / k);
    printf("\nMelhor solucao encontrada:");
    escreve_sol(best, n_moedas);
    printf("Custo final: %2d\n", best_custo);

    free(valores_moedas);
    free(sol);
    free(best);
    return 0;
}
