/*
** depth.c for astar in /home/antonin.rapini/ModulesTek1/IA/dante/astar
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri May  5 00:56:55 2017 Antonin Rapini
** Last update Sat May  6 22:43:35 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "solver_sources.h"
#include "sources.h"

int		main(int ac, char **av)
{
  t_maze	*maze;
  
  if (ac == 2)
    {
      if ((maze = my_create_maze(av[1])) != NULL)
	{
	  my_astar(maze);
	  return (0);
	}
    }
  return (84);
}
