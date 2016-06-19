/*
** get.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Feb 12 16:47:33 2016 Arthur Josso
** Last update Wed May 18 17:23:02 2016 Arthur Josso
*/

#include "rt.h"
#include "my.h"

int             get_ini_vec(t_bunny_ini_scope *scope,
			    const char *field,
			    t_vec *vec)
{
  const char    *data;

  if ((data = bunny_ini_scope_get_field(scope, field, 0)) == NULL)
    return (1);
  vec->x = get_double((char*)data);
  if ((data = bunny_ini_scope_get_field(scope, field, 1)) == NULL)
    return (1);
  vec->y = get_double((char*)data);
  if ((data = bunny_ini_scope_get_field(scope, field, 2)) == NULL)
    return (1);
  vec->z = get_double((char*)data);
  return (0);
}

int             get_ini_size(t_bunny_ini_scope *scope,
			     const char *field,
			     float *nb)
{
  const char    *data;

  if ((data = bunny_ini_scope_get_field(scope, field, 0)) == NULL)
    return (1);
  *nb = get_double((char*)data);
  if (*nb <= 0)
    return (1);
  return (0);
}
int		get_ini_ratio(t_bunny_ini_scope *scope,
			      const char *field, float *nb)
{
  const char    *data;

  if ((data = bunny_ini_scope_get_field(scope, field, 0)) == NULL)
    return (1);
  *nb = get_double((char*)data);
  if (*nb < 0 || *nb > 1)
    return (1);
  return (0);
}

t_bunny_pixelarray	*get_tex(t_bunny_ini_scope *scope)
{
  const char		*data;
  t_bunny_pixelarray	*tex;

  if ((data = bunny_ini_scope_get_field(scope, "texture", 0)) == NULL)
    return (NULL);
  else if ((tex = bunny_load_pixelarray(data)) == NULL)
    return (NULL);
  return (tex);
}
