#include "tela_alteracao_de_compromisso.h"

#include <stdlib.h>
#include <stdio.h>

void tela_alteracao_de_compromisso(NoCompromisso **lc)
{
    Data data;
    Horario horario_inicial;

    /* Se a lista estiver vazia, retorna para a página inicial */
    if (*lc == NULL)
    {
        puts("\nLista de compromissos está vazia...\r");
        dormir(2);
        return;
    }

    puts("|-----------------------| Alterar Compromisso |------------------------|");

    while (true)
    {
        printf("(1/2) Data\n");
        data = nova_data();

        printf("(2/2) Começa as\n");
        horario_inicial = novo_horario();

        NoCompromisso *nc = busca_compromisso(*lc, data, horario_inicial);

        if (nc == NULL)
        {
            puts("Não há nenhum compromisso nesse horário...\r");
            dormir(2);
            return;
        }

        imprime_compromisso(nc->compromisso);

        if (escolher("Alterar Compromisso"))
        {
            int opcao;
            do
            {
                puts("O que você deseja alterar?");
                printf("(%d) Data\n", DATA);
                printf("(%d) Horario de início\n", HORARIO_INICIO);
                printf("(%d) Horario de término\n", HORARIO_TERMINO);
                printf("(%d) Local\n", LOCAL);
                printf("(%d) Descrição\n", DESCRICAO);
                printf("(%d) Observação\n", OBSERVACAO);
                printf("(%d) Nada\n", NADA);

                opcao = ler_integer();
                if (1 <= opcao && opcao <= 6)
                {
                    altera_compromisso(lc, nc, opcao);
                    imprime_compromisso(nc->compromisso);
                    if (escolher("Alterar outro campo?") == false)
                        opcao = NADA;
                }
                else if ((opcao < 1 || opcao > 7))
                    puts("Opção inválida");

            } while (opcao != NADA);
        }

        if (escolher("Alterar outro contato?") == false)
            return;
    }
}