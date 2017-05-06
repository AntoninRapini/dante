/*
** my_get_maze.c for dante in /home/antonin.rapini/ModulesTek1/IA/dante/depth/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat Apr 29 17:30:33 2017 Antonin Rapini
** Last update Sat May  6 19:12:46 2017 Antonin Rapini
*/

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "solver_sources.h"
#include "solver_utils.h"

int	my_check_maze(t_maze *maze)
{
  int	i;
  int	j;

  i = 0;
  if (maze->maze != NULL && maze->maze[i] != NULL)
    {
      maze->x = my_strlen(maze->maze[i]);
      while (maze->maze[i] != NULL)
	{
	  j = 0;
	  while (maze->maze[i][j])
	    {
	      if (maze->maze[i][j] != WALL_CHAR
		  && maze->maze[i][j] != EMPTY_CHAR)
		  return (1);
	      j++;
	    }
	  if (j != maze->x)
	    return (1);
	  i++;
	}
    }
  maze->y = i;
  return (0);
}

t_maze		*my_get_maze(char *filename)
{
  int		fd;
  t_maze	*maze;
  char		*buffer;
  int		size;

  size = 0;
  if ((maze = my_init_maze()) == NULL)
    return (NULL);
  if ((fd = open(filename, O_RDONLY)) != -1)
    {
      while ((buffer = get_next_line(fd)) != NULL)
	{
	  size++;
	  if ((maze->maze = realloc(maze->maze, sizeof(char *) * (size + 1))) == NULL)
	    {
	      free(buffer);
	      return (my_free_maze(maze));
	    }
	  maze->maze[size - 1] = buffer;
	  maze->maze[size] = NULL;
	}
    }
  return (my_check_maze(maze) == 1 ? my_free_maze(maze) : maze);
}
