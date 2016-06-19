/*
** add_basic.c for rt in /home/josso/rendu/gfx/gfx_raytracer2
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Apr 23 13:45:58 2016 Arthur Josso
** Last update Sun Apr 24 21:09:29 2016 Arthur Josso
*/

#include "mesh.h"
#include "my.h"

static int	realloc_mesh_vec(t_vec ***list, t_vec *vec)
{
  t_vec		*vec_pt;
  int		size;

  if ((vec_pt = bunny_malloc(sizeof(t_vec))) == NULL)
    return (1);
  *vec_pt = *vec;
  size = 0;
  while (*list && (*list)[size])
    size++;
  if ((*list = bunny_realloc(*list, (size + 2) * sizeof(t_vec*))) == NULL)
    return (1);
  (*list)[size++] = vec_pt;
  (*list)[size] = NULL;
  return (0);
}

int	mesh_add_v(t_mesh *mesh, char **val)
{
  int	i;
  t_vec	v;

  i = 0;
  while (val[i])
    if (!is_float(val[i++]))
      return (1);
  if (i != 3)
    return (1);
  v.x = get_double(val[0]);
  v.y = get_double(val[1]);
  v.z = get_double(val[2]);
  if (realloc_mesh_vec(&mesh->v, &v) == 1)
    return (1);
  return (0);
}

int	mesh_add_vn(t_mesh *mesh, char **val)
{
  int	i;
  t_vec	v;

  i = 0;
  while (val[i])
    if (!is_float(val[i++]))
      return (1);
  if (i != 3)
    return (1);
  v.x = get_double(val[0]);
  v.y = get_double(val[1]);
  v.z = get_double(val[2]);
  if (realloc_mesh_vec(&mesh->vn, &v) == 1)
    return (1);
  return (0);
}

int	mesh_add_vt(t_mesh *mesh, char **val)
{
  int	i;
  t_vec	v;

  i = 0;
  while (val[i])
    if (!is_float(val[i++]))
      return (1);
  if (i != 2 && i != 3)
    return (1);
  v.x = get_double(val[0]);
  v.y = get_double(val[1]);
  if (i == 2)
    v.z = 0;
  else
    v.z = get_double(val[2]);
  if (realloc_mesh_vec(&mesh->vt, &v) == 1)
    return (1);
  return (0);
}
