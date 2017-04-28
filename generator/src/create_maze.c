/*
** create_maze.c for  in /home/yoann.rey/dante/generator
**
** Made by Yoann Rey
** Login   <yoann.rey@epitech.net>
**
** Started on  Tue Apr 25 16:17:57 2017 Yoann Rey
** Last update Fri Apr 28 15:02:28 2017 Yoann Rey
*/

#include "maze.h"

void	print_delim(char *size)
{
  int	x;

  x = 0;
  while (x < my_getnbr(size) * 2 + 1)
    {
      my_putchar('1');
      x++;
    }
}

int	main(int ac, char **av)
{
  if (ac < 2)
    return (84);
  print_delim(av[1]);
  return (0);
}
