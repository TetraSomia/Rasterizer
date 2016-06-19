/*
** add_face.c for rt in /home/josso/rendu/gfx/gfx_raytracer2
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Apr 23 14:52:28 2016 Arthur Josso
** Last update Wed May 18 16:41:53 2016 Arthur Josso
*/

#include "mesh.h"
#include "my.h"

static int	realloc_mesh_tri(t_tri_mesh ***list, t_tri_mesh const *tri)
{
  t_tri_mesh	*tri_pt;
  int		size;

  if ((tri_pt = bunny_malloc(sizeof(t_tri_mesh))) == NULL)
    return (1);
  *tri_pt = *tri;
  size = 0;
  while (*list && (*list)[size])
    size++;
  if ((*list = bunny_realloc(*list, (size + 2) * sizeof(t_tri_mesh*))) == NULL)
    return (1);
  (*list)[size++] = tri_pt;
  (*list)[size] = NULL;
  return (0);
}

static int	get_vertex(t_mesh const *mesh,
			   t_nb_mesh const *nb,
			   char *s,
			   t_vertex *vert)
{
  char		**val;
  int		i;

  my_epurstr(s, '/');
  if (!s[0] || (val = my_str_to_tab(s, '/')) == NULL)
    return (1);
  i = -1;
  while (val[++i])
    if (!is_number(val[i]))
      return (1);
  if (i != 3)
    return (1);
  if ((i = get_double(val[0])) > nb->v || i == 0)
    return (1);
  vert->pos = mesh->v[i - 1];
  vert->i = i - 1;
  if ((i = get_double(val[1])) > nb->vt || i == 0)
    return (1);
  vert->t = mesh->vt[i - 1];
  if ((i = get_double(val[2])) > nb->vn || i == 0)
    return (1);
  vert->n = mesh->vn[i - 1];
  free_tab(val);
  return (0);
}

static int	add_meshes(t_mesh *mesh,
			   char **val,
			   t_nb_mesh const *nb,
			   int nb_vert)
{
  t_tri_mesh	tri;
  int		i;

  i = 0;
  while (i < 3)
    {
      if (get_vertex(mesh, nb, val[i], &tri.vert[i]) == 1)
	return (1);
      i++;
    }
  if (realloc_mesh_tri(&mesh->tri, &tri) == 1)
    return (1);
  while (i < nb_vert)
    {
      tri.vert[1] = tri.vert[2];
      if (get_vertex(mesh, nb, val[i], &tri.vert[2]) == 1)
	return (1);
      if (realloc_mesh_tri(&mesh->tri, &tri) == 1)
	return (1);
      i++;
    }
  return (0);
}

int	mesh_add_f(t_mesh *mesh, char **val, t_nb_mesh const *nb)
{
  int	nb_vert;

  nb_vert = 0;
  while (val[nb_vert])
    nb_vert++;
  if (nb_vert < 3)
    return (1);
  if (add_meshes(mesh, val, nb, nb_vert) == 1)
    return (1);
  return (0);
}
