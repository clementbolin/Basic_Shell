/*
** EPITECH PROJECT, 2020
** link path execve
** File description:
** link_path
*/

#include "mysh.h"

node_t *create_node_path(char *path)
{
    node_t *new_node = malloc(sizeof(*new_node));

    if (!new_node)
        return (NULL);
    new_node->path = path;
    new_node->next = NULL;
    return (new_node);
}

void add_node_path(char *path, link_t *link)
{
    node_t *current = NULL;

    if (link->head == NULL)
        link->head = create_node_path(path);
    else {
        current = link->head;
        while (current->next != NULL)
            current = current->next;
        current->next = create_node_path(path);
    }
}

void display_link_path(link_t *link)
{
    node_t *current = link->head;

    if (link->head == NULL)
        return;
    for (; current != NULL; current = current->next)
        my_printf("%s:", current->path);
    my_printf("NULL\n");
}