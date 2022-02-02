#if !defined(TELA_ALTERACAO_DE_COMPROMISSO_H)
#define TELA_ALTERACAO_DE_COMPROMISSO_H

#include "../../core/compromisso/compromisso.h"


void tela_alteracao_de_compromisso(NoCompromisso **lc);

enum OpcoesMenuAlteracaoDeCompromisso{
    DATA=1,
    HORARIO_INICIO,
    HORARIO_TERMINO,
    LOCAL,
    DESCRICAO,
    OBSERVACAO,
    NADA,
};

#endif // TELA_ALTERACAO_DE_COMPROMISSO_H