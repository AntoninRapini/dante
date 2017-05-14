/*
** my_generate_perfect.c for generator in /home/antonin.rapini/ModulesTek1/IA/dante/generator/src
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun May 14 18:10:52 2017 Antonin Rapini
** Last update Sun May 14 18:56:37 2017 Antonin Rapini
*/

#include "maze.h"

void		my_generate_perfect(t_maze *maze)
{
  t_node	*visited;
  t_node	*curr;

  visited = my_init_node(0, 0, NULL);
  maze->maze[0][0] = PATH_CHAR;
  while (visited != NULL)
    {
      curr = visited;
      if (my_move_next(&curr, maze) == 0)
	{
	  curr->previous = visited;
	  visited = curr;
	}
      else
	{
	  visited = visited->previous;
	  free(curr);
	}
    }
  fix_maze(maze);
}
