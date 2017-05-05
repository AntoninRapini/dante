/*
** depth.c for astar in /home/antonin.rapini/ModulesTek1/IA/dante/astar
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri May  5 00:56:55 2017 Antonin Rapini
** Last update Fri May  5 00:57:08 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "solver_sources.h"
#include "sources.h"

int		main(int ac, char **av)
{
  t_dante	*dante;
  
  if (ac == 2)
    {
      if ((dante = my_create_dante(av[1])) != NULL)
	{
	  my_astar(dante->graph, dante->maze);
	  my_free_dante(dante);
	  return (0);
	}
    }
  return (84);
}
