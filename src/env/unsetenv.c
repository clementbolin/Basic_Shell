/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** unsetenv
*/

#include "mysh.h"

void my_unsetenv(char **name, link_t *link_env)
{
    int i = 0;
    node_t *node = link_env->head;

    for (int j = 1; name[j] != NULL; j++) {
        node = link_env->head;
        i = 0;
        while (node != NULL) {
            if (my_strcmp(node->name, name[j]) == 0) {
                delete_node(i, link_env);
                break;
            }
            i += 1;
            node = node->next;
        }
    }
}

void check_unsetenv(shell_t *shell)
{
    if (size_tab(shell->command) == 1) {
        my_putstr("unsetenv: Too few arguments.\n");
    } else
        my_unsetenv(shell->command, shell->env);
}