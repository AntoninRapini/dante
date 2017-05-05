/*
** sources.h for base in /home/antonin.rapini/my_programs/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Mar  2 17:18:06 2017 Antonin Rapini
** Last update Fri May  5 20:00:23 2017 Antonin Rapini
*/

#ifndef SOURCES_H_
# define SOURCES_H_

#include "depth.h"

void	my_dfs(char **);
t_dnode	*my_init_dnode(int, int, t_dnode *);
void	*my_free_dnodes(t_dnode *);
void	my_clear_visited(char **);

#endif /* !SOURCES_H_ */
