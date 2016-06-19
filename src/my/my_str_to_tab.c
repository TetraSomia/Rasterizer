/*
** my_str_to_tab.c for my in /home/josso/rendu/gfx/gfx_raytracer2
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Apr 21 16:12:39 2016 Arthur Josso
** Last update Thu Apr 21 18:48:23 2016 Arthur Josso
*/

#include <lapin.h>

static int	add_str(char ***tab, const char *s, int len)
{
  int		size;
  int		i;
  char		*new_str;

  size = 0;
  while (*tab && (*tab)[size])
    size++;
  if ((*tab = bunny_realloc(*tab, (size + 2)  * sizeof(char*))) == NULL)
    return (1);
  if ((new_str = bunny_malloc(len + 1)) == NULL)
    return (1);
  i = -1;
  while (++i < len)
    new_str[i] = s[i];
  new_str[i] = '\0';
  (*tab)[size++] = new_str;
  (*tab)[size] = NULL;
  return (0);
}

char	**my_str_to_tab(const char *s, char sep)
{
  char	**tab;
  int	beg;
  int	end;

  tab = NULL;
  beg = 0;
  end = 0;
  while (s[end])
    {
      while (s[end] && s[end] != sep)
	end++;
      if (add_str(&tab, s + beg, end - beg) == 1)
	return (NULL);
      if (s[end])
	end++;
      beg = end;
    }
  return (tab);
}
