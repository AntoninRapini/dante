/*
** my_astar.c for astar in /home/antonin.rapini/ModulesTek1/IA/dante/astar/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri May  5 00:58:12 2017 Antonin Rapini
** Last update Sat May  6 18:48:25 2017 Antonin Rapini
*/

int my_distance(int x, int y, int x_size, int y_size)
{
  return (x_size - x + y_size - y);
}

t_node		*my_astar(t_maze *maze)
{
  t_queue	*queue;

  queue = my_init_queue(my_init_node(0,0, NULL));
  if (queue)
    queue->distance = my_distance(0, 0, maze->x, maze->y);
  while (queue != NULL && queue->distance->node != 0)
    {
    }
  return (queue->node);
}
