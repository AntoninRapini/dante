/*
** fix_odd.c for generator in /home/antonin.rapini/ModulesTek1/IA/dante/generator/src
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun May 14 07:44:22 2017 Antonin Rapini
** Last update Sun May 14 20:53:20 2017 Antonin Rapini
*/

#include "maze.h"

void	clear_visited(char **maze)
{
  int	i;
  int	j;

  i = 0;
  while (maze[i])
    {
      j = 0;
      while (maze[i][j])
	{
	  if (maze[i][j] == VISITED_CHAR)
	    maze[i][j] = PATH_CHAR;
	  j++;
	}
      i++;
    }
}
void	fix_maze(t_maze *maze)
{
  int	random;
  int	x;
  int	y;

  x = maze->x - 1;
  y = maze->y - 1;
  while (maze->maze[y][x] != PATH_CHAR)
    {
      maze->maze[y][x] = PATH_CHAR;
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
