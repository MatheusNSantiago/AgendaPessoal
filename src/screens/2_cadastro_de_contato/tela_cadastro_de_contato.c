#include "tela_cadastro_de_contato.h"
#include "../../core/auxiliares/utils/utils.h"
#include <stdio.h>
#include <string.h>

void tela_cadastro_de_contato(NoContato **l)
{
    puts("|------------------------| Cadastrar Contato |-------------------------|");

    Contato c;
    while (true)
    {
        // do
        // {
        //     puts("(1/6) Nome");
        //     ler_string(c.nome, 50);

        //     if (strlen(c.nome) == 0)
        //         puts("Nome não pode ficar em branco");

        // } while (strlen(c.nome) == 0);

        // puts("(2/6) Local de Trabalho");
        // ler_string(c.local_de_trabalho, 100);

        // puts("(3/6) Telefones para contato");
        // c.telefones[0] = novo_telefone();
        // if (escolher("Adicionar outro telefone?"))
        //     c.telefones[1] = novo_telefone();

        // puts("(4/6) Endereço completo");
        // c.endereco_completo = novo_endereco();

        // puts("(5/6) Data de nascimento");
        // c.data_de_nascimento = nova_data();

        // puts("(6/6) Observação");
        // ler_string(c.observacao, 500);

        c.data_de_nascimento.ano = 1999;
        c.data_de_nascimento.mes = 7;
        c.data_de_nascimento.dia = 19;

        strcpy(c.endereco_completo.bairro, "Bairro");
        strcpy(c.endereco_completo.cep, "CEP");
        strcpy(c.endereco_completo.cidade, "CIDADE");
        strcpy(c.endereco_completo.complemento, "COMPLEMENTO");
        strcpy(c.endereco_completo.estado, "ESTADO");
        strcpy(c.endereco_completo.nome_logradouro, "Nome Logradouro");
        strcpy(c.endereco_completo.tipo_logradouro, "Tipo Logradouro");
        strcpy(c.endereco_completo.pais, "BRASIL");
        c.endereco_completo.numero = 12;

        strcpy(c.local_de_trabalho, "Perto do lado do outro lado");
        ler_string(c.nome, 50);
        strcpy(c.observacao, "OBS");
        strcpy(c.telefones[0].codigo_pais, "55");
        strcpy(c.telefones[0].ddd, "21");
        strcpy(c.telefones[0].numero, "993823598");

        inserir_contato_em_ordem_alfabetica(l, c);
        //|-----------------------------------------||-----------------------------------------|
        // if (escolher("Confirmar inclusão?"))
        // {
        //     inserir_contato_em_ordem_alfabetica(l, c);
        //     puts("\nContato foi inserido com sucesso!\n");
        //     dormir(1);
        // }

        if (escolher("Inserir outro?") == false)
            return;
    }
}
