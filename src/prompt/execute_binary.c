/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** execute_binary
*/

#include "mysh.h"

void check_exec(shell_t *shell)
{
    if (execve(shell->bin, shell->command, \
    transform_env(shell->env)) == -1 && errno != ENOEXEC) {
        my_printf("%s: Permission denied.\n", shell->command[0]);
    }
    if (errno == ENOEXEC)
        my_printf("%s: Exec format error. Wrong Architecture.\n", \
        shell->command[0]);
    shell->etat = EXIT;
}

void check_segfault(int error)
{
    if (error == 11)
        my_printf("Segmentation fault\n");
    if (error == 136 || error == 8)
        my_printf("Floating exception\n");
}