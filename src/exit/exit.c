/*
** exit.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Feb 18 17:59:57 2016 Arthur Josso
** Last update Thu May 12 19:31:04 2016 Arthur Josso
*/

#include <unistd.h>
#include "rt.h"

static void	close_fd(t_data *data)
{
  int		i;

  i = 0;
  while (i < data->obj.nb.mesh)
    close(data->obj.mesh[i++].fd);
}

static void	free_vec_tab(t_vec **v)
{
  int		i;

  i = 0;
  while (v && v[i])
    bunny_free(v[i++]);
  if (v)
    bunny_free(v);
}

static void	free_obj(t_data *data)
{
  int		i;
  int		j;

  i = 0;
  while (i < data->obj.nb.mesh)
    {
      free_vec_tab(data->obj.mesh[i].v);
      free_vec_tab(data->obj.mesh[i].vn);
      free_vec_tab(data->obj.mesh[i].vt);
      j = 0;
      while (data->obj.mesh[i].tri && data->obj.mesh[i].tri[j])
	bunny_free(data->obj.mesh[i].tri[j++]);
      if (data->obj.mesh[i].tri)
	bunny_free(data->obj.mesh[i].tri);
      if (data->obj.mesh[i].scr_pos)
	bunny_free(data->obj.mesh[i].scr_pos);
      i++;
    }
}

static void	free_z_buffer(float **buffer)
{
  int		i;

  i = 0;
  while (i < W_Y)
    bunny_free(buffer[i++]);
  bunny_free(buffer);
}

void	exit_prog(t_data *data)
{
  bunny_delete_clipable(&data->pix->clipable);
  close_fd(data);
  free_obj(data);
  free_z_buffer(data->z_buff);
  bunny_stop(data->win);
}
