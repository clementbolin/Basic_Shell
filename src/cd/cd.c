/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** cd.c
*/

#include "mysh.h"

static char *oldpwd = 0;

char *pars_cd_arg(char const *arg)
{
    char *path = malloc(sizeof(char) * my_strlen(arg) + 1);
    int i = 0;
    int j = 0;

    for (; arg[i] != ' '; i++);
    for (; arg[i] != '\0'; i++, j++)
        path[j] = arg[i];
    path[j] = '\0';
    return (path);
}

char *cut_egal(char *str)
{
    int i = 1;
    int j = 0;
    char *new = malloc(sizeof(char) * my_strlen(str));

    for (; str[i] != '\0'; i++, j++)
        new[j] = str[i];
    new[j+1] = '\0';
    return (new);
}

int no_arg(link_t *env_link, char *path)
{
    char *buffer = 0;
    char *str = 0;

    if (path == 0) {
        str = recup_variable("HOME", env_link);
        str = reucp_value_env(str);
        str = cut_egal(str);
        oldpwd = getcwd(oldpwd, 150);
        chdir(str);
        my_setenv("PWD", getcwd(buffer, 150), env_link);
        my_setenv("OLDPWD", oldpwd, env_link);
        return (1);
    }
    return (0);
}

int sub_cd(link_t *env_link, char *path)
{
    char *buf = getcwd(buf, 150);

    if (my_strcmp(path, "-") == 0) {
        if (my_strcmp(oldpwd, buf) == 0) {
            my_putstr(": Not a file or directory\n");
            return (1);
        }
        chdir(oldpwd);
        my_setenv("OLDPWD", buf, env_link);
        my_setenv("PWD", oldpwd, env_link);
        return (1);
    }
    return (0);
}

void cd(link_t *env_link, char *path)
{
    char *buffer = 0;
    char *pwd = 0;

    if (no_arg(env_link, path) == 1) return;
    oldpwd = getcwd(oldpwd, 150);
    if (sub_cd(env_link, path) == 1) return;
    if (basic_cd(path, buffer, oldpwd, env_link) == 1) return;
    if (chdir(path) < 0) {
        my_putstr(path);
        my_putstr(": Not a directory");
        my_putchar('\n');
        return;
    }
    buffer = getcwd(buffer, 150);
    my_setenv("OLDPWD", oldpwd, env_link);
    my_setenv("PWD", buffer, env_link);
}