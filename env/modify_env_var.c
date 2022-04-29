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

char **add_var_opt(char **env, char **str)
{
    char **new_env = NULL;
    char *full_str = exoc(
        sizeof(char) * (my_strlen(str[1]) + my_strlen(str[2]) + 2), 1, 0);
    int env_size = 0;
    for (int i = 0; env[i] != NULL; i++)
        env_size++;
    full_str[0] = '\0';
    full_str = my_strcat(full_str, str[1]);
    full_str = my_strcat(full_str, "=");
    full_str = my_strcat(full_str, str[2]);
    new_env = malloc_env_array(env, 2);
    new_env[env_size] = my_strdup(full_str);
    new_env[env_size + 1] = NULL;
    return write_on_tab(env, new_env);
}

char **add_var(char **env, char **str)
{
    char **new_env = NULL;
    char *full_str = exoc(
        sizeof(char) * (my_strlen(str[1]) + 3), 1, 0);
    int env_size = 0;
    for (int i = 0; env[i] != NULL; i++)
        env_size++;
    full_str[0] = '\0';
    full_str = my_strcat(full_str, str[1]);
    full_str = my_strcat(full_str, "=");
    new_env = malloc_env_array(env, 2);
    new_env[env_size] = my_strdup(full_str);
    new_env[env_size + 1] = NULL;
    return write_on_tab(env, new_env);
}

char *replace_var(char **env, char **str, int check)
{
    if (check == 2) {
        char *tmp = exoc(sizeof(char) * (my_strlen(str[1]) + 3), 1, 0);
        tmp[0] = '\0';
        tmp = my_strcat(tmp, str[1]);
        tmp = my_strcat(tmp, "=");
        return tmp;
    } else if (check == 3) {
        char *tmp = exoc(sizeof(char) *
            (my_strlen(str[1]) + my_strlen(str[2]) + 2), 1, 0);
        tmp[0] = '\0';
        tmp = my_strcat(tmp, str[1]);
        tmp = my_strcat(tmp, "=");
        tmp = my_strcat(tmp, str[2]);
        return tmp;
    }
}
