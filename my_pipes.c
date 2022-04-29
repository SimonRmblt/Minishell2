/*
** EPITECH PROJECT, 2021
** Mini Shell 2
** File description:
** Mini Shell 2 loop
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/list.h"
#include "include/minishell.h"
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

void close_fd(hub *h)
{
    close(h->s->fd1[1]);
    close(h->s->fd1[0]);
    close(h->s->fd[1]);
    close(h->s->fd[0]);
}

void first_pipe(hub *h, char **env)
{
    int pid;
    if (pipe(h->s->fd) == -1)
        exoc(0, 0, 84);
    pid = fork();
    if (pid == 0) {
        dup2(h->s->fd[1], 1);
        close(h->s->fd[1]);
        close(h->s->fd[0]);
        exec_pipe_minishell(env, h);
    }
}

void mid_pipe(hub *h, char **env)
{
    int pid;
    if (pipe(h->s->fd1) == -1)
        exoc(0, 0, 84);
    pid = fork();
    if (pid == 0) {
        dup2(h->s->fd[0], 0);
        dup2(h->s->fd1[1], 1);
        close_fd(h);
        exec_pipe_minishell(env, h);
    } else {
        close(h->s->fd[1]);
        close(h->s->fd[0]);
        h->s->fd[0] = h->s->fd1[0];
        h->s->fd[1] = h->s->fd1[1];
    }
}

void last_pipe(hub *h, char **env)
{
    int pid = fork();
    if (pid == 0) {
        dup2(h->s->fd[0], 0);
        close(h->s->fd[1]);
        close(h->s->fd[0]);
        exec_pipe_minishell(env, h);
    } else {
        close(h->s->fd[1]);
        close(h->s->fd[0]);
        waitpid(pid, NULL, 0);
    }
}
