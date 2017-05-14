/*
** my_maze.c for  in /home/yoann.rey/dante/generator/src/
**
** Made by Yoann Rey
** Login   <yoann.rey@epitech.eu>
**
** Started on  Wed May 10 17:30:36 2017 Yoann Rey
** Last update Fri May 12 15:15:29 2017 Yoann Rey
*/

#include "maze.h"

char	**create_maze(int w, int h)
{
  t_maze	*map;

  if ((map = malloc(sizeof(t_maze))) == NULL)
    return (NULL);
  map->maze = malloc(sizeof(char *) * (h + 1));
  (map->maze[h] = NULL);
  map->y = 0;
  while (map->y < h)
    {
      map->x = 0;
      map->maze[map->y] = malloc(sizeof(char) * (w + 1));
      map->maze[map->y][w] = '\0';
      while (map->x < w)
	{
	  (map->maze[map->y][map->x] = 'X');
	  map->x++;
	}
      map->y++;
    }
  return (map->maze);
}

void	display_maze(char **map)
{
  int	i;

  i = 0;
  while (map[i] != NULL)
    {
      my_putstr(map[i]);
      my_putchar('\n');
      i++;
    }
}

int	free_map(char **map)
{
  int	i;

  i = 0;
  while (map[i])
    {
      free(map[i]);
      i++;
    }
  free(map);
  return (0);
}

int	main(int ac, char **av)
{
  t_maze	*map;
  char 		**my_maze;

  if (ac != 3)
    return (1);
  if ((map = malloc(sizeof(t_maze))) == NULL)
    return (1);
  init_random();
  my_maze = create_maze(my_getnbr(av[1]), my_getnbr(av[2]));
  display_maze(my_maze);
  east(my_maze, my_getnbr(av[1]), my_getnbr(av[2]));
  free_map(my_maze);
  free(map);
  return (0);
}
