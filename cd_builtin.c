/*
** EPITECH PROJECT, 2021
** Mini Shell 2
** File description:
** Mini Shell 2 command handler
*/

#include "include/my.h"
#include "include/list.h"
#include "include/minishell.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

int cd_error_handling(char **str, char **env, int size)
{
    char *error_msg = NULL;
    if (size > 1 && chdir(str[1]) == -1) {
        if (access(str[1], F_OK) == -1) {
            write(2, str[1], my_strlen(str[1]));
            write(2, ": No such file or directory.\n", 29);
            return 0;
        }
        write(2, str[1], my_strlen(str[1]));
        write(2, ": Not a directory.\n", 19);
    }
    return 0;
}

int my_cd(char **str, char **env, int i)
{
    if (str[1] == NULL || str[1][0] == '~') {
        check_if_exists_env(env, create_old_pwd_array(), 3);
        return chdir(get_env_var(env, "HOME=", 5));
    } else if (my_strcmp(str[1], "home") == 0) {
        check_if_exists_env(env, create_old_pwd_array(), 3);
        my_printf("~\n");
        return chdir(get_env_var(env, "HOME=", 5));
    }
    if (my_strncmp(str[1], "-", 1) == 0 && my_strlen(str[1]) == 1) {
        return chdir(get_env_var(env, "OLDPWD=", 7));
    } else {
        check_if_exists_env(env, create_old_pwd_array(), 3);
        return cd_error_handling(str, env, i);
    }
    return 1;
}

int cd_handle(char **str, char **env)
{
    int i = 0;
    check_if_exists_env(env, create_pwd_array(), 3);
    while (str[i] != NULL)
        i++;
    if (i > 2) {
        write(2, "cd: Too many arguments.\n", 24);
        return 0;
    }
    return my_cd(str, env, i);
}
