/*
** get2.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Feb 20 16:27:02 2016 Arthur Josso
** Last update Wed May 11 17:32:45 2016 Arthur Josso
*/

#include "rt.h"
#include "init.h"
#include "my.h"

static int	get_ini_color(t_bunny_ini_scope *scope, t_color *color)
{
  const char	*data;

  if ((data = bunny_ini_scope_get_field(scope, "color", 0)) == NULL)
    color->argb[RED_CMP] = 255;
  else
    color->argb[RED_CMP] = get_double((char*)data);
  if ((data = bunny_ini_scope_get_field(scope, "color", 1)) == NULL)
    color->argb[GREEN_CMP] = 255;
  else
    color->argb[GREEN_CMP] = get_double((char*)data);
  if ((data = bunny_ini_scope_get_field(scope, "color", 2)) == NULL)
    color->argb[BLUE_CMP] = 255;
  else
    color->argb[BLUE_CMP] = get_double((char*)data);
  if ((data = bunny_ini_scope_get_field(scope, "color", 3)) == NULL)
    color->argb[ALPHA_CMP] = 0;
  else
    color->argb[ALPHA_CMP] = get_double((char*)data);
  return (0);
}

int	get_ini_meta(t_bunny_ini_scope *scope, t_meta *meta)
{
  if (get_ini_color(scope, &meta->color) == 1)
    return (1);
  if (get_ini_vec(scope, "position", &meta->pos) == 1)
    return (1);
  if (get_ini_vec(scope, "rotation", &meta->rot) == 1)
    {
      meta->rot.x = 0;
      meta->rot.y = 0;
      meta->rot.z = 0;
    }
  if (get_ini_vec(scope, "scale", &meta->scale) == 1)
    {
      meta->scale.x = 1;
      meta->scale.y = 1;
      meta->scale.z = 1;
    }
  if (meta->scale.x > 1 || meta->scale.x < 0)
    meta->scale.x = 1;
  if (meta->scale.y > 1 || meta->scale.y < 0)
    meta->scale.y = 1;
  if (meta->scale.z > 1 || meta->scale.z < 0)
    meta->scale.z = 1;
  return (0);
}
