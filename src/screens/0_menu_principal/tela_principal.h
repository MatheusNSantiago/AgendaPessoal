#if !defined(TELA_PRINCIPAL_H)
#define TELA_PRINCIPAL_H
#include "../../core/compromisso/compromisso.h"
#include "../../core/contato/contato.h"

enum OpcoesMenuPrincipal
{
    CADASTRAR_COMPROMISSO = 1,
    CADASTRAR_CONTATO,
    REMOVER_COMPROMISSO,
    REMOVER_CONTATO,
    ALTERAR_COMPROMISSO,
    ALTERAR_CONTATO,
    CONSULTAR_COMPROMISSO,
    CONSULTAR_CONTATO,
    CONSULTAR_ANIVERSARIANTE,
    SAIR,
};

void tela_principal(NoCompromisso *lista_de_compromissos, NoContato *lista_de_contatos);

#endif // TELA_PRINCIPAL_H
