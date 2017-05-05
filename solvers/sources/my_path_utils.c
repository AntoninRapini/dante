/*
** my_path_utils.c for dante in /home/antonin.rapini/ModulesTek1/IA/dante/solvers/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed May  3 23:44:32 2017 Antonin Rapini
** Last update Fri May  5 01:38:05 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "dante.h"
#include <stdio.h>

void my_show_path(t_path *path)
{
  while (path != NULL)
    {
      printf("x : %i y : %i ", path->node->x, path->node->y);
      path = path->next;
    }
  printf("\n");
}

void	my_mark_path(t_path *path, char **maze)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (path != NULL && path->next != NULL)
    {
      maze[path->node->y][path->node->x] = 'o';
      while (i != path->next->node->y)
	{
	  i += i < path->next->node->y ? 1 : -1;
	  maze[i][j] = 'o';
	}
      while (j != path->next->node->x)
	{
	  j += j < path->next->node->x ? 1 : -1;
	  maze[i][j] = 'o';
	}
      path = path->next;
    }
}

void		*my_free_path(t_path *path)
{
  t_path	*tmp;

  while (path != NULL)
    {
      tmp = path;
      path = path->next;
      free(tmp);
    }
  return (NULL);
}

t_path		*my_init_path(t_node *node)
{
  t_path	*path;

  if ((path = malloc(sizeof(t_path))) == NULL)
    return (NULL);
  path->node = node;
  if (node)
    node->visited = 1;
  path->previous = NULL;
  path->next = NULL;
  return (path);
}

t_path          *my_copy_path(t_path *original)
{
  t_path        *new_start;
  t_path        *curr;

  if ((new_start = my_init_path(original->node)) == NULL)
    return (NULL);
  curr = new_start;
  original = original->next;
  while (original != NULL)
    {
      if ((curr->next = my_init_path(original->node)) == NULL)
        return (my_free_path(new_start));
      curr->next->previous = curr;
      curr = curr->next;
      original = original->next;
    }
  return (new_start);
}

int             my_add_node(t_path **path, t_node *node)
{
  t_path	*new_node;
  t_path	*curr;

  if (((new_node) = my_init_path(node)) == NULL)
    return (1);
  if ((*path) == NULL)
    {
      (*path) = new_node;
      return (0);
    }
  curr = (*path);
  while (curr->next != NULL)
    curr = curr->next;
  curr->next = new_node;
  return (0);
}
