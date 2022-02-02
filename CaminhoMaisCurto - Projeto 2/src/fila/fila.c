#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

Fila *criar_fila()
{
    Fila *f = (Fila *)malloc(sizeof(Fila)); // Aloca dinâmicamente uma Fila
    f->ini = f->fim = 0;

    return f;
}

int incrementar(int i)
{
    return (i + 1) % MAX_LEN;
}

void insere_na_fila(Fila *f, int valor)
{
    if (incrementar(f->fim) == f->ini)
    {
        puts("A capacidade da fila estourou");
        exit(1);
    }

    f->itens[f->fim] = valor; // Insere na posição livre
    f->fim = incrementar(f->fim);
}

int retira_da_fila(Fila *f)
{
    int item;

    if (fila_vazia(f))
    {
        puts("Fila está vazia");
        // item = 0;
        exit(1);
    }
    else
    {
        item = f->itens[f->ini];
        f->ini = incrementar(f->ini);
    }

    return item;
}

bool fila_vazia(Fila *f)
{
    return (f->ini == f->fim);
}
