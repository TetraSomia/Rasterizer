/*
** fdf.c for rt in /home/josso/rendu/gfx/gfx_rasterizer
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu May 12 14:48:47 2016 Arthur Josso
** Last update Fri May 13 17:30:17 2016 Arthur Josso
*/

#include "rt.h"

void			fdf(t_data *data, t_mesh *mesh)
{
  int			i;
  int			j;
  t_color		c;
  t_bunny_position	p[2];
  t_tri_mesh		*tri;

  c.full = RED;
  j = 0;
  while (mesh->tri[j])
    {
      tri = mesh->tri[j];
      i = 0;
      while (i < 3)
	{
	  p[0].x = mesh->scr_pos[tri->vert[i].i].x;
	  p[0].y = mesh->scr_pos[tri->vert[i].i].y;
	  p[1].x = mesh->scr_pos[tri->vert[(i + 1) % 3].i].x;
	  p[1].y = mesh->scr_pos[tri->vert[(i + 1) % 3].i].y;
	  tekline(data->pix, p, &c);
	  i++;
	}
      j++;
    }
}

void                    zbuff(t_data *data, t_mesh *mesh)
{
  int                   i;
  t_color               c;
  t_bunny_position      p;
  char                  comp;

  i = 0;
  while (mesh->v[i])
    {
      comp = MAP(mesh->scr_pos[i].z, mesh->z_min, mesh->z_max, 0, 255);
      c.argb[RED_CMP] = comp;
      c.argb[BLUE_CMP] = comp;
      c.argb[GREEN_CMP] = comp;
      p.x = mesh->scr_pos[i].x;
      p.y = mesh->scr_pos[i].y;
      tekpixel(data->pix, &p, &c);
      i++;
    }
}
