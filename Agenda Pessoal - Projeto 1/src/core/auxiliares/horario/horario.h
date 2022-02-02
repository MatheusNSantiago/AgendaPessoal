#if !defined(HORARIO_H)
#define HORARIO_H

typedef struct horario
{
    int hora;
    int minuto;
} Horario;

Horario novo_horario(void);

int horarios_iguais(Horario h1, Horario h2);

void imprime_horario(Horario h);

#endif // HORARIO_H