##
## Makefile for my_ls in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls
## 
## Made by Antonin Rapini
## Login   <antonin.rapini@epitech.net>
## 
## Started on  Tue Nov 29 08:50:17 2016 Antonin Rapini
## Last update Fri May  5 00:57:31 2017 Antonin Rapini
##

CFLAGS	+= -Wall -Werror -Wextra
CFLAGS 	+= -I ../solvers/include -I include -g3

COMMONDIR =	../solvers

SRC	=	$(COMMONDIR)/sources/my_get_maze.c	\
		$(COMMONDIR)/sources/my_node_utils.c	\
		$(COMMONDIR)/sources/my_dante_utils.c	\
		$(COMMONDIR)/sources/my_path_utils.c	\
		$(COMMONDIR)/sources/my_connection_utils.c	\
		$(COMMONDIR)/sources/my_construct_graph.c	\
		$(COMMONDIR)/utils/get_next_line.c	\
		$(COMMONDIR)/utils/my_wordtab_utils.c	\
		$(COMMONDIR)/utils/my_strlen.c		\
		$(COMMONDIR)/utils/my_putchar.c		\
		$(COMMONDIR)/utils/my_putstr.c		\
		sources/my_astar.c			\
		astar.c

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
