#include "../../screens/6_alteracao_de_contato/tela_alteracao_de_contato.h"
#include "../auxiliares/utils/utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

NoContato *buscar_contato_por_nome(NoContato *l, char nome[50])
{
    NoContato *tmp;

    for (tmp = l; tmp != NULL; tmp = tmp->prox)
        if (strcmp(tmp->contato.nome, nome) == 0)
            return tmp;

    return NULL;
}

NoContato *buscar_contato_por_telefone(NoContato *l, Telefone tel)
{
    NoContato *tmp;

    for (tmp = l; tmp != NULL; tmp = tmp->prox)
        for (int i = 0; i < 2; i++)
            if (telefones_iguais(tmp->contato.telefones[i], tel))
                return tmp;

    return NULL;
}

NoContato *buscar_aniversariante_por_dia(NoContato *l, int dia, int mes)
{
    NoContato *tmp;
    for (tmp = l; tmp != NULL; tmp = tmp->prox)
    {
        Data data_nasc = tmp->contato.data_de_nascimento;
        if ((data_nasc.dia == dia) && (data_nasc.mes == mes))
            return tmp;
    }

    return NULL;
}

NoContato *buscar_aniversariante_por_mes(NoContato *l, int mes)
{
    NoContato *tmp;
    for (tmp = l; tmp != NULL; tmp = tmp->prox)
        if (tmp->contato.data_de_nascimento.mes == mes)
            return tmp;

    return NULL;
}

bool lista_de_contatos_vazia(NoContato *l)
{
    if (l == NULL)
        return true;
    return false;
}

void imprimir_contato(Contato c)
{
    puts("******************************************************************");

    printf("Nome: %s\n", c.nome);

    printf("Data: ");
    imprime_data(c.data_de_nascimento);

    for (int i = 0; i < 2; i++)
    {
        if (is_telefone_valido(c.telefones[i]))
            imprimir_telefone(c.telefones[i]);
    }

    printf("Local de trabalho: %s\n", c.local_de_trabalho);

    puts("******************************************************************");
}

NoContato *aloca_contato(Contato c)
{

    NoContato *novo = (NoContato *)malloc(sizeof(NoContato)); /* Aloca o novo nó */

    novo->contato = c; /* place value in node */
    novo->prox = NULL; /* node does not link to another node */
    novo->ant = NULL;

    return novo;
}

void inserir_contato_em_ordem_alfabetica(NoContato **l, Contato c)
{
    NoContato *novo;     /* ponteiro para o novo nó */
    NoContato *no_atual; /* ponteiro para o nó atual na lista */
    NoContato *no_ant;   /* ponteiro para o nó anterior ao atual */

    novo = aloca_contato(c);
    no_atual = *l;
    no_ant = NULL;

    /* faz um loop para procurar a localização correta na lista baseado no nome do contato*/
    while ((no_atual != NULL) && (strcmp(no_atual->contato.nome, c.nome) < 0))
    {
        no_ant = no_atual;
        no_atual = no_atual->prox;
    }

    /* Se a lista está vazia ou a localização correta de inserção é a primeira da lista  */
    if (lista_de_contatos_vazia(*l) || no_ant == NULL)
    { /* Insere no início */
        novo->prox = *l;
        *l = novo;
    }
    /* Se o loop de procura chegou até o final e não encontrou nada*/
    else if (no_atual == NULL)
    { /* insere no final */
        no_ant->prox = novo;
        novo->ant = no_ant;
        novo->prox = no_atual;
    }
    /* Se o loop encontrou um contato que não está nas extremidades*/
    else
    { /* insere entre o nó anterior e o nó atual */
        no_ant->prox = novo;
        novo->ant = no_ant;
        novo->prox = no_atual;
        no_atual->ant = novo;
    }
}

void remover_contato(NoContato **l, NoContato *c)
{
    /* Se c estiver no início da lista */
    if (c == (*l))
        *l = (*l)->prox;
    else
        c->ant->prox = c->prox;

    /* Se o contato não for o último da lista */
    if (c->prox != NULL)
        c->prox->ant = c->ant;

    free(c);
}

void altera_contato(NoContato **l, NoContato *c, int opcao)
{
    switch (opcao)
    {
    case NOME:
        Contato contato;
        char nome[50];

        printf("Nome: ");
        ler_string(nome, 50);

        if (escolher("Confirmar Alteração"))
        { /* muda o nome e refaz a inserção por ordem alfabetica com o contato modificado */
            contato = c->contato;
            strcpy(contato.nome, nome);

            remover_contato(l, c);
            inserir_contato_em_ordem_alfabetica(l, contato);
        }

        break;
    case LOCAL_DE_TRABALHO:
        char local[100];

        printf("Local de trabalho: ");
        ler_string(local, 100);

        if (escolher("Confirmar Alteração"))
            strcpy(c->contato.local_de_trabalho, local);
        break;
    case TELEFONES:
        Telefone t1, t2;

        t1 = novo_telefone();

        bool incluir_t2 = escolher("Incluir segundo telefone?");
        if (incluir_t2)
            t2 = novo_telefone();

        if (escolher("Confirmar Alteração"))
        {
            c->contato.telefones[0] = t1;

            if (incluir_t2)
                c->contato.telefones[1] = t2;
        }
        break;
    case ENDERECO_:
        Endereco e = novo_endereco();
        if (escolher("Confirmar Alteração"))
            c->contato.endereco_completo = e;
        break;
    case DATA_DE_NASCIMENTO_:
        Data data_nasc;

        printf("Data de nascimento: ");
        data_nasc = nova_data();

        if (escolher("Confirmar Alteração"))
            c->contato.data_de_nascimento = data_nasc;

        break;
    case OBSERVACAO_:
        char obs[200];

        printf("Observação: ");
        ler_string(obs, 200);

        if (escolher("Confirmar Alteração"))
            strcpy(c->contato.observacao, obs);
        break;
    }
}
