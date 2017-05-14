/*
** my_node_utils.c for generator in /home/antonin.rapini/ModulesTek1/IA/dante/generator/src
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun May 14 05:08:05 2017 Antonin Rapini
** Last update Sun May 14 18:24:29 2017 Antonin Rapini
*/

#include "maze.h"

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
