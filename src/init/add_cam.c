/*
** add_cam.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Feb 12 16:55:32 2016 Arthur Josso
** Last update Thu Apr 14 14:52:41 2016 Arthur Josso
*/

#include "init.h"

int	add_cam(t_obj *obj, t_bunny_ini_scope *scope)
{
  if (get_ini_vec(scope, "position", &obj->cam.pos) == 1)
    return (1);
  if (get_ini_vec(scope, "rotation", &obj->cam.rot) == 1)
    return (1);
  return (0);
}
