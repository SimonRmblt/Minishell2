##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Compiles libmy.a
##

SRC	=	lib/my/my_putchar.c	\
		lib/my/my_put_nbr.c	\
		lib/my/my_putstr.c	\
		lib/my/my_strlen.c	\
		lib/my/my_strcpy.c	\
		lib/my/my_strncpy.c	\
		lib/my/my_strcmp.c	\
		lib/my/my_getnbr.c	\
		lib/my/my_printf.c	\
		lib/my/int_to_bin.c	\
		lib/list/push_list.c\
		lib/list/print_list.c\
		lib/list/free_list.c\
		lib/my/a_to_oct.c	\
		lib/my/a_to_hex_x.c	\
		lib/my/a_to_hex_x_maj.c	\
		lib/my/my_strcat.c	\
		lib/my/parse_arg.c	\
		lib/my/find_char_pos.c	\
		lib/my/free_var.c	\
		lib/my/my_strdup.c	\
		lib/my/get_tab_height.c	\
		lib/my/char_in_string.c	\

FILE =	main.c	\
		exec_commands.c	\
		exoc.c	\
		env/env_manager.c	\
		env/setenv.c	\
		env/unsetenv.c	\
		env/setenv_error_handling.c	\
		env/modify_env_var.c	\
		env/create_env_var_array.c	\
		shell_loop.c	\
		char_is.c	\
		cd_builtin.c	\
		parse_prompt.c	\
		init_structs.c	\
		sig_handler.c	\
		pipes_manager.c	\
		my_pipes.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME) clean

$(NAME):	$(OBJ)
	ar rc lib/my/$(NAME) $(OBJ)
	gcc -o mysh $(FILE) -Llib/my/ -lmy
	rm -f *.o

debug:
	gcc -g -o mysh $(FILE) $(SRC)
	rm -f *.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f lib/my/$(NAME)
	rm mysh
	clear

re: 	fclean all
