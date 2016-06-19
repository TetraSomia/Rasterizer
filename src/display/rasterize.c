/*
** rasterize.c for rt in /home/josso/rendu/gfx/gfx_rasterizer
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu May 12 15:49:20 2016 Arthur Josso
** Last update Thu May 19 17:54:41 2016 Arthur Josso
*/

#include "rt.h"

static t_bounds	get_bounds(t_mesh *mesh, t_tri_mesh *tri)
{
  t_bounds	bounds;
  int		i;

  bounds.min.x = mesh->scr_pos[tri->vert[0].i].x;
  bounds.min.y = mesh->scr_pos[tri->vert[0].i].y;
  bounds.max.x = bounds.min.x;
  bounds.max.y = bounds.min.y;
  i = 0;
  while (++i < 3)
    {
      if (mesh->scr_pos[tri->vert[i].i].x > bounds.max.x)
	bounds.max.x = mesh->scr_pos[tri->vert[i].i].x;
      else if (mesh->scr_pos[tri->vert[i].i].x < bounds.min.x)
	bounds.min.x = mesh->scr_pos[tri->vert[i].i].x;
      if (mesh->scr_pos[tri->vert[i].i].y > bounds.max.y)
	bounds.max.y = mesh->scr_pos[tri->vert[i].i].y;
      else if (mesh->scr_pos[tri->vert[i].i].y < bounds.min.y)
	bounds.min.y = mesh->scr_pos[tri->vert[i].i].y;
    }
  resize(&bounds.min);
  resize(&bounds.max);
  return (bounds);
}

static void	put_pix(t_data *data, t_mesh *mesh, t_vec *p, float z)
{
  char		comp;
  t_color	c;

  if (z < data->z_buff[(int)p->y][(int)p->x])
    {
      data->z_buff[(int)p->y][(int)p->x] = z;
      comp = MAP(z, mesh->z_min, mesh->z_max, 255, 0);
      c.argb[RED_CMP] = comp;
      c.argb[BLUE_CMP] = comp;
      c.argb[GREEN_CMP] = comp;
      put_pixel(data->pix, p, &c);
    }
}

static void	put_tex(t_data *data,
			t_mesh *mesh,
			t_vec *p,
			t_tri_mesh *tri,
			t_vec *area,
			float z)
{
  t_color       c;
  t_vec		col_coord;

  if (z < data->z_buff[(int)p->y][(int)p->x])
    {
      data->z_buff[(int)p->y][(int)p->x] = z;
      col_coord = get_tex_coord(tri, area);
      col_coord.x = MAP(col_coord.x, 0, 1,
			0, mesh->meta.tex->clipable.clip_width);
      col_coord.y = MAP(col_coord.y, 0, 1,
			mesh->meta.tex->clipable.clip_height, 0);
      c = get_pixel(mesh->meta.tex, &col_coord);
      put_pixel(data->pix, p, &c);
    }
}

static void	draw_triangle(t_data *data,
			      t_mesh *mesh,
			      t_tri_mesh *tri,
			      t_bounds *bounds)
{
  t_vec		p;
  t_vec		area;
  float		z;
  float		w;

  w = 1 / edge(&mesh->scr_pos[tri->vert[0].i], &mesh->scr_pos[tri->vert[1].i],
	       &mesh->scr_pos[tri->vert[2].i]);
  p.x = bounds->min.x - 1;
  while (++p.x <= bounds->max.x && p.x < W_X)
    {
      p.y = bounds->min.y - 1;
      while (++p.y <= bounds->max.y && p.y < W_Y)
	{
	  area = get_bary_coef(&p, mesh, tri);
	  if ((area.x <= 0 && area.y <= 0 && area.z <= 0) ||
	      (area.x >= 0 && area.y >= 0 && area.z >= 0))
	    {
	      mult_vec(w, &area);
	      z = get_depth(mesh, tri, &area);
	      mesh->meta.tex ? put_tex(data, mesh, &p, tri, &area, z) :
		put_pix(data, mesh, &p, z);
	    }
	}
    }
}

int		rasterize(t_data *data, t_mesh *mesh)
{
  int		i;
  t_bounds	bounds;

  i = 0;
  while (mesh->tri[i])
    {
      bounds = get_bounds(mesh, mesh->tri[i]);
      draw_triangle(data, mesh, mesh->tri[i], &bounds);
      i++;
    }
  return (0);
}
