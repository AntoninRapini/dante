/*
** my_astar.c for astar in /home/antonin.rapini/ModulesTek1/IA/dante/astar/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri May  5 00:58:12 2017 Antonin Rapini
** Last update Sun May 14 21:08:13 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "dante.h"
#include "solver_sources.h"
#include "solver_utils.h"

int my_distance(int x, int y, int x_size, int y_size)
{
  return (x_size - x + y_size - y);
}

void		my_add_nodes(t_maze *maze, t_queue **queue)
{
  t_node	*curr;
  t_queue	*tmp;
  t_node	*new_node;
  t_queue	*new_queue;

  tmp = (*queue)->next;
  curr = (*queue)->node;
  free((*queue));
  (*queue) = tmp;
  while (curr->next++ < 3)
    {
      if ((new_node = my_get_next_node(maze, curr)) != NULL)
	{
	  maze->maze[POS(maze->x, new_node->y, new_node->x)] = VISITED_CHAR;
	  new_node->cost = curr->cost
	    + my_distance(curr->x, curr->y, new_node->x, new_node->y);
	  new_node->distance =
	    my_distance(new_node->x, new_node->y, maze->x - 1, maze->y - 1);
	  curr->connection_count++;
	  if ((new_queue = my_init_queue(new_node)) != NULL)
	    my_insert_node(new_queue, queue);
	}
    }
  if (curr->connection_count == 0)
    my_free_nodepath(curr);
}

t_node		*my_astar(t_maze *maze)
{
  t_queue	*queue;

  queue = maze->maze[0] == EMPTY_CHAR ?
    my_init_queue(my_init_node(0, 0, NULL)) : NULL;
  if (queue)
    queue->node->distance = my_distance(0, 0, maze->x, maze->y);
  maze->maze[POS(maze->x, 0, 0)] = VISITED_CHAR;
  while (queue != NULL && queue->node->distance != 0)
    {
      my_add_nodes(maze, &queue);
    }
  return (my_get_last(maze, queue));
}
