#if !defined(TELA_CONSULTA_DE_CONTATO_H)
#define TELA_CONSULTA_DE_CONTATO_H

#include "../../core/contato/contato.h"

enum OpcoesMenuConsultaDeContato
{
    POR_NOME = 1,
    POR_TELEFONE,
    VOLTAR_
};

void tela_geral_de_consulta_de_contato(NoContato **l);

void tela_de_consulta_de_contato_por_nome(NoContato **l);

void tela_consulta_de_contato_por_telefone(NoContato **l);



#endif // TELA_CONSULTA_DE_CONTATO_H
