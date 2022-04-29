/*
** EPITECH PROJECT, 2021
** Mini Shell 2
** File description:
** Mini Shell 2 main
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

char **malloc_env_array(char **env, int size)
{
    char **new_env = NULL;
    int i = 0;
    new_env = exoc(sizeof(char *) * (get_tab_height(env) + size), 1, 0);
    for (; env[i] != NULL; i++) {
        new_env[i] = my_strdup(env[i]);
        new_env[i + 1] = NULL;
    }
    return new_env;
}

int main(int ac, char **av, char **env)
{
    char **new_env = malloc_env_array(env, 1);
    while (1) {
        main_loop(new_env);
    }
    return 0;
}
