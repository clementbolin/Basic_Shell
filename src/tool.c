/*
** EPITECH PROJECT, 2020
** minishel2
** File description:
** tool
*/

#include "mysh.h"

node_t *recup_node_env(char *search, link_t *env)
{
    node_t *node = env->head;

    while (node != NULL) {
        if (my_strcmp(node->name, search) == 0)
            return (node);
        node = node->next;
    }
    return (NULL);
}

char *clear_buffer(char *b)
{
    char *str = malloc(sizeof(char) * my_strlen(b) + 1);
    int i = 0;
    int j = 0;

    for (; b[i] == ' ' || b[i] == '\t'; i++);
    for (; b[i] != '\n'; i++) {
        str[j] = b[i];
        j += 1;
    }
    str[j] = '\0';
    return (str);
}

char *name_env(char *env)
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

int size_tab(char **tab)
{
    int i = 0;

    for (; tab[i] != NULL; i++);
    return (i);
}