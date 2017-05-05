/*
** my_construct_graph.c for dante in /home/antonin.rapini/ModulesTek1/IA/dante/solvers/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon May  1 18:53:24 2017 Antonin Rapini
** Last update Fri May  5 02:00:41 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "dante.h"
#include "solver_sources.h"

static t_pos const directions[] =
{
  {0, 1},
  {1, 0},
  {0, -1},
  {-1, 0}
};

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
  if (maze[i] != NULL && maze[i][j] != '\0' && maze[i + 1] == NULL && maze[i][j + 1] == '\0')
    return (1);
  return (0);
}

int		my_get_next_node(t_dante *dante, t_node **curr, int *i, int *j)
{
  t_node	*tmp;
  int		size;

  size = 1;
  *i += directions[(*curr)->search_dir].y;
  *j += directions[(*curr)->search_dir].x;
  while (is_valid_position(dante->maze, *i, *j))
    {
      if (has_choice(dante->maze, *i, *j, (*curr)->search_dir))
	{
	  if ((tmp = my_get_node(dante->graph, *i, *j)) != NULL)
	    {
	      *i = (*curr)->y;
	      *j = (*curr)->x;
	      my_connect_nodes(*curr, tmp, size);
	      return (0);
	    }
	  else if ((tmp = my_init_node(*i, *j, &(dante->graph))) != NULL)
	    {
	      my_connect_nodes(*curr, tmp, size);
	      (*curr) = tmp;
	      return (0);
	    }
	  return (1);
	}
      *i += directions[(*curr)->search_dir].y;
      *j += directions[(*curr)->search_dir].x;
      size++;
    }
  *i = (*curr)->y;
  *j = (*curr)->x;
  return (0);
}

void		my_construct_graph(t_dante *dante)
{
  t_node	*curr;
  int		i;
  int		j;

  dante->start = my_init_node(0, 0, NULL);
  dante->graph = dante->start;
  curr = dante->graph;
  i = 0;
  j = 0;
  while (curr != NULL)
    {
      curr->search_dir++;
      if (curr->search_dir < 4)
	my_get_next_node(dante, &curr, &i, &j);
      else
	{
	  curr = curr->next;
	  if (curr)
	    {
	      i = curr->y;
	      j = curr->x;
	    }
	}
    }
}
