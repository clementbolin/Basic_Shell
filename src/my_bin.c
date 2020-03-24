/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_bin.c
*/

#include "mysh.h"

int size_tab(char **com)
{
    int i = 0;

    for (; com[i] != NULL; i++);
    return (i);
}

int my_bin_2(char **com, link_t *env, int *leave)
{
    if (my_strcmp(com[0], "unsetenv") == 0) {
        if (size_tab(com) == 1) {
            my_putstr("unsetenv: Too few arguments.\n");
            *leave = -10;
            return (2);
        }
        my_unsetenv(com, env);
        return (1);
    }
}

int my_bin_function(char **com, link_t *env, int *leave)
{
    if (my_strcmp(com[0], "setenv") == 0) {
        if (size_tab(com) > 3) {
            my_putstr("setenv: Too many arguments.\n");
            *leave = -10;
            return (2);
        }
        my_setenv(com[1], com[2], env);
        return (1);
    }
    if (my_strcmp(com[0], "env") == 0 && size_tab(com) == 1) {
        display_link_env(env);
        return (1);
    }
    if (my_bin_2(com, env, leave) == 1) return (1);
    if (my_strcmp(com[0], "cd") == 0 && size_tab(com) < 3) {
        cd(env, com[1]);
        return (1);
    }
    return (0);
}