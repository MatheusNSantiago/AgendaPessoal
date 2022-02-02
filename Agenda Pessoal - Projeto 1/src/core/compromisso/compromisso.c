#include "./compromisso.h"
#include "../../screens/5_alteracao_de_compromisso/tela_alteracao_de_compromisso.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Compromisso cria_compromisso(Data data, Horario h_ini, Horario h_fim, Endereco local, char desc[700], char obs[200])
{
    Compromisso c;

    c.data = data;
    c.hora_inicio = h_ini;
    c.hora_fim = h_fim;
    c.local = local;
    strcpy(c.descricao, desc);
    strcpy(c.observacao, desc);

    return c;
}

bool lista_de_compromisso_vazia(NoCompromisso *lc)
{
    if (lc == NULL)
        return true;
    return false;
}

void imprime_compromisso(Compromisso c)
{
    puts("******************************************************************");
    
    printf("Data: ");
    imprime_data(c.data);

    printf("Começa as: ");
    imprime_horario(c.hora_inicio);

    printf("Termina as: ");
    imprime_horario(c.hora_fim);

    printf("Local: ");
    imprimir_endereco(c.local);

    printf("Descrição: %s\n", c.descricao);

    printf("Observação: %s\n", c.observacao);

    puts("******************************************************************\n");
}

void insere_compromisso(NoCompromisso **lc, Compromisso c)
{
    NoCompromisso *novo = (NoCompromisso *)malloc(sizeof(NoCompromisso));

    novo->compromisso = c;

    novo->prox = (*lc);
    novo->ant = NULL;

    if ((*lc) != NULL)
        (*lc)->ant = novo;

    (*lc) = novo;
}

NoCompromisso *busca_compromisso(NoCompromisso *lc, Data data, Horario hora_inicio)
{
    NoCompromisso *p;

    for (p = lc; p != NULL; p = p->prox)
        if (datas_iguais(p->compromisso.data, data) && horarios_iguais(p->compromisso.hora_inicio, hora_inicio))
            return p;

    return NULL;
}

NoCompromisso *busca_compromisso_por_mes(NoCompromisso *lc, int mes)
{
    NoCompromisso *p;

    for (p = lc; p != NULL; p = p->prox)
        if (p->compromisso.data.mes == mes)
            return p;

    return NULL;
}

void remove_compromisso(NoCompromisso **lc, NoCompromisso *c)
{
    if (c == (*lc)) // é o primeiro da lista
        (*lc) = (*lc)->prox;
    else
        c->ant->prox = c->prox;

    /* Se não for o último da lista*/
    if (c->prox != NULL)
        c->prox->ant = c->ant;

    free(c);
}

void altera_compromisso(NoCompromisso **lc, NoCompromisso *c, int opcao)
{
    switch (opcao)
    {
    case DATA:
        Data d = nova_data();
        if (escolher("Confirmar Alteração"))
            c->compromisso.data = d;
        break;
    case HORARIO_INICIO:
        Horario hi = novo_horario();
        if (escolher("Confirmar Alteração"))
            c->compromisso.hora_inicio = hi;
        break;
    case HORARIO_TERMINO:
        Horario ht = novo_horario();
        if (escolher("Confirmar Alteração"))
            c->compromisso.hora_fim = ht;
        break;
    case LOCAL:
        Endereco e = novo_endereco();
        if (escolher("Confirmar Alteração"))
            c->compromisso.local = e;
        break;
    case DESCRICAO:
        char desc[700];

        printf("Descrição: ");
        ler_string(desc, 700);

        if (escolher("Confirmar Alteração"))
            strcpy(c->compromisso.descricao, desc);
        break;
    case OBSERVACAO:
        char obs[200];

        printf("Observação: ");
        ler_string(obs, 200);

        if (escolher("Confirmar Alteração"))
            strcpy(c->compromisso.observacao, obs);
        break;
    }
}
