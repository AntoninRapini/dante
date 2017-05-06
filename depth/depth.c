/*
** depth.c for depth in /home/antonin.rapini/ModulesTek1/IA/dante/depth
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat Apr 29 17:26:06 2017 Antonin Rapini
** Last update Sat May  6 18:58:46 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "solver_sources.h"
#include "solver_utils.h"
#include "sources.h"

int		main(int ac, char **av)
{
  t_node	*path;
  t_maze	*maze;
  
  if (ac == 2)
    {
      if ((maze = my_get_maze(av[1])) != NULL)
	{
	  if ((path = my_dfs(maze->maze)) == NULL)
	    my_putstr("no solution found\n");
	  else
	    {
	      my_resolve_maze(maze->maze, path);
	      my_free_nodes(path);
	    }
	  my_free_maze(maze);
	  return (0);
	}
    }
  return (84);
}
