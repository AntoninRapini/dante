/*
** dante.h for dante in /home/antonin.rapini/ModulesTek1/IA/dante/depth/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun Apr 30 03:16:23 2017 Antonin Rapini
** Last update Sun Apr 30 21:47:10 2017 Antonin Rapini
*/

#ifndef DEPTH_H_
# define DEPTH_H_

# define WALL_CHAR 'X'
# define EMPTY_CHAR '*'
# define PATH_CHAR 'o'

# define RIGHT 1
# define DOWN 2
# define LEFT 3
# define UP 4

typedef struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

typedef struct	s_node
{
  t_pos		pos;
  int		next;
  struct s_node *previous;
}		t_node;

#endif /* !DEPTH_H_ */
