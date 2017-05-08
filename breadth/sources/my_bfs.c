/*
** my_bfs.c for breadth in /home/antonin.rapini/ModulesTek1/IA/dante/breadth/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu May  4 17:13:13 2017 Antonin Rapini
** Last update Mon May  8 02:08:12 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "sources.h"
#include "dante.h"
#include "solver_sources.h"
#include "solver_utils.h"

int		my_queue_connections(t_maze *maze, t_queue **queue, t_node *node)
{
  t_node	*tmp_node;
  t_queue	*tmp_queue;
  int		is_end;

  is_end = 0;
  while (node->next < 3)
    {
      node->next++;
      if ((tmp_node = my_get_next_node(maze, node)) != NULL)
	{
	  node->connection_count++;
	  maze->maze[POS(maze->x, tmp_node->y, tmp_node->x)] = VISITED_CHAR;
	  if ((tmp_queue = my_init_queue(tmp_node)) != NULL)
	    {
	      if (*queue)
		tmp_queue->next = (*queue);
	      (*queue) = tmp_queue;
	      if (my_is_end(maze, tmp_node->y, tmp_node->x))
		is_end = 1;
	    }
	}
    }
  if (node->connection_count == 0)
    my_free_nodepath(node);
  return (is_end);
}

int	my_get_next_queue(t_maze *maze, t_queue *old, t_queue **new)
{
  int	status;

  status = 0;
  while (old != NULL)
    {
      status += my_queue_connections(maze, new, old->node);
      old = old->next;
    }
  return (status);
}

t_node		*my_bfs(t_maze *maze)
{
  t_queue	*old;
  t_queue	*new;

  old = NULL;
  new = my_init_queue(my_init_node(0, 0, NULL));
  while (new != NULL && !my_is_end(maze, new->node->y, new->node->x))
    {
      old = new;
      new = NULL;
      if (my_get_next_queue(maze, old, &new))
	break;
      my_free_queue(old, 0);
      old = NULL;
    }
  my_free_queue(old, 0);
  return (my_get_last(maze, new));
}
