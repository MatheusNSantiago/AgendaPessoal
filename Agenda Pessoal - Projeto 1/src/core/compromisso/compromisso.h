#if !defined(COMPROMISSO_H)
#define COMPROMISSO_H

#include "../auxiliares/utils/utils.h"
#include "../auxiliares/data/data.h"
#include "../auxiliares/horario/horario.h"
#include "../auxiliares/endereco/endereco.h"


typedef struct compromisso
{
    Data data;
    Horario hora_inicio;
    Horario hora_fim;
    Endereco local;
    char descricao[700];
    char observacao[200];
} Compromisso;

typedef struct no_compromisso
{
    Compromisso compromisso;
    struct no_compromisso *ant;
    struct no_compromisso *prox;
} NoCompromisso;


/* Cria uma lista de compromissos vazia */
NoCompromisso *criar_lista_de_compromissos(void);

Compromisso cria_compromisso(Data data, Horario h_ini, Horario h_fim, Endereco local, char desc[700], char obs[200]);

void imprime_compromisso(Compromisso c);

void insere_compromisso(NoCompromisso **lc, Compromisso c);

void remove_compromisso(NoCompromisso **lc, NoCompromisso *c);

void altera_compromisso(NoCompromisso **lc, NoCompromisso *c, int opcao);

bool lista_de_compromisso_vazia(NoCompromisso *lc);

NoCompromisso *busca_compromisso(NoCompromisso *l, Data data, Horario hora_inicio);

NoCompromisso *busca_compromisso_por_mes(NoCompromisso *lc, int mes);

#endif // COMPROMISSO_H
