#include "tela_consulta_de_contato.h"
#include "../../core/auxiliares/utils/utils.h"
#include <stdio.h>

void tela_geral_de_consulta_de_contato(NoContato **l)
{

    if (lista_de_contatos_vazia(*l))
    {
        puts("Lista de contatos está vazia...");
        dormir(2);
        return;
    }

    int opcao;
    do
    {
        puts("|-----------------------| Consulta de Contato |------------------------|");

        printf("(%d) Por nome\n", POR_NOME);
        printf("(%d) Por telefone\n", POR_TELEFONE);
        printf("(%d) Voltar\n", VOLTAR_);

        opcao = ler_integer();

        switch (opcao)
        {
        case POR_NOME:
            tela_de_consulta_de_contato_por_nome(l);
            break;
        case POR_TELEFONE:
            tela_consulta_de_contato_por_telefone(l);
            break;
        case VOLTAR_:
            break;
        default:
            puts("Opcao inválida");
            break;
        }

    } while (opcao != VOLTAR_);
}

void tela_de_consulta_de_contato_por_nome(NoContato **l)
{
    puts("|-------------------| Consulta de contato por nome |-------------------|");

    while (true)
    {
        NoContato *res;
        char nome[50];

        printf("Nome: ");
        ler_string(nome, 50);

        res = buscar_contato_por_nome(*l, nome);

        /* Se não achou contato com esse nome */
        if (res == NULL)
            puts("Não foi encontrado nenhum contato com esse nome");
        else
            imprimir_contato(res->contato);

        if (escolher("Consultar outro?") == false)
            return;
    }
}

void tela_consulta_de_contato_por_telefone(NoContato **l)
{
    puts("|-----------------| Consulta de contato por telefone |-----------------|");

    while (true)
    {
        NoContato *res;
        Telefone tel;

        tel = novo_telefone();

        res = buscar_contato_por_telefone(*l, tel);

        if (res == NULL)
            puts("Nenhum contato possui esse telefone");
        else
            imprimir_contato(res->contato);

        if (escolher("Consultar outro?") == false)
            return;
    }
}