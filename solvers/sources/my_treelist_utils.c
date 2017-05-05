/*
** my_treelist_utils.c for dante in /home/antonin.rapini/ModulesTek1/IA/dante/solvers/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu May  4 20:26:39 2017 Antonin Rapini
** Last update Thu May  4 20:31:41 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "dante.h"

void		*my_free_branches(t_treelist *branches)
{
  t_treelist	*tmp;

  while (branches != NULL)
    {
      tmp = branches;
      branches = branches->next;
      free(tmp);
    }
  return (NULL);
}

t_treelist	*my_init_branch(t_tree *tree)
{
  t_treelist	*branch;

  if ((branch = malloc(sizeof(t_treelist))) == NULL)
    return (NULL);
  branch->branch = tree;
  branch->next = NULL;
  return (branch);
}
