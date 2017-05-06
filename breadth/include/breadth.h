/*
** breadth.h for breadth in /home/antonin.rapini/ModulesTek1/IA/dante/breadth/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri May  5 22:52:05 2017 Antonin Rapini
** Last update Sat May  6 15:27:34 2017 Antonin Rapini
*/

#ifndef BREADTH_H_
# define BREADTH_H_

#include "dante.h"

typedef struct		s_queue
{
  t_node		*node;
  struct s_queue	*next;
}			t_queue;

#endif /* !BREADTH_H_ */
