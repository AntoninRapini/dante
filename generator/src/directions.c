/*
** directions.c for  in /home/yoann.rey/dante/generator/src/
**
** Made by Yoann Rey
** Login   <yoann.rey@epitech.eu>
**
** Started on  Thu May  4 14:36:03 2017 Yoann Rey
** Last update Thu May  4 15:53:05 2017 Yoann Rey
*/

#include "maze.h"

void,	up_move(t_maze *map)
{
  int	x;
  int	y;

  x = (y = 0);
  while(map->maze[x])
  if (map->maze[x][y - 1] == 'X')
    {
      map->maze[x][y - 1] == '*';
      y--;
    }
  else if (map->maze[x][y - 1] == NULL)
    {
      if (map->maze[x - 1][y] == NULL)
	x++;
    }
}

void	down_move(t_maze *map)
{

}
