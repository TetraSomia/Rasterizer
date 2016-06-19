/*
** add_light.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Feb 12 17:02:57 2016 Arthur Josso
** Last update Thu Apr 14 14:41:26 2016 Arthur Josso
*/

#include "init.h"

static int	add(t_light **item, int *nb_item, t_light new_item)
{
  t_light	*new;
  int		i;

  if ((new = bunny_malloc((*nb_item + 1) * sizeof(t_light))) == NULL)
    return (1);
  i = 0;
  while (i < *nb_item)
    {
      new[i] = (*item)[i];
      i++;
    }
  new[*nb_item] = new_item;
  if (*nb_item != 0)
    bunny_free(*item);
  (*item) = new;
  (*nb_item)++;
  return (0);
}

int             add_light(t_obj *obj, t_bunny_ini_scope *scope)
{
  t_light	light;

  if (get_ini_vec(scope, "position", &light.pos) == 1)
    return (1);
  if (get_ini_ratio(scope, "power", &light.power) == 1)
    return (1);
  if (add(&obj->light, &obj->nb.light, light) == 1)
    return (1);
  return (0);
}
