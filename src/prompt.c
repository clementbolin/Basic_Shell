/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** prompt.c
*/

#include "mysh.h"

int check_stantdar(char *com)
{
    if (access(com, F_OK) == 0) {
        if (access(com, X_OK) == 0) {
            return (1);
        }
    }
    return (0);
}

char *check_acces(link_t *link, char *com)
{
    if (check_stantdar(com) == 1)
        return (com);
    if (link == NULL)
        return (NULL);
    node_t *node = link->head;
    char *path = 0;

    while (node != NULL) {
        path = malloc(sizeof(char) * (my_strlen(node->path)+my_strlen(com)));
        path = my_strcat(node->path, com);
        if (access(path, F_OK) == 0) {
            if (access(path, X_OK) == 0) {
                return (path);
            }
        }
        node = node->next;
    }
    free(path);
    return (NULL);
}

int check_valid_command(link_t *link, link_t *env, char **comm, char *buffer)
{
    int leave = 0;

    link = change_path(env);
    if (my_strlen(buffer) == 0)
        return (2);
    if (my_bin_function(comm, env, &leave) == 1)
        return (2);
    if (leave < 0)
        return (0);
    if (check_acces(link, comm[0]) != NULL)
        return (1);
    else {
        my_putstr(comm[0]);
        my_putstr(": Command not found.");
        my_putchar('\n');
        return (0);
    }
}

int command(link_t *link, char **env, link_t *env_link, info_t info)
{
    if (info.a == -1)
        return (1);
    int i = 0;
    char *buffer_clear = clear_buffer(info.buffer);
    char **comm = my_str_to_word_array(buffer_clear, &i);
    char *bin = 0;
    char **env1 = 0;

    if (my_strcmp("exit", buffer_clear) == 0) {
        my_putstr("exit\n");
        return (1);
    }
    if (check_valid_command(link, env_link, comm, buffer_clear) == 1)
        bin = check_acces(link, comm[0]);
    else
        return (0);
    if (fork() == 0) {
        env1 = env_trans(env_link);
        execve(bin, comm, env1);
    } else {
        wait(NULL);
        return (0);
    }
    return (0);
}

void prompt(char **env, link_t *path, link_t *my_env)
{
    size_t size = 100;
    info_t info;

    info.a = 0;
    info.buffer = malloc(sizeof(char) * 100);
    if (isatty(0) <= 0) {
        info.a = getline(&info.buffer, &size, stdin);
        command(path, env, my_env, info);
        while (info.a >= 0) {
            info.a = getline(&info.buffer, &size, stdin);
            if (info.a < 0)
                break;
            command(path, env, my_env, info);
        }
        return;
    }
    do {
        my_printf("\033[1;31m $\033[1;32m>\033[1;34m ");
    } while ((info.a = getline(&info.buffer, &size, stdin)) && \
            command(path, env, my_env, info) == 0);
}