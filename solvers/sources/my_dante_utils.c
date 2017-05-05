/*
** my_dante_utils.c for dante in /home/antonin.rapini/ModulesTek1/IA/dante/solvers/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue May  2 02:43:21 2017 Antonin Rapini
** Last update Wed May  3 19:18:30 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "dante.h"
#include "solver_sources.h"
#include "solver_utils.h"

void *my_free_dante(t_dante *dante)
{
  if (dante != NULL)
    {
      my_free_wordtab(dante->maze);
      my_free_nodes(dante->graph);
      free(dante);
    }
  return (NULL);
}

t_dante		*my_init_dante()
{
  t_dante	*dante;

  if ((dante = malloc(sizeof(t_dante))) == NULL)
    return (NULL);
  dante->maze = NULL;
  dante->graph = NULL;
  return (dante);
}

t_dante		*my_create_dante(char *filename)
{
  t_dante	*dante;

  if ((dante = my_init_dante()) == NULL)
    return (NULL);
  if ((dante->maze = my_get_maze(filename)) == NULL)
    return (my_free_dante(dante));
  my_construct_graph(dante);
  if (dante->graph == NULL)
    return (NULL);
  return (dante);
}
