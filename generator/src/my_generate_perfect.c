/*
** my_generate_perfect.c for generator in /home/antonin.rapini/ModulesTek1/IA/dante/generator/src
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun May 14 18:10:52 2017 Antonin Rapini
** Last update Sun May 14 21:12:04 2017 Antonin Rapini
*/

#include "maze.h"

static t_pos const dir[] =
  {
    {0, 2},
    {0, -2},
    {2, 0},
    {-2, 0},
    {0, 0}
  };

void my_add_neighbours(int x, int y, t_node **frontiers, t_maze *maze)
{
  int	i;

  i = 0;
  while (dir[i].x != 0 || dir[i].y != 0)
    {
      if (is_valid(x + dir[i].x, y + dir[i].y, maze))
	{
	  (*frontiers) = my_init_node(y + dir[i].y, x + dir[i].x, *frontiers);
	  maze->maze[(*frontiers)->y][(*frontiers)->x] = VISITED_CHAR;
	}
      i++;
    }
}

void		my_connect_random_visited(t_node *node, t_maze *maze)
{
  int		random;

  random = rand() % 4;
  while (!is_visited_neighbour(node->x + dir[random].x,
			       node->y + dir[random].y, maze))
    random = rand() % 4;
  maze->maze[node->y][node->x] = PATH_CHAR;
  maze->maze[node->y + dir[random].y / 2][node->x + dir[random].x / 2]
    = PATH_CHAR;
}

void		my_connect_random(t_node **frontiers, t_maze *maze)
{
  t_node	*node;

  node = remove_random_node(frontiers);
  my_connect_random_visited(node, maze);
  my_add_neighbours(node->x, node->y, frontiers, maze);
  free(node);
}

void		my_generate_perfect(t_maze *maze)
{
  t_node	*frontiers;

  frontiers = NULL;
  maze->maze[0][0] = PATH_CHAR;
  my_add_neighbours(0, 0, &frontiers, maze);
  while (frontiers != NULL)
    my_connect_random(&frontiers, maze);
  fix_maze(maze);
}
