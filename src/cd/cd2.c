/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** cd2.c
*/

#include "mysh.h"

int basic_cd(char *path, char *buffer, char *oldpwd, link_t *env_link)
{
    if (my_strcmp(path, "~") == 0 || my_strcmp(path, "~/") == 0) {
        chdir("/home/clementbl");
        buffer = getcwd(buffer, 150);
        my_setenv("OLDPWD", oldpwd, env_link);
        my_setenv("PWD", buffer, env_link);
        return (1);
    }
    return (0);
}