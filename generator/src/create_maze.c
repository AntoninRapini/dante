/*
** create_maze.c for  in /home/yoann.rey/dante/generator
**
** Made by Yoann Rey
** Login   <yoann.rey@epitech.net>
**
** Started on  Tue Apr 25 16:17:57 2017 Yoann Rey
** Last update Thu May  4 14:35:41 2017 Yoann Rey
*/

#include "maze.h"

int	directions(t_maze *dir)
{
  int	rand_value;

  srand(time(NULL));
  rand_value = (rand() % 4);
}
int	create_map(int x, int y)
{
  t_maze	*map;
  int		tab_size;

  if ((map = malloc(sizeof(t_maze))) == NULL)
    return (1);
  map->wall = 'X';
  map->size = 0;
  tab_size = 1;
  malloc_my_tab(y, map->maze);
  map->size = 0;
  while (tab_size < y + 1)
    {
      while (map->size < x)
	{
	  my_putchar(map->wall);
	  map->size++;
	}
      map->size = 0;
      my_putchar('\n');
      tab_size++;
    }
  return (0);
}

int	main(int ac, char **av)
{
  if (ac != 3)
    return (84);
  create_map(my_getnbr(av[1]), my_getnbr(av[2]));
  return (0);
}
