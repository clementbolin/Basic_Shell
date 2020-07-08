/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** tool env
*/

#include "mysh.h"

char *recup_variable(char const *name, link_t *env_link)
{
    node_t *node = env_link->head;
    char *str = 0;

    while (node != NULL) {
        if (my_strcmp(name, node->name) == 0)
            break;
        node = node->next;
    }
    if (node == NULL)
        return (NULL);
    str = my_strcpy(str, node->path);
    return (str);
}

char *reucp_value_env(char const *value)
{
    int i = 0;
    int j = 0;
    char *str = malloc(sizeof(char) * my_strlen(value) + 1);

    while (value[i] != '=')
        i += 1;
    for (; value[i] != '\0'; i++, j++)
        str[j] = value[i];
    str[j] = '\0';
    return (str);
}