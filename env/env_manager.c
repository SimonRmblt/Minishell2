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

char *get_env_var(char **env, char *var, int size)
{
    char *env_var = NULL;
    int j = -1;
    int a = 0;
    for (int i = 0; env[i] != NULL; i++)
        if (my_strncmp(env[i], var, size) == 0)
            j = i;
    if (j == -1)
        return NULL;
    env_var =
        exoc(sizeof(char) * (my_strlen(env[j]) - size) + 1, 1, 0);
    for (int i = size; env[j][i] != '\0'; i++ && a++)
        env_var[a] = env[j][i];
    env_var[a] = '\0';
    return env_var;
}

char **set_env(char **env, char **str)
{
    int check = 0;
    for (int i = 0; str[i] != NULL; i++)
        check++;
    if (env_error_handling(str, check, env) == 0)
        return env;
    env = add_to_env(env, str, check);
    return env;
}

char **write_over_array(char **src, char **dest)
{
    for (int i = 0; src[i]; i++) {
        dest[i] = my_strdup(src[i]);
    }
    return dest;
}

char **unset_env(char **env, char **str)
{
    char **new_env = NULL;
    new_env = exoc(sizeof(char *) * get_tab_height(env) + 1, 1, 0);
    if (get_tab_height(str) == 1) {
        write(2, "unsetenv: Too few arguments.\n", 29);
        return env;
    }
    for (int i = 1; str[i]; i++) {
        new_env = remove_env_var(str[i], env, new_env);
        env = write_over_array(new_env, env);
    }
    return env;
}
