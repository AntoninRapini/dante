/*
** fix_odd.c for generator in /home/antonin.rapini/ModulesTek1/IA/dante/generator/src
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun May 14 07:44:22 2017 Antonin Rapini
** Last update Sun May 14 07:53:40 2017 Antonin Rapini
*/

#include "maze.h"

void	fix_odd(t_node **node, t_maze *maze)
{
  int	random;

  if (maze->x > 1 && maze->y > 1)
    {
      if (maze->x % 2 == 0 && maze->y % 2 == 0)
	{
	  random = rand() % 2;
	  if (random == 0)
	    (*node) = my_init_node(1, 0, *node, maze);
	  else
	    (*node) = my_init_node(0, 1, *node, maze);
	  (*node) = my_init_node(1, 1, *node, maze);
	}
      else if (maze->x % 2 == 0)
	(*node) = my_init_node(0, 1, *node, maze);
      else if (maze->y % 2 == 0)
	(*node) = my_init_node(1, 0, *node, maze);
    }
}
