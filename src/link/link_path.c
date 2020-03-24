/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** link.c
*/

#include "mysh.h"

node_t *create_node(char *path)
{
    node_t *new_node = malloc(sizeof(*new_node));

    if (!new_node)
        return (NULL);
    new_node->path = path;
    new_node->next = NULL;
    return (new_node);
}

link_t *init_list(void)
{
    link_t *link = malloc(sizeof(link));

    if (!link)
        return (NULL);
    link->head = NULL;
    return (link);
}

void display_link(link_t *link)
{
    node_t *current = link->head;

    if (link->head == NULL)
        return;
    for (; current != NULL; current = current->next)
        my_printf("%s-> ", current->path);
    my_printf("NULL\n");
}

void add_node(char *path, link_t *link)
{
    node_t *current = NULL;

    if (link->head == NULL)
        link->head = create_node(path);
    else {
        current = link->head;
        while (current->next != NULL)
            current = current->next;
        current->next = create_node(path);
    }
}

void delete_node(int size, link_t *link)
{
    node_t *current = link->head;
    node_t *prev = current;
    int i = 0;

    while (current != NULL) {
        if (i == size) {
            prev->next = current->next;
            if (current == link->head)
                link->head = current->next;
            free(current);
            return;
        }
        prev = current;
        current = current->next;
        i += 1;
    }
}