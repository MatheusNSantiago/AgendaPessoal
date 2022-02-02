#include "grafo.h"
#include <stdlib.h>
#include <stdio.h>

static int **criar_matriz(int n_linhas, int n_colunas, int valor)
{
    /* Aloca o espaço necessário para matriz */
    int **matriz = malloc(n_linhas * sizeof(int *)); // Aloca linhas
    for (vertex l = 0; l < n_linhas; ++l)
        matriz[l] = malloc(n_colunas * sizeof(int)); // Aloca colunas

    /* Define o valor de todos os elementos da matriz  */
    for (vertex l = 0; l < n_linhas; ++l)
        for (vertex c = 0; c < n_colunas; ++c)
            matriz[l][c] = valor; // Cada elemento recebe o valor 'valor'

    return matriz;
}

Grafo criar_grafo(int n_vertices)
{
    Grafo G = malloc(sizeof *G);

    G->n_vertices = n_vertices;
    G->n_arcos = 0;
    G->adj = criar_matriz(n_vertices, n_vertices, 0);

    return G;
}

void inserir_arco(Grafo G, vertex src, vertex dest)
{
    /* Se não houver um arco ali (i.e. o elemento marcado como 0) */
    if (G->adj[src][dest] == 0)
    {
        G->adj[src][dest] = 1; // Diz que existe um arco ali
        G->n_arcos++;          // Aumenta o total de arcos
    }
}

void remover_arco(Grafo G, vertex v1, vertex v2)
{
    /* Se houver um arco ali (i.e. elemento marcado como 1) */
    if (G->adj[v1][v2] == 1)
    {
        G->adj[v1][v2] = 0; // Diz que não existe um arco ali
        G->n_arcos--;        // Diminui o total de arcosl
    }
}