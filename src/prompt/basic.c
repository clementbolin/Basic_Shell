/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** basic
*/

#include "mysh.h"

static ft_t comm_array[] = {
    {"setenv", check_setenv},
    {"env", env},
    {"unsetenv", check_unsetenv},
    {"cd", check_cd}
};

int my_bin_tab(shell_t *shell)
{
    for (int i = 0; i < 4; i++) {
        if (my_strcmp(shell->command[0], comm_array[i].name) == 0) {
            comm_array[i].ft(shell);
            shell->etat_fork = LEAVE;
            return (1);
        }
    }
    return (0);
}