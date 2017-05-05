/*
** breadth.c for breadth in /home/antonin.rapini/ModulesTek1/IA/dante/breadth
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu May  4 21:58:09 2017 Antonin Rapini
** Last update Fri May  5 02:17:30 2017 Antonin Rapini
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
	  my_bfs(dante->start, dante->maze);
	  my_free_dante(dante);
	  return (0);
	}
    }
  return (84);
}
