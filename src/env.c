/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** env.c
*/

#include "mysh.h"

char *my_getenv(char const *path, char **env)
{
    char *str = 0;
    char *tmp = 0;
    int i = 0;
    int j = 0;

    for (; env[i] != NULL; i++) {
        tmp = malloc(sizeof(char) * my_strlen(env[i]) + 1);
        for (; env[i][j] != '='; j++) {
            tmp[j] = env[i][j];
        }
        tmp[j] = '\0';
        if (my_strcmp(tmp, path) == 0) {
            str = my_strcpy(str, env[i]);
            return (str);
        }
        free(tmp);
        j = 0;
    }
    return (NULL);
}

void pars_path(link_t *link, char const *path)
{
    char *str = 0;
    int i = 0;
    int j = 0;

    for (; path[i] != '='; i++);
    i += 1;
    str = malloc(sizeof(char) * my_strlen(path) + 2);
    for (; path[i] != '\0'; i++, j++) {
        if (path[i] == ':') {
            str[j] = '/';
            str[j+1] = '\0';
            add_node(str, link);
            str = malloc(sizeof(char) * my_strlen(path) + 2);
            j = 0;
            i += 1;
        }
        str[j] = path[i];
    }
    free(str);
}

void pars_last_path(link_t *link, char const *path)
{
    char *str = malloc(sizeof(char) * my_strlen(path) + 2);
    int i = my_strlen(path) - 1;
    int j = 1;

    str[0] = '/';
    for (; path[i] != '='; i--, j++) {
        if (path[i] == ':') {
            str[j] = '\0';
            my_printf("str = %s\n", str);
            str = my_revstr(str);
            add_node(str, link);
            break;
        }
        str[j] = path[i];
    }
    free(str);
}

void create_new_env(char **env, link_t *env_link)
{
    char *name = 0;

    for (int i = 0; env[i] != NULL; i++) {
        name = name_env(env[i]);
        add_node_env(env[i], env_link, name);
    }
}