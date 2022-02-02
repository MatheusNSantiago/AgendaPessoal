#include "endereco.h"
#include "../utils/utils.h"
#include <stdio.h>

Endereco novo_endereco(void)
{
    Endereco end;

    printf("Tipo de logradouro: ");
    ler_string(end.tipo_logradouro, 50);

    printf("Nome do logradouro: ");
    ler_string(end.nome_logradouro, 50);

    printf("País: ");
    ler_string(end.pais, 50);

    printf("Estado: ");
    ler_string(end.estado, 50);

    printf("Cidade: ");
    ler_string(end.cidade, 50);

    printf("Bairro: ");
    ler_string(end.bairro, 50);

    printf("Número: ");
    end.numero = ler_integer();

    printf("Complemento: ");
    ler_string(end.complemento, 100);

    printf("CEP: ");
    ler_string(end.cep, 15);

    return end;
}

void imprimir_endereco(Endereco e)
{
    printf("%s: %s\n%s, %s, %s, %s, nº%i (%s) - %s\n", e.tipo_logradouro, e.nome_logradouro, e.pais, e.estado, e.cidade, e.bairro, e.numero, e.complemento, e.cep);
}