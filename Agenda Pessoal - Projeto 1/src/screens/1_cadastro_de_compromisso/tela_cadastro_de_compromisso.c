#include "tela_cadastro_de_compromisso.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void tela_cadastro_de_compromisso(NoCompromisso **l)
{
    Data data;
    Horario h_ini, h_fim;
    Endereco local;
    char descricao[500], observacao[150];

    printf("|-----------------| Cadastrar compromisso |-----------------|\n");
    printf("(1/6) Data\n");
    data = nova_data();

    printf("(2/6) Começa as\n");
    h_ini = novo_horario();

    printf("(3/6) Termina as\n");
    h_fim = novo_horario();

    printf("(4/6) Local\n");
    local = novo_endereco();

    printf("(5/6) Descrição: ");
    ler_string(descricao, 500);

    printf("\n(6/6) Observação: ");
    ler_string(observacao, 150);

    Compromisso c = cria_compromisso(data, h_ini, h_fim, local, descricao, observacao);

    /* Valida se já existe um compromisso nesse horário */
    if (*l != NULL)
        if (busca_compromisso(*l, data, h_ini) != NULL)
        {
            puts("\nJá existe um compromisso nesse horário");
            dormir(2);
            return;
        }

    if (escolher("Confirmar Inclusão"))
    {
        insere_compromisso(l, c);
        puts("\nCompromisso inserido com sucesso!\n");
    }

    if (escolher("Inserir outro compromisso?"))
        tela_cadastro_de_compromisso(l);
}