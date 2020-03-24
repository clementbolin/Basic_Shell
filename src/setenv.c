/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** setenv.c
*/

#include "mysh.h"

int no_arg_setenv(char *name, char const *value, link_t *link_env)
{
    if (name == NULL && value == NULL) {
        display_link_env(link_env);
        return (0);
    }
    return (1);
}

int env_manage(char *name, char const *value, link_t *link_env)
{
    node_t *node = link_env->head;
    char *name_path = 0;

    if (no_arg_setenv(name, value, link_env) == 0) return (0);
    if (name != NULL && value == NULL) {
        while (node != NULL) {
            name_path = name_env(node->path);
            if (my_strcmp(name_path, name) == 0) {
                name = my_strcat(name, "=");
                node->path = my_strcpy(node->path, name);
                return (0);
            }
            node = node->next;
        }
        name = my_strcat(name, "=");
        add_node_env(name, link_env, "ONLY");
        return (0);
    }
    return (1);
}

void my_setenv(char *name, char const *value, link_t *link_env)
{
    node_t *node = link_env->head;
    char *path = 0;

    if (env_manage(name, value, link_env) == 0) return;
    while (node != NULL) {
        if (my_strcmp(node->name, name) == 0)
            break;
        node = node->next;
    }
    if (node == NULL) {
        path = my_strcpy(path, name);
        path = my_strcat(path, "=");
        path = my_strcat(path, value);
        add_node_env(path, link_env, name);
        return;
    }
    path = my_strcpy(path, name);
    path = my_strcat(path, "=");
    path = my_strcat(path, value);
    node->path = my_strcpy(node->path, path);
}

void my_unsetenv(char **name, link_t *link_env)
{
    int i = 0;
    node_t *node = link_env->head;

    for (int j = 1; name[j] != NULL; j++) {
        node = link_env->head;
        while (node != NULL) {
            if (my_strcmp(node->name, name[j]) == 0)
                delete_node_env(i, link_env);
            i += 1;
            node = node->next;
        }
    }
}