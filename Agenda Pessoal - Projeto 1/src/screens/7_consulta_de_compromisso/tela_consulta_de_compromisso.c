#include "tela_consulta_de_compromisso.h"
#include <stdio.h>

void tela_geral_consulta_de_compromisso(NoCompromisso **lc)
{

    if (lista_de_compromisso_vazia(*lc))
    {
        puts("Lista de compromissos está vazia.");
        dormir(2);
        return;
    }

    int opcao;
    do
    {
        puts("|-----------------| Consulta Compromisso |-----------------|");

        printf("(%d) Por mês\n", POR_MES);
        printf("(%d) Voltar\n", VOLTAR);

        printf("Escolher opção: ");
        opcao = ler_integer();

        switch (opcao)
        {
        case POR_MES:
            tela_de_consulta_de_compromisso_por_mes(lc);
            break;
        case VOLTAR:
            break;
        default:
            puts("Opção inválida");
            break;
        }

    } while (opcao != VOLTAR);
}

void tela_de_consulta_de_compromisso_por_mes(NoCompromisso **lc)
{
    puts("|-----------------| Consulta Compromisso por Mês |-----------------|");

    NoCompromisso *tmp;
    int mes;

    while (true)
    {
        printf("Mês: ");
        mes = ler_integer();

        if ((1 <= mes) && (mes <= 12)) // Mês válido
        {
            tmp = busca_compromisso_por_mes((*lc), mes);

            int n_resultados = 0;
            for (tmp; tmp != NULL; tmp = busca_compromisso_por_mes(tmp->prox, mes))
            {
                imprime_compromisso(tmp->compromisso);
                n_resultados++;
            }
            if (n_resultados == 0)
                puts("Não encontrou nenhum compromisso nesse esse mês");

            if (escolher("Consultar outro?") == false)
                return;
        }
        else
            puts("Mês inválido. Escolha um número entre 1 e 12");
    }
}