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

void sig_handler(int sig_num)
{
    if (sig_num == 2)
        return;
}

void my_segfault(int status)
{
    int signal = WIFSIGNALED(status);
    if (signal == 1) {
        write(2, strsignal(11), my_strlen(strsignal(11)));
        write(2, " (core dumped)\n", 15);
    }
}
