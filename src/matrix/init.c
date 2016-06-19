/*
** set_m2w.c for matrix in /home/josso/rendu/gfx/gfx_rasterizer
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue May 10 16:06:35 2016 Arthur Josso
** Last update Mon May 16 15:17:51 2016 Arthur Josso
*/

#include <math.h>
#include "matrix.h"
#include "rt.h"

static t_cosin	g_cosin_values;

void	set_cosin_values(t_meta *obj)
{
  g_cosin_values.cos.x = cos(obj->rot.x);
  g_cosin_values.cos.y = cos(obj->rot.y);
  g_cosin_values.cos.z = cos(obj->rot.z);
  g_cosin_values.sin.x = sin(obj->rot.x);
  g_cosin_values.sin.y = sin(obj->rot.y);
  g_cosin_values.sin.z = sin(obj->rot.z);
}

static void	set_m2w(t_matrix *m, t_meta *obj)
{
  m[0].m[1][1] = g_cosin_values.cos.x;
  m[0].m[1][2] = -g_cosin_values.sin.x;
  m[0].m[2][1] = g_cosin_values.sin.x;
  m[0].m[2][2] = g_cosin_values.cos.x;
  m[1].m[0][0] = g_cosin_values.cos.y;
  m[1].m[2][0] = -g_cosin_values.sin.y;
  m[1].m[0][2] = g_cosin_values.sin.y;
  m[1].m[2][2] = g_cosin_values.cos.y;
  m[2].m[0][0] = g_cosin_values.cos.z;
  m[2].m[0][1] = -g_cosin_values.sin.z;
  m[2].m[1][0] = g_cosin_values.sin.z;
  m[2].m[1][1] = g_cosin_values.cos.z;
  m[3].m[0][3] = obj->pos.x;
  m[3].m[1][3] = obj->pos.y;
  m[3].m[2][3] = obj->pos.z;
  m[4].m[0][0] = obj->scale.x;
  m[4].m[1][1] = obj->scale.y;
  m[4].m[2][2] = obj->scale.z;
}

static void	set_w2v(t_matrix *m)
{
  t_vec		f;
  t_vec		s;
  t_vec		u;
  t_vec		up;

  up.x = 0;
  up.y = 1;
  up.z = 0;
  f.x = 0;
  f.y = 0;
  f.z = 1;
  s = vec_product(&f, &up);
  set_uni_vec(&s);
  u = vec_product(&s, &f);
  set_uni_vec(&u);
  m->m[0][0] = s.x;
  m->m[0][1] = s.y;
  m->m[0][2] = s.z;
  m->m[1][0] = u.x;
  m->m[1][1] = u.y;
  m->m[1][2] = u.z;
  m->m[2][0] = -f.x;
  m->m[2][1] = -f.y;
  m->m[2][2] = -f.z;
}

int	init_matrices(t_matrix *m, t_cam *cam, t_meta *obj)
{
  int	i;
  t_vec	p;

  i = 0;
  while (i < NB_MATRICES)
    if (new_matrix(&m[i++], 4, 4) == 1)
      return (1);
  set_m2w(m, obj);
  set_w2v(&m[6]);
  p.x = -cam->pos.x;
  p.y = -cam->pos.y;
  p.z = -cam->pos.z;
  set_uni_vec(&p);
  m[7].m[0][3] = p.x;
  m[7].m[1][3] = p.y;
  m[7].m[2][3] = p.z;
  mult_matrix(&m[6], &m[7], &m[5]);
  return (0);
}

int	init_pts(t_matrix *pt, t_vec *pos)
{
  if (new_matrix(&pt[0], 1, 4) == 1)
    return (1);
  if (new_matrix(&pt[1], 1, 4) == 1)
    return (1);
  pt[0].m[0][0] = pos->x;
  pt[0].m[1][0] = pos->y;
  pt[0].m[2][0] = pos->z;
  pt[0].m[3][0] = 1;
  return (0);
}
