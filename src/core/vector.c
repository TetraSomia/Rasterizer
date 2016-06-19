/*
** vector.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Feb  1 18:00:08 2016 Arthur Josso
** Last update Tue May 10 16:48:33 2016 Arthur Josso
*/

#include <math.h>
#include "rt.h"

void	set_uni_vec(t_vec *v)
{
  float	div;

  div = sqrt(POW(v->x) + POW(v->y) + POW(v->z));
  v->x /= div;
  v->y /= div;
  v->z /= div;
}

float   get_norm(float k, t_vec *vec)
{
  float ret;

  ret = POW(vec->x * k) + POW(vec->y * k) + POW(vec->z * k);
  ret = sqrt(ret);
  return (ret);
}

t_vec   get_vec(t_vec *pt1, t_vec *pt2)
{
  t_vec coord;

  coord.x = pt2->x - pt1->x;
  coord.y = pt2->y - pt1->y;
  coord.z = pt2->z - pt1->z;
  return (coord);
}

t_vec   get_uni_vec(t_vec *pt1, t_vec *pt2)
{
  t_vec coord;
  float	div;

  coord.x = pt2->x - pt1->x;
  coord.y = pt2->y - pt1->y;
  coord.z = pt2->z - pt1->z;
  div = sqrt(POW(coord.x) + POW(coord.y) + POW(coord.z));
  coord.x /= div;
  coord.y /= div;
  coord.z /= div;
  return (coord);
}

float   get_dot(t_vec *v1, t_vec *v2)
{
  float dot;

  dot = v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
  return (dot);
}
