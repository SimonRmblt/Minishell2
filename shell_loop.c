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
#include "include/struct.h"
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

void fork_minishell(char **env, hub *h)
{
    h->s->pid = fork();
    if (h->s->pid == 0) {
        h->c->tmp_table == NULL ? exoc(0, 0, 0) : 0;
        if (exec_command(h->c->tmp_table, env) == 1)
            command_not_found(h->c->tmp_table);
        exoc(0, 0, 0);
    } else {
        waitpid(h->s->pid, &h->s->status, 0);
        my_segfault(h->s->status);
    }
}

void display_prompt(hub *h)
{
    if (wait(&h->s->status) > 0 || h->s->pid != 0 && isatty(0)) {
        signal(SIGINT, sig_handler);
        my_printf(H_MAG "%s >>> " RESET, h->c->cwd);
    }
}

int main_loop(char **env)
{
    hub *h = init_hub();
    int pos = 0;

    display_prompt(h);
    free(h->c->cwd);
    h->c->str = prompt(h);
    if (h->c->str == NULL)
        return 0;
    for (int i = 0; h->c->str[i] != NULL; i++) {
        if (char_in_string(h->c->str[i], '|')) {
            pipe_handler(h, i, env);
            continue;
        }
        h->c->tmp_table = parse_arg(h->c->str[i], " \t\r\0");
        h->c->spec_command = special_commands(h->c->tmp_table, env);
        check_if_exists_env(env, create_pwd_array(), 3);
        if (h->c->spec_command == 0)
            continue;
        fork_minishell(env, h);
    }
}
