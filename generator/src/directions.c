/*
** directions.c for  in /home/yoann.rey/dante/generator/src/
**
** Made by Yoann Rey
** Login   <yoann.rey@epitech.eu>
**
** Started on  Wed May 10 15:46:27 2017 Yoann Rey
** Last update Sun May 14 06:06:07 2017 Antonin Rapini
*/

#include "maze.h"

int	north(char **map, int x, int y)
{
  if (map[y - 1])
    {
      if ((!(map[y - 2]) || (map[y - 2] && map[y - 2][x] == 'X')) &&
	  (map[y - 1][x - 1] == 'X') && (map[y - 1][x + 1] == 'X'))
	{
	  map[y - 2][x] = '*';
	  map[y - 1][x] = '*';
	  return (1);
	}
    }
  return (0);
    }

int	south(char **map, int x, int y)
{
  if (map[y + 1])
    {
      if ((!(map[y + 2]) || (map[y + 2] && map[y + 2][x] == 'X')) &&
	  (map[y + 1][x + 1] == 'X') && (map[y + 1][x + 1] == 'X'))
	{
	  map[y + 1][x] = '*';
	  map[y + 2][x] = '*';
	  return (1);
	}
    }
  return (0);
}

int	west(char **map, int x, int y)
{
  if (x - 1 >= 0)
    {
      if (((x - 2 > 0 && map[y][x - 2] == 'X')) &&
	  (map[y - 1][x - 1] == 'X') && (map[y + 1][x + 1] == 'X'))
	return (1);
      else
	{
	  my_putchar('h');
	  map[y][x - 2] = '*';
	  map[y][x - 1] = '*';
	}
    }
  return (0);
}

int east(t_node **node, t_maze **maze)
{
  if (map[y][x + 1] != '\0')
    {
      my_put_nbr(y);
      if (map[y][x + 2] != 'X')
	return (1);
      map[y][x + 1] = '*';
      map[y][x + 2] = '*';
      return (0);
    }
  return (1);
}

void	init_func(int (*func[4])(char **, int, int))
{
  func[0] = &north;
  func[1] = &south;
  func[2] = &west;
  func[3] = &east;
}
