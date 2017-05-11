/*
** directions.c for  in /home/yoann.rey/dante/generator/src/
**
** Made by Yoann Rey
** Login   <yoann.rey@epitech.eu>
**
** Started on  Wed May 10 00:57:35 2017 Yoann Rey
** Last update Thu May 11 03:02:34 2017 Yoann Rey
*/

#include "maze.h"

char	**generations(char **map, int ac)
{
  int	(*func[4])(char **, int, int);

  //map = malloc_my_tab(map);
  init_func(func);
  my_putchar('g');
  if (ac == 4)
    map = generator_perf(map, func);
  my_putchar('t');
  return (map);
}

void	init_random()
{
  srand(time(NULL));
}

int	my_random()
{
  int	rdm;
  int	var;

  rdm = rand();
  var = (int)(((float) (rdm) / RAND_MAX) * 4);
  return (var);
}

int	generator_perf(char **map, int (*func[4])(char **, int, int))
{
  int	random;

  random = my_random();
  if ((random = 0))
    {
      my_putchar('h');
      generator_perf(map, &func[0]);
    }
  else if ((random = 1))
    generator_perf(map, &func[1]);
  else if ((random = 2))
    generator_perf(map, &func[2]);
  else if ((random = 3))
    generator_perf(map, &func[3]);
  my_putchar('f');
  return (0);
}

/*int	generator_imperf(char **map, int (*func[4])(char **, int, int))
{
  return (0);
}*/
