/*
** my_pathlist_utils.c for lemin in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_Lemin/sources/init
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri Apr 21 19:47:01 2017 Antonin Rapini
** Last update Thu May  4 21:50:12 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "solver_sources.h"
#include "utils.h"

void		*my_free_pathlist(t_pathlist *paths)
{
  t_pathlist	*tmp;

  while (paths != NULL)
    {
      tmp = paths;
      paths = paths->next;
      my_free_path(tmp->path);
      free(tmp);
    }
  return (NULL);
}

t_pathlist	*my_init_pathlist_item(t_path *path)
{
  t_pathlist	*item;

  if ((item = malloc(sizeof(t_pathlist))) == NULL)
    return (NULL);
  item->path = path;
  item->next = NULL;
  return (item);
}

int		my_add_path(t_pathlist **paths, t_path *path)
{
  t_pathlist	*new_path;
  t_pathlist	*curr;

  if (((new_path) = my_init_pathlist_item(path)) == NULL)
    return (1);
  if ((*paths) == NULL)
    {
      (*paths) = new_path;
      return (0);
    }
  curr = (*paths);
  while (curr->next != NULL)
    curr = curr->next;
  curr->next = new_path;
  return (0);
}
