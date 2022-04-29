/*
** EPITECH PROJECT, 2021
** Mini Shell 2
** File description:
** Mini Shell 2 init structs
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
#include "include/struct.h"

signals *init_signals(void)
{
    signals *s = exoc(sizeof(signals), 1, 0);
    s->pid = getpid();
    s->status = 0;
    s->state = 0;
    return s;
}

command *init_command(void)
{
    command *c = exoc(sizeof(command), 1, 0);
    c->buf = NULL;
    c->str = NULL;
    c->tmp_table = NULL;
    c->spec_command = 0;
    c->cwd = getcwd(NULL, 0);
    c->sep_nbr = 0;
    c->pipe_table = NULL;
    return c;
}

hub *init_hub(void)
{
    hub *h = exoc(sizeof(hub), 1, 0);
    h->c = init_command();
    h->s = init_signals();
    return h;
}
