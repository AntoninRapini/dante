/*
** my_resolve_maze.c for dante in /home/antonin.rapini/ModulesTek1/IA/dante/solvers/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat May  6 15:58:51 2017 Antonin Rapini
** Last update Sat May  6 21:27:59 2017 Antonin Rapini
*/

#include <unistd.h>
#include "dante.h"
#include "solver_sources.h"
#include "solver_utils.h"

void my_resolve_maze(t_maze *maze, t_node *path)
{
  my_mark_path(maze, path);
  my_clear_visited(maze->maze);
  write(1, maze->maze, maze->size);
  write(1, "\n", 1);
}
