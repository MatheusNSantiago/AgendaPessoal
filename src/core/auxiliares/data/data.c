#include "data.h"
#include "../utils/utils.h"
#include <stdio.h>

Data nova_data(void)
{
    Data data;
    char buffer[11];

    printf("Insira uma data na forma 'dd-mm-yyyy': ");

    ler_string(buffer, 12);
    sscanf(buffer, "%i-%i-%i", &data.dia, &data.mes, &data.ano);

    if (!(1 <= data.dia && data.dia <= 31) || !(1 <= data.mes && data.mes <= 12))
    {
        printf("Data inválida.\n");
        nova_data();
    }

    return data;
}

int datas_iguais(Data d1, Data d2)
{
    return ((d1.dia == d2.dia) && (d1.mes == d2.mes) && (d1.ano == d2.ano));
}

void imprime_data(Data d)
{
    printf("%i/%i/%i\n", d.dia, d.mes, d.ano);
}