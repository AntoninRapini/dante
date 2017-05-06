/*
** my_maze_utils.c for dante in /home/antonin.rapini/ModulesTek1/IA/dante/solvers/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat May  6 04:26:30 2017 Antonin Rapini
** Last update Sat May  6 22:19:31 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "solver_sources.h"
#include "dante.h"

void		my_mark_path(t_maze *maze, t_node *path)
{
  int		i;
  int		j;

  while (path != NULL)
    {
      i = path->y;
      j = path->x;
      maze->maze[POS(maze->x, i, j)] = PATH_CHAR;
      if (path->previous != NULL)
	{
	  while (i != path->previous->y)
	    {
	      i += i < path->previous->y ? 1 : -1;
	      maze->maze[POS(maze->x, i, j)] = PATH_CHAR;
	    }
	  while (j != path->previous->x)
	    {
	      j += j < path->previous->x ? 1 : -1;
	      maze->maze[POS(maze->x, i, j)] = PATH_CHAR;
	    }
	}
      path = path->previous;
    }
}

void    my_clear_visited(char *maze)
{
  int   i;

  i = 0;
  while (maze[i])
    {
      if (maze[i] == VISITED_CHAR)
	maze[i] = EMPTY_CHAR;
      i++;
    }
}

int is_valid_position(t_maze *maze, int i, int j)
{
  return (i >= 0 && j >= 0
	  && i < maze->y
	  && maze->maze[POS(maze->x, i, j)] == EMPTY_CHAR);
}

int has_choice(t_maze *maze, int i, int j, int dir)
{
  if ((is_valid_position(maze, i, j + 1) || is_valid_position(maze, i, j - 1))
      && ((dir != 0) && (dir != 2)))
    return (1);
  if ((is_valid_position(maze, i + 1, j) || is_valid_position(maze, i - 1, j))
      && ((dir != 1) && (dir != 3)))
    return (1);
  return (0);
}

t_node	*my_get_next_node(t_maze *maze, t_node *curr)
{
  int	*dir;
  int	way;
  int	i;
  int	j;

  i = curr->y;
  j = curr->x;
  dir = curr->next == 0 || curr->next == 2 ? &j : &i;
  way = curr->next == 0 || curr->next == 1 ? 1 : -1;
  (*dir) += way;
  while (is_valid_position(maze, i, j))
    {
      if (my_is_end(maze, i, j) || (has_choice(maze, i, j, curr->next)))
	return (my_init_node(i, j, curr));
      (*dir) += way;
    }
  return (NULL);
}
