/*
** maze.h for  in /home/yoann.rey/dante/includes
**
** Made by Yoann Rey
** Login   <yoann.rey@epitech.net>
**
** Started on  Wed Apr 26 17:10:35 2017 Yoann Rey
** Last update Sun May 14 07:53:21 2017 Antonin Rapini
*/

#ifndef MAZE_H_
# define MAZE_H_

# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <stdio.h>
# include <string.h>

# define VISITED_CHAR 'V'
# define WALL_CHAR 'X'
# define EMPTY_CHAR '*'
# define PATH_CHAR 'o'

typedef struct s_maze
{
  char	**maze;
  int	perfect;
  int	x;
  int	y;
}		t_maze;

typedef struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

typedef struct	s_node
{
  struct s_node	*previous;
  int		x;
  int		y;
}		t_node;

/* create_maze.c */

char	**create_maze(int, int);
void	display_maze(char **);

/* my_maze_utils.c */
t_maze *my_create_maze(int, char **);
void *my_free_maze(t_maze *);

/* fix_odd.c */
void fix_odd(t_node **, t_maze *);

/* my_node_utils.c */
t_node *my_init_node(int, int, t_node *, t_maze *);

/* my_generate_maze.c */
void my_generate_maze(t_maze *);
int my_move_next(t_node **, t_maze *);
int try_direction(t_node **, t_maze *, int, int);
int is_valid(t_node *, t_maze *, int, int);

/* display.c */

void 	my_putchar(char);
void	my_putstr(char *);
void	my_put_nbr(int);
int	my_strlen(char *);

/* my_wordtab_utils.c */

char **my_init_wordtab(int);
int my_wordtablen(char **);
void my_show_wordtab(char **);
void *my_free_wordtab(char **);

/* my_getnbr.c */

int	my_getnbr(char *, int *);

/* directions.c */

int	north(char **, int, int);
int	south(char **, int, int);
int	east(char **, int, int);
int	west(char **, int, int);
void	init_func(int (*func[4])(char **, int, int));

/* generations.c */

char	**generations(char **, int);
void	init_random();
int	generator_perf(char **, int (*func[4])(char **, int, int));
int	generator_imperf(char **, int (*func[4])(char **, int, int));

#endif
