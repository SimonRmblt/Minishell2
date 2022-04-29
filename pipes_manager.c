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

void exec_pipe_minishell(char **env, hub *h)
{
    h->c->tmp_table == NULL ? exoc(0, 0, 0) : 0;
    if (exec_command(h->c->tmp_table, env) == 1)
        command_not_found(h->c->tmp_table);
    exoc(0, 0, 0);
}

void pipe_manager(hub *h, char **env)
{
    if (h->s->state == 0) {
        first_pipe(h, env);
        h->s->state++;
    } else if (h->s->state == 1) {
        mid_pipe(h, env);
    } else {
        last_pipe(h, env);
    }
}

void pipe_handler(hub *h, int i, char **env)
{
    h->s->state = 0;
    int pipes = count_separators(h->c->str[i], "|");
    h->c->pipe_table = parse_arg(h->c->str[i], "|");
    if (get_tab_height(h->c->pipe_table) <= pipes ||
    h->c->pipe_table == NULL) {
        write(2, "Invalid null command.\n", 22);
        return;
    }
    for (int j = 0; h->c->pipe_table[j]; j++) {
        h->c->tmp_table = parse_arg(h->c->pipe_table[j], " \t\r\0");
        if (h->c->tmp_table == NULL) {
            write(2, "Invalid null command.\n", 22);
            return;
        }
        if (h->c->pipe_table[j + 1] == NULL)
            h->s->state++;
        pipe_manager(h, env);
    }
}
