#include <stdlib.h>
#include <stdio.h>
#include "src/grafo/grafo.h"
#include "src/fila/fila.h"

void BFS_caminho_mais_curto(Grafo G, vertex vertice_inicial)
{
    Fila *fila = criar_fila();

    /*
     Vetor de Distâncias percorridas até encontrar o vértice
     Isso vai servir como uma lista de vértices visitados, de forma que qualquer valor diferente de n_vertices se equivalha a marcar o vértice como visitado
    */
    int distancias[G->n_vertices];

    /* Inicia o vetor de distâncias*/
    for (int i = 0; i < G->n_vertices; i++)
        distancias[i] = G->n_vertices; // n_vertices é o default e significa que não está conectado

    distancias[vertice_inicial] = 0; // A distância pro vértice atual é 0

    /* Coloca o vertice inicial na Fila */
    insere_na_fila(fila, vertice_inicial);

    /* Enquando a fila não terminar */
    while (!fila_vazia(fila))
    {
        /* Tira o primeiro vértice fila */
        vertex v_atual = retira_da_fila(fila);

        /* Procura os outros vértices */
        for (vertex v = 0; v < G->n_vertices; v++)
            /* Se v_atual-v for um arco e v não foi visitado*/
            if ((G->adj[v_atual][v] == 1) && (distancias[v] == G->n_vertices))
            {
                distancias[v] = distancias[v_atual] + 1;
                insere_na_fila(fila, v); // Insere esse outro vértice na fila
            }
    }
    printf("     i   ");
    for (int i = 0; i < G->n_vertices; i++)
        printf("%i ", i);

    printf("\ndist[i]  ");
    for (int i = 0; i < G->n_vertices; i++)
        printf("%i ", distancias[i]);
}

int main()
{
    Grafo G = criar_grafo(6);
    inserir_arco(G, 0, 1);
    inserir_arco(G, 1, 2);
    inserir_arco(G, 2, 4);
    inserir_arco(G, 3, 2);
    inserir_arco(G, 3, 4);
    inserir_arco(G, 4, 0);
    inserir_arco(G, 5, 1);

    BFS_caminho_mais_curto(G, 3);

    return 0;
}