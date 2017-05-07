/*
** depth.c for astar in /home/antonin.rapini/ModulesTek1/IA/dante/astar
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri May  5 00:56:55 2017 Antonin Rapini
** Last update Sun May  7 02:38:52 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "solver_utils.h"
#include "solver_sources.h"
#include "sources.h"

int		main(int ac, char **av)
{
  t_node	*path;
  t_maze	*maze;

  if (ac == 2)
    {
      if ((maze = my_create_maze(av[1])) != NULL)
	{
	  if ((path = my_astar(maze)) == NULL)
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
