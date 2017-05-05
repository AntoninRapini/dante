/*
** my_connection_utils.c for dante in /home/antonin.rapini/ModulesTek1/IA/dante/solvers/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue May  2 17:36:29 2017 Antonin Rapini
** Last update Tue May  2 20:15:08 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "dante.h"
#include <stdio.h>

void	my_show_connections(t_connection *connections)
{
  while (connections != NULL)
    {
      printf("connection x : %i y : %i ", connections->node->x, connections->node->y);
      connections = connections->next;
    }
}

void		*my_free_connections(t_connection *connections)
{
  t_connection	*tmp;

  while (connections != NULL)
    {
      tmp = connections;
      connections = connections->next;
      free(tmp);
    }
  return (NULL);
}

t_connection	*my_init_connection(t_node *node, int size)
{
  t_connection	*connection;

  if ((connection = malloc(sizeof(t_connection))) == NULL)
    return (NULL);
  connection->node = node;
  connection->size = size;
  return (connection);
}

int		my_add_connection(t_node *curr, t_node *new, int size)
{
  t_connection	*new_connection;

  if ((new_connection = my_init_connection(new, size)) == NULL)
    return (1);
  new_connection->next = curr->connections;
  curr->connections = new_connection;
  return (0);
}

int             my_connect_nodes(t_node *a, t_node *b, int size)
{
  t_connection	*tmp;

  tmp = a->connections;
  while (tmp != NULL)
    {
      if (tmp->node->x == b->x && tmp->node->y == b->y)
	return (0);
      tmp = tmp->next;
    }
  my_add_connection(a, b, size);
  my_add_connection(b, a, size);
  return (0);
}
