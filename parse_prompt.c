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

char **parse_command(hub *h)
{
    h->c->str = parse_arg(h->c->buf, ";");
    free(h->c->buf);
    if (h->c->str == NULL)
        return NULL;
    return h->c->str;
}

char **prompt(hub *h)
{
    size_t len = 0;

    if (getline(&h->c->buf, &len, stdin) == -1) {
        isatty(0) ? my_printf("exit\n") : 0;
        free(h->c->buf);
        exoc(0, 0, h->s->status);
    }
    h->c->buf[char_pos_finder(h->c->buf, '\n')] = '\0';
    if (my_strlen(h->c->buf) == 0) {
        free(h->c->buf);
        return NULL;
    }
    return parse_command(h);
}
