#if !defined(TELA_CONSULTA_DE_ANIVERSARIANTE_H)
#define TELA_CONSULTA_DE_ANIVERSARIANTE_H

#include "../../core/contato/contato.h"

enum OpcoesMenuConsultaDeAniversario
{
    DO_DIA = 1,
    DO_MES,
    VOLTAR__,
};

void tela_geral_consulta_de_aniversariante(NoContato **l);

void tela_consulta_de_aniversariantes_do_dia(NoContato **l);

void tela_consulta_de_aniversariantes_do_mes(NoContato **l);


#endif // TELA_CONSULTA_DE_ANIVERSARIANTE_H
