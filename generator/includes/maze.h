/*
** maze.h for  in /home/yoann.rey/dante/includes
**
** Made by Yoann Rey
** Login   <yoann.rey@epitech.net>
**
** Started on  Wed Apr 26 17:10:35 2017 Yoann Rey
** Last update Thu May  4 14:22:32 2017 Yoann Rey
*/

#ifndef MAZE_H_
# define MAZE_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_maze
{
  int	size;
  char	**maze;
  char	wall;
}		t_maze;

/* create_maze.c */

int	create_map(int, int);

/* malloc_my_tab */

int	malloc_my_tab(int, char **);

/* display.c */

void 	my_putchar(char);
void	my_putstr(char *);
int	my_strlen(char *);

/* my_getnbr.c */

int	my_getnbr(char *);

#endif
