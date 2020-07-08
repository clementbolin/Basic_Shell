/*
** EPITECH PROJECT, 2020
** minushell2
** File description:
** init env
*/

#include "mysh.h"

char *recup_name_var_env(char *env)
{
    int i = 0;
    char *name = 0;

    for (; env[i] != '='; i++);
    name = malloc(sizeof(char) * i + 1);
    i = 0;
    for (; env[i] != '='; i++)
        name[i] = env[i];
    name[i] = '\0';
    return (name);
}

char **transform_env(link_t *env)
{
    char **my_env = 0;
    node_t *node = env->head;
    int size_y = 0;
    int i = 0;

    for (; node != NULL; node = node->next, size_y++);
    my_env = malloc(sizeof(char *) * (size_y + 1));
    node = env->head;
    for (; node != NULL; node = node->next, i++)
        my_env[i] = my_strcpy(my_env[i], node->path);
    my_env[i] = NULL;
    return (my_env);
}

void init_env(char **env, link_t *link)
{
    for (int i = 0; env[i] != NULL; i++)
        add_node_env(env[i], link, recup_name_var_env(env[i]));
}