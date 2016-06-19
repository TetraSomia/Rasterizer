/*
** my_strcmp.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Feb 12 17:37:15 2016 Arthur Josso
** Last update Fri Feb 12 17:37:15 2016 Arthur Josso
*/

int     my_strcmp(char *s1, char *s2)
{
  int   i;

  if (!s1 && !s2)
    return (0);
  else if (!s1 || !s2)
    return (1);
  i = 0;
  while (!(s1[i] == 0 || s2[i] == 0))
    {
      if (s1[i] < s2[i])
	return (-1);
      else if (s1[i] > s2[i])
	return (1);
      i++;
    }
  if (s1[i] == 0 && s2[i] != 0)
    return (-1);
  else if (s2[i] == 0 && s1[i] != 0)
    return (1);
  else
    return (0);
}
