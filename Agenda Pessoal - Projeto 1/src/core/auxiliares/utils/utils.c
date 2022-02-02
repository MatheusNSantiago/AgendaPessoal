#include "utils.h"
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

void ler_string(char *minha_string, int max)
{
    char str[max];
    if (fgets(str, max, stdin))
    {
        str[strcspn(str, "\n")] = '\0'; // Já que o fgets lê o \n, devemos trocar o \n por um null char
        strcpy(minha_string, str);
    }

    if ((strlen(minha_string) + 1) >= max)
    {
        /* Se livra do buffer do stdin */
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
        {
        }
    }
}

int ler_integer(void)
{
    char buf[10];
    ler_string(buf, 10);

    return atoi(buf);
}

void dormir(int sec)
{
    sleep(sec);
}

bool escolher(char *mensagem)
{
    int opcao;
    do
    {
        printf("%s (1-sim, 2-não): ", mensagem);
        opcao = ler_integer();
    } while ((opcao != 1) && (opcao != 2));

    if (opcao == 1)
        return true;
    return false;
}