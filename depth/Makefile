##
## Makefile for my_ls in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls
## 
## Made by Antonin Rapini
## Login   <antonin.rapini@epitech.net>
## 
## Started on  Tue Nov 29 08:50:17 2016 Antonin Rapini
## Last update Sun Apr 30 22:17:01 2017 Antonin Rapini
##

CFLAGS	+= -Wall -Werror -Wextra
CFLAGS 	+= -I include -g3

SRC	=	sources/my_depth_algo.c		\
		sources/my_get_maze.c		\
		sources/my_node_utils.c		\
		utils/get_next_line.c		\
		utils/my_wordtab_utils.c	\
		utils/my_strlen.c		\
		utils/my_putchar.c		\
		utils/my_putstr.c		\
		depth.c

OBJ	=	$(SRC:.c=.o)

NAME	= 	solver

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
