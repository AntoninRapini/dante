/*
** create_maze.c for  in /home/yoann.rey/dante/generator
**
** Made by Yoann Rey
** Login   <yoann.rey@epitech.net>
**
** Started on  Tue Apr 25 16:17:57 2017 Yoann Rey
** Last update Tue May  2 16:43:54 2017 Yoann Rey
*/

#include "maze.h"

void	print_delim(int x, t_maze *map)
{
  while (map->size < x * 2 + 1)
    {
      my_putchar('X');
      map->size++;
    }
  my_putchar('\n');
}
int	create_maze(int x, int y)
{
  t_maze	*map;
  int		tab_size;

  if ((map = malloc(sizeof(t_maze))) == NULL)
    return (1);
  map->wall = 'X';
  map->size = 0;
  tab_size = 1;
  malloc_my_tab(x, map->maze);
  print_delim(x, map);
  map->size = 0;
  while (tab_size < y)
    {
      while (map->size < x * 2 + 1)
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
  create_maze(my_getnbr(av[1]), my_getnbr(av[2]));
  return (0);
}
