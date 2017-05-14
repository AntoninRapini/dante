/*
** my_wordtab_utils.c for my_wordtab_utils in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_tetris/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun Mar 12 20:25:38 2017 Antonin Rapini
** Last update Sun May 14 04:26:22 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "maze.h"

char	**my_init_wordtab(int size)
{
  char	**wordtab;
  int	i;

  i = 0;
  if ((wordtab = malloc(sizeof(char *) * (size + 1))) == NULL)
    return (NULL);
  while (i < size + 1)
    {
      wordtab[i] = NULL;
      i++;
    }
  return (wordtab);
}

void	*my_free_wordtab(char **tab)
{
  int	i;

  i = 0;
  if (tab != NULL)
    {
      while (tab[i++])
	free(tab[i - 1]);
      free(tab);
    }
  return (NULL);
}

void	my_show_wordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab && tab[i++])
    {
      my_putstr(tab[i - 1]);
      if (tab[i] != NULL)
	my_putchar('\n');
    }
}

int	my_wordtablen(char **tab)
{
  int	i;

  i = 0;
  while (tab && tab[i])
    i++;
  return (i);
}
