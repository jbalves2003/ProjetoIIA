//
// Created by 2003j on 09/12/2024.
//

#ifndef UTILS_H
#define UTILS_H

float* ler_moedas(char *nome_ficheiro, int *n_moedas, float *valor_objetivo);
void gera_sol_inicial(int *sol, int n_moedas);
void escreve_sol(int *sol, int n_moedas);
void substitui(int a[], int b[], int n);
void init_rand();
int random_l_h(int min, int max);

#endif
