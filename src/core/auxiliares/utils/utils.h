#if !defined(AUXILIARES_H)
#define AUXILIARES_H
#include <stdbool.h>

void ler_string(char *minha_string, int max);

int ler_integer(void);

void dormir(int sec);

/* Faz o user escolher entre sim ou não */
bool escolher(char *mensagem);

#endif // AUXILIARES_H