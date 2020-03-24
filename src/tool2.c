/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** tool2.c
*/

#include "mysh.h"

int my_linklen(link_t *env)
{
    int i = 0;
    node_t *node = env->head;

    while (node != NULL) {
        node = node->next;
        i += 1;
    }
    return (i);
}

node_t *nr_ft(link_t *env)
{
    node_t *node = env->head;
    while (node != NULL) {
        if (my_strcmp(node->name, "PATH") == 0)
            break;
        node = node->next;
    }
    if (node == NULL) {
        return (NULL);
    }
    return (node);
}

link_t *fill_link(node_t *node, int i, char *str, int j)
{
    link_t *link = init_list();

    for (; node->path[i] != '='; i++);
    i += 1;
    str = malloc(sizeof(char) * my_strlen(node->path) + 2);
    for (; node->path[i] != '\0'; i++, j++) {
        if (node->path[i] == ':') {
            str[j] = '/';
            str[j+1] = '\0';
            add_node(str, link);
            str = malloc(sizeof(char) * my_strlen(node->path) + 2);
            j = 0;
            i += 1;
        }
        str[j] = node->path[i];
    }
    return (link);
}

link_t *change_path(link_t *env)
{
    node_t *node = nr_ft(env);
    link_t *link = init_list();
    char *str = 0;
    int i = 0;
    int j = 0;

    if (node == NULL) return (NULL);
    link = fill_link(node, i, str, j);
    free(str);
    return (link);
}