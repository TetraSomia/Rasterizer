/*
** display.c for rt in /home/josso/rendu/gfx/gfx_rasterizer
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon May  9 14:57:00 2016 Arthur Josso
** Last update Thu May 12 19:20:41 2016 Arthur Josso
*/

#include "rt.h"

static int	check_mesh(t_data *data, t_mesh *mesh)
{
  if (get_screen_pos(data, mesh) == 1)
    return (1);
#ifdef ZBUFF
  zbuff(data, mesh);
#elif FDF
  fdf(data, mesh);
#else
  if (rasterize(data, mesh) == 1)
    return (1);
#endif
  return (0);
}

int	gen_scene(t_data *data)
{
  int	i;

  i = 0;
  while (i < data->obj.nb.mesh)
    {
      if (check_mesh(data, &data->obj.mesh[i]) == 1)
	return (1);
      i++;
    }
  return (0);

}
