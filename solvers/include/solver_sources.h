/*
** sources.h for base in /home/antonin.rapini/my_programs/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Mar  2 17:18:06 2017 Antonin Rapini
** Last update Sun May  7 03:52:54 2017 Antonin Rapini
*/

#ifndef SOLVER_SOURCES_H_
# define SOLVER_SOURCES_H_

#include "dante.h"

// Helpers
void	my_clear_visited(char *);
int	has_choice(t_maze *, int, int, int);
int	is_valid_position(t_maze *, int, int);
int	my_is_end(t_maze *, int, int);
void	my_resolve_maze(t_maze *, t_node *);
t_node	*my_get_next_node(t_maze *, t_node *);
void	my_mark_path(t_maze *, t_node *);

// Maze
t_maze	*my_create_maze(char *);
t_maze	*my_init_maze();
void	*my_free_maze(t_maze *);

// Queue
t_node	*my_get_last(t_maze *, t_queue *);
void	my_show_queue(t_queue *);
void	my_insert_node(t_queue *, t_queue **);
void	*my_free_queue(t_queue *, int);
t_queue *my_init_queue(t_node *);

// Nodes
void	my_free_nodepath(t_node *);
void	*my_free_nodes(t_node *);
t_node	*my_init_node(int, int, t_node *);

#endif /* !SOLVER_SOURCES_H_ */
