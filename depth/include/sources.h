/*
** sources.h for base in /home/antonin.rapini/my_programs/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Mar  2 17:18:06 2017 Antonin Rapini
** Last update Sun Apr 30 22:02:52 2017 Antonin Rapini
*/

#ifndef SOURCES_H_
# define SOURCES_H_

#include "depth.h"

void	*my_free_nodes(t_node *);
t_node	*my_init_node(int, int, t_node *);
char	**my_get_maze(char *);
void	my_depth_algo(char **);

#endif /* !SOURCES_H_ */
