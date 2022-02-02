#if !defined(CONTATO_H)
#define CONTATO_H

#include <stdbool.h>

#include "../auxiliares/endereco/endereco.h"
#include "../auxiliares/telefone/telefone.h"
#include "../auxiliares/data/data.h"

typedef struct contato
{
    char nome[50];
    char local_de_trabalho[100];
    Telefone telefones[2];
    Endereco endereco_completo;
    Data data_de_nascimento;
    char observacao[200];
} Contato;

typedef struct no_contato
{
    Contato contato;
    struct no_contato *prox;
    struct no_contato *ant;
} NoContato;

NoContato *aloca_contato(Contato c);

void inserir_contato_em_ordem_alfabetica(NoContato **l, Contato c);

NoContato *buscar_contato_por_nome(NoContato *l, char nome[50]);

NoContato *buscar_contato_por_telefone(NoContato *l, Telefone tel);

NoContato *buscar_aniversariante_por_dia(NoContato *l, int dia, int mes);

NoContato *buscar_aniversariante_por_mes(NoContato *l, int mes);

void remover_contato(NoContato **l, NoContato *c);

void imprimir_contato(Contato c);

bool lista_de_contatos_vazia(NoContato *l);

void altera_contato(NoContato **l, NoContato *c, int opcao);

#endif // CONTATO_H
