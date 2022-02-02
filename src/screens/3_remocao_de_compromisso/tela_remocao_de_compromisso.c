#include "tela_remocao_de_compromisso.h"
#include <stdio.h>
#include <stdlib.h>

void tela_remocao_de_compromisso(NoCompromisso **lc)
{
    Data data;
    Horario horario_inicial;

    puts("|----------------../../../core-| Remover compromisso |-----------------|");

    /* Se ele estiver vazia, retorna pra página inicial */
    if (*lc == NULL)
    {
        puts("Lista de compromissos está vazia...");
        dormir(2);
        return;
    }

    puts("(1/2) Data");
    data = nova_data();

    puts("(2/2) Começa as");
    horario_inicial = novo_horario();

    NoCompromisso *c = busca_compromisso(*lc, data, horario_inicial);
    if (c == NULL)
        puts("\nEsse compromisso não está na agenda.");
    else
    {
        Compromisso comp = c->compromisso;
        imprime_compromisso(comp);

        if (escolher("Confirmar remoção"))
        {
            remove_compromisso(lc, c);
            puts("\nCompromisso removido com sucesso!\n");
        }
    }

    if (escolher("Remover outro"))
        tela_remocao_de_compromisso(lc);

    return;
}