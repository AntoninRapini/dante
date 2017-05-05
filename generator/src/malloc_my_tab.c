/*
** malloc_my_tab.c for dantr in /home/yoann.rey/dante/generator/src/
**
** Made by Yoann Rey
** Login   <yoann.rey@epitech.eu>
**
** Started on  Mon May  1 19:33:41 2017 Yoann Rey
** Last update Tue May  2 16:37:30 2017 Yoann Rey
*/

#include "maze.h"

int	malloc_my_tab(int y, char **tab)
{
  int	i;
  int	len;

  i = 0;
  if ((tab = malloc(sizeof(char *) * y + 1)) == NULL)
    return (1);
  while (tab[i])
    {
      len = my_strlen(tab[i]);
      if ((tab[i] = malloc(sizeof(char) * len + 1)) == NULL)
	return (1);
    }
  return (0);
}
