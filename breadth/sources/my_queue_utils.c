/*
** my_queue_utils.c for breadth in /home/antonin.rapini/ModulesTek1/IA/dante/breadth/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat May  6 03:49:19 2017 Antonin Rapini
** Last update Sat May  6 16:31:50 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "dante.h"
#include "breadth.h"
#include "solver_sources.h"

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
