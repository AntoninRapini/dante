/*
** maze.h for  in /home/yoann.rey/dante/includes
**
** Made by Yoann Rey
** Login   <yoann.rey@epitech.net>
**
** Started on  Wed Apr 26 17:10:35 2017 Yoann Rey
** Last update Thu Apr 27 03:09:57 2017 Yoann Rey
*/

#ifndef MAZE_H_
# define MAZE_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_maze
{
  int	x;
  int	y;
  int	size;
  char	**maze;
}		t_maze;

#endif
