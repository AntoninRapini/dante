/*
** sources.h for base in /home/antonin.rapini/my_programs/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Mar  2 17:18:06 2017 Antonin Rapini
** Last update Fri May  5 02:01:14 2017 Antonin Rapini
*/

#ifndef SOLVER_SOURCES_H_
# define SOLVER_SOURCES_H_

#include "dante.h"

char	**my_get_maze(char *);
void	my_construct_graph(t_dante *);
void	my_show_graph(t_node *);

// Connections
void	*my_free_connections(t_connection *);
t_connection *my_init_connection(t_node *, int);
int	my_connect_nodes(t_node *, t_node *, int);
void my_show_connections(t_connection *);

// Dante
void	*my_free_dante(t_dante *);
t_dante	*my_create_dante(char *);

// Nodes
t_node *my_get_last_node(t_path *);
int	my_add_node(t_path **, t_node *);
void	my_mark_nodes(char **maze, t_node *);
void	*my_free_nodes(t_node *);
t_node	*my_init_node(int, int, t_node **);
t_node	*my_get_node(t_node *, int, int);

// Path
void my_show_path(t_path *);
void	my_mark_path(t_path *, char **);
void	*my_free_path(t_path *);
t_path	*my_init_path(t_node *);
t_path	*my_copy_path(t_path *);

// Pathlist
int my_add_path(t_pathlist **, t_path *);
t_pathlist *my_init_pathlist_item(t_path *);
void *my_free_pathlist(t_pathlist *);

#endif /* !SOLVER_SOURCES_H_ */
