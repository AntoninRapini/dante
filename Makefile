##
## Makefile for  in /home/yoann.rey/dante
##
## Made by Yoann Rey
## Login   <yoann.rey@epitech.net>
##
## Started on  Thu Apr 20 14:13:08 2017 Yoann Rey
## Last update Thu Apr 20 15:32:20 2017 Yoann Rey
##

all: 	make -C astar/
	make -C breadth/
	make -C depth/
	make -C tournament/

clean:	make clean -C astar/
	make clean -C breadth/
	make clean -C depth/
	make clear -C tournament/


fclean:	make fclean -C astar/
	make fclean -C breadth/
	make fclean -C depth/
	make fclean -C tournament/

re: fclean all

.PHONY: all clean fclean re