/*
** EPITECH PROJECT, 2021
** Mini Shell 2
** File description:
** Mini Shell 2 env manager
*/

#include "../include/my.h"
#include "../include/list.h"
#include "../include/minishell.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int check_if_exists_unset(char **env, char *str, int i)
{
    if (my_strncmp(env[i], str, my_strlen(str)) == 0 &&
        env[i][my_strlen(str)] == '=') {
        return 0;
    }
    return 1;
}

char **remove_env_var(char *var, char **env, char **new_env)
{
    int a = 0;
    for (int i = 0; env[i] != NULL; i++ && a++) {
        if (check_if_exists_unset(env, var, i) == 0)
            continue;
        if (env[i] != NULL) {
            new_env[a] = my_strdup(env[i]);
            new_env[a + 1] = NULL;
        }
    }
    return new_env;
}
