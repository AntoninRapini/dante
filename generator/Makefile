##
## Makefile for  in /home/yoann.rey/dante
##
## Made by Yoann Rey
## Login   <yoann.rey@epitech.net>
##
## Started on  Thu Apr 20 14:13:08 2017 Yoann Rey
## Last update Tue May  2 14:44:51 2017 Yoann Rey
##

CC	= gcc

RM	= rm -f

SRCS	= src/create_maze.c	\
	  src/malloc_my_tab.c	\
	  src/my_getnbr.c	\
	  src/display.c

OBJS	= $(SRCS:.c=.o)

CFLAGS += -I includes/
CFLAGS += -W -Wall -Wextra

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
