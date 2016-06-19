/*
** my_epurstr.c for my in /home/josso/rendu/gfx/gfx_raytracer2
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Apr 21 15:21:28 2016 Arthur Josso
** Last update Sat Apr 23 15:33:57 2016 Arthur Josso
*/

static void	epur_from(char *s, char sep)
{
  int		i;
  int		j;

  i = 0;
  while (s[i] && (s[i] == sep || s[i] == '\t'))
    i++;
  j = 0;
  while (s[i])
    s[j++] = s[i++];
  s[j] = '\0';
}

void	my_epurstr(char *s, char sep)
{
  int	i;

  i = 0;
  while (s[i])
    {
      if (s[i] == sep || s[i] == '\t')
	{
	  if (s[i] == '\t')
	    s[i] = sep;
	  if (i)
	    epur_from(s + i + 1, sep);
	  else
	    epur_from(s + i, sep);
	  if (!s[i + 1])
	    s[i] = '\0';
	}
      i++;
    }
}
