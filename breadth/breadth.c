/*
** breadth.c for breadth in /home/antonin.rapini/ModulesTek1/IA/dante/breadth
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu May  4 21:58:09 2017 Antonin Rapini
** Last update Sun May  7 03:57:19 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "solver_utils.h"
#include "solver_sources.h"
#include "sources.h"

int		main(int ac, char **av)
{
  t_maze       	*maze;
  t_node	*path;

  if (ac == 2)
    {
      if ((maze = my_create_maze(av[1])) != NULL)
	{
	  if ((path = my_bfs(maze)) == NULL)
	      my_putstr("no solution found\n");
	  else
	    {
		my_resolve_maze(maze, path);
		my_free_nodes(path);
	    }
	  my_free_maze(maze);
	  return (0);
	}
    }
  return (84);
}
