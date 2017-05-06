/*
** my_is_end.c for dante in /home/antonin.rapini/ModulesTek1/IA/dante/solvers/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat May  6 05:32:16 2017 Antonin Rapini
** Last update Sat May  6 05:33:41 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "dante.h"

int my_is_end(char **maze, t_node *curr)
{
  return (maze[curr->y + 1] == NULL && maze[curr->y][curr->x + 1] == '\0');
}
