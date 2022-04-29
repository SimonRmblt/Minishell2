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

int env_error_handling(char **str, int check, char **env)
{
    if (check == 1)
        return 1;
    if (check > 3) {
        write(2, "setenv: Too many arguments.\n", 28);
        return 0;
    }
    if (is_alpha(str[1][0]) == 0) {
        write(2, "setenv: Variable name must begin with a letter.\n", 48);
        return 0;
    }
    if (is_alphanumerical(str[1]) == 0) {
        write(2,
        "setenv: Variable name must contain alphanumeric characters.\n", 60);
        return 0;
    }
    return 1;
}
