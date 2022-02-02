#if !defined(DATA_H)
#define DATA_H

typedef struct data
{
    int dia;
    int mes;
    int ano;
} Data;

Data nova_data(void);

int datas_iguais(Data d1, Data d2);

void imprime_data(Data d);

#endif // DATA_H