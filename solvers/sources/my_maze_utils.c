/*
** my_maze_utils.c for dante in /home/antonin.rapini/ModulesTek1/IA/dante/solvers/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat May  6 18:46:46 2017 Antonin Rapini
** Last update Sat May  6 19:02:47 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "solver_utils.h"
#include "dante.h"

void *my_free_maze(t_maze *maze)
{
  if (maze != NULL)
    {
      my_free_wordtab(maze->maze);
      free(maze);
    }
  return (NULL);
}

t_maze		*my_init_maze()
{
  t_maze	*maze;

  if ((maze = malloc(sizeof(t_maze))) == NULL)
    return (NULL);
  maze->x = 0;
  maze->y = 0;
  maze->maze = NULL;
  return (maze);
}
