/*
** my_getnbr.c for  in /home/yoann.rey/CPool_Day04
**
** Made by Yoann Rey
** Login   <yoann.rey@epitech.net>
**
** Started on  Sun Oct  9 08:48:17 2016 Yoann Rey
** Last update Fri May 12 13:49:18 2017 Yoann Rey
*/

#include "maze.h"

int	my_getnbr_bis(char *str, int i, int nb1, int nb2)
{
  if (str[i] == '-' && !(str[i - 1] >= '0' && str[i - 1] <= '9'))
    my_getnbr_bis(str, i + 1, nb1, nb2 * - 1);
  else if (str[i] >= '0' && str[i] <= '9')
    my_getnbr_bis(str, i + 1, (nb1 * 10) + (str[i] - 48), nb2);
  else
    return (nb1 * nb2);
}

int	my_getnbr(char *str)
{
  int	i;

  i = my_getnbr_bis(str, 0, 0, 1);
  return (i);
}
