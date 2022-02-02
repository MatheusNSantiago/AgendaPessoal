#include "horario.h"
#include "../utils/utils.h"
#include <string.h>
#include <stdio.h>

Horario novo_horario(void)
{
    printf("Insira um horário no formato 'hh:mm': ");

    Horario h;

    char buf[8];

    ler_string(buf, 8);
    sscanf(buf, "%i:%i", &h.hora, &h.minuto);

    if (!(0 <= h.hora && h.hora <= 24) || !(0 <= h.minuto && h.minuto <= 60))
    {
        printf("Horário inválido\n");
        novo_horario();
    }

    return h;
}

int horarios_iguais(Horario h1, Horario h2)
{
    return ((h1.hora == h2.hora) && (h1.minuto == h2.minuto));
}

void imprime_horario(Horario h)
{
    if (h.hora < 10)
        printf("0%i", h.hora);
    else
        printf("%i", h.hora);

    if (h.minuto < 10)
        printf(":0%i", h.minuto);
    else
        printf(":%i", h.minuto);
    printf("\n");
}