/*
** my_node_utils.c for generator in /home/antonin.rapini/ModulesTek1/IA/dante/generator/src
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun May 14 05:08:05 2017 Antonin Rapini
** Last update Sun May 14 20:57:39 2017 Antonin Rapini
*/

#include "maze.h"

t_node          *remove_random_node(t_node **frontiers)
{
  t_node        *chosen;
  t_node        *tmp;
  int           len;
  int           i;

  i = 1;
  len = 0;
  tmp = *frontiers;
  while (tmp != NULL)
    {
      len++;
      tmp = tmp->previous;
    }
  len = (rand() % len) + 1;
  tmp = *frontiers;
  chosen = *frontiers;
  if (len == 1)
    (*frontiers) = (*frontiers)->previous;
  else
    {
      while (++i < len)
        tmp = tmp->previous;
      chosen = tmp->previous;
      tmp->previous = tmp->previous->previous;
    }
  return (chosen);
}

t_node		*my_init_node(int y, int x, t_node *previous)
{
  t_node	*node;

  if ((node = malloc(sizeof(t_node))) == NULL)
    return (NULL);
  node->y = y;
  node->x = x;
  node->previous = previous;
  return (node);
}
