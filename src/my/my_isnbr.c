/*
** my_isnbr.c for rt in /home/josso/rendu/gfx/gfx_raytracer2
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Apr 23 15:56:27 2016 Arthur Josso
** Last update Sat Apr 23 15:57:20 2016 Arthur Josso
*/

int	is_number(char const *s)
{
  int	i;

  i = 0;
  while (s[i])
    {
      if (s[i] < '0' || s[i] > '9')
	return (0);
      i++;
    }
  return (1);
}
