#include "telefone.h"
#include "../utils/utils.h"
#include <stdio.h>
#include <string.h>

Telefone novo_telefone()
{
    Telefone t;

    while (true)
    {
        printf("Código do país: ");
        ler_string(t.codigo_pais, 3);

        printf("ddd: ");
        ler_string(t.ddd, 3);

        printf("Número: ");
        ler_string(t.numero, 10);

        if (is_telefone_valido(t))
            return t;
        else
            puts("Telefone inválido");
    }
}

void imprimir_telefone(Telefone tel)
{
    printf("+%s %s %s\n", tel.codigo_pais, tel.ddd, tel.numero);
}

bool is_telefone_valido(Telefone tel)
{
    char cod_pais[3], ddd[3], num[10];

    if ((sscanf(tel.codigo_pais, "%3[0-9]", cod_pais) == 1) &&
        (sscanf(tel.ddd, "%3[0-9]", ddd) == 1) &&
        (sscanf(tel.numero, "%10[0-9]", num) == 1))
        return true;

    return false;
}

bool telefones_iguais(Telefone t1, Telefone t2)
{
    if ((strcmp(t1.codigo_pais, t2.codigo_pais) == 0) &&
        (strcmp(t1.ddd, t2.ddd) == 0) &&
        (strcmp(t1.numero, t2.numero) == 0))
        return true;

    return false;
}
