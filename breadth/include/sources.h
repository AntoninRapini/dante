/*
** sources.h for base in /home/antonin.rapini/my_programs/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Mar  2 17:18:06 2017 Antonin Rapini
** Last update Sat May  6 16:16:50 2017 Antonin Rapini
*/

#ifndef SOURCES_H_
# define SOURCES_H_

#include "dante.h"
#include "breadth.h"

t_queue *my_bfs(char **);
void *my_free_queue(t_queue *, int);
t_queue *my_init_queue(t_node *);

#endif /* !SOURCES_H_ */
