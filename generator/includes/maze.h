/*
** maze.h for  in /home/yoann.rey/dante/includes
**
** Made by Yoann Rey
** Login   <yoann.rey@epitech.net>
**
** Started on  Wed Apr 26 17:10:35 2017 Yoann Rey
** Last update Thu May 11 02:47:46 2017 Yoann Rey
*/

#ifndef MAZE_H_
# define MAZE_H_

# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <stdio.h>
# include <string.h>

typedef struct s_maze
{
  char	**maze;
  int	x;
  int	y;
}		t_maze;

/* create_maze.c */

char	**create_maze(int, int);
void	display_maze(char **);

/* malloc_my_tab */

int	malloc_my_tab(char **);

/* display.c */

void 	my_putchar(char);
void	my_putstr(char *);
int	my_strlen(char *);

/* my_getnbr.c */

int	my_getnbr(char *);

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
