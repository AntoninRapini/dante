/*
** malloc_my_tab.c for dante in /home/yoann.rey/dante/generator/
**
** Made by Yoann Rey
** Login   <yoann.rey@epitech.eu>
**
** Started on  Thu Apr 20 15:09:26 2017 Yoann Rey
** Last update Tue Apr 25 16:22:15 2017 Yoann Rey
*/

#include "dante.h"

int	malloc_my_tab(char **tab)
{
  int	i;
  int	j;
  int	maze_len;
  int	line_lenght;

  i = -1;
  j = 0;
  line_lenght = my_strlen(map[i]);
  maze_len = my_tablen(tab);
  if ((tab = malloc(sizeof(char *) * maze_len + 1)) == NULL)
    return (1);
  while (tab[++i])
    {
      if ((map[i] = malloc(sizeof(char) * line_lenght + 1)) == NULL)
	return (1);
      j++;
    }
  return (0);
}
