/*
** my_maze.c for  in /home/yoann.rey/dante/generator/src/
**
** Made by Yoann Rey
** Login   <yoann.rey@epitech.eu>
**
** Started on  Wed May 10 17:30:36 2017 Yoann Rey
** Last update Sun May 14 06:47:57 2017 Antonin Rapini
*/

#include "maze.h"

int		main(int ac, char **av)
{
  t_maze	*maze;

  if (ac < 3 || ac > 4)
    return (84);
  if ((maze = my_create_maze(ac, av)) == NULL)
    return (84);
  my_generate_maze(maze);
  my_show_wordtab(maze->maze);
  my_free_maze(maze);
  return (0);
}
