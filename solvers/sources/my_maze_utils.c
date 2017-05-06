/*
** my_maze_utils.c for dante in /home/antonin.rapini/ModulesTek1/IA/dante/solvers/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat May  6 04:26:30 2017 Antonin Rapini
** Last update Sat May  6 15:23:10 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "solver_sources.h"
#include "dante.h"

void		my_mark_path(char **maze, t_node *path)
{
  int		i;
  int		j;

  while (path != NULL)
    {
      i = path->y;
      j = path->x;
      maze[i][j] = PATH_CHAR;
      if (path->previous != NULL)
	{
	  while (i != path->previous->y)
	    {
	      i += i < path->previous->y ? 1 : -1;
	      maze[i][j] = PATH_CHAR;
	    }
	  while (j != path->previous->x)
	    {
	      j += j < path->previous->x ? 1 : -1;
	      maze[i][j] = PATH_CHAR;
	    }
	}
      path = path->previous;
    }
}

void    my_clear_visited(char **maze)
{
  int   i;
  int   j;

  i = 0;
  while (maze[i])
    {
      j = 0;
      while (maze[i][j])
        {
          if (maze[i][j] == VISITED_CHAR)
            maze[i][j] = EMPTY_CHAR;
          j++;
        }
      i++;
    }
}

int is_valid_position(char **maze, int i, int j)
{
  if (i < 0 || j < 0 || maze[i] == NULL || maze[i][j] != EMPTY_CHAR)
    return (0);
  return (1);
}

int has_choice(char **maze, int i, int j, int dir)
{
  if ((is_valid_position(maze, i, j + 1) || is_valid_position(maze, i, j - 1))
      && ((dir != 0) && (dir != 2)))
    return (1);
  if ((is_valid_position(maze, i + 1, j) || is_valid_position(maze, i - 1, j))
      && ((dir != 1) && (dir != 3)))
    return (1);
  return (0);
}

t_node	*my_get_next_node(char **maze, t_node *curr)
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
      if ((maze[i + 1] == NULL && maze[i][j + 1] == '\0')
	  || (has_choice(maze, i, j, curr->next)))
	return (my_init_node(i, j, curr));
      (*dir) += way;
    }
  return (NULL);
}
