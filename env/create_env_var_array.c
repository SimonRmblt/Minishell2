/*
** EPITECH PROJECT, 2021
** Mini Shell 2
** File description:
** Mini Shell 2 command handler
*/

#include "../include/my.h"
#include "../include/list.h"
#include "../include/minishell.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

char **create_old_pwd_array(void)
{
    char *cwd = getcwd(NULL, 0);
    char *tmp_cwd = my_strdup(cwd);
    free(cwd);
    char **tmp = exoc(sizeof(char *) * 4, 1, 0);
    tmp[0] = NULL;
    tmp[1] = exoc(sizeof(char) * my_strlen("OLDPWD"), 1, 0);
    tmp[1] = "OLDPWD";
    tmp[2] = exoc(sizeof(char) * my_strlen(tmp_cwd), 1, 0);
    tmp[2] = tmp_cwd;
    tmp[3] = NULL;
    return tmp;
}

char **create_pwd_array(void)
{
    char *cwd = getcwd(NULL, 0);
    char *tmp_cwd = my_strdup(cwd);
    free(cwd);
    char **tmp = exoc(sizeof(char *) * 4, 1, 0);
    tmp[0] = NULL;
    tmp[1] = exoc(sizeof(char) * my_strlen("PWD"), 1, 0);
    tmp[1] = "PWD";
    tmp[2] = exoc(sizeof(char) * my_strlen(tmp_cwd), 1, 0);
    tmp[2] = tmp_cwd;
    tmp[3] = NULL;
    return tmp;
}

char **create_path_array(void)
{
    char *path = "/usr/local/sbin:/usr/local/bin:/usr/sbin:"
    "/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin";
    char **tmp = exoc(sizeof(char *) * 4, 1, 0);
    tmp[0] = NULL;
    tmp[1] = exoc(sizeof(char) * my_strlen("PATH"), 1, 0);
    tmp[1] = "PATH";
    tmp[2] = exoc(sizeof(char) * my_strlen(path), 1, 0);
    tmp[2] = path;
    tmp[3] = NULL;
    return tmp;
}
