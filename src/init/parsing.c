/*
** parsing.c for rt in /home/josso/rendu/gfx/gfx_raytracer2
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Apr 21 13:35:10 2016 Arthur Josso
** Last update Mon Apr 25 14:19:58 2016 Arthur Josso
*/

#include "mesh.h"
#include "my.h"

static int	add_elem(t_mesh *mesh, char **tab, t_nb_mesh *nb)
{
  if (!tab[0])
    return (1);
  if (my_strcmp(tab[0], "v") == 0)
    {
      nb->v++;
      if (mesh_add_v(mesh, tab + 1) == 1)
	return (1);
    }
  else if (my_strcmp(tab[0], "vt") == 0)
    {
      nb->vt++;
      if (mesh_add_vt(mesh, tab + 1) == 1)
	return (1);
    }
  else if (my_strcmp(tab[0], "vn") == 0)
    {
      nb->vn++;
      if (mesh_add_vn(mesh, tab + 1) == 1)
	return (1);
    }
  else if (my_strcmp(tab[0], "f") == 0 &&
	   mesh_add_f(mesh, tab + 1, nb) == 1)
    return (1);
  return (0);
}

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab && tab[i])
    bunny_free(tab[i++]);
  if (tab)
    bunny_free(tab);
}

int		mesh_pars(t_mesh *mesh)
{
  t_nb_mesh	nb;
  char		*line;
  char		**tab;

  nb.v = 0;
  nb.vn = 0;
  nb.vt = 0;
  while ((line = get_next_line(mesh->fd)) != NULL)
    {
      tab = NULL;
      my_epurstr(line, ' ');
      if (line[0])
	{
	  if ((tab = my_str_to_tab(line, ' ')) == NULL)
	    return (1);
	  if (add_elem(mesh, tab, &nb) == 1)
	    return (1);
	}
      free_tab(tab);
      bunny_free(line);
    }
  return (0);
}
