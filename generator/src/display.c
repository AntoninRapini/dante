/*
** display.c for  in /home/yoann.rey/System_Unix/PSU_2016_minishell1/src
**
** Made by Yoann Rey
** Login   <yoann.rey@epitech.net>
**
** Started on  Wed Mar  8 15:19:51 2017 Yoann Rey
** Last update Thu Apr 20 14:19:50 2017 Yoann Rey
*/

#include "dante.h"

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

int     my_strcmp(char *str, char *str2)
{
  int   i;

  i = 0;
  while (str[i] || str2[i])
    {
      if (str[i] != str2[i])
	return (-1);
      i++;
    }
  return (0);
}

char	*my_strcat(char	*src, char *cat)
{
  int	len1 = my_strlen(src);
  int	len2 = my_strlen(cat);
  char	*str;
  int	i;
  int	x;

  i = 0;
  x = 0;
  str = malloc(sizeof(char) * (len1 + len2) + 2);
  while (src[x])
    str[i++] = src[x++];
  x = 0;
  str[i] = '/';
  i++;
  while (cat[x])
    str[i++] = cat[x++];
  str[i] = '\0';
  return (str);
}
