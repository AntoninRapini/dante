/*
** my_dfs.c for depth in /home/antonin.rapini/ModulesTek1/IA/dante/depth/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed May  3 19:28:16 2017 Antonin Rapini
** Last update Fri May  5 02:17:02 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "depth.h"
#include "solver_sources.h"
#include "solver_utils.h"

int is_end(char **maze, t_node *curr)
{
  return (maze[curr->y + 1] == NULL && maze[curr->y][curr->x + 1] == '\0');
}

t_path		*my_get_next_path(t_path *curr)
{
  t_connection	*connections;
  t_path	*new;

  connections = curr->node->connections;
  while (connections != NULL)
    {
      if (connections->node->visited == 0)
	{
	  if ((new = my_init_path(connections->node)) == NULL)
	    return (NULL);
	  new->previous = curr;
	  curr->next = new;
	  return (new);
	}
      connections = connections->next;
    }
  new = curr->previous;
  my_free_path(curr);
  curr = NULL;
  if (new != NULL)
    new->next = NULL;
  return (new);
}

void		my_dfs(t_node *graph, char **maze)
{
  t_path	*start;
  t_path	*curr;

  if ((start = my_init_path(graph)) == NULL)
    return ;
  curr = start;
  while (curr != NULL && is_end(maze, curr->node) == 0)
    curr = my_get_next_path(curr);
  if (curr == NULL)
    my_putstr("no solution found\n");
  else
    {
      my_mark_path(start, maze);
      my_show_wordtab(maze);
      my_free_path(start);
    }
}
