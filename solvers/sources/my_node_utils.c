/*
** my_node_utils.c for dante in /home/antonin.rapini/ModulesTek1/IA/dante/breadth/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun Apr 30 03:36:49 2017 Antonin Rapini
** Last update Fri May  5 02:01:44 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "dante.h"
#include "solver_sources.h"
#include <stdio.h>

t_node *my_get_last_node(t_path *path)
{
  while (path->next != NULL)
    path = path->next;
  return (path->node);
}

void my_show_graph(t_node *graph)
{
  while (graph != NULL)
    {
      printf("x : %i y : %i ", graph->x, graph->y);
      my_show_connections(graph->connections);
      printf("\n");
      graph = graph->next;
    }
}

t_node	*my_get_node(t_node *start, int i, int j)
{
  while (start != NULL)
    {
      if (start->x == j && start->y == i)
	return (start);
      start = start->next;
    }
  return (NULL);
}

void		*my_free_nodes(t_node *nodes)
{
  t_node	*tmp;

  while (nodes != NULL)
    {
      tmp = nodes;
      my_free_connections(nodes->connections);
      nodes = nodes->next;
      free(tmp);
    }
  return (NULL);
}

t_node		*my_init_node(int y, int x, t_node **start)
{
  t_node	*node;

  if ((node = malloc(sizeof(t_node))) == NULL)
    return (NULL);
  node->connections = NULL;
  if (start)
    {
      node->next = (*start);
      (*start)->previous = node;
      (*start) = node;
    }
  else
    node->next = NULL;
  node->previous = NULL;
  node->search_dir = -1;
  node->visited = 0;
  node->x = x;
  node->y = y;
  return (node);
}
