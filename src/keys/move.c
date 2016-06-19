/*
** move.c for move in /home/alies_a/rendu/gfx_raytracer2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Apr 20 14:29:45 2016 alies_a
** Last update Thu May 19 13:57:46 2016 Arthur Josso
*/

#include <math.h>
#include "rt.h"
#include "core.h"

int     key_forward(t_data *data)
{
  (data->obj.cam).pos.x += MOVE * cos((data->obj.cam).rot.z);
  (data->obj.cam).pos.y += MOVE * sin((data->obj.cam).rot.z);
  return (0);
}

int     key_backward(t_data *data)
{
  (data->obj.cam).pos.x -= MOVE * cos((data->obj.cam).rot.z);
  (data->obj.cam).pos.y -= MOVE * sin((data->obj.cam).rot.z);
  return (0);
}

int     key_left(t_data *data)
{
  (data->obj.cam).pos.x += MOVE * cos((data->obj.cam).rot.z + M_PI / 2);
  (data->obj.cam).pos.y += MOVE * sin((data->obj.cam).rot.z + M_PI / 2);
  return (0);
}

int     key_right(t_data *data)
{
  (data->obj.cam).pos.x -= MOVE * cos((data->obj.cam).rot.z + M_PI / 2);
  (data->obj.cam).pos.y -= MOVE * sin((data->obj.cam).rot.z + M_PI / 2);
  return (0);
}
