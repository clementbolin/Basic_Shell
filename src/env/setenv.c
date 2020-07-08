/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** setenv
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

void check_setenv(shell_t *shell)
{
    if (size_tab(shell->command) == 1) {
        display_link_env(shell->env);
        return;
    }
    if (size_tab(shell->command) > 3)
        my_putstr("setenv: Too many arguments.\n");
    else {
        for (int i = 1; shell->command[i]; i++) {
            if (is_alphanumeric(shell->command[i]) == -1) {
                my_printf("setenv: Variable name must contain ");
                my_printf("alphanumeric characters.\n");
                return;
            }
        }
        my_setenv(shell->command[1], shell->command[2], shell->env);
    }
}

void env(shell_t *shell)
{
    display_link_env(shell->env);
}