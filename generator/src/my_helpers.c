/*
** my_generate_maze.c for generator in /home/antonin.rapini/ModulesTek1/IA/dante/generator/src
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun May 14 05:04:14 2017 Antonin Rapini
** Last update Sun May 14 18:48:55 2017 Antonin Rapini
*/

#include "maze.h"

static t_pos const dirs[] =
  {
    {0, 2},
    {0, -2},
    {2, 0},
    {-2, 0}
  };

int is_valid(t_node *node, t_maze *maze, int x, int y)
{
  return (node->x + x >= 0
	  && node->y + y >= 0
	  && node->x + x < maze->x
	  && node->y + y < maze->y
	  && maze->maze[node->y + y][node->x + x] == WALL_CHAR);
}

int try_direction(t_node **node, t_maze *maze, int x, int y)
{
  if (is_valid((*node), maze, x, y))
    {
      maze->maze[(*node)->y + (y / 2)][(*node)->x + (x / 2)] = PATH_CHAR;
      maze->maze[(*node)->y + y][(*node)->x + x] = PATH_CHAR;
      (*node) = my_init_node((*node)->y + y, (*node)->x + x, *node);
      return (0);
    }
  return (1);
}

int	my_move_next(t_node **node, t_maze *maze)
{
  int	random;

  if (is_valid((*node), maze, 2, 0)
      || is_valid((*node), maze, -2, 0)
      || is_valid((*node), maze, 0, 2)
      || is_valid((*node), maze, 0, -2))
    {
      random = rand() % 4;
      while (try_direction(node, maze, dirs[random].x, dirs[random].y))
	random = rand() % 4;
      return (0);
    }
  return (1);
}
