/*
** init.c for rt in /home/josso/en_cours/rt
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jan 29 18:38:07 2016 Arthur Josso
** Last update Thu May 12 18:05:41 2016 Arthur Josso
*/

#include "rt.h"

void			put_in_black(t_bunny_pixelarray *pix)
{
  t_bunny_position	pos;
  t_color		color;

  color.full = BLACK;
  pos.x = 0;
  while (pos.x < pix->clipable.clip_width)
    {
      pos.y = 0;
      while (pos.y < pix->clipable.clip_height)
	{
	  tekpixel(pix, &pos, &color);
	  pos.y++;
	}
      pos.x++;
    }
}

static int	win_init(t_data *data)
{
  if ((data->win = bunny_start(W_X, W_Y, FULL_SCR, "RT")) == NULL)
    return (ERROR);
  if ((data->pix = bunny_new_pixelarray(W_X, W_Y)) == NULL)
    return (ERROR);
  put_in_black(data->pix);
  return (SUCCESS);
}

static int	alloc_z_buffer(t_data *data)
{
  int		i;

  i = 0;
  if ((data->z_buff = bunny_malloc(sizeof(float*) * W_Y)) == NULL)
    return (1);
  while (i < W_Y)
    {
      if ((data->z_buff[i] = bunny_malloc(sizeof(float) * W_X)) == NULL)
	return (1);
      i++;
    }
  return (0);
}

int	init(t_data *data, const char *file)
{
  data->keys = NULL;
  if (alloc_z_buffer(data) == 1)
    return (1);
  if (win_init(data) == ERROR)
    return (ERROR);
  if (load_scene(&data->obj, file) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
