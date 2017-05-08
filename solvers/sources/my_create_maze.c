/*
** my_create_maze.c for dante in /home/antonin.rapini/ModulesTek1/IA/dante/solvers/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat May  6 19:20:57 2017 Antonin Rapini
** Last update Mon May  8 02:28:45 2017 Antonin Rapini
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "dante.h"
#include "solver_sources.h"

int	my_check_maze(t_maze *maze)
{
  int	i;

  i = 0;
  while (maze->maze[i] && maze->maze[i] != '\n')
    {
      if (maze->maze[i] != EMPTY_CHAR && maze->maze[i] != WALL_CHAR)
	return (1);
      i++;
    }
  maze->x = i;
  while (maze->maze[i])
    {
      if (maze->maze[i] == '\n')
	{
	  if (maze->maze[i + 1] == '\0')
	    return (1);
	  if ((i + 1 - maze->y) / maze->y != maze->x)
	    return (1);
	  maze->y++;
	}
      else if (maze->maze[i] != EMPTY_CHAR && maze->maze[i] != WALL_CHAR)
	return (1);
      i++;
    }
  return (0);
}

int		my_get_filesize(FILE *file)
{
  struct stat	sb;

  if (fstat(fileno(file), &sb) != -1)
    return (sb.st_size);
  return (-1);
}

t_maze		*my_create_maze(char *filename)
{
  FILE		*file;
  t_maze	*maze;

  if ((file = fopen(filename, "r")) == NULL)
    return (NULL);
  if ((maze = my_init_maze()) == NULL)
    return (NULL);
  if ((maze->size = my_get_filesize(file)) <= 0)
    return (my_free_maze(maze));
  if ((maze->maze = malloc(sizeof(char) * (maze->size + 1))) == NULL)
    return (my_free_maze(maze));
  fread(maze->maze, maze->size, 1, file);
  fclose(file);
  return (my_check_maze(maze) == 0 ? maze : my_free_maze(maze));
}
