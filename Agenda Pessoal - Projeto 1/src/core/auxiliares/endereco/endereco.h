#if !defined(ENDERECO_H)
#define ENDERECO_H

typedef struct endereco
{
    char tipo_logradouro[50];
    char nome_logradouro[150];
    int numero;
    char complemento[100];
    char bairro[50];
    char cidade[50];
    char estado[50];
    char pais[50];
    char cep[15];
} Endereco;

Endereco novo_endereco(void);

void imprimir_endereco(Endereco e);


#endif // ENDERECO_H