//
// Created by 2003j on 09/12/2024.
//

#include "funcao.h"
#include <math.h>

// Calcula a qualidade de uma solução
int calcula_fit(int *sol, float *valores_moedas, int n_moedas, float valor_objetivo) {
    float soma = 0.0;
    int total_moedas = 0;

    for (int i = 0; i < n_moedas; i++) {
        soma += sol[i] * valores_moedas[i];
        total_moedas += sol[i];
    }

    if (fabs(soma - valor_objetivo) < 0.01) { // Solução válida
        return total_moedas;
    } else { // Penaliza soluções inválidas
        return total_moedas + 1000 * fabs(soma - valor_objetivo);
    }
}
