/*
** vector2.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Feb 18 14:43:43 2016 Arthur Josso
** Last update Tue May 10 17:44:18 2016 Arthur Josso
*/

#include "rt.h"

void	inv_vec(t_vec *v)
{
  v->x *= -1;
  v->y *= -1;
  v->z *= -1;
}

void	mult_vec(float x, t_vec *v)
{
  v->x *= x;
  v->y *= x;
  v->z *= x;
}

t_vec	vec_product(t_vec *u, t_vec *v)
{
  t_vec	product;

  product.x = u->y * v->z - u->z * v->y;
  product.y = u->z * v->x - u->x * v->z;
  product.z = u->x * v->y - u->y * v->x;
  return (product);
}
