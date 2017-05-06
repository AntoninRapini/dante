/*
** my_resolve_maze.c for dante in /home/antonin.rapini/ModulesTek1/IA/dante/solvers/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat May  6 15:58:51 2017 Antonin Rapini
** Last update Sat May  6 18:58:30 2017 Antonin Rapini
*/

#include "dante.h"
#include "solver_sources.h"
#include "solver_utils.h"

void my_resolve_maze(char **maze, t_node *path)
{
  my_mark_path(maze, path);
  my_clear_visited(maze);
  my_show_wordtab(maze);
}
