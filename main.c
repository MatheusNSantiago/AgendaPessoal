#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "src/screens/0_menu_principal/tela_principal.h"
#include "src/core/compromisso/compromisso.h"
#include "src/core/contato/contato.h"
#include "src/core/auxiliares/utils/utils.h"

int main(void)
{
    /* Inicia lista de compromissos vazia */
    NoCompromisso *lista_de_compromissos = NULL;
    /* Inicia lista de contatos vazia */
    NoContato *lista_de_contatos = NULL;

    tela_principal(lista_de_compromissos, lista_de_contatos);
}
