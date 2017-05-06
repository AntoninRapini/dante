##
## Makefile for my_ls in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls
## 
## Made by Antonin Rapini
## Login   <antonin.rapini@epitech.net>
## 
## Started on  Tue Nov 29 08:50:17 2016 Antonin Rapini
## Last update Sat May  6 22:45:30 2017 Antonin Rapini
##

CFLAGS	+= -Wall -Werror -Wextra
CFLAGS 	+= -I ../solvers/include -I include -g3

COMMONDIR =	../solvers

SRC	=	$(COMMONDIR)/sources/my_create_maze.c	\
		$(COMMONDIR)/sources/my_node_utils.c	\
		$(COMMONDIR)/sources/my_queue_utils.c	\
		$(COMMONDIR)/sources/my_helpers.c	\
		$(COMMONDIR)/sources/my_is_end.c	\
		$(COMMONDIR)/sources/my_maze_utils.c	\
		$(COMMONDIR)/sources/my_resolve_maze.c	\
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
