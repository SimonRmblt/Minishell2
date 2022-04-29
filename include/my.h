/*
** EPITECH PROJECT, 2021
** my
** File description:
** Includes all the functions in libmy.a
*/

#include <stddef.h>

#ifndef MY_H
    #define MY_H
    #define RESET "\x1b[0m"
    #define H_MAG "\e[0;95m"

int char_in_string(char *str, char c);
int get_tab_height_n(char **str, char *stop);
int get_tab_height(char **str);
char *my_strdup(char *str);
int my_char_strcmp(char *str1, char *str2, char c);
void free_exec_command(
    char *error, char *error2, char *full_error_msg);
void free_double_tab(char **tab);
int my_strncmp(char *str1, char *str2, int size);
int char_pos_finder(char *, char);
int count_separators(char *, const char *);
char **parse_arg(char *, const char *);
int my_strcmp(char *, char *);
char *my_strcat(char *, char const *);
int int_to_bin(int);
int a_to_hex_x_maj(char *);
int a_to_hex_x(char *);
char *a_to_oct(char *);
int my_printf(char *, ...);
void my_putchar(char);
int my_put_nbr(int);
int my_putstr(char const *);
int my_strlen(char const *);
int my_getnbr(char const *);
char *my_strncpy(char *, char const *, int, int);

#endif
