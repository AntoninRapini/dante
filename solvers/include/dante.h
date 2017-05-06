/*
** dante.h for dante in /home/antonin.rapini/ModulesTek1/IA/dante/solvers/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon May  1 17:58:10 2017 Antonin Rapini
** Last update Sat May  6 15:42:30 2017 Antonin Rapini
*/

#ifndef DANTE_H_
# define DANTE_H_

# define VISITED_CHAR 'V'
# define WALL_CHAR 'X'
# define EMPTY_CHAR '*'
# define PATH_CHAR 'o'

typedef	struct		s_connection
{
  struct s_node		*node;
  struct s_connection	*next;
}			t_connection;

typedef struct	s_node
{
  int		x;
  int		y;
  int		next;
  int		connection_count;
  struct s_node	*previous;
}		t_node;

#endif /* !DANTE_H_ */
