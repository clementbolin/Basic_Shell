/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** tool.c
*/

#include "mysh.h"

char *clear_buffer(char *b)
{
    char *str = malloc(sizeof(char) * my_strlen(b) + 1);
    int i = 0;

    for (; (b[i] < 'A' && b[i] > 'Z') || (b[i] < 'a' && b[i] > 'z'); i++);
    for (; b[i] != '\n'; i++)
        str[i] = b[i];
    b[i] = '\0';
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

char **env_trans(link_t *env)
{
    node_t *node = env->head;
    char **env_str = 0;
    int i = 0;

    env_str = malloc(sizeof(char *) * my_linklen(env) + 1);
    while (node != NULL) {
        env_str[i] = my_strcpy(env_str[i], node->path);
        i += 1;
        node = node->next;
    }
    env_str[i] = NULL;
    return (env_str);
}