/*
** dante.h for dante in /home/antonin.rapini/ModulesTek1/IA/dante/depth/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun Apr 30 03:16:23 2017 Antonin Rapini
** Last update Fri May  5 20:03:28 2017 Antonin Rapini
*/

#ifndef DEPTH_H_
# define DEPTH_H_

#include "dante.h"

typedef struct		s_dnode
{
  t_pos			pos;
  int			next;
  struct s_dnode	*previous;
}			t_dnode;

#endif /* !DEPTH_H_ */
