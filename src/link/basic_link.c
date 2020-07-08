/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** basic link
*/

#include "mysh.h"

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

link_t *init_list(void)
{
    link_t *link = malloc(sizeof(link));

    if (!link)
        return (NULL);
    link->head = NULL;
    return (link);
}

void destroy_link(link_t *link)
{
    node_t *current = link->head;
    node_t *next = current;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(link);
}