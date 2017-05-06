/*
** sources.h for base in /home/antonin.rapini/my_programs/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Mar  2 17:18:06 2017 Antonin Rapini
** Last update Sat May  6 18:56:45 2017 Antonin Rapini
*/

#ifndef SOLVER_SOURCES_H_
# define SOLVER_SOURCES_H_

#include "dante.h"


// Helpers
void	my_clear_visited(char **);
int	has_choice(char **, int, int, int);
int	is_valid_position(char **, int, int);
int	my_is_end(char **, t_node *);
void	my_resolve_maze(char **, t_node *);
t_node	*my_get_next_node(char **, t_node *);
void	my_mark_path(char **, t_node *);

// Maze
t_maze	*my_get_maze(char *);
t_maze	*my_init_maze();
void	*my_free_maze(t_maze *);

// Queue
void	*my_free_queue(t_queue *, int);
t_queue *my_init_queue(t_node *);

// Nodes
void	my_free_nodepath(t_node *);
void	*my_free_nodes(t_node *);
t_node	*my_init_node(int, int, t_node *);

#endif /* !SOLVER_SOURCES_H_ */
