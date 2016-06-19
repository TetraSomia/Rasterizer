/*
** my_getnbr.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Feb 12 17:37:24 2016 Arthur Josso
** Last update Fri Feb 12 17:37:26 2016 Arthur Josso
*/

int     get_nbr(char *s)
{
  int   len;
  int   ret;
  long  mult;

  ret = 0;
  len = -1;
  mult = 1;
  while (s && s[++len]);
  len--;
  while (len >= 0 && s[len] != '-')
    {
      ret += mult * (s[len] - '0');
      mult *= 10;
      len--;
    }
  if (len == 0 && s[len] == '-')
    ret *= -1;
  return (ret);
}
