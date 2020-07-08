/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** prompt
*/

#include "mysh.h"

info_t *init_info(int size_malloc, size_t size_read)
{
    info_t *info = malloc(sizeof(*info));

    info->buffer = malloc(sizeof(char) * size_malloc);
    if (info->buffer == NULL)
        return (NULL);
    info->size = size_read;
    if (info->size <= 0)
        return (NULL);
    info->a = 0;
    return (info);
}

int prompt(shell_t *shell)
{
    if ((shell->info = init_info(100, 100)) == NULL)
        return (84);
    if (isatty(0) <= 0) {
        shell->info->a = getline(&shell->info->buffer, &shell->info->size, \
        stdin);
        command(shell);
        while (shell->info->a >= 0) {
            shell->info->a = getline(&shell->info->buffer, &shell->info->size, \
            stdin);
            if (shell->info->a < 0)
                break;
            command(shell);
        }
        return (0);
    }
    do {
        my_printf("\033[1;31m $\033[1;32m>\033[1;34m ");
    } while ((shell->info->a = getline(&shell->info->buffer, \
    &shell->info->size, stdin)) && command(shell) == 0 && shell->etat == 0);
    return (0);
}