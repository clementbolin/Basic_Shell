/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** main.c
*/

#include "mysh.h"

int main(int ac, char **av, char **env)
{
    char *str = my_getenv("PATH", env);
    link_t *link = init_list();
    link_t *env_link = init_list();

    if (str == NULL)
        return (84);
    pars_path(link, str);
    create_new_env(env, env_link);
    prompt(env, link, env_link);
    return (0);
}