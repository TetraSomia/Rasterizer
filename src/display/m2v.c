/*
** m2v.c for rt in /home/josso/rendu/gfx/gfx_rasterizer
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu May 12 14:54:12 2016 Arthur Josso
** Last update Mon May 16 15:13:15 2016 Arthur Josso
*/

#include "rt.h"
#include "matrix.h"

static void	reset_z_buffer(float **buffer, float z_max)
{
  int		i;
  int		j;

  z_max *= 2;
  i = 0;
  while (i < W_Y)
    {
      j = 0;
      while (j < W_X)
	buffer[i][j++] = z_max;
      i++;
    }
}

static int      get_point(t_cam *cam, t_meta *obj,
			  t_vec *pos_3d, t_vec *pos_2d)
{
  t_matrix      m[NB_MATRICES];
  t_matrix      pt[2];
  int           i;
  int           j;

  if (init_matrices(m, cam, obj) == 1)
    return (1);
  if (init_pts(pt, pos_3d) == 1)
    return (1);
  i = 0;
  while (i < NB_MATRICES - 2)
    {
      mult_matrix(&m[i++], &pt[0], &pt[1]);
      j = -1;
      while (++j < 4)
	pt[0].m[j][0] = pt[1].m[j][0];
      if (i == NB_MATRICES - 3)
	pos_2d->z = pt[0].m[2][0];
    }
  pos_2d->x = ((pt[0].m[0][0] * (float)W_X) / 2.0) / pt[0].m[3][0] + W_X / 2.0;
  pos_2d->y = ((pt[0].m[1][0] * (float)W_Y) / 2.0) / pt[0].m[3][0] + W_Y / 2.0;
  free_mat_and_pt(m, pt);
  return (0);
}

int	get_screen_pos(t_data *data, t_mesh *mesh)
{
  int	i;

  set_cosin_values(&mesh->meta);
  if (get_point(&data->obj.cam, &mesh->meta,
		mesh->v[0], &mesh->scr_pos[0]) == 1)
    return (1);
  mesh->z_max = mesh->scr_pos[0].z;
  mesh->z_min = mesh->scr_pos[0].z;
  i = 1;
  while (mesh->v[i])
    {
      if (get_point(&data->obj.cam, &mesh->meta,
		    mesh->v[i], &mesh->scr_pos[i]) == 1)
	return (1);
      if (mesh->scr_pos[i].z > mesh->z_max)
	mesh->z_max = mesh->scr_pos[i].z;
      else if (mesh->scr_pos[i].z < mesh->z_min)
	mesh->z_min = mesh->scr_pos[i].z;
      i++;
    }
  reset_z_buffer(data->z_buff, mesh->z_max);
  return (0);
}
