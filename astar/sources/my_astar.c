/*
** my_astar.c for astar in /home/antonin.rapini/ModulesTek1/IA/dante/astar/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri May  5 00:58:12 2017 Antonin Rapini
** Last update Sat May  6 22:44:56 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "dante.h"
#include "solver_sources.h"

int my_distance(int x, int y, int x_size, int y_size)
{
  return (x_size - x + y_size - y);
}

t_node		*my_astar(t_maze *maze)
{
  t_queue	*queue;

  queue = my_init_queue(my_init_node(0,0, NULL));
  if (queue)
    queue->node->distance = my_distance(0, 0, maze->x, maze->y);
  /*while (queue != NULL && queue->distance->node != 0)
    {
    }*/
  return (queue->node);
}
