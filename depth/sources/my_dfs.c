/*
** my_depth_algo.c for depth in /home/antonin.rapini/ModulesTek1/IA/dante/depth/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun Apr 30 03:50:19 2017 Antonin Rapini
** Last update Fri May  5 20:04:06 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "solver_utils.h"
#include "depth.h"
#include "sources.h"

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

void		my_backtrack(char **maze, t_dnode **curr, int *i, int *j)
{
  int		*dir;
  int		way;
  t_dnode	*tmp;

  dir = (*curr)->previous->pos.x != *j ? j : i;
  way = (*dir == *j && *dir < (*curr)->previous->pos.x) ||
    (*dir == *i && *dir < (*curr)->previous->pos.y) ? 1 : -1;
  while (*i != (*curr)->previous->pos.y || *j != (*curr)->previous->pos.x)
    {
      maze[*i][*j] = VISITED_CHAR;
      (*dir) += way;
    }
  tmp = (*curr)->previous;
  free((*curr));
  (*curr) = tmp;
}

void		my_move_next(char **maze, t_dnode **curr, int *i, int *j)
{
  int		*dir;
  int		way;

  dir = (*curr)->next == 0 || (*curr)->next == 2 ? j : i;
  way = (*curr)->next == 0 || (*curr)->next == 1 ? 1 : -1;
  (*dir) += way;
  while (is_valid_position(maze, *i, *j))
    {
      maze[*i][*j] = PATH_CHAR;
      if (maze[(*i) + 1] == NULL && maze[*i][(*j) + 1] == '\0')
	return ;
      if (has_choice(maze, *i, *j, (*curr)->next))
	{
	  (*curr) = my_init_dnode(*i, *j, *curr);
	  return ;
	}
      (*dir) += way;
    }
  (*dir) -= way;
  while (*i != (*curr)->pos.y || *j != (*curr)->pos.x)
    {
      maze[*i][*j] = VISITED_CHAR;
      (*dir) -= way;
    }
}

void		my_dfs(char **maze)
{
  t_dnode	*curr;
  int		i;
  int		j;

  i = 0;
  j = 0;
  curr = my_init_dnode(i, j, NULL);
  maze[0][0] = PATH_CHAR;
  while (maze[i + 1] != NULL || maze[i][j + 1] != '\0')
    {
      curr->next++;
      if (curr->next < 4)
	my_move_next(maze, &curr, &i, &j);
      else if (curr->previous != NULL)
	my_backtrack(maze, &curr, &i, &j);
      else
	{
	  my_putstr("no solution found\n");
	  return ;
	}
    }
  my_clear_visited(maze);
  my_show_wordtab(maze);
}
