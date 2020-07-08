/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** link env
*/

#include "mysh.h"

node_t *create_node_env(char *path, char *name)
{
    node_t *new_node = malloc(sizeof(*new_node));

    if (!new_node)
        return (NULL);
    new_node->path = path;
    new_node->name = name;
    new_node->next = NULL;
    return (new_node);
}

void display_link_env(link_t *link)
{
    node_t *current = link->head;

    if (link->head == NULL)
        return;
    for (; current != NULL; current = current->next)
        my_printf("%s\n", current->path);
}

void add_node_env(char *path, link_t *link, char *name)
{
    node_t *current = NULL;

    if (link->head == NULL)
        link->head = create_node_env(path, name);
    else {
        current = link->head;
        while (current->next != NULL)
            current = current->next;
        current->next = create_node_env(path, name);
    }
}