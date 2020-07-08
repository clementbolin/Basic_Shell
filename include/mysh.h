/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** mysh
*/

#ifndef MYSH_H_
#define MYSH_H_

#include "struct.h"
#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/errno.h>

#define EXIT 10
#define START 0
#define LEAVE 80

/* //////////////////////////////
            LINK                /
///////////////////////////////*/
node_t *create_node_env(char *path, char *name);
void display_link_env(link_t *link);
void add_node_env(char *path, link_t *link, char *name);
node_t *create_node_path(char *path);
void add_node_path(char *path, link_t *link);
void display_link_path(link_t *link);
void delete_node(int size, link_t *link);
link_t *init_list(void);
void destroy_link(link_t *link);
void regeneration_path(shell_t *shell);

/* //////////////////////////////
            ENV                 /
///////////////////////////////*/
void init_env(char **env, link_t *link);

/* //////////////////////////////
            ENV                 /
///////////////////////////////*/
void init_link_path(link_t *env, link_t *path);
char **transform_env(link_t *env);
char *reucp_value_env(char const *value);
char *recup_variable(char const *name, link_t *env_link);;

/* //////////////////////////////
            TOOL                /
///////////////////////////////*/
node_t *recup_node_env(char *search, link_t *env);
char *clear_buffer(char *b);
char *name_env(char *env);
int size_tab(char **tab);
int is_alphanumeric(char *str);

/* //////////////////////////////
            PROMPT              /
///////////////////////////////*/
int prompt(shell_t *shell);
int command(shell_t *shell);
void check_segfault(int error);
void check_exec(shell_t *shell);
int my_bin_tab(shell_t *shell);

/* //////////////////////////////
            CD                  /
///////////////////////////////*/
char *pars_cd_arg(char const *arg);
char *cut_egal(char *str);
int no_arg(link_t *env_link, char *path);
int sub_cd(link_t *env_link, char *path);
void cd(link_t *env_link, char *path);
int basic_cd(char *path, char *buffer, char *oldpwd, link_t *env_link);
void check_cd(shell_t *shell);

/* //////////////////////////////
    SETENV UNSETENV             /
///////////////////////////////*/
void my_setenv(char *name, char const *value, link_t *link_env);
void check_setenv(shell_t *shell);
void env(shell_t *shell);
void check_unsetenv(shell_t *shell);

/* //////////////////////////////
        BINARY TREE             /
///////////////////////////////*/

#endif /* !MYSH_H_ */
