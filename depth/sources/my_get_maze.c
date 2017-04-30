/*
** my_get_maze.c for dante in /home/antonin.rapini/ModulesTek1/IA/dante/depth/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat Apr 29 17:30:33 2017 Antonin Rapini
** Last update Sun Apr 30 22:07:28 2017 Antonin Rapini
*/

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "utils.h"
#include "depth.h"

#include <stdio.h>

int	my_check_maze(char **maze)
{
  int	i;
  int	j;
  int	line_size;

  i = 0;
  if (maze != NULL && maze[i] != NULL)
    {
      line_size = my_strlen(maze[i]);
      while (maze[i] != NULL)
	{
	  if (my_strlen(maze[i]) != line_size)
	      return (1);
	  j = 0;
	  while (maze[i][j])
	    {
	      if (maze[i][j] != WALL_CHAR && maze[i][j] != EMPTY_CHAR)
		  return (1);
	      j++;
	    }
	  i++;
	}
    }
  return (0);
}

char	**my_get_maze(char *filename)
{
  int	fd;
  char	**maze;
  char	*buffer;
  int	size;

  size = 0;
  maze = NULL;
  if ((fd = open(filename, O_RDONLY)) != -1)
    while ((buffer = get_next_line(fd)) != NULL)
      {
	size++;
	if ((maze = realloc(maze, sizeof(char *) * (size + 1))) == NULL)
	  {
	    free(buffer);
	    return (my_free_wordtab(maze));
	  }
	maze[size - 1] = buffer;
	maze[size] = NULL;
      }
  return (my_check_maze(maze) == 1 ? my_free_wordtab(maze) : maze);
}
