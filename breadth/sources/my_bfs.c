/*
** my_bfs.c for breadth in /home/antonin.rapini/ModulesTek1/IA/dante/breadth/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu May  4 17:13:13 2017 Antonin Rapini
** Last update Thu May  4 22:27:56 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "dante.h"
#include "solver_sources.h"
#include "solver_utils.h"

#include <stdio.h>

int is_end(char **maze, t_node *curr)
{
  return (maze[curr->y + 1] == NULL && maze[curr->y][curr->x + 1] == '\0');
}

int		my_add_next_path
(t_pathlist **paths, t_connection *connection)
{
  t_path	*new;

  if ((new = my_copy_path((*paths)->path)) != NULL)
    {
      if (!my_add_node(&new, connection->node))
	{
	  if (!my_add_path(paths, new))
	    return (0);
	}
    }
  my_free_path(new);
  return (1);
}

int		my_push_new_paths
(t_pathlist **paths, t_connection *connections, char **maze)
{
  t_pathlist	*tmp;

  while (connections != NULL)
    {
      if (connections->node->visited == 0)
	{
	  if (my_add_next_path(paths, connections))
	    return (1);
	  if (is_end(maze, connections->node))
	    return (2);
	}
      connections = connections->next;
    }
  tmp = (*paths)->next;
  my_free_path((*paths)->path);
  free(*paths);
  (*paths) = tmp;
  return (0);
}

t_path *my_get_last_path(t_pathlist *paths)
{
  while (paths->next != NULL)
    paths = paths->next;
  return (paths->path);
}

int		my_bfs(t_node *graph, char **maze)
{
  t_pathlist	*paths;
  int		ret;

  ret = 0;
  paths = my_init_pathlist_item(my_init_path(graph));
  if (paths)
    paths->path->node->visited = 1;
  while (!ret && paths != NULL)
    {
      ret = my_push_new_paths
	(&paths, my_get_last_node(paths->path)->connections, maze);
    }
  if (ret == 1 || paths == NULL)
    my_putstr("no solution found\n");
  else
    {
      my_mark_path(my_get_last_path(paths), maze);
      my_show_wordtab(maze);
    }
  my_free_pathlist(paths);
  return (0);
}
