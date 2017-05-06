##
## Makefile for breadth in /home/antonin.rapini/ModulesTek1/IA/dante/breadth
## 
## Made by Antonin Rapini
## Login   <antonin.rapini@epitech.net>
## 
## Started on  Thu May  4 17:11:11 2017 Antonin Rapini
## Last update Sat May  6 16:35:08 2017 Antonin Rapini
##

CFLAGS	+= -Wall -Werror -Wextra
CFLAGS 	+= -I ../solvers/include -I include -g3

COMMONDIR =	../solvers

SRC	=	$(COMMONDIR)/sources/my_get_maze.c	\
		$(COMMONDIR)/sources/my_node_utils.c	\
		$(COMMONDIR)/sources/my_is_end.c	\
		$(COMMONDIR)/sources/my_maze_utils.c	\
		$(COMMONDIR)/sources/my_resolve_maze.c	\
		$(COMMONDIR)/utils/get_next_line.c	\
		$(COMMONDIR)/utils/my_wordtab_utils.c	\
		$(COMMONDIR)/utils/my_strlen.c		\
		$(COMMONDIR)/utils/my_putchar.c		\
		$(COMMONDIR)/utils/my_putstr.c		\
		sources/my_queue_utils.c		\
		sources/my_bfs.c			\
		breadth.c

OBJ	=	$(SRC:.c=.o)

NAME	= 	solver

$(NAME): $(OBJ)
	gcc -pg $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
