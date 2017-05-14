/*
** my_maze.c for  in /home/yoann.rey/dante/generator/src/
**
** Made by Yoann Rey
** Login   <yoann.rey@epitech.eu>
**
** Started on  Wed May 10 17:30:36 2017 Yoann Rey
** Last update Sun May 14 18:44:39 2017 Antonin Rapini
*/

#include "maze.h"

int		main(int ac, char **av)
{
  t_maze	*maze;

  if (ac < 3 || ac > 4)
    return (84);
  if ((maze = my_create_maze(ac, av)) == NULL)
    return (84);
  srand(time(NULL));
  if (maze->perfect)
    my_generate_perfect(maze);
  else
    my_generate_imperfect(maze);
  my_show_wordtab(maze->maze);
  my_free_maze(maze);
  return (0);
}
