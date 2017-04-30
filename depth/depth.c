/*
** depth.c for depth in /home/antonin.rapini/ModulesTek1/IA/dante/depth
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat Apr 29 17:26:06 2017 Antonin Rapini
** Last update Sun Apr 30 22:04:15 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "sources.h"

int	main(int ac, char **av)
{
  char	**maze;
  
  if (ac == 2)
    {
      if ((maze = my_get_maze(av[1])) != NULL)
	{
	  my_depth_algo(maze);
	  return (0);
	}
    }
  return (84);
}
