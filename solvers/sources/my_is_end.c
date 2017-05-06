/*
** my_is_end.c for dante in /home/antonin.rapini/ModulesTek1/IA/dante/solvers/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat May  6 05:32:16 2017 Antonin Rapini
** Last update Sat May  6 22:22:38 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "dante.h"

int my_is_end(t_maze *maze, int y, int x)
{
  return (y == maze->y - 1 && x == maze->x - 1);
}
