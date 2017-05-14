/*
** my_maze_utils.c for generator in /home/antonin.rapini/ModulesTek1/IA/dante/generator/src
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun May 14 04:04:24 2017 Antonin Rapini
** Last update Sun May 14 18:56:19 2017 Antonin Rapini
*/

#include "maze.h"

char	**my_init_map(int y, int x)
{
  char	**map;
  int	i;
  int	j;

  i = 0;
  if ((map = my_init_wordtab(y + 1)) == NULL)
    return (NULL);
  while (i < y)
    {
      j = 0;
      if ((map[i] = malloc(sizeof(char) * (x + 1))) == NULL)
	return (my_free_wordtab(map));
      map[i][x] = '\0';
      while (j < x)
	{
	  map[i][j] = 'X';
	  j++;
	}
      i++;
    }
  return (map);
}

void *my_free_maze(t_maze *maze)
{
  if (maze != NULL)
    {
      my_free_wordtab(maze->maze);
      free(maze);
    }
  return (NULL);
}

t_maze		*my_init_maze()
{
  t_maze	*maze;

  if ((maze = malloc(sizeof(t_maze))) == NULL)
    return (NULL);
  maze->maze = NULL;
  maze->x = 0;
  maze->y = 0;
  maze->perfect = 0;
  return (maze);
}

t_maze		*my_create_maze(int ac, char **av)
{
  t_maze	*maze;
  int		ret;

  if ((maze = my_init_maze()) == NULL)
    return (NULL);
  maze->x = my_getnbr(av[1], &ret);
  if (maze->x <= 0 || ret != 0)
    return (my_free_maze(maze));
  maze->y = my_getnbr(av[2], &ret);
  if (maze->y <= 0 || ret != 0)
    return (my_free_maze(maze));
  if ((maze->maze = my_init_map(maze->y, maze->x)) == NULL)
    return (my_free_maze(maze));
  if (ac == 4 && strcmp(av[3], "perfect") == 0)
    maze->perfect = 1;
  return (maze);
}
