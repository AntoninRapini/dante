/*
** dante.h for dante in /home/antonin.rapini/ModulesTek1/IA/dante/solvers/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon May  1 17:58:10 2017 Antonin Rapini
** Last update Tue May  9 06:07:04 2017 Antonin Rapini
*/

#ifndef DANTE_H_
# define DANTE_H_

# define VISITED_CHAR 'V'
# define WALL_CHAR 'X'
# define EMPTY_CHAR '*'
# define PATH_CHAR 'o'
# define POS(max, i, j) (((max + 1) * i) + j)

typedef struct	s_node
{
  int		x;
  int		y;
  int		next;
  int		connection_count;
  int		cost;
  int		distance;
  struct s_node	*previous;
}		t_node;

typedef struct		s_queue
{
  t_node		*node;
  struct s_queue	*next;
}			t_queue;

typedef struct	s_maze
{
  int		x;
  int		y;
  int		size;
  char		*maze;
}		t_maze;

#endif /* !DANTE_H_ */
