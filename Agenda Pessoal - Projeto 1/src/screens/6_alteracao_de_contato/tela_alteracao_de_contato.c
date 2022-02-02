#include "tela_alteracao_de_contato.h"
#include "../../core/auxiliares/utils/utils.h"
#include <stdio.h>

void tela_alteracao_de_contato(NoContato **l)
{
    char nome[50];        /* nome a ser pesquisado */
    NoContato *resultado; /* nó que representa o resultado da pesquisa */

    /* Se a lista estiver vazia, retorna para a página inicial */
    if (*l == NULL)
    {
        puts("\nLista de contatos está vazia...\r");
        dormir(2);
        return;
    }

    puts("|-----------------------| Alterar Contato |------------------------|");

    while (true)
    {
        printf("Nome: ");
        ler_string(nome, 50);

        resultado = buscar_contato_por_nome(*l, nome);

        if (resultado == NULL)
        {
            puts("Não há nenhum contato com esse nome...\r");
            dormir(1);
            return;
        }

        imprimir_contato(resultado->contato);

        if (escolher("Alterar Contato?"))
        {
            int opcao;
            do
            {
                puts("O que você deseja alterar?");
                printf("(%d) Nome\n", NOME);
                printf("(%d) Local de trabalho\n", LOCAL_DE_TRABALHO);
                printf("(%d) Telefones\n", TELEFONES);
                printf("(%d) Endereço\n", ENDERECO_);
                printf("(%d) Data de nascimento\n", DATA_DE_NASCIMENTO_);
                printf("(%d) Observação\n", OBSERVACAO_);
                printf("(%d) Nada\n", NADA_);

                opcao = ler_integer();
                if (1 <= opcao && opcao <= 6)
                {
                    altera_contato(l, resultado, opcao);
                    imprimir_contato(resultado->contato);

                    if (escolher("Alterar outro campo?") == false)
                        opcao = NADA_;
                }
                else if ((opcao < 1 || opcao > 7))
                    puts("Opção inválida");

            } while (opcao != NADA_);
        }

        if (escolher("Alterar outro contato?") == false)
            return;
    }
}