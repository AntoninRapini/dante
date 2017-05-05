/*
** display.c for  in /home/yoann.rey/System_Unix/PSU_2016_minishell1/src
**
** Made by Yoann Rey
** Login   <yoann.rey@epitech.net>
**
** Started on  Wed Mar  8 15:19:51 2017 Yoann Rey
** Last update Mon May  1 19:32:50 2017 Yoann Rey
*/

#include "maze.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    my_putchar(str[i++]);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
