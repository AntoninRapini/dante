/*
** my_generate_maze.c for generator in /home/antonin.rapini/ModulesTek1/IA/dante/generator/src
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun May 14 05:04:14 2017 Antonin Rapini
** Last update Sun May 14 22:02:02 2017 Antonin Rapini
*/

#include "maze.h"

void		my_generate_imperfect(t_maze *maze)
{
  t_node	*tmp;
  t_node	*node;

  node = my_init_node(0, 0, NULL);
  maze->maze[0][0] = EMPTY_CHAR;
  while (node != NULL)
    {
      if (my_move_next(&node, maze) == 1)
	{
	  tmp = node;
	  node = node->previous;
	  free(tmp);
	}
    }
  fix_maze(maze);
}
