/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** init_path_link
*/

#include "mysh.h"

void regeneration_path(shell_t *shell)
{
    destroy_link(shell->path);
    shell->path = init_list();
    init_link_path(shell->env, shell->path);
}

void clear_str(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ':')
            str[i] = '\0';
    }
}

int recup_size_j(node_t *current)
{
    int i = 0;

    for (; current->path[i] != '='; i++);
    i += 1;
    return (i);
}

void init_link_path(link_t *env, link_t *path)
{
    node_t *current = recup_node_env("PATH", env);
    char *str = malloc(sizeof(char) * 40);
    int j = 0;
    int i = 0;

    if (current == NULL) return;
    for (i = recup_size_j(current); current->path[i] != '\0'; i++) {
        str[j] = current->path[i];
        j += 1;
        if (current->path[i] == ':' || current->path[i+1] == '\0') {
            str[j] = '\0';
            clear_str(str);
            j = 0;
            str = my_strcat(str, "/");
            add_node_path(str, path);
            str = malloc(sizeof(char) * 40);
            continue;
        }
    }
    free(str);
}