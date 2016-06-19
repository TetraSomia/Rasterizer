/*
** rast_utils.c for rasterizer in /home/josso/rendu/gfx/gfx_rasterizer
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed May 18 16:26:36 2016 Arthur Josso
** Last update Thu May 19 17:16:18 2016 Arthur Josso
*/

#include "rt.h"

float	edge(t_vec *v1, t_vec *v2, t_vec *p)
{
  return ((p->x - v1->x) * (v2->y - v1->y) -
	  (p->y - v1->y) * (v2->x - v1->x));
}

t_vec	get_bary_coef(t_vec *pix, t_mesh *mesh, t_tri_mesh *tri)
{
  t_vec	area;
  t_vec	p;

  p = *pix;
  p.x += 0.5;
  p.y += 0.5;
  area.x = edge(&mesh->scr_pos[tri->vert[0].i],
		&mesh->scr_pos[tri->vert[1].i], &p);
  area.y = edge(&mesh->scr_pos[tri->vert[1].i],
		&mesh->scr_pos[tri->vert[2].i], &p);
  area.z = edge(&mesh->scr_pos[tri->vert[2].i],
		&mesh->scr_pos[tri->vert[0].i], &p);
  return (area);
}

void	resize(t_bunny_position *p)
{
  if (p->x > W_X)
    p->x = W_X;
  if (p->y > W_Y)
    p->y = W_Y;
  if (p->x < 0)
    p->x = 0;
  if (p->y < 0)
    p->y = 0;
}

float	get_depth(t_mesh *mesh,
		  t_tri_mesh *tri,
		  t_vec *area)
{
  float	z;

  z = mesh->scr_pos[tri->vert[0].i].z * area->x
    + mesh->scr_pos[tri->vert[1].i].z * area->y
    + mesh->scr_pos[tri->vert[2].i].z * area->z;
  return (z);
}

t_vec	get_tex_coord(t_tri_mesh *tri, t_vec *area)
{
  t_vec	c;

  c.x = tri->vert[2].t->x * area->x
    + tri->vert[0].t->x * area->y
    + tri->vert[1].t->x * area->z;
  c.y = tri->vert[2].t->y * area->x
    + tri->vert[0].t->y * area->y
    + tri->vert[1].t->y * area->z;
  c.z = 0;
  return (c);
}
