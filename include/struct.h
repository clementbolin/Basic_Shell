/*
** EPITECH PROJECT, 2020
** struct
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <unistd.h>

/* //////////////////////////////
            NODE                /
///////////////////////////////*/

typedef struct node_s {
    char *path;
    char *name;
    struct node_s *next;
} node_t;

typedef struct link_s {
    node_t *head;
} link_t;

typedef struct info_s {
    char *buffer;
    int a;
    size_t size;
} info_t;

/* //////////////////////////////
            Binary tree         /
///////////////////////////////*/

typedef struct tree_s {
    int data;
    struct tree_s *left;
    struct tree_s *right;
} tree_t;

typedef struct shell_s {
    link_t *env;
    link_t *path;
    char **my_env;
    info_t *info;
    char **command;
    char *bin;
    int debug;
    int i;
    int error;
    int etat_fork;
    int etat;
} shell_t;

typedef struct ft_s {
    char *name;
    void (*ft)(shell_t *);
} ft_t;

#endif /* !STRUCT_H_ */
