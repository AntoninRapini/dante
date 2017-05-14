##
## Makefile for  in /home/yoann.rey/dante
##
## Made by Yoann Rey
## Login   <yoann.rey@epitech.net>
##
## Started on  Thu Apr 20 14:13:08 2017 Yoann Rey
## Last update Sun May 14 18:06:55 2017 Antonin Rapini
##

CFLAGS += 	-I includes/
CFLAGS += 	-g3 -Werror -Wall -Wextra

CC	= 	gcc

RM	= 	rm -f

SRCS	= 	src/my_put_nbr.c	\
	  	src/my_getnbr.c		\
		src/my_wordtab_utils.c	\
		src/my_generate_maze.c	\
		src/my_node_utils.c	\
		src/fix_maze.c		\
		src/my_maze_utils.c	\
	  	src/display.c		\
		generator.c

OBJS	= 	$(SRCS:.c=.o)

NAME	= generator

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
