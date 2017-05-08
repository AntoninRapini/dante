/*
** my_depth_algo.c for depth in /home/antonin.rapini/ModulesTek1/IA/dante/depth/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun Apr 30 03:50:19 2017 Antonin Rapini
** Last update Mon May  8 02:03:54 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "solver_sources.h"
#include "dante.h"

t_node		*my_dfs(t_maze *maze)
{
  t_node	*curr;
  t_node	*new;

  curr = maze->maze[0] == PATH_CHAR ? my_init_node(0, 0, NULL) : NULL;
  maze->maze[0] = VISITED_CHAR;
  while (curr != NULL && !my_is_end(maze, curr->y, curr->x))
    {
      curr->next++;
      if (curr->next < 4)
	{
	  if ((new = my_get_next_node(maze, curr)) != NULL)
	    {
	      curr = new;
	      maze->maze[POS(maze->x, curr->y, curr->x)] = VISITED_CHAR;
	    }
	}
      else
	{
	  new = curr->previous;
	  free(curr);
	  curr = new;
	}
    }
  return (curr);
}
