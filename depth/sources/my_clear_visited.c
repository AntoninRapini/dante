/*
** my_clear_visited.c for depth in /home/antonin.rapini/ModulesTek1/IA/dante/depth/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri May  5 19:57:11 2017 Antonin Rapini
** Last update Fri May  5 19:57:26 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "utils.h"
#include "depth.h"

void	my_clear_visited(char **tab)
{
  int	i;
  int	j;

  i = 0;
  while (tab[i])
    {
      j = 0;
      while (tab[i][j])
	{
	  if (tab[i][j] == VISITED_CHAR)
	    tab[i][j] = EMPTY_CHAR;
	  j++;
	}
      i++;
    }
}
