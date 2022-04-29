/*
** EPITECH PROJECT, 2021
** Minishell
** File description:
** Includes all the functions in minishell2
*/

#include <stddef.h>
#include "../include/struct.h"

#ifndef MINISHELL_H
    #define MINISHELL_H

void pipe_handler(hub *h, int i, char **env);
void pipe_manager(hub *h, char **env);
void exec_pipe_minishell(char **env, hub *h);
void last_pipe(hub *h, char **env);
void mid_pipe(hub *h, char **env);
void first_pipe(hub *h, char **env);
char **write_on_tab(char **dest, char **src);
char **malloc_env_array(char **env, int);
char **create_path_array(void);
char **create_pwd_array(void);
char **create_old_pwd_array(void);
char **check_if_exists_env(char **env, char **str, int check);
char **add_var_opt(char **env, char **str);
char **add_var(char **env, char **str);
char *replace_var(char **env, char **str, int check);
void my_segfault(int status);
hub *init_hub(void);
char **parse_command(hub *);
char **prompt(hub *);
void sig_handler(int sig_num);
int get_tab_height(char **str);
char *my_strdup(char *str);
char **remove_env_var(char *var, char **env, char **new_env);
char **unset_env(char **env, char **str);
char *get_env_var(char **env, char *var, int size);
int cd_handle(char **str, char **env);
void command_not_found(char **str);
char **add_to_env(char **env, char **str, int check);
int env_error_handling(char **str, int check, char **env);
int is_alpha(char c);
int is_alphanumerical(char *str);
char **set_env(char **env, char **str);
void *exoc(size_t, int opt, int ex_code);
int main_loop(char **);
char **shell_loop(char **, int, int);
char *get_path(char **);
int exec_command(char **, char **);
int special_commands(char **, char **);

#endif
