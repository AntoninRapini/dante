/*
** my_node_utils.c for dante in /home/antonin.rapini/ModulesTek1/IA/dante/breadth/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun Apr 30 03:36:49 2017 Antonin Rapini
** Last update Tue May  9 06:07:57 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "dante.h"

void		my_free_nodepath(t_node *node)
{
  t_node	*tmp;

  while (node != NULL && node->connection_count == 0)
    {
      tmp = node;
      node = node->previous;
      if (node)
	node->connection_count--;
      free(tmp);
    }
}

void		*my_free_nodes(t_node *nodes)
{
  t_node	*tmp;

  while (nodes != NULL)
    {
      tmp = nodes;
      nodes = nodes->previous;
      free(tmp);
    }
  return (NULL);
}

t_node		*my_init_node(int y, int x, t_node *previous)
{
  t_node	*node;

  if ((node = malloc(sizeof(t_node))) == NULL)
    return (NULL);
  node->previous = previous;
  node->next = -1;
  node->connection_count = 0;
  node->distance = 0;
  node->cost = 0;
  node->x = x;
  node->y = y;
  return (node);
}
