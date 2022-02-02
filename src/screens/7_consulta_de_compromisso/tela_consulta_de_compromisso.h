#if !defined(TELA_CONSULTA_DE_COMPROMISSO_H)
#define TELA_CONSULTA_DE_COMPROMISSO_H

#include "../../core/compromisso/compromisso.h"

enum OpcoesMenuConsultaDeCompromisso
{
    POR_MES = 1,
    VOLTAR,
};

void tela_geral_consulta_de_compromisso(NoCompromisso **lc);

void tela_de_consulta_de_compromisso_por_mes(NoCompromisso **lc);

#endif // TELA_CONSULTA_DE_COMPROMISSO_H
