#if !defined(TELEFONE_H)
#define TELEFONE_H

#include <stdbool.h>

typedef struct telefone
{
    char codigo_pais[3];
    char ddd[3];
    char numero[10];
} Telefone;

void imprimir_telefone(Telefone tel);

Telefone novo_telefone();

bool is_telefone_valido(Telefone t);

bool telefones_iguais(Telefone t1, Telefone t2);

#endif // TELEFONE_H
