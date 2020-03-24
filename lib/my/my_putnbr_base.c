/*
** EPITECH PROJECT, 2019
** my
** File description:
** my_putnbr_base.c
*/

#include <unistd.h>
#include <stdlib.h>

char *my_revstr(char *str);

int my_putstr(char *str);

void my_putchar(char );

int my_strlen(char const *str);

int my_putnbr_base(int nbr, char *base)
{
    int count = 0;
    char *str = malloc(sizeof(str));
    if (nbr < 0)
        nbr *= -1;
    for (int i = 0; nbr > 0; i += 1) {
        count = nbr % my_strlen(base);
        str[i] = base[count];
        nbr /= my_strlen(base);
    }
    my_revstr(str);
    my_putstr(str);
    return (nbr);
}