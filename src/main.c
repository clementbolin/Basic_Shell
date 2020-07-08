/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "mysh.h"

int main(int ac, char **av, char **env)
{
    shell_t shell;

    shell.env = init_list();
    shell.path = init_list();
    shell.error = 0;
    shell.etat_fork = 0;
    shell.etat = 0;
    shell.i = 0;
    if (ac != 1) {
        if (ac == 2 && my_strcmp(av[1], "--debug") == 0)
            shell.debug = 1;
        else
            return (84);
    }
    init_env(env, shell.env);
    init_link_path(shell.env, shell.path);
    prompt(&shell);
    return (0);
}

