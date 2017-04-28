/*
** my_getnbr.c for  in /home/yoann.rey/CPool_Day04
** 
** Made by Yoann Rey
** Login   <yoann.rey@epitech.net>
** 
** Started on  Sun Oct  9 08:48:17 2016 Yoann Rey
** Last update Mon Oct 17 20:39:57 2016 Yoann Rey
*/

int	my_getnbr_bis(char *str, int a, int b, int d)
{
  if (str[a] == '-' && !(str[a - 1] >= '0' && str[a - 1] <= '9'))
    {
      my_getnbr_bis(str, a + 1, b, d * - 1); 
    }
  else if (str[a] >= '0' && str[a] <= '9')
    {
      my_getnbr_bis(str, a + 1, (b * 10) + (str[a] - 48), d);
    }
  else
    {
      return (b * d);
    }
}

int	my_getnbr(char *str)
{
  int	i;

  i = my_getnbr_bis(str, 0, 0, 1);
  return (i);
}
