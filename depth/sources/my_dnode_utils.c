/*
** my_node_utils.c for dante in /home/antonin.rapini/ModulesTek1/IA/dante/breadth/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun Apr 30 03:36:49 2017 Antonin Rapini
** Last update Fri May  5 20:05:08 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "depth.h"

void		*my_free_dnodes(t_dnode *nodes)
{
  t_dnode	*tmp;

  while (nodes != NULL)
    {
      tmp = nodes;
      nodes = nodes->previous;
      free(tmp);
    }
  return (NULL);
}

t_dnode		*my_init_dnode(int y, int x, t_dnode *previous)
{
  t_dnode	*node;

  if ((node = malloc(sizeof(t_dnode))) == NULL)
    return (NULL);
  node->previous = previous;
  node->next = -1;
  node->pos.x = x;
  node->pos.y = y;
  return (node);
}
