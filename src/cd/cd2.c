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

void check_cd(shell_t *shell)
{
    if (size_tab(shell->command) < 3) {
        if (shell->debug == 1)
            my_printf("use this cd\n");
        cd(shell->env, shell->command[1]);
    }
}