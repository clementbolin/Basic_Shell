/*
** EPITECH PROJECT, 2020
** strcut mysh
** File description:
** struct.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include "my.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

typedef struct node_s {
    char *path;
    char *name;
    struct node_s *next;
} node_t;

typedef struct link_s {
    node_t *head;
}link_t;

typedef struct info_s {
    char *buffer;
    int a;
} info_t;

#endif /* !STRUCT_H_ */
