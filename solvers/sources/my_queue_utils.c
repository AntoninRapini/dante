/*
** my_queue_utils.c for breadth in /home/antonin.rapini/ModulesTek1/IA/dante/breadth/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat May  6 03:49:19 2017 Antonin Rapini
** Last update Tue May  9 06:12:25 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "dante.h"
#include "solver_sources.h"

t_node		*my_get_last(t_maze *maze, t_queue *queue)
{
  t_node	*last;
  t_queue	*tmp;

  last = NULL;
  while (queue != NULL)
    {
      tmp = queue;
      queue = queue->next;
      if (my_is_end(maze, tmp->node->y, tmp->node->x))
	last = tmp->node;
      else
	my_free_nodepath(tmp->node);
      free(tmp);
    }
  return (last);
}

void		my_insert_node(t_queue *new, t_queue **queue)
{
  t_queue	*start;
  t_queue	*tmp;
  int		total;

  total = new->node->distance + new->node->cost;
  start = (*queue);
  if ((*queue) == NULL ||
      total < (*queue)->node->distance + (*queue)->node->cost)
    {
      (*queue) = new;
      new->next = start;
      return ;
    }
  while (start->next != NULL)
    {
      if (total < start->next->node->distance + start->next->node->cost)
	{
	  tmp = start->next;
	  start->next = new;
	  new->next = tmp;
	  return ;
	}
      start = start->next;
    }
  start->next = new;
}

void		*my_free_queue(t_queue *queue, int free_nodes)
{
  t_queue	*tmp;

  while (queue != NULL)
    {
      tmp = queue;
      queue = queue->next;
      if (free_nodes)
	my_free_nodepath(tmp->node);
      free(tmp);
    }
  return (NULL);
}

t_queue		*my_init_queue(t_node *node)
{
  t_queue	*queue;

  if ((queue = malloc(sizeof(t_queue))) == NULL)
    return (NULL);
  queue->node = node;
  queue->next = NULL;
  return (queue);
}
