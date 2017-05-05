/*
** my_tree_utils.c for dante in /home/antonin.rapini/ModulesTek1/IA/dante/solvers/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu May  4 19:00:20 2017 Antonin Rapini
** Last update Thu May  4 20:29:56 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "dante.h"

t_tree		*my_init_tree(t_tree *previous)
{
  t_tree	*tree;

  if ((tree = malloc(sizeof(t_tree))) == NULL)
    return (NULL);
  tree->node = NULL;
  tree->branches = NULL;
  tree->previous = previous;
  return (tree);
}
