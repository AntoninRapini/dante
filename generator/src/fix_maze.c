/*
** fix_odd.c for generator in /home/antonin.rapini/ModulesTek1/IA/dante/generator/src
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun May 14 07:44:22 2017 Antonin Rapini
** Last update Sun May 14 22:02:55 2017 Antonin Rapini
*/

#include "maze.h"

void	fix_maze(t_maze *maze)
{
  int	random;
  int	x;
  int	y;

  x = maze->x - 1;
  y = maze->y - 1;
  while (maze->maze[y][x] != EMPTY_CHAR)
    {
      maze->maze[y][x] = EMPTY_CHAR;
      if (y - 1 >= 0 && x - 1 >= 0)
	{
	  random = rand() % 2;
	  if (random == 0)
	    y--;
	  else
	    x--;
	}
      else if (y - 1 >= 0)
	y--;
      else if (x - 1 >= 0)
	x--;
    }
}
