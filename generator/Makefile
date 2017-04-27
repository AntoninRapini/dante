##
## Makefile for  in /home/yoann.rey/dante
##
## Made by Yoann Rey
## Login   <yoann.rey@epitech.net>
##
## Started on  Thu Apr 20 14:13:08 2017 Yoann Rey
## Last update Thu Apr 27 14:26:26 2017 Yoann Rey
##

CC	= gcc

RM	= rm -f

SRCS	= malloc_my_tab.c	\

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I include/
CFLAGS += -W Wall -Wextra

NAME	= maze

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
