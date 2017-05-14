/*
** put_nbr.c for  in /home/yoann.rey/System_Unix/PSU_2016_navy/src
**
** Made by Yoann Rey
** Login   <yoann.rey@epitech.net>
**
** Started on  Fri Feb 17 14:37:01 2017 Yoann Rey
** Last update Fri May 12 14:05:12 2017 Yoann Rey
*/

void	put_nbr(int nbr)
{
  if (nbr < 0)
    {
      my_putchar('-');
      put_nbr(nbr = -nbr);
    }
  else if (nbr >= 10)
    {
      put_nbr(nbr / 10);
      my_putchar((nbr % 10) + 48);
    }
  else if (nbr <= -10)
    {
      my_putchar ('-');
      put_nbr(nbr / 10);
      my_putchar((nbr % 10) + 48);
    }
  else
    my_putchar(nbr + 48);
}
