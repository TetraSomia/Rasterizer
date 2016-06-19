/*
** my_is_float.c for my in /home/josso/rendu/gfx/gfx_raytracer2
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Apr 23 13:50:29 2016 Arthur Josso
** Last update Sat Apr 23 13:54:20 2016 Arthur Josso
*/

int	is_float(char const *s)
{
  int	i;

  i = 0;
  while (s[i])
    {
      if ((s[i] < '0' || s[i] > '9') && s[i] != '.')
	{
	  if (i != 0)
	    return (0);
	  else if (s[i] != '-')
	    return (0);
	}
      i++;
    }
  return (1);
}
