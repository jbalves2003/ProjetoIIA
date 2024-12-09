//
// Created by 2003j on 09/12/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

float* ler_moedas(char *nome_ficheiro, int *n_moedas, float *valor_objetivo) {
    FILE *f = fopen(nome_ficheiro, "r");
    if (!f) {
        printf("Erro ao abrir o ficheiro\n");
        exit(1);
    }

    fscanf(f, "%d %f", n_moedas, valor_objetivo);
    float *valores_moedas = malloc(sizeof(float) * (*n_moedas));

    for (int i = 0; i < *n_moedas; i++) {
        fscanf(f, "%f", &valores_moedas[i]);
    }

    fclose(f);
    return valores_moedas;
}

void gera_sol_inicial(int *sol, int n_moedas) {
    for (int i = 0; i < n_moedas; i++) {
        sol[i] = random_l_h(0, 20); // Até 20 moedas de cada tipo
    }
}

void escreve_sol(int *sol, int n_moedas) {
    printf("\nSolucao: ");
    for (int i = 0; i < n_moedas; i++) {
        printf("%2d ", sol[i]);
    }
    printf("\n");
}

void substitui(int a[], int b[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = b[i];
    }
}

void init_rand() {
    srand((unsigned)time(NULL));
}

int random_l_h(int min, int max) {
    return min + rand() % (max - min + 1);
}
