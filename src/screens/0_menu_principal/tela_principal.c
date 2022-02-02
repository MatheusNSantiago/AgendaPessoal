#include <stdlib.h>
#include <stdio.h>
#include "tela_principal.h"

#include "../1_cadastro_de_compromisso/tela_cadastro_de_compromisso.h"
#include "../3_remocao_de_compromisso/tela_remocao_de_compromisso.h"
#include "../5_alteracao_de_compromisso/tela_alteracao_de_compromisso.h"
#include "../7_consulta_de_compromisso/tela_consulta_de_compromisso.h"

#include "../2_cadastro_de_contato/tela_cadastro_de_contato.h"
#include "../4_remocao_de_contato/tela_remocao_de_contato.h"
#include "../6_alteracao_de_contato/tela_alteracao_de_contato.h"
#include "../8_consulta_de_contato/tela_consulta_de_contato.h"

#include "../9_consulta_de_aniversariante/tela_consulta_de_aniversariante.h"

void tela_principal(NoCompromisso *lista_de_compromissos, NoContato *lista_de_contatos)
{
    int opcao;
    do
    {
        puts("|-----------------| Minha agenda |-----------------|");
        printf("(%d) Cadastrar compromisso\n", CADASTRAR_COMPROMISSO);
        printf("(%d) Cadastrar contato\n", CADASTRAR_CONTATO);
        printf("(%d) Remover compromisso\n", REMOVER_COMPROMISSO);
        printf("(%d) Remover contato\n", REMOVER_CONTATO);
        printf("(%d) Alterar compromisso\n", ALTERAR_COMPROMISSO);
        printf("(%d) Alterar contato\n", ALTERAR_CONTATO);
        printf("(%d) Consultar compromisso\n", CONSULTAR_COMPROMISSO);
        printf("(%d) Consultar contato\n", CONSULTAR_CONTATO);
        printf("(%d) Consulta aniversariante\n", CONSULTAR_ANIVERSARIANTE);
        printf("(%d) Sair\n", SAIR);

        printf("Escolher opção: ");
        opcao = ler_integer();
        switch (opcao)
        {
        case CADASTRAR_COMPROMISSO:
            tela_cadastro_de_compromisso(&lista_de_compromissos);
            break;
        case CADASTRAR_CONTATO:
            tela_cadastro_de_contato(&lista_de_contatos);
            break;
        case REMOVER_COMPROMISSO:
            tela_remocao_de_compromisso(&lista_de_compromissos);
            break;
        case REMOVER_CONTATO:
            tela_remocao_de_contato(&lista_de_contatos);
            break;
        case ALTERAR_COMPROMISSO:
            tela_alteracao_de_compromisso(&lista_de_compromissos);
            break;
        case ALTERAR_CONTATO:
            tela_alteracao_de_contato(&lista_de_contatos);
            break;
        case CONSULTAR_COMPROMISSO:
            tela_geral_consulta_de_compromisso(&lista_de_compromissos);
            break;
        case CONSULTAR_CONTATO:
            tela_geral_de_consulta_de_contato(&lista_de_contatos);
            break;
        case CONSULTAR_ANIVERSARIANTE:
            tela_geral_consulta_de_aniversariante(&lista_de_contatos);
            break;
        case SAIR:
            break;
        default:
            printf("Opção inválida\n");
            break;
        }
    } while (opcao != SAIR);
}
