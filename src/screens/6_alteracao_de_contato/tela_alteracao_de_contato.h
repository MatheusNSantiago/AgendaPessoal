#if !defined(TELA_ALTERACAO_DE_CONTATO_H)
#define TELA_ALTERACAO_DE_CONTATO_H

#include "../../core/contato/contato.h"

void tela_alteracao_de_contato(NoContato **l);

enum OpcoesMenuAlteracaoDeContato{
    NOME=1,
    LOCAL_DE_TRABALHO,
    TELEFONES,
    ENDERECO_,
    DATA_DE_NASCIMENTO_,
    OBSERVACAO_,
    NADA_,
};

#endif // TELA_ALTERACAO_DE_CONTATO_H

