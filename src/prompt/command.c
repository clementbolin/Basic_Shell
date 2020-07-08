/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** basic command check
*/

#include "mysh.h"

int stantar_check(char *com, shell_t *shell)
{
    if (access(com, F_OK) == 0) {
        shell->bin = my_strcpy(shell->bin, com);
        if (access(com, X_OK) == 0) {
            return (1);
        }
    }
    return (0);
}

void check_acess(shell_t *shell)
{
    node_t *node = shell->path->head;

    if (node == NULL) {
        shell->bin = 0;
        return;
    }
    if (stantar_check(shell->command[0], shell) == 1) return;
    for (; node != NULL; node = node->next) {
        shell->bin = my_strcat(node->path, shell->command[0]);
        if (access(shell->bin, F_OK) == 0) {
            if (access(shell->bin, X_OK) == 0)
                return;
        }
    }
    free(shell->bin);
    shell->bin = 0;
}

int is_valid_command(shell_t *shell, char *buffer)
{
    regeneration_path(shell);
    if (my_strlen(buffer) == 0)
        return (1);
    if (my_strcmp(shell->command[0], "exit") == 0) {
        my_printf("exit\n");
        shell->etat_fork = EXIT;
        return (EXIT);
    }
    if (my_bin_tab(shell) == 1) return (1);
    check_acess(shell);
    shell->etat_fork = 0;
    if (shell->bin == 0) {
        my_printf("%s: Command not found.\n", shell->command[0]);
        return (1);
    }
    return (START);
}

int command(shell_t *shell)
{
    if (shell->info->a == -1) return (1);
    char *buffer_clear = clear_buffer(shell->info->buffer);
    int value_acess = 0;

    shell->command = my_str_to_word_array(buffer_clear, &shell->i);
    value_acess = is_valid_command(shell, buffer_clear);
    if (value_acess == EXIT) return (EXIT);
    if (value_acess == 1) return (0);
    if (fork() == 0 && shell->etat_fork == 0)
        check_exec(shell);
    else {
        wait(&shell->error);
        return (0);
    }
    check_segfault(shell->error);
    return (0);
}