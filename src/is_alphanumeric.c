/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** is_alphanumeric
*/

#include "mysh.h"

int is_alphanumeric(char *str)
{
    for (int i = 0; str[i]; i++) {
        if ((str[i] < '0' || str[i] > '9') && (str[i] < 'A' || str[i] > 'Z') \
            && (str[i] < 'a' || str[i] > 'z'))
            return (-1);
    }
    return (1);
}