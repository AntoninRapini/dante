/*
** uses.c for  in /home/yoann.rey/System_Unix/PSU_2016_minishell2/src
**
** Made by Yoann Rey
** Login   <yoann.rey@epitech.net>
**
** Started on  Sat Apr 15 18:40:40 2017 Yoann Rey
** Last update Thu Apr 20 14:19:54 2017 Yoann Rey
*/

#include "dante.h"

char	*my_strcpy(char *dest, char *src)
{
  int   i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

char	*my_strdup(char *src)
{
  char	*dup;

  dup = malloc(my_strlen(src) + 1);
  if (dup == NULL)
    return (NULL);
  my_strcpy(dup, src);
  free(src);
  return (dup);
}

int	my_tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i++] != NULL);
  return (i);
}
int	my_strncmp(char *s1, char *s2, int n)
{
  int   i;

  i = 0;
  while ((i < n) && (s1[i] != '\0' || s2[i] != '\0'))
    {
      if (s1[i] < s2[i])
	return (s1[i] - s2[i]);
      if (s1[i] > s2[i])
	return (s1[i] - s2[i]);
      i = i + 1;
    }
  return (0);
}
