/*
** my_generate_maze.c for generator in /home/antonin.rapini/ModulesTek1/IA/dante/generator/src
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun May 14 05:04:14 2017 Antonin Rapini
** Last update Sun May 14 22:03:21 2017 Antonin Rapini
*/

#include "maze.h"

static t_pos const dirs[] =
  {
    {0, 2},
    {0, -2},
    {2, 0},
    {-2, 0}
  };

int is_visited_neighbour(int x, int y,  t_maze *maze)
{
  return (x >= 0 && y >= 0 && x < maze->x && y < maze->y
	  && maze->maze[y][x] == EMPTY_CHAR);
}

int is_valid(int x, int y,  t_maze *maze)
{
  return (x >= 0 && y >= 0 && x < maze->x && y < maze->y
	  && maze->maze[y][x] == WALL_CHAR);
}

int try_direction(t_node **node, t_maze *maze, int x, int y)
{
  if (is_valid((*node)->x + x, (*node)->y + y, maze))
    {
      maze->maze[(*node)->y + (y / 2)][(*node)->x + (x / 2)] = EMPTY_CHAR;
      maze->maze[(*node)->y + y][(*node)->x + x] = EMPTY_CHAR;
      (*node) = my_init_node((*node)->y + y, (*node)->x + x, *node);
      return (0);
    }
  return (1);
}

int	my_move_next(t_node **node, t_maze *maze)
{
  int	random;

  if (is_valid((*node)->x + 2, (*node)->y, maze)
      || is_valid((*node)->x - 2, (*node)->y, maze)
      || is_valid((*node)->x, (*node)->y + 2, maze)
      || is_valid((*node)->x, (*node)->y - 2, maze))
    {
      random = rand() % 4;
      while (try_direction(node, maze, dirs[random].x, dirs[random].y))
	random = rand() % 4;
      return (0);
    }
  return (1);
}
