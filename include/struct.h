/*
** EPITECH PROJECT, 2021
** Structures
** File description:
** Includes all the structures
*/


#ifndef STRUCT_H
    #define STRUCT_H

typedef struct c {
    char *buf;
    char **str;
    int spec_command;
    char *cwd;
    char **tmp_table;
    int sep_nbr;
    char **pipe_table;
} command;

typedef struct s {
    int pid;
    int status;
    int state;
    int fd[2];
    int fd1[2];
} signals;

typedef struct h {
    command *c;
    signals *s;
} hub;

#endif
