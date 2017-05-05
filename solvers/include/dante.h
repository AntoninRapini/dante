/*
** dante.h for dante in /home/antonin.rapini/ModulesTek1/IA/dante/solvers/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon May  1 17:58:10 2017 Antonin Rapini
** Last update Fri May  5 01:38:28 2017 Antonin Rapini
*/

#ifndef DANTE_H_
# define DANTE_H_

# define WALL_CHAR 'X'
# define EMPTY_CHAR '*'
# define PATH_CHAR 'o'

typedef struct	s_pos
{
  int		y;
  int		x;
}		t_pos;

typedef	struct		s_connection
{
  struct s_node		*node;
  int			size;
  struct s_connection	*next;
}			t_connection;

typedef struct	s_node
{
  int		search_dir;
  int		x;
  int		y;
  int		visited;
  t_connection	*connections;
  struct s_node	*previous;
  struct s_node	*next;
}		t_node;

typedef struct	s_path
{
  t_node	*node;
  struct s_path	*next;
  struct s_path *previous;
}		t_path;

typedef struct		s_pathlist
{
  t_path		*path;
  struct s_pathlist	*next;
}			t_pathlist;

typedef struct		s_treelist
{
  struct s_tree		*branch;
  struct s_branch	*next;
}			t_treelist;

typedef struct		s_tree
{
  t_node		*node;
  struct s_treelist	*branches;
  struct s_tree		*previous;
}			t_tree;

typedef struct	s_dante
{
  char		**maze;
  t_node	*graph;
  t_node	*start;
}		t_dante;

#endif /* !DANTE_H_ */
