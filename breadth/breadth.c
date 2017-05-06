/*
** breadth.c for breadth in /home/antonin.rapini/ModulesTek1/IA/dante/breadth
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu May  4 21:58:09 2017 Antonin Rapini
** Last update Sat May  6 22:34:10 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "solver_utils.h"
#include "solver_sources.h"
#include "sources.h"

t_node *my_get_path(t_maze *maze, t_queue *paths)
{
  while (paths != NULL)
    {
      if (my_is_end(maze, paths->node->y, paths->node->x))
	return (paths->node);
      paths = paths->next;
    }
  return (NULL);
}

int		main(int ac, char **av)
{
  t_maze       	*maze;
  t_queue	*paths;
  t_node	*path;

  if (ac == 2)
    {
      if ((maze = my_create_maze(av[1])) != NULL)
	{
	  if ((paths = my_bfs(maze)) == NULL)
	      my_putstr("no solution found\n");
	  else
	    {
	      if ((path = my_get_path(maze, paths)) != NULL)
		my_resolve_maze(maze, path);
	      my_free_queue(paths, 1);
	    }
	  my_free_maze(maze);
	  return (0);
	}
    }
  return (84);
}
