/*
** my_depth_algo.c for depth in /home/antonin.rapini/ModulesTek1/IA/dante/depth/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun Apr 30 03:50:19 2017 Antonin Rapini
** Last update Sat May  6 05:35:38 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "solver_sources.h"
#include "dante.h"

t_node		*my_dfs(char **maze)
{
  t_node	*curr;
  t_node	*new;

  curr = my_init_node(0, 0, NULL);
  maze[curr->y][curr->x] = VISITED_CHAR;
  while (curr != NULL && !my_is_end(maze, curr))
    {
      curr->next++;
      if (curr->next < 4)
	{
	  if ((new = my_get_next_node(maze, curr)) != NULL)
	    {
	      curr = new;
	      maze[curr->y][curr->x] = VISITED_CHAR;
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
