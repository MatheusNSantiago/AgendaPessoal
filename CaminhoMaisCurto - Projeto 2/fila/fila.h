#if !defined(FILA_H)
#define FILA_H
#define MAX_LEN 100

#include <stdbool.h>

/* Eu não entendi como usar linked list aqui... Também não achei na internet
Vou Fazer com filas com array estático mesmo
*/

typedef struct fila
{
    int itens[MAX_LEN];
    int ini, fim;
} Fila;

int incrementar(int i);

Fila *criar_fila();

void insere_na_fila(Fila *f, int v);

int retira_da_fila(Fila *f);

bool fila_vazia(Fila *f);

#endif // FILA_H
