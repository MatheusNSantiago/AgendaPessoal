#include "tela_remocao_de_contato.h"
#include <stdio.h>
#include "../../core/auxiliares/utils/utils.h"

void tela_remocao_de_contato(NoContato **l)
{
    puts("|-------------------------| Remover contato |--------------------------|");

    if (lista_de_contatos_vazia(*l))
    {
        puts("A lista de contatos está vazia...");
        dormir(2);
        return;
    }

    char nome[50];
    NoContato *resultado;
    while (true)
    {
        printf("Nome: ");
        ler_string(nome, 50);

        resultado = buscar_contato_por_nome(*l, nome);

        if (resultado)
        {
            imprimir_contato(resultado->contato);
            if (escolher("Confirmar remoção?"))
            {
                remover_contato(l, resultado);

                puts("\nContato removido com sucesso!\n");
                dormir(1);
            }
        }
        else
        {
            puts("Contato não foi encontrado");
            dormir(1);
        }

        if (escolher("Remover outro") == false)
            return;
    }
}