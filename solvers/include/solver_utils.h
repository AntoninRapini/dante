/*
** utils.h for base in /home/antonin.rapini/my_programs/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Mar  2 17:18:39 2017 Antonin Rapini
** Last update Mon May  1 18:38:05 2017 Antonin Rapini
*/

#ifndef SOLVER_UTILS_H_
# define SOLVER_UTILS_H_

# define READ_SIZE 1023

char	*get_next_line(int);
void	*my_free_wordtab(char **);
void	my_show_wordtab(char **);
int	my_strlen(char *);
void	my_putstr(char *);
void	my_putchar(char);

#endif /* !SOLVER_UTILS_H_ */
