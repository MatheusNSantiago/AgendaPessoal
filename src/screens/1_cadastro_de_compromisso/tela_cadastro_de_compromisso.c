#include "tela_cadastro_de_compromisso.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void tela_cadastro_de_compromisso(NoCompromisso **l)
{
    Data data;
    Horario h_ini, h_fim;
    Endereco local;
    char descricao[500], observacao[150];

    // printf("|-----------------| Cadastrar compromisso |-----------------|\n");
    // printf("(1/6) Data\n");
    // data = nova_data();
    data.dia = 1;
    data.mes = 1;
    data.ano = 2022;

    // printf("(2/6) Começa as\n");
    h_ini = novo_horario();
    // h_ini.hora = 1;
    // h_ini.minuto = 1;

    // printf("(3/6) Termina as\n");
    // h_fim = novo_horario();
    h_fim.hora = 13;
    h_fim.minuto = 30;

    // printf("(4/6) Local\n");
    // local = novo_endereco();
    strcpy(local.bairro, "Bairro");
    strcpy(local.cep, "CEP");
    strcpy(local.cidade, "CIDADE");
    strcpy(local.complemento, "COMPLEMENTO");
    strcpy(local.estado, "ESTADO");
    strcpy(local.nome_logradouro, "Nome Logradouro");
    strcpy(local.tipo_logradouro, "Tipo Logradouro");
    strcpy(local.pais, "BRASIL");
    local.numero = 12;

    // printf("(5/6) Descrição: ");
    // ler_string(descricao, 500);
    strcpy(descricao, "DESCRIÇÃO");

    // printf("\n(6/6) Observação: ");
    // ler_string(observacao, 150);
    strcpy(observacao, "OBSERVACAO");

    Compromisso c = cria_compromisso(data, h_ini, h_fim, local, descricao, observacao);

    /* Valida se já existe um compromisso nesse horário */
    if (*l != NULL)
        if (busca_compromisso(*l, data, h_ini) != NULL)
        {
            puts("\nJá existe um compromisso nesse horário");
            dormir(2);
            return;
        }

    insere_compromisso(l, c); // TODO Tirar isso dps

    // if (escolher("Confirmar Inclusão"))
    // {
    //     insere_compromisso(l, c);
    //     puts("\nCompromisso inserido com sucesso!\n");
    // }

    // if (escolher("Inserir outro compromisso?"))
    //     tela_cadastro_de_compromisso(l);
}