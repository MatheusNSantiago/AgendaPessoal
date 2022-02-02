#include "tela_consulta_de_aniversariante.h"
#include "../../core/auxiliares/utils/utils.h"
#include "stdio.h"

void tela_geral_consulta_de_aniversariante(NoContato **l)
{

    if (lista_de_contatos_vazia(*l))
    {
        puts("Lista de contatos está vazia.");
        dormir(2);
        return;
    }

    int opcao;
    do
    {
        puts("|---------------------| Consulta Aniversariante |----------------------|");

        printf("(%d) Por dia\n", DO_DIA);
        printf("(%d) Por mês\n", DO_MES);
        printf("(%d) Voltar\n", VOLTAR__);

        opcao = ler_integer();

        switch (opcao)
        {
        case DO_DIA:
            tela_consulta_de_aniversariantes_do_dia(l);
            break;
        case DO_MES:
            tela_consulta_de_aniversariantes_do_mes(l);
            break;
        default:
            break;
        }

    } while (opcao != VOLTAR__);
}

void tela_consulta_de_aniversariantes_do_dia(NoContato **l)
{
    puts("|-----------------| Consulta aniversariantes do dia |------------------|");

    while (true)
    {
        int dia, mes;

        bool is_dia_valido = false;
        while (!is_dia_valido)
        {
            printf("Dia: ");
            dia = ler_integer();

            if (!(1 <= dia) || !(dia <= 31))
                puts("Valor inválido. Insira um valor entre 1 e 31");
            else
                is_dia_valido = true;
        }

        bool is_mes_valido = false;
        while (!is_mes_valido)
        {
            printf("Mês: ");
            mes = ler_integer();
            if (!(1 <= mes) || !(mes <= 12))
                puts("Valor inválido. Insira um valor entre 1 e 12");
            else
                is_mes_valido = true;
        }

        NoContato *res = buscar_aniversariante_por_dia(*l, dia, mes);
        if (res == NULL)
        {
            puts("Nenhum de seus contatos faz aniversário nesse dia.");
            dormir(2);
        }
        else
        {
            while (res != NULL)
            {
                imprimir_contato(res->contato);
                res = buscar_aniversariante_por_dia(res->prox, dia, mes);
            }
        }
        if (escolher("Consultar outro dia?") == false)
            return;
    }
}

void tela_consulta_de_aniversariantes_do_mes(NoContato **l)
{
    puts("|-----------------| Consulta aniversariantes do mês |------------------|");

    while (true)
    {
        int mes;

        bool is_mes_valido = false;
        while (!is_mes_valido)
        {
            printf("Mês: ");
            mes = ler_integer();
            if (!(1 <= mes) || !(mes <= 31))
                puts("Valor inválido. Insira um valor entre 1 e 12");
            else
                is_mes_valido = true;
        }

        NoContato *res = buscar_aniversariante_por_mes(*l, mes);
        if (res == NULL)
        {
            puts("Nenhum de seus contatos faz aniversário nesse mês.");
            dormir(2);
        }
        else
        {
            while (res != NULL)
            {
                imprimir_contato(res->contato);
                res = buscar_aniversariante_por_mes(res->prox, mes);
            }
        }
        
        if (escolher("Consultar outro mês?") == false)
            return;
    }
}