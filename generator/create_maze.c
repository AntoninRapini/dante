/*
** create_maze.c for  in /home/yoann.rey/dante/generator
**
** Made by Yoann Rey
** Login   <yoann.rey@epitech.net>
**
** Started on  Tue Apr 25 16:17:57 2017 Yoann Rey
** Last update Thu Apr 27 17:19:44 2017 Yoann Rey
*/

#include "maze.h"

char	**create_walls(int x, int y)
{
  t_maze	map;

  map->maze = malloc_my_tab(map->maze);
  map->size = ((x - 1) * (y - 1));
}
