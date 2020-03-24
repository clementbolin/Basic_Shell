/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** mysh
*/

#ifndef MYSH_H_
#define MYSH_H_

#include "struct.h"

/*########################### ENV ##################*/
char *my_getenv(char const *path, char **env);
void pars_path(link_t *link, char const *path);
void pars_last_path(link_t *link, char const *path);
void create_new_env(char **env, link_t *env_link);
void my_setenv(char *name, char const *value, link_t *link_env);
void my_unsetenv(char **name, link_t *link_env);

/*########################## LINK PATH #############*/
node_t *create_node(char *path);
link_t *init_list(void);
void display_link(link_t *link);
void add_node(char *path, link_t *link);
void delete_node(int size, link_t *link);

/*######################### LINK ENV ###############*/
node_t *create_node_env(char *path, char *name);
void display_link_env(link_t *link);
void add_node_env(char *path, link_t *link, char *name);
void delete_node_env(int size, link_t *link);

/*######################### PROMPT #################*/
void prompt(char **env, link_t *path, link_t *my_env);
int command(link_t *link, char **env, link_t *env_link, info_t info);
char *check_acces(link_t *link, char *com);
int my_bin_function(char **com, link_t *env, int *leave);

/*###################### TOOL ####################*/
char *clear_buffer(char *buffer);
char *name_env(char *env);
char *recup_variable(char const *name, link_t *env_link);
char *reucp_value_env(char const *value);
int size_tab(char **com);
int my_linklen(link_t *env);
char **env_trans(link_t *env);
link_t *change_path(link_t *env);

/*#################### CD #########################*/
void cd(link_t *env_link, char *path);
int basic_cd(char *path, char *buffer, char *oldpwd, link_t *env_link);


#endif /* !MYSH_H_ */
