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
#include <signal.h>

char *get_path(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "PATH", 4) == 0)
            return env[i];
    }
}

int special_commands(char **str, char **env)
{
    if (str == NULL)
        return 0;
    if (my_strcmp(str[0], "cd") == 0)
        return cd_handle(str, env);
    if (my_strcmp(str[0], "env") == 0) {
        for (int i = 0; env[i] != NULL; i++)
            my_printf("%s\n", env[i]);
        return 0;
    }
    if (my_strcmp(str[0], "exit") == 0)
        exoc(0, 0, 0);
    if (my_strcmp(str[0], "setenv") == 0) {
        set_env(env, str);
        return 0;
    }
    if (my_strcmp(str[0], "unsetenv") == 0) {
        unset_env(env, str);
        return 0;
    }
    return 1;
}

void command_not_found(char **str)
{
    if (str[0] != NULL) {
        char *error = str[0];
        char *error2 = ": Command not found.\n";
        char *full_error_msg =
            exoc(sizeof(char) *
            (my_strlen(error) + my_strlen(error2) + 2), 1, 0);
        full_error_msg[0] = '\0';
        my_strcat(full_error_msg, error);
        my_strcat(full_error_msg, error2);
        write(2, full_error_msg, my_strlen(full_error_msg));
    } else {
        write(2, ": Command not found.\n", 21);
    }
    exoc(0, 0, 1);
}

int test_path(char **str, char **env, char *command, char **table)
{
    for (int i = 0; table[i] != NULL; i++) {
        command =
            exoc(sizeof(char) * (my_strlen(table[i]) + my_strlen(str[0]) + 2),
                1, 0);
        if (execve(str[0], str, env) != -1) {
            exoc(0, 0, -1);
            return 0;
        }
        command[0] = '\0';
        command = my_strcat(command, table[i]);
        command = my_strcat(command, "/");
        command = my_strcat(command, str[0]);
        if (execve(command, str, env) != -1) {
            exoc(0, 0, -1);
            return 0;
        }
    }
    return 1;
}

int exec_command(char **str, char **env)
{
    char **table = parse_arg(get_path(env), ":=");
    char *command = NULL;
    return test_path(str, env, command, table);
}
